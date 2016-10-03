/*
** draw_line.c for fdf in /home/daguen_s//Ighaph/fdf
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Fri Dec  7 09:36:30 2012 simon daguenet
** Last update Sat Dec  8 13:32:29 2012 simon daguenet
*/
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include "my_fdf.h"

int	draw_cas_un_deux(t_element *param)
{
  int	x;

  x = param->x1;
  while (x <= param->x2)
    {
      my_pixel_put_to_image(param, x, param->y1
			    + ((param->y2-param->y1)*(x-param->x1))
			    /(param->x2-param->x1));
      x++;
    }
}

int	draw_cas_trois_quatre(t_element *param)
{
  int	x;

  x = param->x2;
  while (x <= param->x1)
    {
      my_pixel_put_to_image(param, x, param->y1
			    + ((param->y2-param->y1)*(x-param->x1))
			    /(param->x2-param->x1));
      x++;
    }
}

int	draw_cas_five_six(t_element *param)
{
  int	y;

  y = param->y1;
  while (y <= param->y2)
    {
      my_pixel_put_to_image(param, param->x1
			    + ((param->y1-y)*(param->x2-param->x1))
			    /(param->y1-param->y2), y);
      y++;
    }
}

int	draw_cas_seven_eight(t_element *param)
{
  int	y;

  y = param->y2;
  while (y <= param->y1)
    {
      my_pixel_put_to_image(param, param->x1
			    + ((param->y1-y)*(param->x2-param->x1))
			    /(param->y1-param->y2), y);
      y++;
    }
}

int	draw_exeption(t_element *param)
{
  int	x;

  x = param->x1;
  while (x <= param->x2)
    {
      my_pixel_put_to_image(param, x,
			    param->y1 + (param->y2-param->y1)*(x-param->x1));
      x++;
    }
}
