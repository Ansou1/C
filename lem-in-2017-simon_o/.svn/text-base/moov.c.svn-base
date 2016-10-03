/*
** moov.c for lemin in /home/corrad_f//projet/lem-in
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Wed Apr 17 15:08:34 2013 florian corradin
** Last update Sun Apr 28 23:28:55 2013 simon daguenet
*/

#include "lemin.h"

void	push_name(t_room *room, t_room *save)
{
  save->ant--;
  room->ant++;
  if (room->n1 == 0)
    room->n1 = save->n1;
  else
    room->n2 = save->n1;
  save->n1 = save->n2;
}

void		push_ant_until(t_room *room, int name)
{
  t_room	*save;
  int		stop;

  stop = 0;
  room->ant++;
  my_printf("P%d-%s ", name, room->name);
  if (room->n1 == 0)
    room->n1 = name;
  else
    room->n2 = name;
  while (room->type != END && stop == 0)
    {
      if (room->ant == 2)
	{
	  save = room;
	  room = next_room(room);
	  push_name(room, save);
	  name = (room->n2 == 0) ? room->n1 : room->n2;
	  my_printf("P%d-%s ", name, room->name);
	}
      else
	stop = 1;
    }
}

int	clean_the_way(t_room *way)
{
  while (way->ant == 0 && way->type != END)
    way = next_room(way);
  if (way->type != END)
    {
      way->ant--;
      push_ant_until(next_room(way), way->n1);
      return (0);
    }
  return (1);
}
