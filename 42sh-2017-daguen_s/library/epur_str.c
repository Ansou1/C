/*
** epur_str.c for string.h in /home/corrad_f//lib/string
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Fri Jan 18 18:27:18 2013 florian corradin
** Last update Fri Apr  5 15:41:19 2013 florian corradin
*/

#include "42.h"

char	*my_epurstr(char *str)
{
  int	i;
  char	*ret;
  int	a;

  a = 0;
  if ((ret = malloc(my_strlen(str) + 1)) == NULL)
    return (NULL);
  ret[my_strlen(str)] = '\0';
  i = 0;
  while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
    i++;
  while (str[i] != '\0')
    {
      if ((str[i] == ' ' || str[i] == '\t') &&
	  (str[i + 1] == ' ' || str[i + 1] == '\t'))
	i++;
      else
	ret[a++] = str[i++];
    }
  if (a > 0)
    if (ret[a - 1] == ' ' || ret[a - 1] == '\t')
      ret[a - 1] = '\0';
  ret[a] = '\0';
  return (ret);
}

char	*my_epurstr_free(char *str)
{
  int	i;
  char	*ret;
  int	a;

  a = 0;
  if ((ret = malloc(my_strlen(str) + 1)) == NULL)
    return (NULL);
  ret[my_strlen(str)] = '\0';
  i = 0;
  while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
    i++;
  while (str[i] != '\0')
    {
      if ((str[i] == ' ' || str[i] == '\t') &&
	  (str[i + 1] == ' ' || str[i + 1] == '\t'))
	i++;
      else
	ret[a++] = str[i++];
    }
  if (a > 0)
    if (ret[a - 1] == ' ' || ret[a - 1] == '\t')
      ret[a - 1] = '\0';
  ret[a] = '\0';
  free(str);
  return (ret);
}

int	is_s(char *str, int pos)
{
  if (is_c(str, pos, ' ') == 1)
    return (1);
  else
    return (is_c(str, pos, '\t'));
}

char	*my_epurstr_inib(char *str)
{
  int	i;
  char	*ret;
  int	a;

  a = 0;
  if ((ret = malloc(my_strlen(str) + 1)) == NULL)
    return (NULL);
  ret[my_strlen(str)] = '\0';
  i = 0;
  while (str[i] != '\0' && is_s(str, i) == 1)
    i++;
  while (str[i] != '\0')
    {
      if (is_s(str, i) == 1 && is_s(str, i + 1) == 1)
	i++;
      else
	ret[a++] = str[i++];
    }
  if (a > 0)
    if (ret[a - 1] == ' ' || ret[a - 1] == '\t')
      ret[a - 1] = '\0';
  ret[a] = '\0';
  free(str);
  return (ret);
}
