/*
** my_fdf.c for fdf in /home/daguen_s//Ighaph/fdf
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Dec  3 10:26:39 2012 simon daguenet
** Last update Sat Dec  8 17:21:24 2012 simon daguenet
*/

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include "my_fdf.h"

void	my_pixel_put_to_image(t_element *param, int x, int y)
{
  param->data = mlx_get_data_addr(param->img,
				  &param->bpp, &param->sizeline,
				  &param->endian);
  y = param->sizeline * y;
  param->data[y + x*(param->bpp/8)] = 0;
  param->data[y + x*(param->bpp/8) + 1] = 255;
  param->data[y + x*(param->bpp/8) + 2] = 0;
}

int	draw_base(t_element *param)
{
  int	x;
  int	y;

  x = abs(param->x2 - param->x1);
  y = abs(param->y2 - param->y1);
  if (x >= y)
    {
      if (param->x1 > param->x2)
  	  draw_cas_trois_quatre(param);
      else if (param->x1 == param->x2)
	draw_exeption(param);
      else
  	  draw_cas_un_deux(param);
    }
  else
    {
      if (param->y1 > param->y2)
     	  draw_cas_seven_eight(param);
      else if (param->y1 == param->y2)
	draw_exeption(param);
      else
	  draw_cas_five_six(param);
    }
}

int	isometrique(t_element *param, int x, int y, char *z1)
{
  static int	pel = 0;
  int	z;

  z = my_getnbr(z1);
  z = z * -1;
  if (pel == 2)
    pel = 0;
  if (pel == 0)
    {
      param->x1 = - (910 + ((0.67 * x * 20) - (0.67 * y * 20)));
      param->y1 = 540 + z + ((0.67/2) * x * 20) + ((0.67/2) * y * 20);
    }
  if (pel == 1)
    {
      param->x2 = - (910 + ((0.67 * x * 20) - (0.67 * y * 20)));
      param->y2 = 540 + z + ((0.67/2) * x * 20) + ((0.67/2) * y * 20);
      draw_base(param);
    }
  pel++;
}

int	display_draw(t_element *param, char ***tab, int taille)
{
  int	i;
  int	j;

  j = 0;
  while (tab[j])
    {
      i = 0;
      while (tab[j][i] != NULL)
	{
	  if (tab[i + 1] != NULL)
	    {
	      isometrique(param, i, j, tab[i][j]);
	      isometrique(param, (i + 1), j, tab[i + 1][j]);
	    }
	  if ((j + 1) < taille)
	    {
	      isometrique(param, i, j, tab[i][j]);
	      isometrique(param, i, (j + 1), tab[i][j + 1]);
	    }
	  i++;
	}
      j++;
    }
  free_tab(tab, taille);
}

int	display_screen(char ***tab, int i)
{
  t_element	param;

  param.mlx_ptr = mlx_init();
  if (param.mlx_ptr == NULL)
    exit(EXIT_FAILURE);
  param.win_ptr = mlx_new_window(param.mlx_ptr, 1920, 1080, "fdf");
  if (param.win_ptr == NULL)
    exit(EXIT_FAILURE);
  param.img = mlx_new_image(param.mlx_ptr, 1920, 1080);
  if (param.img == NULL)
    exit(EXIT_FAILURE);
  param.data = mlx_get_data_addr
    (param.img, &param.bpp, &param.sizeline, &param.endian);
  if (param.data == NULL)
    exit(EXIT_FAILURE);
  display_draw(&param, tab, i);
  mlx_key_hook(param.win_ptr, gere_key, 0);
  mlx_expose_hook(param.win_ptr, gere_expose, &param);
  mlx_put_image_to_window(param.mlx_ptr, param.win_ptr, param.img, 0, 0);
  mlx_loop(param.mlx_ptr);
}
