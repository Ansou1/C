#include <stdio.h>
#include "maths.h"

double	prod_scal(t_coords *u, t_coords *v)
{
  return ((u->x * v->x) + (u->y * v->y) + (u->z * v->z));
}

void	get_vector(t_coords *vector,
	       t_coords *u,
	       t_coords *v)
{
  vector->x = v->x - u->x;
  vector->y = v->y - u->y;
  vector->z = v->z - u->z;
}

void	get_normal_to_triangle(t_coords *vector,
			   t_coords *u,
			   t_coords *v)
{
  vector->x = u->y * v->z - u->z * v->y;
  vector->y = u->z * v->x - u->x * v->z;
  vector->z = u->x * v->y - u->y * v->x;
}
