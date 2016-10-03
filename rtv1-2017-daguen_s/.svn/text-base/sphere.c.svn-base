/*
** sphere.c for rtv1 in /home/daguen_s//prepa_rtv1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Mar 17 16:03:30 2013 simon daguenet
** Last update Sun Mar 17 16:04:35 2013 simon daguenet
*/

#include "rtv1.h"

t_result	sphere(t_point_3d save, t_point_3d vect, t_element *p)
{
  t_point_3d	eye;
  t_result	ret;
  double	a;
  double	b;
  double	c;

  eye = save;
  eye.x = eye.x - p->sph.x;
  eye.y = eye.y - p->sph.y;
  eye.z = eye.z - p->sph.z;
  a = vect.x * vect.x + vect.y * vect.y + vect.z * vect.z;
  b = 2 *(eye.x * vect.x + eye.y * vect.y + eye.z * vect.z);
  c = eye.x * eye.x + eye.y * eye.y + eye.z * eye.z - (p->sph.r * p->sph.r);
  ret = equation_second(a, b, c);
  ret.n.x = eye.x + ret.min * vect.x;
  ret.n.y = eye.y + ret.min * vect.y;
  ret.n.z = eye.z + ret.min * vect.z;
  ret.sec = ret.n;
  return (ret);
}

t_result	calc_sphere(t_element *param, int x, int y)
{
  t_point_3d	vect;
  t_result	ret;
  int		color;

  vect.x = 100;
  vect.y = (WIDTH / 2) - (double)x - param->eyes.y;
  vect.z = (HEIGHT / 2) - (double)y - param->eyes.z;
  ret = sphere(param->eyes, vect, param);
  return (ret);
}
