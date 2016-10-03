#include <math.h>

#include "utils.h"
#include "maths.h"

static t_coords	*inv_vect(t_coords *v)
{
  v->x *= -1;
  v->y *= -1;
  v->z *= -1;
  return (v);
}

static int	calc_vector(t_coords *v, t_coords *normal, double n)
{
  t_coords	t;
  double	scal;
  double	val2;

  n = 1.0 / n;
  unitarise(v);
  unitarise(normal);
  scal = get_scal(v, normal);
  val2 = 1.0 + n * n * (scal * scal - 1.0);
  if (val2 < 0.0f)
    return (-1);
  val2 = sqrt(val2);
  val2 = n * scal - val2;
  t.x = n * v->x + val2 * normal->x;
  t.y = n * v->y + val2 * normal->y;
  t.z = n * v->z + val2 * normal->z;
  v->x = t.x;
  v->y = t.y;
  v->z = t.z;
  return (0);
}

static t_color	calc_tr(t_rt *this, t_coords *from, t_intersect *p)
{
  t_color	new;
  t_coords	v;
  t_coords	*n;
  t_intersect	*inter;
  int		isnan;

  n = get_normal(p);
  v.x = (p->pos->x - from->x);
  v.y = (p->pos->y - from->y);
  v.z = (p->pos->z - from->z);
  if (this->temps.last_tr != p->obj)
    isnan = calc_vector(&v, n, p->obj->ind);
  else if (p->obj->ind != 0)
    isnan = calc_vector(&v, inv_vect(n), 1.0 / p->obj->ind);
  w_free((void **)&n);
  if (this->temps.last_tr == p->obj)
    this->temps.last_tr = 0;
  else
    this->temps.last_tr = p->obj;
  if (isnan == -1)
    return (calc_reflex(this, from, p));
  inter = list_inters(this, p->pos, &v);
  new = gcalc_color(this, inter, p->pos, 0x0);
  free_intersect(inter);
  return (new);
}

t_color		calc_transparency(t_rt *this,
			 t_coords *from,
			 t_intersect *p,
			 t_color base)
{
  t_color	tr;
  t_color	nr;
  t_color	ng;
  t_color	nb;
  double	ratio;

  ratio = p->obj->tr;
  nr = 0;
  ng = 0;
  nb = 0;
  if (ratio != 1.f)
    {
      nr = (double)(RED(base)) * (1.f - ratio);
      ng = (double)(GRE(base)) * (1.f - ratio);
      nb = (double)(BLU(base)) * (1.f - ratio);
    }
  if (ratio * 10 > 0 && this->temps.tdepth / ratio < 64)
    {
      this->temps.tdepth++;
      tr = calc_tr(this, from, p);
      nr += ((double)RED(tr) * ratio);
      ng += ((double)GRE(tr) * ratio);
      nb += ((double)BLU(tr) * ratio);
    }
  return (form_color(nr, ng, nb));
}
