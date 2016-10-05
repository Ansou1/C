/*
** graphique.c for sudoku in /home/daguen_s//rush/graphique
**
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
**
** Started on  Sun Apr 21 17:05:00 2013 simon daguenet
** Last update Sun Apr 21 22:14:31 2013 simon daguenet
*/

#include "sudoku.h"

int	gere_key(int touche)
{
  if (touche == 65307)
    exit(0);
  return (0);
}

int	gere_expose(t_element *param)
{
  mlx_put_image_to_window(param->mlx_ptr,
			  param->win_ptr, param->img, 0, 0);
  draw_string(param, param->tab, param->base);
  return (0);
}

void	my_pixel_put_to_image(t_element *param, int x, int y)
{
  param->data = mlx_get_data_addr(param->img,
				  &param->bpp, &param->sizeline,
				  &param->endian);
  y = param->sizeline * y;
  param->data[y + x*(param->bpp/8)] = 0;
  param->data[y + x*(param->bpp/8) + 1] = (char)255;
  param->data[y + x*(param->bpp/8) + 2] = 0;
}

void		aff(char **tab, char *base)
{
  t_element	p;

  p.tab = tab;
  p.base = base;
  if ((p.mlx_ptr = mlx_init()) == NULL)
    exit(EXIT_FAILURE);
  if ((p.win_ptr = mlx_new_window(p.mlx_ptr, 1920, 1080, "SUDOKU")) == NULL)
    exit(EXIT_FAILURE);
  if ((p.img = mlx_new_image(p.mlx_ptr, 1920, 1080)) == NULL)
    exit(EXIT_FAILURE);
  if ((p.data = mlx_get_data_addr
       (p.img, &p.bpp, &p.sizeline, &p.endian)) == NULL)
    exit(EXIT_FAILURE);
  draw_sudo_y(&p);
  draw_sudo_x(&p);
  mlx_key_hook(p.win_ptr, gere_key, 0);
  mlx_expose_hook(p.win_ptr, gere_expose, &p);
  mlx_put_image_to_window(p.mlx_ptr, p.win_ptr, p.img, 0, 0);
  mlx_loop(p.mlx_ptr);
}
