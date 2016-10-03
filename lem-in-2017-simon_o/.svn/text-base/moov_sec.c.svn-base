/*
** moov_sec.c for lem_in in /home/daguen_s//final_lemin/tar
**
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Apr 25 14:50:58 2013 simon daguenet
** Last update Sun Apr 28 18:22:06 2013 simon daguenet
*/

#include "lemin.h"

void	moov_ant_bis(t_room *start, int i, int check, int name)
{
  while (start->ant != 0)
    {
      check = 0;
      i = 0;
      while (start->tab[i])
	{
	  if (start->tab[i]->p <= start->ant && start->tab[i]->type != 4)
	    {
	      push_ant_until(start->tab[i], name);
	      name++;
	      start->ant--;
	      check = 1;
	    }
	  i++;
	}
      if (check == 0)
	{
	  push_ant_until(start->tab[0], name);
	  name++;
	  start->ant--;
	}
      my_printf("\n");
    }
}

void	moov_the_last(t_room *start)
{
  int	all_ant_are_not_at_end;
  int	i;

  i = 0;
  all_ant_are_not_at_end = 1;
  while (all_ant_are_not_at_end == 1)
    {
      i = 0;
      while (start->tab[i])
	{
	  all_ant_are_not_at_end -= clean_the_way(start->tab[i]);
	  i++;
	}
      my_printf("\n");
    }
}

void	moov_ant(t_room *start)
{
  int	i;
  int	check;
  int	name;

  name = 1;
  i = 0;
  check = 0;
  moov_ant_bis(start, i, check, name);
  moov_the_last(start);
}
