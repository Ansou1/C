/*
** del_crossing_way.c for lemin.c in /home/corrad_f//projet/lem-in
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Tue Apr 16 11:45:19 2013 florian corradin
** Last update Sun Apr 28 18:33:23 2013 simon daguenet
*/

#include "lemin.h"

t_room		**sort_tab(t_room **tab)
{
  int		i;
  int		max;
  int		a;
  t_room	*tmp;

  i = 0;
  max = my_tablen(tab);
  while (i < max)
    {
      a = 0;
      while (tab[a + 1])
	{
	  if (tab[a]->p > tab[a + 1]->p)
	    {
	      tmp = tab[a];
	      tab[a] = tab[a + 1];
	      tab[a + 1] = tmp;
	    }
	  a++;
	}
      i++;
    }
  return (tab);
}

t_room	*next_room(t_room *way)
{
  int	p;
  int	i;

  i = 0;
  p = way->p;
  while (way->tab[i])
    {
      if (way->tab[i]->p == (p - 1) && way->tab[i]->type != USELESS)
	return (way->tab[i]);
      i++;
    }
  my_puterror("\033[1;31mERROR: The END is not reachable.\033[0;m\n");
  return (NULL);
}
