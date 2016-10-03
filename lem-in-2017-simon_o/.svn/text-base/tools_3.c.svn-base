/*
** tools_3.c for lem_in in /home/daguen_s//final_lemin/tar
**
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Apr 25 15:10:35 2013 simon daguenet
** Last update Thu Apr 25 15:11:08 2013 simon daguenet
*/

#include "lemin.h"

int	my_tablen(t_room **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

void	free_room(t_room **tab)
{
  while (*tab)
    free(*tab++);
}

char	is_digit(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

char	*get_name(char *str)
{
  int	i;
  char	*ret;

  i = 0;
  while (str[i] != '\0' && str[i] != ' ' && str[i++] != '\t');
  ret = xmalloc(i + 1);
  i = 0;
  while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
    {
      ret[i] = str[i];
      i++;
    }
  ret[i] = '\0';
  return (ret);
}

