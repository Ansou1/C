/*
** water_fill.c for lem_in in /home/corrad_f//projet/lem-in
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Mon Apr 15 14:30:50 2013 florian corradin
** Last update Thu Apr 25 14:31:30 2013 simon daguenet
*/

#include "lemin.h"

char	change_all_link_weight(t_room **tab, int p)
{
  int	i;
  char	end;

  end = 1;
  i = 0;
  while (tab[i])
    {
      if (tab[i]->p == -1)
	{
	  tab[i]->p = p + 1;
	  end = 0;
	}
      i++;
    }
  return (end);
}

char	fill_all_of_the_same_weight(t_room **tab, int p)
{
  int	i;
  char	end;

  end = 0;
  i = 0;
  while (tab[i])
    {
      if (tab[i]->p == p)
	end += change_all_link_weight(tab[i]->tab, p);
      i++;
    }
  return (end);
}

t_room	**water_fill(t_room **tab)
{
  char	end;
  int	p;

  p = 0;
  end = 0;
  while ((end = fill_all_of_the_same_weight(tab, p++)) == 0);
  return (tab);
}

void	reset_water(t_room **r)
{
  int	i;

  i = 0;
  while (r[i])
    {
      if (r[i]->type == END)
	r[i]->p = 0;
      else
	r[i]->p = -1;
      i++;
    }
}
