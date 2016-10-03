#include<stdlib.h>
#include<math.h>

#include "utils.h"
#include "maths.h"

static t_intersect	*list_light_inters(t_rt *this,
				     t_coords *light,
				     t_coords *p)
{
  t_coords	v;

  v.x = p->x - light->x;
  v.y = p->y - light->y;
  v.z = p->z - light->z;
  return (list_inters(this, light, &v));
}

static t_color	color_ratio(t_color curr,
			  t_color base,
			  t_light_list *add,
			  t_intersect *p)
{
  double	r;
  double	g;
  double	b;
  double	d;
  double	br;
  double	ratio;

  br = p->obj->bright;
  if (add->type == LIGHT_NOR)
    d = get_dist(add->pos, p->pos);
  else
    d = 100;
  ratio = 1;
  if (d > 1)
    ratio = add->watt / d;
  if (add->type != LIGHT_AMB)
    ratio *= get_normal_ratio(add, p);
  r = RED(curr) + (double)((RED(base)) * (1.f - br) * ratio);
  r += (double)(RED(add->color) * ratio * br);
  g = GRE(curr) + (double)((GRE(base)) * (1.f - br) * ratio);
  g += (double)(GRE(add->color) * ratio * br);
  b = BLU(curr) + (double)((BLU(base)) * (1.f - br) * ratio);
  b += (double)(BLU(add->color) * ratio * br);
  return (form_color((int)r, (int)g, (int)b));
}

double	list_transparency(t_rt *this,
			t_light_list *curr,
			t_coords *it,
			double tratio)
{
  t_intersect	*inter;
  t_intersect	*prec;

  prec = NULL;
  inter = list_light_inters(this, curr->pos, it);
  while (inter != NULL && is_same_coord(inter->pos, it)
	 != TRUE && tratio > 0 && inter->obj != NULL)
    {
      tratio *= mod_txt_light(inter, inter->obj->tr);
      curr->color = adapt_light_color(curr->color, inter->color, tratio);
      prec = inter;
      inter = list_light_inters(this, inter->pos, it);
      if (is_same_coord(inter->pos, prec->pos) == TRUE
	  && inter->obj == prec->obj)
	tratio = 0.0f;
      prec = free_intersect(prec);
    }
  free_intersect(prec);
  free_intersect(inter);
  return (tratio);
}

t_color	ratioed_color(t_color c1, t_color c2, double ratio)
{
  int	r;
  int	g;
  int	b;
  int	rt;

  if (ratio >= 1)
    return (c1);
  if (ratio <= 0)
    return (c2);
  rt = (int)((double)256 * ratio);
  r = RED(c1) * rt + RED(c2) * (256 - rt);
  r /= 256;
  g = GRE(c1) * rt + GRE(c2) * (256 - rt);
  g /= 256;
  b = BLU(c1) * rt + BLU(c2) * (256 - rt);
  b /= 256;
  return (form_color(r, g, b));
}

t_color		calc_light(t_rt *this, t_intersect *it)
{
  t_color	lighted_color;
  t_color	base_color;
  t_color	tmp_color;
  t_color	spot_color;
  t_light_list	*curr;
  double	tratio;

  lighted_color = 0x0;
  base_color = it->color;
  curr = this->lights;
  while (curr != 0)
    {
      tratio = 1.0f;
      spot_color = curr->color;
      if (curr->type != LIGHT_AMB)
	tratio = soft_listing(this, curr, it->pos);
      if (tratio != 0)
	{
	  tmp_color = color_ratio(lighted_color, base_color, curr, it);
	  lighted_color = ratioed_color(tmp_color, lighted_color, tratio);
	}
      curr->color = spot_color;
      curr = curr->next;
    }
  return (lighted_color);
}
