/*
** intersection.c for PiRaNhA in /home/cheval_y//rtv1
**
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
**
** Started on  Wed Feb 27 11:55:29 2013 franck chevallier
** Last update Sat Jun  8 17:59:22 2013 antoine simon
*/

#include "raytracer.h"

int		check_limit_plan(t_coord tmp_eye_pos, t_mlx *mlx, double k,
				 t_coord eye_vector)
{
  t_coord		vv;

  vv.x = tmp_eye_pos.x + k * eye_vector.x;
  vv.y = tmp_eye_pos.y + k * eye_vector.y;
  vv.z = tmp_eye_pos.z + k * eye_vector.z;
  if (vv.x > (OBJECT->width_limit / 2) ||
      vv.x < ((OBJECT->width_limit / 2) * -1))
    return (1);
  if (vv.y > (OBJECT->length_limit / 2) ||
      vv.y < ((OBJECT->length_limit / 2) * -1))
    return (1);
  return (0);
}

int			inter_plan(t_mlx *mlx, t_coord v_eye,
				   t_coord eye_pos)
{
  double		k;
  t_coord		eye_vector;
  t_coord		tmp_eye_pos;

  eye_vector = v_eye;
  translate(mlx, &tmp_eye_pos, eye_pos);
  rotate(-RAD(OBJECT->r_x), -RAD(OBJECT->r_y), -RAD(OBJECT->r_z), &eye_vector);
  rotate(-RAD(OBJECT->r_x), -RAD(OBJECT->r_y), -RAD(OBJECT->r_z), &tmp_eye_pos);
  k = (tmp_eye_pos.z / eye_vector.z) * (-1);
  if (k >= 0)
    {
      fill_result(mlx, k, k);
      if (OBJECT->width_limit != -1 && OBJECT->length_limit != -1)
	{
	  if (check_limit_plan(tmp_eye_pos, mlx, k, eye_vector) == 1)
	    return (1);
	}
      return (0);
    }
  return (1);
}
