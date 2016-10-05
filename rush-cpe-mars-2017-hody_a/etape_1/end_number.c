/*
** end_number.c for rush in /home/daguen_s//rush/save_valgrind
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Mar  3 10:38:13 2013 simon daguenet
** Last update Sun Mar  3 10:53:19 2013 simon daguenet
*/

#include "rush.h"

int	end_one(int x, int y, t_laby *s)
{
  if ((y - 1) >= 0)
    return (s->algo[y - 1][x]);
  return (0);
}

int	end_two(int x, int y, t_laby *s)
{
  if (s->algo[y + 1])
    return (s->algo[y + 1][x]);
  return (0);
}

int	end_three(int x, int y, t_laby *s)
{
  if ((x + 1) <= s->size_x)
    return (s->algo[y][x + 1]);
  return (0);
}

int	end_for(int x, int y, t_laby *s)
{
  if ((x - 1) >= 0)
    return (s->algo[y][x - 1]);
  return (0);
}
