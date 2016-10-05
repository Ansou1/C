/*
** end.c for rush in /home/hody_a//rush
** 
** Made by alexy hody
** Login   <hody_a@epitech.net>
** 
** Started on  Sat Mar  2 15:58:44 2013 alexy hody
** Last update Sun Mar  3 15:22:36 2013 simon daguenet
*/

#include "rush.h"

void	get_end(t_laby *s)
{
  if (end_for(s->x, s->y, s) == (s->cnt))
    {
      s->end[s->y][s->x - 1] = -5;
      s->x = s->x - 1;
    }
  else if (end_three(s->x, s->y, s) == (s->cnt))
    {
      s->end[s->y][s->x + 1] = -5;
      s->x = s->x + 1;
    }
  else if (end_two(s->x, s->y, s) == (s->cnt))
    {
      s->end[s->y + 1][s->x] = -5;
      s->y = s->y + 1;
    }
  else if (end_one(s->x, s->y, s) == (s->cnt))
    {
      s->end[s->y - 1][s->x] = -5;
      s->y = s->y - 1;
    }
  s->cnt--;
}

void	end_tab(t_laby *s)
{
  s->x = s->new_pathx;
  s->y = s->new_pathy;
  s->cnt = s->bestpath - 1;
  while (s->cnt > 1)
    get_end(s);
}

int	end(t_laby *s)
{
  int	i;
  int	x;

  if ((s->end = malloc(4097 * sizeof (int**))) == NULL)
    return (-1);
  i = 0;
  while (i < s->size_y)
    {
      s->end[i] = malloc((s->size_y + 10) * sizeof (int*));
      x = 0;
      while (x < s->size_x)
        {
	  s->end[i][x] = s->tab[i][x];
	  x++;
        }
      s->end[i][x] = 0;
      i++;
    }
  s->end[i] = 0;
  return (0);
}
