/*
** translate.c for raytracer in /home/cheval_y//raytracer/sources/intersection
** 
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
** 
** Started on  Thu Apr 11 11:16:33 2013 franck chevallier
** Last update Thu May 30 00:13:02 2013 jonathan racaud
*/

#include "raytracer.h"

void	translate(t_mlx *mlx, t_coord *tmp_pos_eye, t_coord pos_eye)
{
  tmp_pos_eye->x = pos_eye.x - OBJECT->x;
  tmp_pos_eye->y = pos_eye.y - OBJECT->y;
  tmp_pos_eye->z = pos_eye.z - OBJECT->z;
}

