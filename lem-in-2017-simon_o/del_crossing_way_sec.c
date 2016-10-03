/*
** del_crossing_way_sec.c for lem_in in /home/daguen_s//final_lemin/tar
**
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Apr 25 14:45:35 2013 simon daguenet
** Last update Thu Apr 25 15:16:45 2013 simon daguenet
*/

#include "lemin.h"

t_room		**del_link(t_room **tab, t_room *link, t_room *room)
{
  t_room	**ret;
  int		i;
  int		a;

  a = 0;
  i = 0;
  ret = xmalloc(sizeof (*ret) * (my_tablen(tab) + 1));
  if (room != NULL)
    link->tab = del_link(link->tab, room, NULL);
  while (tab[i])
    {
      if (tab[i] != link)
	ret[a++] = tab[i];
      i++;
    }
  ret[a] = NULL;
  free(tab);
  return (ret);
}

void	del_the_cross_bis(t_room *way, int *ctr, int *ctr2, int i)
{
  if (way->tab[i]->p == way->p - 1)
    *ctr = *ctr + 1;
  if (way->tab[i]->p == way->p + 1)
    *ctr2 = *ctr2 + 1;
  if (*ctr2 == 2)
    {
      *ctr2 = *ctr2 - 1;
      way->tab = del_link(way->tab, way->tab[i], way);
    }
  if (*ctr == 2)
    {
      *ctr = *ctr - 1;
      way->tab = del_link(way->tab, way->tab[i], way);
    }
}

void	del_the_cross(t_room *way)
{
  int	ctr;
  int	i;
  int	ctr2;

  while (way->p != 0)
    {
      i = 0;
      ctr = 0;
      ctr2 = 0;
      while (way->tab[i])
	{
	  del_the_cross_bis(way, &ctr, &ctr2, i);
	  i++;
	}
      way = next_room(way);
    }
}

void	del_the_useless_link(t_room *start, t_room **r)
{
  int	i;

  i = 0;
  while (start->tab[i])
    {
      if (start->tab[i]->p == start->p - 1 && start->tab[i]->type != USELESS)
	{
	  del_the_cross(start->tab[i]);
	  reset_water(r);
	  r = water_fill(r);
	}
      i++;
    }
}

void		del_crossing_way(t_room	**r)
{
  int		i;
  t_room	*start;

  i = 0;
  while (r[i])
    {
      if (r[i]->type == START)
	start = r[i];
      i++;
    }
  start->tab = sort_tab(start->tab);
  del_the_useless_link(start, r);
}

