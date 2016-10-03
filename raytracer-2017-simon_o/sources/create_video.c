/*
** create_video.c for create_video in /home/efilon/raytracer-2017-simon_o/sebastien/sources
** 
** Made by efilon
** Login   <efilon@Heisenbergs-RV>
** 
** Started on  Thu May 30 13:32:51 2013 efilon
** Last update Sun Jun  9 22:14:58 2013 sebastien antonico
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>
#include "raytracer.h"
#include "video.h"

int	create_tmp_bmp(t_mlx *mlx, int id)
{
  char	*tmp_name;
  int	ret;

  if ((tmp_name = malloc(strlen(mlx->image->name) + 1)) == NULL)
    manage_error("Erreur malloc\n");
  memset(tmp_name, 0, strlen(mlx->image->name) + 1);
  snprintf(tmp_name, strlen(mlx->image->name) - 3, "%s", mlx->image->name);
  free(mlx->image->name);
  if ((mlx->image->name = malloc(strlen(tmp_name) + 10)) == NULL)
    manage_error("Erreur malloc\n");
  memset(mlx->image->name, 0, strlen(tmp_name) + 10);
  sprintf(mlx->image->name, "tmp/%s%d.bmp", basename(tmp_name), id);
  ret = create_bmp_file(mlx);
  free(mlx->image->name);
  if ((mlx->image->name = malloc(strlen(tmp_name) + 5)) == NULL)
    manage_error("Erreur malloc\n");
  memset(mlx->image->name, 0, strlen(tmp_name) + 5);
  sprintf(mlx->image->name, "%s.bmp", tmp_name);
  free(tmp_name);
  if (ret == -1)
    return (!fprintf(stderr, "Video generation stopped.\n"));
  return (1);
}

int	generate_video(t_mlx *mlx)
{
  char	*cmd;
  char	*name_file;
  int	len;

  name_file = my_strndup(mlx->image->name, strlen(mlx->image->name) - 4);
  len = 40 + strlen(name_file) * 2;
  if ((cmd = malloc(len)) == NULL)
    manage_error("Erreur malloc\n");
  memset(cmd, 0, len);
  sprintf(cmd, "ffmpeg -i tmp/%s%%d.bmp -r 24 video.avi", basename(name_file));
  system(cmd);
  memset(cmd, 0, len);
  free(cmd);
  free(name_file);
  return (1);
}

int	create_tmp_img(t_mlx *mlx)
{
  int	x;
  int	y;

  y = 0;
  while (y < WINDOW_Y)
    {
      x = 0;
      while (x < WINDOW_X)
    	{
    	  my_pixel_put_to_image(mlx, x, y, calc(x, y, mlx));
    	  x += 1;
    	}
      y += 1;
    }
  return (1);
}

int		create_next_file(t_mlx *mlx, int id, double *t)
{
  printf("Creating file %d of %d...\n", id, mlx->video.nb_images);
  EYE->eye_pos.x = -(mlx->video.center_x + cos(*t) * (double)mlx->video.radius);
  EYE->eye_pos.y = -(mlx->video.center_y + sin(*t) * (double)mlx->video.radius);
  EYE->r_z -= (360.0 / (double)(mlx->video.nb_images));
  create_tmp_img(mlx);
  if (!create_tmp_bmp(mlx, id))
    return (0);
  *t += DEGTORAD((360.0 / (double)(mlx->video.nb_images)));
  return (1);
}

int		create_video(t_mlx *mlx)
{
  t_eye		copy_eye;
  char		*copy_data;
  int		id;
  double	t;
  int		cont;

  cont = 1;
  if (mkdir("tmp", 0777) == -1 && errno != EEXIST)
    return (!fprintf(stderr, "Impossible de créer le dossier temporaire.\n"));
  copy_eye = *(EYE);
  copy_data = mlx->image->data;
  set_eye_video(mlx);
  t = 0;
  id = 1;
  while (t < 2 * MY_PI && cont)
    if (!create_next_file(mlx, id++, &t))
      cont = 0;
  if (cont)
    generate_video(mlx);
  if (access("/usr/bin/ffmpeg", X_OK) != -1)
    system("rm -rf tmp/");
  *(EYE) = copy_eye;
  mlx->image->data = copy_data;
  return (cont);
}
