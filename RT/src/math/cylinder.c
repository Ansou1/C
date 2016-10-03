#include"maths.h"

double	cylinder_inter(t_object_list *cur,
		     t_coords *v,
		     t_coords *f)
{
  t_object	*tmp;
  double	a;
  double	b;
  double	c;
  double	k;

  tmp = cur->obj;
  a = v->x * v->x + v->y * v->y;
  b = 2 * (f->x * v->x + f->y * v->y);
  c = f->x * f->x + f->y * f->y - tmp->val1 * tmp->val1;
  k = simple_poly_resolve(a, b, c, v);
  return (k);
}
