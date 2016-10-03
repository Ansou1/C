/*
** getenv.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sat Mar 30 21:22:35 2013 florian corradin
** Last update Wed May 15 16:33:19 2013 florian corradin
*/

#include "42.h"

/* retourn ret pour la fonction reoit la chaine de caractere */
/*  contenant la valeur de la variable */
char	*get_var_env(char *env)
{
  int	i;
  char	*ret;
  int	i2;

  i2 = 0;
  i = 0;
  while (env[i] != '=' && env[i] != '\0')
    i++;
  if (env[i] == '\0')
    return (NULL);
  i++;
  ret = malloc(my_strlen(&env[i]) + 1);
  if (ret == NULL)
    return (NULL);
  while (env[i] != '\0')
    {
      ret[i2] = env[i];
      i2++;
      i++;
    }
  ret[i2] = '\0';
  return (ret);
}

char	*my_getenv(char *var)
{
  int	i;
  char	*ret;

  ret = NULL;
  i = 0;
  if (info.env == NULL)
    return (NULL);
  while (info.env[i] != NULL)
    {
      if (my_strncmp(var, info.env[i], my_strlen(var)) == 1)
	ret = get_var_env(info.env[i]);
      i++;
    }
  return (ret);
}

/* recoit $var et retourne valeur de var */
char	*get_value_of_var(char *str)
{
  char	*ret;

  if (str[1] == '\0' || str[1] == ' ' || str[1] == '\t')
    {
      ret = malloc(2);
      if (ret == NULL)
	return (ret);
      ret[0] = '$';
      ret[1] = '\0';
      return (ret);
    }
  if ((ret = my_getenv(&str[1])) == NULL)
    ret = get_other_shell_var(str);
  if (ret == NULL)
    {
      fprintf(stderr, "%s: Undefined variable\n", &str[1]);
      return (NULL);
    }
  return (ret);
}

char	*replace_in_str(char *src, char *del, char *rep, int pos)
{
  int	i;
  int	j;
  int	k;
  char	*ret;

  i = 0;
  j = 0;
  k = 0;
  ret = malloc(my_strlen(src) + my_strlen(rep) + 1);
  if (ret == NULL)
    return (NULL);
  while (i < pos && src[i] != '\0')
    ret[j++] = src[i++];
  while (rep[k] != '\0')
    ret[j++] = rep[k++];
  k = 0;
  while (del[k++] != '\0' && src[i] != '\0')
    i++;
  while (src[i] != '\0')
    ret[j++] = src[i++];
  ret[j] = '\0';
  free(del);
  free(rep);
  free(src);
  return (ret);
}

int	is_special_char(char c)
{
  int	i;

  i = 0;
  while (SPECIAL_CHAR[i] != '\0')
    {
      if (c == SPECIAL_CHAR[i])
	return (1);
      i++;
    }
  return (0);
}
