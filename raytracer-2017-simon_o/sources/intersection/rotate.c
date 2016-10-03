/*
** rotate.c for PiRaNhA in /home/cheval_y//rtv1
**
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
**
** Started on  Mon Feb 25 22:48:42 2013 franck chevallier
** Last update Sun Jun  9 13:54:39 2013 jonathan racaud
*/

#include "raytracer.h"

int		rotate(double r_x, double r_y, double r_z, t_coord *vector)
{
  t_coord	s;
  double	a;
  double	b;
  double	c;
  double	d;
  double	e;
  double	f;

  a = cos(r_x);
  b = sin(r_x);
  c = cos(r_y);
  d = sin(r_y);
  e = cos(r_z);
  f = sin(r_z);
  s = *vector;
  vector->y = vector->y * a - vector->z * b;
  vector->z = s.y * b + vector->z * a;
  s = *vector;
  vector->x = vector->x * c + vector->z * d;
  vector->z = -s.x * d + vector->z * c;
  s = *vector;
  vector->x = vector->x * e - vector->y * f;
  vector->y = s.x * f + vector->y * e;
  return (0);
}

