/*
** my_wolf.c for wolf in /home/daguen_s//charlotte
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Jan 13 00:49:47 2013 simon daguenet
** Last update Sun Jan 13 19:13:14 2013 simon daguenet
*/

#include "my_wolf.h"

int	gere_key(int keycode, t_element *param)
{
  if (keycode == 65307)
    exit(EXIT_SUCCESS);
  else if (keycode == 65362)
    move_down(param, 0.1);
  else if (keycode == 65364)
    move_up(param, -0.1);
  else if (keycode == 65363)
    go_left(param);
  else if (keycode == 65361)
    go_right(param);
  return (0);
}

int	gere_expose(t_element *param)
{
  mlx_put_image_to_window(param->mlx_ptr,
			param->win_ptr, param->img.image, 0, 0);
}

int	main()
{
  t_element	param;

  param.x = 8;
  param.y = 8;
  param.agl = 235 * RAD;
  if ((param.mlx_ptr = mlx_init()) == NULL)
    exit(EXIT_FAILURE);
  if ((param.win_ptr = mlx_new_window
      (param.mlx_ptr, WIDTH, HEIGHT, "Wolf3D")) == NULL)
    exit(EXIT_FAILURE);
  if ((param.img.image = mlx_new_image(param.mlx_ptr, WIDTH, HEIGHT)) == NULL)
    exit(EXIT_FAILURE);
  param.img.data = mlx_get_data_addr
    (param.img.image, &param.img.bpp, &param.img.sizeline, &param.img.endian);
  if (param.img.data == NULL)
    exit(EXIT_FAILURE);
  draw_all(&param);
  mlx_put_image_to_window(param.mlx_ptr, param.win_ptr, param.img.image, 0, 0);
  mlx_expose_hook(param.win_ptr, gere_expose, &param);
  mlx_hook(param.win_ptr, KeyPress, KeyPressMask, &gere_key, &param);
  mlx_key_hook(param.win_ptr, gere_key, &param);
  mlx_loop(param.mlx_ptr);
}
