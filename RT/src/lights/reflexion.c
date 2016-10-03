#include "utils.h"
#include "maths.h"

void		set_ref_vect(t_coords *from,
		 t_intersect *p,
		 t_coords *r)

{
  double	scal;
  t_coords	*n;
  t_coords	v;

  n = get_normal(p);
  v.x = (p->pos->x - from->x);
  v.y = (p->pos->y - from->y);
  v.z = (p->pos->z - from->z);
  scal = get_scal(&v, n);
  r->x = -2.f * n->x * scal + v.x;
  r->y = -2.f * n->y * scal + v.y;
  r->z = -2.f * n->z * scal + v.z;
  w_free((void **)&n);
}

t_color		calc_reflex(t_rt *this, t_coords *from, t_intersect *p)
{
  t_color	new;
  t_coords	r;
  t_intersect	*inter;

  set_ref_vect(from, p, &r);
  inter = list_inters(this, p->pos, &r);
  new = gcalc_color(this, inter, p->pos, 0x0);
  free_intersect(inter);
  return (new);
}

t_color		calc_ref(t_rt *this,
		t_coords *from,
		t_intersect *p,
		t_color base)
{
  t_color	ref;
  t_color	nr;
  t_color	ng;
  t_color	nb;
  double	ratio;

  ratio = p->obj->reflexion;
  nr = 0;
  ng = 0;
  nb = 0;
  if (ratio != 1.f)
    {
      nr = (double)(RED(base)) * (1.f - ratio);
      ng = (double)(GRE(base)) * (1.f - ratio);
      nb = (double)(BLU(base)) * (1.f - ratio);
    }
  if (ratio * 10 > 0 && this->temps.rdepth / ratio < 64)
    {
      this->temps.rdepth++;
      ref = calc_reflex(this, from, p);
      nr += ((double)RED(ref) * ratio);
      ng += ((double)GRE(ref) * ratio);
      nb += ((double)BLU(ref) * ratio);
    }
  return (form_color(nr, ng, nb));
}
