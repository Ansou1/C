/*
** manage_key.c for raytracer in /home/cheval_y//raytracer
** 
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
** 
** Started on  Tue Apr  9 15:07:26 2013 franck chevallier
** Last update Sun Jun  9 21:00:44 2013 efilon
*/

#include <unistd.h>
#include "raytracer.h"

void	manage_image_video(t_mlx *mlx)
{
  char	buff;

  buff = 0;
  if (access("/usr/local/bin/ffmpeg", X_OK) == -1)
    {
      fprintf(stderr, "\nAttention, ffmpeg n'est peut-etre pas installé.\n");
      fprintf(stderr, "Voulez vous continuer ? [O/n]\n");
      read(0, &buff, 1);
      if (buff == 'n' && (buff != 'O' && buff != '\n'))
	return ;
    }
  printf("Attention, la creation de la video necessite %dMo.\n",
	 ((WINDOW_X * WINDOW_Y * 3) / 1000000) * mlx->video.nb_images);
  create_video(mlx);
  printf("Done.\n");
}

int	manage_key(int keycode, t_mlx *mlx)
{
  if (keycode == 65307)
    {
      mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
      exit (EXIT_SUCCESS);
    }
  if (keycode == 'n')
    {
      mlx->image = mlx->image->next;
      mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image->img_ptr, 0, 0);
    }
  if (keycode == 'p')
    {
      mlx->image = mlx->image->prev;
      mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image->img_ptr, 0, 0);
    }
  if (keycode == 'b')
    {
      printf("\nCreating bmp file %s\n", mlx->image->name);
      create_bmp_file(mlx);
      printf("Done.\n");
    }
  if (keycode == 'v')
    manage_image_video(mlx);
  return (0);
}
