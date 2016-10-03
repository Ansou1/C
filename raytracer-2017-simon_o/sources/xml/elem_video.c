/*
** elem_video.c for elem_video in /home/efilon/WORKSPACERT/raytracer-2017-simon_o/rt
** 
** Made by efilon
** Login   <efilon@Heisenbergs-RV>
** 
** Started on  Sun Jun  9 01:17:25 2013 efilon
** Last update Sun Jun  9 15:29:48 2013 efilon
*/

#include <unistd.h>
#include "raytracer.h"

int	add_video(t_mlx *rt, char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (!my_strncmp_case(tab[i], "centre_x=", 9))
	rt->video.center_x = atoi(tab[i] + 10);
      else if (!my_strncmp_case(tab[i], "centre_y=", 9))
	rt->video.center_y = atoi(tab[i] + 10);
      else if (!my_strncmp_case(tab[i], "centre_z=", 9))
	rt->video.center_z = atoi(tab[i] + 10);
      else if (!my_strncmp_case(tab[i], "rayon=", 6))
	rt->video.radius = atoi(tab[i] + 7);
      else if (!my_strncmp_case(tab[i], "images=", 7))
	rt->video.nb_images = atoi(tab[i] + 8);
      i++;
    }
  rt->video.radius = MAX(10, rt->video.radius);
  rt->video.nb_images = MAX(1, MIN(360, rt->video.nb_images));
  return (1);
}
