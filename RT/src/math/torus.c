#include <math.h>
#include "complex.h"
#include "maths.h"

static double	get_d_torus(t_coords *v, t_coords *f, double r1, double r2)
{
  double	d;

  d = (2 * (2 * v->x * f->x + 2 * v->y * f->y + 2 * v->z * f->z)
       * (pow(f->x, 2) + pow(f->y, 2) + pow(f->z, 2) + pow(r1, 2) - pow(r2, 2))
       - 8 * pow(r1, 2) * (v->x * f->x + v->y * f->y));
  return (d);
}

static double	get_e_torus(t_coords *v, t_coords *f, double r1, double r2)
{
  double	e;

  (void)v;
  e = (pow(f->x , 2) * (pow(f->x, 2) + 2 * pow(f->y, 2) + 2 * pow(f->z, 2)
			- 2 * pow(r1, 2) - 2 * pow(r2, 2)) + pow(f->y, 2)
       * (pow(f->y, 2) + 2 * pow(f->z, 2) - 2 * pow(r1, 2) - 2 * pow(r2, 2))
       + pow(f->z, 2) * (pow(f->z, 2) + 2 * pow(r1, 2) - 2 * pow(r2, 2))
       + pow(r1, 4) - 2 * pow(r1, 2) * pow(r2, 2) + pow(r2, 4));
  return (e);
}

double	torus_inter(t_object_list *cur,
		  t_coords *v,
		  t_coords *f)
{
  t_equation	eq;
  double	r1;
  double	r2;
  double	k;

  r1 = cur->obj->val1;
  r2 = cur->obj->val2;
  eq.a = pow(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2), 2);
  eq.b =  (2 * (pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2))
	   * (2 * v->x * f->x + 2 * v->y * f->y + 2 * v->z * f->z));
  eq.c = (2 * (pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2))
	  * (pow(f->x, 2) + pow(f->y, 2) + pow(f->z, 2)
	     + pow(r1, 2) - pow(r2, 2))
	  + pow(2 * v->x * f->x + 2 * v->y * f->y + 2 * v->z * f->z, 2)
	  - 4 * pow(r1, 2) * (pow(v->x, 2) + pow(v->y, 2)));
  eq.d = get_d_torus(v, f, r1, r2);
  eq.e = get_e_torus(v, f, r1, r2);
  k = resolve_quart(&eq);
  return (k);
}
