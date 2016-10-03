/*
** array2.c for mini in /home/corrad_f//projet/minishell1
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Fri Dec 14 10:28:21 2012 florian corradin
** Last update Thu May 23 14:36:46 2013 simon daguenet
*/

#include "42.h"

char	*my_strdup(char *str)
{
  int	i;
  char	*ret;

  i = 0;
  if (str == NULL)
    return (NULL);
  if ((ret = malloc(my_strlen(str) + 1)) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      ret[i] = str[i];
      i++;
    }
  ret[i] = '\0';
  return (ret);
}

char	**my_copy_tab(char **src)
{
  char	**ret;
  int	i;

  i = 0;
  while (src[i] != NULL)
    i++;
  ret = malloc(sizeof (char *) * (i + 1));
  check_malloc(ret);
  ret[i] = NULL;
  i = 0;
  while (src[i] != NULL)
    {
      ret[i] = my_strdup(src[i]);
      i++;
    }
  return (ret);
}

void	my_free_tab(char **tabl)
{
  int	i;

  i = 0;
  if (tabl != NULL)
    while (tabl[i] != NULL)
      {
	free(tabl[i]);
	i++;
      }
  if (tabl != NULL)
    free(tabl);
}

void	my_put_tab(char **tabl)
{
  int	i;

  i = 0;
  while (tabl[i] != NULL)
    {
      my_putstr(tabl[i]);
      my_putstr("\n");
      i++;
    }
}

char	**my_tabdup(char **tabl)
{
  int	i;
  char	**ret;

  i = 0;
  while (tabl[i])
    i++;
  if ((ret = malloc(sizeof (char *) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  while (tabl[i])
    {
      ret[i] = my_strdup(tabl[i]);
      i++;
    }
  ret[i] = NULL;
  return (ret);
}
