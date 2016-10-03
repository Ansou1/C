/*
** inter_cone.c for PiRaNhA in /home/cheval_y//rtv1
**
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
**
** Started on  Fri Mar 15 20:34:10 2013 franck chevallier
** Last update Sat Jun  8 18:01:15 2013 antoine simon
*/

#include "raytracer.h"

void		delta_cone(t_discriminant *disc, int alpha, t_coord vect,
			   t_coord pos)
{
  double	tan2;

  tan2 = tan(RAD(alpha)) * tan(RAD(alpha));
  disc->a = pow(vect.x, 2) + pow(vect.y, 2) -
    ((1 / tan2) * pow(vect.z, 2));
  disc->b = 2 * (vect.x * pos.x + vect.y * pos.y -
		pos.z * vect.z / tan2);
  disc->c = pow(pos.x, 2) + pow(pos.y, 2) - (pow(pos.z, 2) / tan2);
  disc->delta = pow(disc->b, 2) - 4 * disc->a * disc->c;
}

int			inter_cone(t_mlx *mlx, t_coord v_eye,
				   t_coord eye_pos)
{
  int			alpha;
  double		k1;
  double		k2;
  t_discriminant	disc;
  t_coord		eye_vector;
  t_coord		tmp_eye_pos;

  alpha = OBJECT->radius;
  eye_vector = v_eye;
  translate(mlx, &tmp_eye_pos, eye_pos);
  rotate(-RAD(OBJECT->r_x), -RAD(OBJECT->r_y), -RAD(OBJECT->r_z),
	 &eye_vector);
  rotate(-RAD(OBJECT->r_x), -RAD(OBJECT->r_y), -RAD(OBJECT->r_z),
	 &tmp_eye_pos);
  delta_cone(&disc, alpha, eye_vector, tmp_eye_pos);
  if (calc_k(disc, &k1, &k2) == 0)
    {
      fill_result(mlx, k1, k2);
      return (0);
    }
  return (1);
}
