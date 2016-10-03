/*
** fill_result.c for raytracer in /home/cheval_y//raytracer/sources/intersection
** 
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
** 
** Started on  Thu Apr 11 11:17:35 2013 franck chevallier
** Last update Sat Jun  8 18:00:28 2013 antoine simon
*/

#include "raytracer.h"

void		smallest_k(t_result *result, double k1, double k2)
{
  if (k1 <= k2)
    {
      result->k = k2;
      result->k1 = k1;
      result->k2 = k2;
    }
  else if (k2 <= k1)
    {
      result->k = k2;
      result->k1 = k2;
      result->k2 = k1;
    }
}

int	def_normal(t_coord  *normal, t_coord intersection, int type, int radius)
{
  if (type == CONE)
    {
      normal->x = intersection.x;
      normal->y = intersection.y;
      normal->z = intersection.z / -pow(radius, 2);
    }
  if (type == CYLINDER)
    {
      normal->x = intersection.x;
      normal->y = intersection.y;
      normal->z = 0.0;
    }
  if (type == PLANE)
    {
      normal->x = 0.0;
      normal->y = 0.0;
      normal->z = 100.0;
    }
  if (type == SPHERE)
    {
      normal->x = intersection.x;
      normal->y = intersection.y;
      normal->z = intersection.z;
    }
  return (0);
}

t_result	*fill_result(t_mlx *mlx, double k1, double k2)
{
  smallest_k(OBJECT->result, k1, k2);
  OBJECT->result->intersection.x = EYE->eye_pos.x + OBJECT->result->k1
    * EYE->v_eye.x;
  OBJECT->result->intersection.y = EYE->eye_pos.y + OBJECT->result->k1
    * EYE->v_eye.y;
  OBJECT->result->intersection.z = EYE->eye_pos.z + OBJECT->result->k1
    * EYE->v_eye.z;
  return (OBJECT->result);
}
