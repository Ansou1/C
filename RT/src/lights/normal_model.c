#include "utils.h"
#include "maths.h"

t_coords	*model_normal(t_light_list *light, t_intersect *p)
{
  t_coords	*n;

  (void)light;
  n = w_malloc(sizeof(t_coords));
  if (p->cur_tri == 0 || p->cur_tri->val == 0)
    return (n);
  n->x = p->cur_tri->val->n.x;
  n->y = p->cur_tri->val->n.y;
  n->z = p->cur_tri->val->n.z;
  if (get_scal(n, &(p->v)) < 0)
    {
      n->x *= -1;
      n->y *= -1;
      n->z *= -1;
    }
  my_inv_rotate(n, p->obj->r);
  n->x += p->pos->x;
  n->y += p->pos->y;
  n->z += p->pos->z;
  return (n);
}
