#include "utils.h"
#include "maths.h"

static t_coords *(*g_normal[])(t_light_list *, t_intersect *) =
{
  &sphere_normal,
  &cone_normal,
  &plan_normal,
  &cylinder_normal,
  &cube_normal,
  &model_normal,
  &torus_normal
};

static void	perturb_normal(t_coords *pos, t_intersect *it)
{
  t_color	bump;
  t_coords	deform;
  double	amp;

  if (it->obj->bumpmap == 0)
    return ;
  bump = get_txt_color(it->obj, it->pos, 0);
  amp = it->obj->bumpmap->amp / 30.0;
  deform.x = (RED(bump) - 128) * amp;
  deform.y = (GRE(bump) - 128) * amp;
  deform.z = deform.x + deform.y / 2;
  my_rotate(pos, &deform);
}

t_coords	*get_normal(t_intersect *it)
{
  t_coords	*ret;

  ret = g_normal[it->obj->type % TYPE_NUM](0, it);
  perturb_normal(ret, it);
  ret->x -= it->pos->x;
  ret->y -= it->pos->y;
  ret->z -= it->pos->z;
  return (ret);
}

double		get_normal_ratio(t_light_list *light, t_intersect *p)
{
  double	scal;
  t_coords	*n;

  n = g_normal[p->obj->type % TYPE_NUM](light, p);
  perturb_normal(n, p);
  scal = ((p->pos->x - n->x) * (light->pos->x - p->pos->x))
    + ((p->pos->y - n->y) * (light->pos->y - p->pos->y))
    + ((p->pos->z - n->z) * (light->pos->z - p->pos->z));
  scal /= get_dist(p->pos, n);
  scal /= get_dist(p->pos, light->pos);
  if (scal < 0)
    scal = 0;
  if (scal > 1)
    return (1);
  w_free((void **)&n);
  return (scal);
}
