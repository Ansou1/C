/*
** calc_light_vector.c for PiRaNhA in /home/cheval_y//rtv1
** 
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
** 
** Started on  Wed Feb 27 11:24:29 2013 franck chevallier
** Last update Sat Jun  8 15:42:57 2013 antoine simon
*/

#include "raytracer.h"

void		calc_light_vector(t_coord *light, t_coord pos_light,
				  t_object *select_object)
{
  light->x = pos_light.x - select_object->result->intersection.x;
  light->y = pos_light.y - select_object->result->intersection.y;
  light->z = pos_light.z - select_object->result->intersection.z;
}
