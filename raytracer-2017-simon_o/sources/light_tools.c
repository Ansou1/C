/*
** light_tools.c for PiRaNhA in /home/cheval_y//rtv1
**
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
**
** Started on  Sun Mar 17 16:45:28 2013 franck chevallier
** Last update Thu May 30 00:16:56 2013 jonathan racaud
*/

#include "raytracer.h"

void	translate_vector(t_coord *vector, t_object *select_object)
{
  vector->x -= select_object->x;
  vector->y -= select_object->y;
  vector->z -= select_object->z;
}

int	normalize_vector(t_coord *vector)
{
  float		norme_vector;

  norme_vector = sqrt(vector->x * vector->x + vector->y *
  		 vector->y + vector->z * vector->z);
  vector->x /= norme_vector;
  vector->y /= norme_vector;
  vector->z /= norme_vector;
  return (1);
}
