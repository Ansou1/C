#include <math.h>

#include "maths.h"

double		calc_light_dist(t_rt *this,
		      t_light_list *light,
		      t_coords *eye,
		      t_coords *v)
{
  t_intersect	*tmp;
  t_coords	p;
  t_coords	t;
  double	d;
  double	a;
  double	b;
  double	k;

  a = POW2(v->x) + POW2(v->y) + POW2(v->z);
  if (a <= 0)
    return (V_FAR);
  my_translate(&p, light->pos, eye);
  b = 2 * (v->x * p.x + v->y * p.y + v->z * p.z);
  k = -b / 2 / a;
  p.x = eye->x + v->x * k;
  p.y = eye->y + v->y * k;
  p.z = eye->z + v->z * k;
  my_translate(&t, light->pos, eye);
  tmp = list_inters(this, light->pos, &t);
  k = V_FAR;
  d = get_dist(eye, light->pos);
  if (tmp->obj == 0 || get_dist(light->pos, tmp->pos) * 1.05 > d)
    k = get_dist(&p, light->pos);
  free_intersect(tmp);
  return (k * k * k);
}

static double	calc_phong_value(double direct,
			      double indirect,
			      double lsize,
			      double bright)
{
  double	retain;

  direct = direct / 2;
  retain = MIN(direct, indirect);
  if (indirect < 0.0)
    retain = direct;
  if (direct < 0.0)
    retain = indirect;
  retain = lsize * 50.0 / retain;
  if (retain > 0.8)
    retain = 0.8;
  if (indirect >= 0.0 && indirect < direct)
    retain *= sqrt(sqrt(bright));
  return (retain);
}

t_color		calc_phong(t_rt *this,
		  t_intersect *it,
		  t_coords *from,
		  t_color phonged)
{
  t_light_list	*curr;
  t_coords	reflect;
  double	tmp;
  double	bright;

  curr = this->lights;
  while (curr != 0)
    {
      bright = 0.5;
      if (curr->type != LIGHT_AMB && curr->psize > 1)
	{
	  tmp = -1.0f;
	  if (it->obj != 0)
	    {
	      bright = it->obj->bright;
	      set_ref_vect(from, it, &reflect);
	      tmp = calc_light_dist(this, curr, it->pos, &reflect);
	    }
	  tmp = calc_phong_value(calc_light_dist(this, curr, from, &(it->v)),
				 tmp, curr->psize, bright);
	  phonged = ratioed_color(curr->color, phonged, tmp);
	}
      curr = curr->next;
    }
  return (phonged);
}
