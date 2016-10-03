/*
** cylinder.c for rtv1 in /home/daguen_s//prepa_rtv1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Mar 17 16:05:33 2013 simon daguenet
** Last update Sun Mar 17 16:06:31 2013 simon daguenet
*/

#include "rtv1.h"

t_result	cylindre(t_point_3d save, t_point_3d vect, t_element *p)
{
  t_point_3d	eyes;
  t_result	ret;
  double	a;
  double	b;
  double	c;

  eyes = save;
  eyes.x = eyes.x - p->cyl.x;
  eyes.y = eyes.y - p->cyl.y;
  eyes.z = eyes.z - p->cyl.z;
  eyes = rotate_inv(eyes, p->cyl);
  vect = rotate_inv(vect, p->cyl);
  a = vect.x * vect.x + vect.y * vect.y;
  b = 2 *(eyes.x * vect.x + eyes.y * vect.y);
  c = eyes.x * eyes.x + eyes.y * eyes.y  - p->cyl.r * p->cyl.r;
  ret = equation_second(a, b, c);
  ret.n.x = eyes.x + ret.min * vect.x;
  ret.n.y = eyes.y + ret.min * vect.y;
  ret.n.z = 0;
  ret.sec.x = eyes.x + ret.min * vect.x;
  ret.sec.y = eyes.y + ret.min * vect.y;
  ret.sec.z = eyes.z + ret.min * vect.z;
  return (ret);
}

t_result	calc_cylindre(t_element *param, int x, int y)
{
  t_point_3d	eyes;
  t_point_3d	vect;
  t_result	ret;

  vect.x = 100;
  vect.y = (WIDTH / 2) - (double)x - param->eyes.y;
  vect.z = (HEIGHT / 2) - (double)y - param->eyes.z;
  ret = cylindre(param->eyes, vect, param);
  return (ret);
}
