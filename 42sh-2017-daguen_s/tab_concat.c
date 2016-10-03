/*
** tab_concat.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Fri Feb 22 21:01:50 2013 florian corradin
** Last update Tue May 21 13:42:07 2013 florian corradin
*/

#include "42.h"

int	my_tablen(char	**tabl)
{
  int	i;

  i = 0;
  if (tabl == NULL)
    return (0);
  while (tabl[i] != NULL)
    {
      i++;
    }
  return (i);
}

char	**my_tabcat(char **tabl, char *str)
{
  char	**new_tab;
  int	len;
  int	i;

  i = 0;
  len = my_tablen(tabl);
  if ((new_tab = malloc(sizeof (char **) * (len + 2))) == NULL)
    return (NULL);
  new_tab[len + 1] = NULL;
  while (tabl[i] != NULL)
    {
      new_tab[i] = my_strdup(tabl[i]);
      i++;
    }
  my_free_tab(tabl);
  new_tab[i] = my_strdup(str);
  new_tab[i + 1] = NULL;
  free(str);
  return (new_tab);
}
