#include "maths.h"

double plan_inter(t_object_list *cur,
		 t_coords *v,
		 t_coords *f)
{
  double k;

  (void)cur;
  k = -1;
  if (v->z != 0)
    k = -f->z / v->z;
  else if (f->z == 0)
    k = 1;
  return (k);
}
