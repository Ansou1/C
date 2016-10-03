/*
** light.c for PiRaNhA in /home/cheval_y//rtv1
**
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
**
** Started on  Wed Feb 27 11:53:23 2013 franck chevallier
** Last update Sun Jun  9 13:30:20 2013 jonathan racaud
*/

#include "raytracer.h"

void	deformation(t_coord *normal, t_object *select_object)
{
  if (select_object->bump.x == 1)
    normal->x *= cos(select_object->result->intersection.x);
  if (select_object->bump.y == 1)
    normal->y *= cos(select_object->result->intersection.y);
  if (select_object->bump.z == 1)
    normal->z *= cos(select_object->result->intersection.z);
}

t_coord	add_light(t_coord normal, t_object *select_object, int type)
{
  normal = select_object->result->intersection;
  translate_vector(&normal, select_object);
  rotate(-RAD(select_object->r_x), -RAD(select_object->r_y),
  	 -RAD(select_object->r_z), &normal);
  def_normal(&normal, normal, type, select_object->radius);
  normalize_vector(&normal);
  deformation(&normal, select_object);
  return (normal);
}

t_coord	effect_light(t_coord light, t_object *select_object)
{
  rotate(-RAD(select_object->r_x), -RAD(select_object->r_y),
  	 -RAD(select_object->r_z), &light);
  normalize_vector(&light);
  return (light);
}

int		cos_light(t_object *select_object, int color, t_mlx *mlx, t_spec spec)
{
  double	cos_a;

  cos_a = (spec.normal.x * spec.light.x + spec.normal.y * spec.light.y
	   + spec.normal.z * spec.light.z);
  check_cos(mlx, &color, 0.2, select_object);
  check_cos(mlx, &color, cos_a, select_object);
  color = speculaire(mlx, select_object, color, spec);
  return (color);
}

int		light(int type, t_object *select_object, t_mlx *mlx)
{
  t_light	*tmp;
  int		color;
  t_spec	spec;

  tmp = LIGHT;
  color = 0x000000;
  while (LIGHT)
    {
      calc_light_vector(&spec.light, LIGHT->pos_light, select_object);
      if (shadow(mlx, &spec.light, select_object) == 0)
	color = add_color2(color, 0x000000);
      else
      	{
	  spec.normal = add_light(spec.normal, select_object, type);
	  spec.light = effect_light(spec.light, select_object);
	  color = cos_light(select_object, color, mlx, spec);
	}
      LIGHT = LIGHT->next;
    }
  LIGHT = tmp;
  return (color);
}
