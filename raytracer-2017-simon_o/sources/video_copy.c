/*
** video_copy.c for video_copy in /tmp/mjkzerlzekrjzelkjzer/raytracer-2017-simon_o/rt
** 
** Made by efilon
** Login   <efilon@Heisenbergs-RV>
** 
** Started on  Sun Jun  9 15:11:41 2013 efilon
** Last update Sun Jun  9 16:37:18 2013 jonathan racaud
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <errno.h>
#include <string.h>
#include "raytracer.h"
#include "video.h"

void	set_eye_video(t_mlx *mlx)
{
  EYE->eye_pos.x = mlx->video.center_x - mlx->video.radius;
  EYE->eye_pos.y = 0;
  EYE->eye_pos.z = mlx->video.center_z;
  EYE->r_z = (360.0 / (double)(mlx->video.nb_images));
}
