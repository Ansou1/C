/*
** manage_expose.c for raytracer in /home/cheval_y//raytracer
** 
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
** 
** Started on  Tue Apr  9 15:05:14 2013 franck chevallier
** Last update Tue May 28 18:17:09 2013 jonathan racaud
*/

#include "raytracer.h"

int	manage_expose(t_mlx *mlx)
{
  mlx_put_image_to_window(mlx->mlx_ptr,
			  mlx->win_ptr, mlx->image->img_ptr, 0, 0);
  return (0);
}
