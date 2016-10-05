/*
** resolve_thr.c for sudoku in /home/daguen_s//rush/cpe-rush2-2017-corrad_f
**
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
**
** Started on  Sun Apr 21 11:00:54 2013 simon daguenet
** Last update Sun Apr 21 11:45:09 2013 simon daguenet
*/

#include "sudoku.h"

int	is_col(char **sol, int x, int y, int val)
{
  int	y1;

  y1 = 0;
  while (sol[y1])
    {
      if (sol[y1][x] == val && y1 != y && sol[y1][x] != '0')
	return (0);
      y1++;
    }
  return (1);
}

int	is_line(char **sol, int x, int y, int val)
{
  int	x1;

  x1 = 0;
  while (sol[y][x1])
    {
      if (sol[y][x1] == val && x1 != x && sol[y][x1] != '0')
	return (0);
      x1++;
    }
  return (1);
}

int	is_in_rule(char **sol, int x, int y, int val)
{
  int	ret;

  ret = 0;
  ret += is_col(sol, x, y, val);
  ret += is_line(sol, x, y, val);
  ret += is_cube(sol, x, y, val);
  if (ret == 3)
    return (1);
  else
    return (0);
}

void	next(int *x, int *y)
{
  *x = 0;
  *y = *y + 1;
}

void	previous(int *x, int *y, int len)
{
  *x = len - 1;
  *y = *y - 1;
}
