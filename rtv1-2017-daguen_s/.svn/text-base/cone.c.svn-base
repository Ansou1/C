/*
** cone.c for rtv1 in /home/daguen_s//prepa_rtv1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Mar 17 16:06:57 2013 simon daguenet
** Last update Sun Mar 17 16:24:54 2013 simon daguenet
*/

#include "rtv1.h"

t_result	cone(t_point_3d save, t_point_3d vect, t_element *p)
{
  t_point_3d	eyes;
  t_result	ret;
  double	a;
  double	b;
  double	c;

  eyes = save;
  eyes.x = eyes.x - p->con.x;
  eyes.y = eyes.y - p->con.y;
  eyes.z = eyes.z - p->con.z;
  eyes = rotate_inv(eyes, p->con);
  vect = rotate_inv(vect, p->con);
  a = pow(vect.x, 2) + pow(vect.y, 2) - (pow(vect.z, 2) / (CON(p->con.r)));
  b = 2 *(eyes.x * vect.x + eyes.y * vect.y -
	((eyes.z * vect.z) / CON(p->con.r)));
  c = pow(eyes.x, 2) + pow(eyes.y, 2) - ((eyes.z * eyes.z) / CON(p->con.r));
  ret = equation_second(a, b, c);
  ret.n.x = eyes.x + ret.min * vect.x;
  ret.n.y = eyes.y + ret.min * vect.y;
  ret.n.z = -pow(tan(p->con.r), 2);
  ret.sec.x = eyes.x + ret.min * vect.x;
  ret.sec.y = eyes.y + ret.min * vect.y;
  ret.sec.z = eyes.z + ret.min * vect.z;
  return (ret);
}

t_result	calc_cone(t_element *param, int x, int y)
{
  t_point_3d	eyes;
  t_point_3d	vect;
  t_result	ret;

  vect.x = 100;
  vect.y = ((WIDTH / 2) - (double)x) - param->eyes.y;
  vect.z = ((HEIGHT / 2) - (double)y) - param->eyes.z;
  ret = cone(param->eyes, vect, param);
  return (ret);
}
