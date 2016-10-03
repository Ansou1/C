/*
** inter_cylinder.c for PiRaNhA in /home/cheval_y//rtv1
**
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
**
** Started on  Fri Mar 15 18:39:37 2013 franck chevallier
** Last update Fri Jun  7 18:13:15 2013 antoine simon
*/

#include "raytracer.h"

int			inter_cylinder(t_mlx *mlx, t_coord v_eye,
				       t_coord eye_pos)
{
  double		k1;
  double		k2;
  int			r_s;
  t_discriminant	disc;
  t_coord		eye_vector;
  t_coord		tmp_eye_pos;

  r_s = OBJECT->radius;
  eye_vector = v_eye;
  translate(mlx, &tmp_eye_pos, eye_pos);
  rotate(-RAD(OBJECT->r_x), -RAD(OBJECT->r_y), -RAD(OBJECT->r_z), &eye_vector);
  rotate(-RAD(OBJECT->r_x), -RAD(OBJECT->r_y), -RAD(OBJECT->r_z), &tmp_eye_pos);
  disc.a = pow(eye_vector.x, 2) + pow(eye_vector.y, 2);
  disc.b = 2 * ( eye_vector.x * tmp_eye_pos.x + eye_vector.y * tmp_eye_pos.y);
  disc.c = pow(tmp_eye_pos.x, 2) + pow(tmp_eye_pos.y, 2) - pow(r_s, 2);
  disc.delta = pow(disc.b, 2) - 4 * disc.a * disc.c;
  if (calc_k(disc, &k1, &k2) == 0)
    {
      OBJECT->result = fill_result(mlx, k1, k2);
      return (0);
    }
  return (1);
}
