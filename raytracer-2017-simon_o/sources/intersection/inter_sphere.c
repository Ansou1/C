/*
** inter_sphere.c for PiRaNhA in /home/cheval_y//rtv1
**
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
**
** Started on  Fri Mar 15 17:57:11 2013 franck chevallier
** Last update Sat Jun  8 18:02:50 2013 antoine simon
*/

#include "raytracer.h"

int			inter_sphere(t_mlx *mlx, t_coord v_eye,
				     t_coord eye_pos)
{
  double		k1;
  double		k2;
  int			r_s;
  t_discriminant	disc;
  t_coord		tmp_eye_pos;

  r_s = OBJECT->radius;
  translate(mlx, &tmp_eye_pos, eye_pos);
  disc.a = pow(v_eye.x, 2) + pow(v_eye.y, 2) + pow(v_eye.z, 2);
  disc.b = 2 * (tmp_eye_pos.x * v_eye.x + tmp_eye_pos.y * v_eye.y
		+ tmp_eye_pos.z * v_eye.z);
  disc.c = pow(tmp_eye_pos.x, 2) + pow(tmp_eye_pos.y, 2)
    + pow(tmp_eye_pos.z, 2) - pow(r_s, 2);
  disc.delta = pow(disc.b, 2) - 4 * disc.a * disc.c;
  if (calc_k(disc, &k1, &k2) == 0)
    {
      fill_result(mlx, k1, k2);
      return (0);
    }
  return (1);
}
