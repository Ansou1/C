/*
** draw.c for wolf in /home/daguen_s//charlotte
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Jan 13 00:42:02 2013 simon daguenet
** Last update Sun Jan 13 01:23:23 2013 simon daguenet
*/

#include "my_wolf.h"

int	mlx_put_pixel_to_img(t_img img, int x, int y, int color)
{
  int	position_pixel;

  if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
    return (0);
  position_pixel = x + (y * WIDTH);
  *(((int *)(img.data)) + position_pixel) = color;
  return (0);
}

int	color(t_img img)
{
  if (img.kx > img.ky)
    {
      if (img.primex > 0)
        return (COLOR2);
      else
        return (COLOR4);
    }
  else
    {
      if (img.primey > 0)
        return (COLOR1);
      else
        return (COLOR3);
    }
}

int	draw_wall(int taille, int row, t_img img)
{
  int	y;
  int	save_y;

  y = HEIGHT - taille;
  y = y / 2;
  save_y = y;
  while (y <= save_y + taille)
    {
      mlx_put_pixel_to_img(img, row, y, color(img));
      y++;
    }
  return (0);
}

int	draw(int taille, int row, t_img img)
{
  int	y;

  y = 0;
  while (y <= (HEIGHT - taille) / 2)
    {
      mlx_put_pixel_to_img(img, row, y,
			((0x77 - (0x77 * y / ((HEIGHT) / 2))) << 8 << 8)
			+((0xae - (0xae * y / ((HEIGHT) / 2))) << 8)
			+((0xcb - (0xcb * y / ((HEIGHT) / 2)))));
      y++;
    }
  y = ((HEIGHT - taille) / 2) + taille ;
  while (y <= HEIGHT)
    {
      mlx_put_pixel_to_img(img, row, y,
			(((0x5f * (y - HEIGHT / 2) / ((HEIGHT)))) << 8 << 8)
			+(((0x88 * (y - HEIGHT / 2) / ((HEIGHT)))) << 8)
			+(((0x3d * (y - HEIGHT / 2) / ((HEIGHT))))));
      y++;
    }
  draw_wall(taille, row, img);
  return (0);
}

int	draw_all(t_element *param)
{
  int	row;

  row = 0;
  while (row != WIDTH)
    {
      draw(HEIGHT / (2 * get_k(param, row)), row, param->img);
      row++;
    }
  mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
			param->img.image , 0, 0);
  return (0);
}
