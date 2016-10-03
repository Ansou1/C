/*
** do_rt.c<2> for raytracer in /home/jonathan/Documents/Work/svn/raytracer-2017-simon_o/raytracer-2017-simon_o/Raytracer_antoine
**
** Made by jonathan racaud
** Login   <racaud_j@epitech.net>
**
** Started on  Tue May 28 18:08:38 2013 jonathan racaud
** Last update Sun Jun  9 16:05:55 2013 jonathan racaud
*/

#include <string.h>
#include <stdlib.h>
#include "raytracer.h"

int		add_image(t_mlx *mlx, char *name)
{
  t_image	*tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (-1);
  tmp->img_ptr = mlx_new_image(mlx->mlx_ptr,
			       mlx->width, mlx->height);
  tmp->data = mlx_get_data_addr(tmp->img_ptr, &(tmp->bpp), &(tmp->sizeline),
				&(tmp->endian));
  tmp->name = my_get_file_name(name);
  if (mlx->image == NULL)
    {
      tmp->next = tmp;
      tmp->prev = tmp;
    }
  else
    {
      tmp->next = mlx->image;
      mlx->image->prev->next = tmp;
      tmp->prev = mlx->image->prev;
      mlx->image->prev = tmp;
    }
  mlx->image = tmp;
  return (0);
}

void	mlx_hook_functions(t_mlx *mlx)
{
  mlx_key_hook(mlx->win_ptr, manage_key, mlx);
  mlx_expose_hook(mlx->win_ptr, manage_expose, mlx);
  mlx_loop(mlx->mlx_ptr);
}

void	create_window(t_mlx *mlx)
{
  if (mlx->win_created == 0)
    {
      if ((mlx->mlx_ptr = mlx_init()) == NULL)
	manage_error("Error with mlx_init !\n");
      mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
				    mlx->width,
				    mlx->height, "Raytracer");
      mlx->win_created = 1;
    }
}

int		do_rt(char **av)
{
  t_mlx		mlx;
  int		i;

  i = 1;
  mlx.win_created = 0;
  mlx.xml_error = 0;
  mlx.image = NULL;
  while (av[i] != NULL)
    {
      if (!conf_file(&mlx, av[i]))
  	{
  	  my_print_error(av[i++]);
	  mlx.xml_error += 1;
  	}
      else
  	{
	  create_window(&mlx);
	  add_image(&mlx, av[i++]);
	  multi_thread(&mlx);
    	}
    }
  if (mlx.xml_error != i - 1)
    mlx_hook_functions(&mlx);
  return (0);
}
