/*
** clean_command2.c for 42sh in /home/corrad_f//projet/infect
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Wed May  8 14:23:13 2013 florian corradin
** Last update Wed May  8 14:24:07 2013 florian corradin
*/

#include "42.h"

int	count_pipe(t_com *list)
{
  int	i;

  i = 0;
  while (list)
    {
      if (list->redir == 1)
	i++;
      list = list->next;
    }
  return (i);
}

int	is_strnum(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (!(str[i] >= '0' && str[i] <= '9'))
	return (0);
      i++;
    }
  return (1);
}
