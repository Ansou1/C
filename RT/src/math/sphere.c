#include "maths.h"

double	sphere_inter(t_object_list *cur,
		   t_coords *v,
		   t_coords *f)
{
  t_object	*tmp;
  double	a;
  double	b;
  double	c;
  double	k;

  tmp = cur->obj;
  a = v->x * v->x + v->y * v->y + v->z * v->z;
  b = 2 * (f->x * v->x + f->y * v->y + f->z * v->z);
  c = f->x * f->x + f->y * f->y + f->z * f->z
    - tmp->val1 * tmp->val1;
  k = simple_poly_resolve(a, b, c, v);
  return (k);
}
