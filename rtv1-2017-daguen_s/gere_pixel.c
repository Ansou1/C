/*
** gere_pixel.c for rtv1 in /home/daguen_s//prepa_rtv1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Mar 17 16:09:35 2013 simon daguenet
** Last update Sun Mar 17 16:30:41 2013 simon daguenet
*/

#include "rtv1.h"

int	mlx_put_pixel_to_img(t_img img, int x, int y, int color)
{
  int	position_pixel;

  position_pixel = x + (y * WIDTH);
  *(((int *)(img.data)) + position_pixel) = color;
  return (0);
}

int	gere_key(int keycode, t_element *param)
{
  if (keycode == 65307)
    {
      mlx_destroy_window(param->mlx_ptr, param->win_ptr);
      exit(EXIT_SUCCESS);
    }
  return (0);
}

int	gere_expose(t_element *param)
{
  mlx_put_image_to_window(param->mlx_ptr,
			param->win_ptr, param->img.image, 0, 0);
}
