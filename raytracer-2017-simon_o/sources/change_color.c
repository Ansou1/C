/*
** change_color.c for PiRaNhA in /home/cheval_y//rtv1
** 
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
** 
** Started on  Mon Feb 25 11:02:37 2013 franck chevallier
** Last update Sat Jun  8 15:43:17 2013 antoine simon
*/

#include "raytracer.h"

int		change_color(int color, double cos_a, t_object *select_object,
			     t_mlx *mlx)
{
  int		rr;
  int		gg;
  int		bb;

  rr = RED(color);
  gg = GREEN(color);
  bb = BLUE(color);
  if ((rr = (rr + select_object->brightness *
	     RED(LIGHT->color)) * cos_a) >= 255)
    rr = 255;
  if ((gg = (gg + select_object->brightness *
	     GREEN(LIGHT->color)) * cos_a) >= 255)
    gg = 255;
  if ((bb = (bb + select_object->brightness *
	     BLUE(LIGHT->color)) * cos_a) >= 255)
    bb = 255;
  color = rr * 0x10000 + gg * 0x100 + bb;
  return (color);
}
