/*
** resolve.c for sudoku in /home/corrad_f//projet/sudoku
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Sat Apr 20 09:39:14 2013 florian corradin
** Last update Sun Apr 21 11:38:14 2013 simon daguenet
*/

#include "sudoku.h"

int	is_cube(char **sol, int x, int y, int val)
{
  int	x0;
  int	y0;
  int	x1;
  int	y1;

  y1 = 0;
  x0 = (x / g_len) * g_len;
  y0 = (y / g_len) * g_len;
  while (y1 < g_len)
    {
      x1 = 0;
      while (x1 < g_len)
	{
	  if (sol[y0 + y1][x0 + x1] == val && y0 + y1 != y &&
	      x0 + x1 != x && sol[y0 + y1][x0 + x1] != '0')
	    return (0);
	  x1++;
	}
      y1++;
    }
  return (1);
}

char	get_next_value(char **sol, int x, int y)
{
  char	ctr;
  char	len;

  len = g_len * g_len;
  if (sol[y][x] == '0')
    ctr = 1;
  else
    ctr = sol[y][x] + 1;
  while (ctr < len + 1)
    {
      if (is_in_rule(sol, x, y, ctr))
	return (ctr);
      ctr++;
    }
  return ('0');
}

int	next_case(char **sudo, int *x, int *y)
{
  int	len;

  len = g_len * g_len;
  if (*x == len - 1)
      next(x, y);
  else
    *x = *x + 1;
  if (*y == g_len * g_len)
    return (-1);
  if (is_intouchable(sudo, *x, *y) == 0)
    return (0);
  while (is_intouchable(sudo, *x, *y))
    {
      if (*x == len - 1)
	{
	  *x = 0;
	  *y = *y + 1;
	}
      else
	*x = *x + 1;
      if (*y == g_len * g_len)
	return (-1);
    }
  return (0);
}

int	previous_case(char **sudo, int *x, int *y)
{
  int	len;

  len = g_len * g_len;
  if (*x == 0)
    previous(x, y, len);
  else
    *x = *x - 1;
  if (*y == -1)
    return (-2);
  if (is_intouchable(sudo, *x, *y))
    {
      while (is_intouchable(sudo, *x, *y))
	{
	  if (*x == 0)
	    {
	      *x = len - 1;
	      *y = *y - 1;
	    }
	  else
	    *x = *x - 1;
	  if (*y == -1)
	    return (-2);
	}
    }
  return (0);
}

void	get_good_sudo(char **sudo, char *base)
{
  char	**sol;

  sudo = get_g(sudo, base);
  g_len = (int)sqrt(strlen(base));
  sol = my_tabdup(sudo);
  sol = resolve(sudo, sol);
  aff(sol, base);
  my_freetab(sol);
}
