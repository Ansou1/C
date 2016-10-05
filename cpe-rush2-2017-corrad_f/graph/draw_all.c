/*
** draw_all.c for sudoku in /home/daguen_s//rush/cpe-rush2-2017-corrad_f/graph
**
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
**
** Started on  Sun Apr 21 22:04:52 2013 simon daguenet
** Last update Sun Apr 21 22:06:06 2013 simon daguenet
*/

#include "sudoku.h"

int	draw_sudo_x(t_element *param)
{
  int	i;
  int	x;
  int	y;
  int	k;

  k = 70;
  i = 0;
  while (i < 10)
    {
      y = 0;
      while (y < 5)
	{
	  x = 0;
	  while (x < 900)
	    {
	      my_pixel_put_to_image(param, x + 520, k + y);
	      x++;
	    }
	  y++;
	}
      i++;
      k = k + 100;
    }
  return (0);
}

int	draw_sudo_y(t_element *param)
{
  int	i;
  int	x;
  int	y;
  int	k;

  k = 520;
  i = 0;
  while (i < 10)
    {
      x = 0;
      while (x < 5)
	{
	  y = 0;
	  while (y < 900)
	    {
	      my_pixel_put_to_image(param, x + k, y + 70);
	      y++;
	    }
	  x++;
	}
      i++;
      k = k + 100;
    }
  return (0);
}

int	draw_string(t_element *param, char **tab, char *base)
{
  int	i;
  int	x;
  int	y;
  int	j;
  char	buf[10];

  i = 0;
  y = 130;
  while (tab[i])
    {
      x = 570;
      j = 0;
      while (tab[i][j])
	{
	  sprintf(&(buf[0]), "%c", base[(int)tab[i][j] - 1]);
	  mlx_string_put(param->mlx_ptr, param->win_ptr,
			x, y, 0xFFFFFF, &(buf[0]));
	  x += 100;
	  j++;
	}
      i++;
      y += 100;
    }
  return (0);
}
