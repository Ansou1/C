#include "maths.h"

void	my_translate(t_coords *npos,
		 t_coords *objpos,
		 t_coords *campos)
{
  npos->x = campos->x - objpos->x;
  npos->y = campos->y - objpos->y;
  npos->z = campos->z - objpos->z;
}

void	get_new_rep(t_coords *nf,
		t_coords *nv,
		t_coords *v,
		t_coords *r)
{
  nv->x = v->x;
  nv->y = v->y;
  nv->z = v->z;
  my_rotate(nv, r);
  my_rotate(nf, r);
}

void	my_inv_rotate(t_coords *c, t_coords *r)
{
  t_coords	t;

  t.x = c->x;
  t.y = c->y;
  t.z = c->z;
  c->x = my_cos(-r->z) * t.x - my_sin(-r->z) * t.y;
  c->y = my_sin(-r->z) * t.x + my_cos(-r->z) * t.y;
  t.x = c->x;
  t.y = c->y;
  t.z = c->z;
  c->x = t.x * my_cos(-r->y) + t.z * my_sin(-r->y);
  c->z = -t.x * my_sin(-r->y) + t.z * my_cos(-r->y);
  t.x = c->x;
  t.y = c->y;
  t.z = c->z;
  c->y = t.y * my_cos(-r->x) - t.z * my_sin(-r->x);
  c->z = t.y * my_sin(-r->x) + t.z * my_cos(-r->x);
}
