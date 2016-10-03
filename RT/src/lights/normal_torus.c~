#include "utils.h"
#include "maths.h"

t_coords	*torus_normal(t_light_list *light, t_intersect *p)
{
  t_coords	*n;
  t_coords	rep;
  double	coor;
  double	tmp;
  double	extra;

  (void)light;
  my_translate(&rep, p->pos, p->obj->pos);
  my_rotate(&rep, p->obj->r);
  n = w_malloc(sizeof(t_coords));
  coor = rep.x * rep.x + rep.y * rep.y + rep.z * rep.z;
  tmp = p->obj->val1 * p->obj->val1 - p->obj->val2 * p->obj->val2;
  extra = p->obj->val1 * p->obj->val1 * 8;
  n->x = (coor + tmp) * 4 * rep.x - extra * rep.x;
  n->y = (coor + tmp) * 4 * rep.y - extra * rep.y;
  n->z = (coor + tmp) * 4 * rep.z;
  my_inv_rotate(n, p->obj->r);
  n->x += p->pos->x;
  n->y += p->pos->y;
  n->z += p->pos->z;
  return (n);
}
