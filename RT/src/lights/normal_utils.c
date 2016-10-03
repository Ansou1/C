#include "utils.h"
#include "maths.h"

t_coords	*plan_normal(t_light_list *light, t_intersect *p)
{
  t_object	*tmp;
  t_coords	*new;

  (void)light;
  new = w_malloc(sizeof(t_coords));
  tmp = p->obj;
  my_translate(new, p->pos, tmp->pos);
  my_rotate(new, tmp->r);
  new->z += 100;
  my_inv_rotate(new, tmp->r);
  my_translate(new, new, tmp->pos);
  return (new);
}

t_coords	*cone_normal(t_light_list *light, t_intersect *p)
{
  t_object	*tmp;
  t_coords	*new;

  (void)light;
  new = w_malloc(sizeof(t_coords));
  tmp = p->obj;
  my_translate(new, p->pos, tmp->pos);
  my_rotate(new, tmp->r);
  new->x = 0;
  new->y = 0;
  new->z += tmp->val1 * new->z;
  my_inv_rotate(new, tmp->r);
  my_translate(new, new, tmp->pos);
  return (new);
}

t_coords	*sphere_normal(t_light_list *light, t_intersect *p)
{
  t_object	*tmp;
  t_coords	*new;

  (void)light;
  new = w_malloc(sizeof(t_coords));
  tmp = p->obj;
  new->x = tmp->pos->x;
  new->y = tmp->pos->y;
  new->z = tmp->pos->z;
  return (new);
}

t_coords	*cylinder_normal(t_light_list *light, t_intersect *p)
{
  t_object	*tmp;
  t_coords	*new;

  (void)light;
  new = w_malloc(sizeof(t_coords));
  tmp = p->obj;
  my_translate(new, p->pos, tmp->pos);
  my_rotate(new, tmp->r);
  new->x = 0;
  new->y = 0;
  my_inv_rotate(new, tmp->r);
  my_translate(new, new, tmp->pos);
  return (new);
}

t_coords	*cube_normal(t_light_list *light, t_intersect *p)
{
  t_object	*tmp;
  t_coords	*new;

  (void)light;
  new = w_malloc(sizeof(t_coords));
  tmp = p->obj;
  my_translate(new, p->pos, tmp->pos);
  my_rotate(new, tmp->r);
  if (ABS(new->x) > tmp->val1 * 0.998)
    new->x = 0;
  else if (ABS(new->y) > tmp->val1 * 0.998)
    new->y = 0;
  else if (ABS(new->z) > tmp->val1 * 0.998)
    new->z = 0;
  else
    {
      new->x = 0;
      new->y = 0;
      new->z = 0;
    }
  my_inv_rotate(new, tmp->r);
  my_translate(new, new, tmp->pos);
  return (new);
}
