/*
** resolve_fou.c for sudoku in /home/daguen_s//rush/cpe-rush2-2017-corrad_f
**
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
**
** Started on  Sun Apr 21 11:04:15 2013 simon daguenet
** Last update Sun Apr 21 11:38:25 2013 simon daguenet
*/

#include "sudoku.h"

char		**resolve(char **sudo, char **sol)
{
  int		x;
  int		y;
  char		c;
  t_point	p;
  int		continu;

  continu = 0;
  get_the_first(&x, &y, sudo);
  p.x = x;
  p.y = y;
  while (sol[y] && continu == 0)
    {
      check_imp(sol, x, y, p);
      c = get_next_value(sol, x, y);
      sol[y][x] = c;
      if (c != '0')
	continu = next_case(sudo, &x, &y);
      else
	continu = previous_case(sudo, &x, &y);
    }
  if (continu == -2)
    my_puterror("The map don't check the rules");
  return (sol);
}

char	**get_g(char **sudo, char *base)
{
  int	x;
  int	y;

  y = 0;
  while (sudo[y])
    {
      x = 0;
      while (sudo[y][x])
	{
	  sudo[y][x] = digit(base, sudo[y][x]);
	  x++;
	}
      y++;
    }
  return (sudo);
}

void	check_imp(char **sudo, int x, int y, t_point p)
{
  if (x == p.x && y == p.y)
    {
      if (sudo[y][x] == g_len * g_len)
	my_puterror("The map don't check the rules");
    }
}
