/*
** dell_useless_way.c for lem_in.c in /home/corrad_f//projet/lem-in
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Mon Apr 15 19:55:43 2013 florian corradin
** Last update Sun Apr 28 22:47:58 2013 simon daguenet
*/

#include "lemin.h"

void		delink_in_tab(t_room *room)
{
  static int	cnt = 0;
  t_room	*tmp;

  tmp = room->tab[0];
  room->type = USELESS;
  if (tmp != NULL)
    {
      cnt++;
      if (cnt > 20000)
	exit (0);
      if (my_tablen(tmp->tab) == 1 && tmp->tab[0]->type != END
	  && tmp->tab[0]->type != START)
	delink_in_tab(tmp);
    }
}

void	dell_one_direction_way(t_room **tab)
{
  int	i;

  if ((*tab)->p == -1)
    my_puterror("\033[1;31mINVALID FILE\033[0;m\n");
  i = 0;
  while (tab[i])
    {
      if (my_tablen(tab[i]->tab) == 1 && tab[i]->type != START
	  && tab[i]->type != END)
	delink_in_tab(tab[i]);
      i++;
    }
}
