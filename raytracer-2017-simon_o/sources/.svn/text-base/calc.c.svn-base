/*
** calc.c for PiRaNhA in /home/cheval_y//rtv1
**
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
**
** Started on  Sat Mar 16 23:28:29 2013 franck chevallier
** Last update Sun Jun  9 13:40:54 2013 jonathan racaud
*/

#include "raytracer.h"

void		set_projection(t_mlx *mlx, double x, double y)
{
  double	x1;
  double	y1;
  double	z1;

  x1 = 1000;
  y1 = (WINDOW_X / 2) - x;
  z1 = (WINDOW_Y / 2) - y;
  EYE->v_eye.x = x1;
  EYE->v_eye.y = y1;
  EYE->v_eye.z = z1;
  rotate(-RAD(EYE->r_x), -RAD(EYE->r_y), -RAD(EYE->r_z), &EYE->v_eye);
}

int	filtre(int color, t_mlx *mlx)
{
  if (mlx->filter == FILTER_RED)
    return (color & 0xFF0000);
  else if (mlx->filter == FILTER_BLUE)
    return (color & 0xFF);
  else if (mlx->filter == FILTER_GREEN)
    return (color & 0xFF00);
  else if (mlx->filter == FILTER_BW)
    return (AVG_COLOR(color) * 0x10000 + AVG_COLOR(color) * 0x100
	    + AVG_COLOR(color));
  else if (mlx->filter == FILTER_NEG)
    return ((255 - RED(color)) * 0x10000 + (255 - GREEN(color)) * 0x100
	    + (255 - BLUE(color)));
  else if (mlx->filter == FILTER_SEPIA)
    {
      color = AVG_COLOR(color) * 0x10000 + AVG_COLOR(color) * 0x100
	+ AVG_COLOR(color);
      return (RED(color) * 0x10000
	      + (int)(((double)(GREEN(color)) / 100.0) * 82.9) * 0x100
	      + (int)(((double)(BLUE(color)) / 100.0) * 69.4));
    }
  else
    return (color);
}

int	good_color(int *color, int r, t_mlx *mlx)
{
  int	nbr;
  int	rr;
  int	gg;
  int	bb;
  int	index;

  index = 0;
  rr = 0;
  gg = 0;
  bb = 0;
  nbr = r * r;
  while (index <= nbr)
    {
      rr += RED(color[index]);
      gg += GREEN(color[index]);
      bb += BLUE(color[index++]);
    }
  rr /= nbr;
  gg /= nbr;
  bb /= nbr;
  rr = (rr > 255) ? 255 : (rr / 1.2015);
  gg = (gg > 255) ? 255 : (gg / 1.2015);
  bb = (bb > 255) ? 255 : (bb / 1.2015);
  free(color);
  return (filtre(rr * 0x10000 + gg * 0x100 + bb, mlx));
}

int		calc(double x, double y, t_mlx *mlx)
{
  int		*color;
  double	a;
  double	b;
  double	rapport;
  int		c;

  a = -0.5;
  c = 0;
  rapport = 1 / (((double)(mlx->anti_aliasing) < 1) ?
		 (1) : ((double)(mlx->anti_aliasing)));
  if ((color = malloc(sizeof(int) * (pow(mlx->anti_aliasing, 2) * 2))) == NULL)
    return (-1);
  while (a < 0.5)
    {
      b = -0.5;
      while (b < 0.5)
	{
	  set_projection(mlx, x + b, y + a);
	  color[c++] = find_intersection(mlx, EYE->v_eye, EYE->eye_pos);
	  b += rapport;
	}
      a += rapport;
    }
  return (good_color(color, (double)(mlx->anti_aliasing), mlx));
}
