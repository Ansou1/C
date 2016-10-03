#include"maths.h"

static double	keep_best(double old, double new)
{
  if (new > 0 && new < old)
    return (new);
  if (old <= 0)
    return (new);
  return (old);
}

static t_bool	is_in(t_object_list *cur,
		   t_coords *v,
		   t_coords *f,
		   double k)
{
  t_object	*cube;
  t_coords	tmp;
  double	size;

  cube = cur->obj;
  size = cube->val1;
  tmp.x = f->x + v->x * k;
  tmp.y = f->y + v->y * k;
  tmp.z = f->z + v->z * k;
  if (ABS(tmp.x) > size * 1.001)
    return (FALSE);
  if (ABS(tmp.y) > size * 1.001)
    return (FALSE);
  if (ABS(tmp.z) > size * 1.001)
    return (FALSE);
  return (TRUE);
}

static double	face_routine(t_object_list *cur,
			  t_coords *v,
			  t_coords *f,
			  double tmp)
{
  if (is_in(cur, v, f, -tmp) == TRUE)
    return (-tmp);
  return (-1);
}

double	cube_inter(t_object_list *cur,
		 t_coords *v,
		 t_coords *f)
{
  double	k;
  double	s;

  k = -1;
  s = cur->obj->val1;
  if (v->x != 0)
    k = keep_best(k, face_routine(cur, v, f, (f->x - s) / v->x));
  if (v->x != 0)
    k = keep_best(k, face_routine(cur, v, f, (f->x + s) / v->x));
  if (v->y != 0)
    k = keep_best(k, face_routine(cur, v, f, (f->y - s) / v->y));
  if (v->y != 0)
    k = keep_best(k, face_routine(cur, v, f, (f->y + s) / v->y));
  if (v->z != 0)
    k = keep_best(k, face_routine(cur, v, f, (f->z - s) / v->z));
  if (v->z != 0)
    k = keep_best(k, face_routine(cur, v, f, (f->z + s) / v->z));
  return (k);
}
