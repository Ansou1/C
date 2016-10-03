/*
** other.c for allum1 in /home/daguen_s//myalum1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Feb 10 19:39:13 2013 simon daguenet
** Last update Sun Feb 10 20:12:47 2013 simon daguenet
*/

#include "allum1.h"

int		nbr_line_in_list_current(t_list *list)
{
  t_list	*tmp;
  int		nbr_line;

  nbr_line = 0;
  tmp = list;
  while (tmp)
    {
      if (tmp->nbr != 0)
        nbr_line++;
      tmp = tmp->next;
    }
  return (nbr_line);
}

int		nbr_max_in_list(t_list *list)
{
  t_list	*tmp;
  int		nbr_line;

  nbr_line = 0;
  tmp = list;
  while (tmp)
    {
      if (nbr_line < tmp->nbr)
        nbr_line = tmp->nbr;
      tmp = tmp->next;
    }
  return (nbr_line);
}

void	check_end(int check_match)
{
  if (check_match == 1)
    {
      my_putstr("\033[31m");
      my_putstr("You WIN!!!\n");
      my_putstr("\033[37m");
    }
}
