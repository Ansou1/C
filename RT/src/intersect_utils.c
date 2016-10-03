#include<stdlib.h>

#include "utils.h"
#include "maths.h"

static	double(*g_inters[])(t_object_list *, t_coords *, t_coords *) =
{
  &sphere_inter,
  &cone_inter,
  &plan_inter,
  &cylinder_inter,
  &cube_inter,
  &model_inter,
  &torus_inter
};

double	handle_matrix(t_object_list *curr,
		    t_coords *v,
		    t_coords *f,
		    t_uint type)
{
  t_coords	tmpf;
  t_coords	tmpv;

  my_translate(&tmpf, curr->obj->pos, f);
  if (type != TYPE_SPHERE)
    get_new_rep(&tmpf, &tmpv, v, curr->obj->r);
  else
    return (g_inters[type](curr, v, &tmpf));
  return (g_inters[type](curr, &tmpv, &tmpf));
}

t_intersect	*free_intersect(t_intersect *it)
{
  if (it == NULL)
    return (NULL);
  (void)free(it->pos);
  (void)free(it);
  return (NULL);
}

t_intersect	*init_inter(t_coords *v)
{
  t_intersect	*tmp;

  tmp = w_malloc(sizeof(t_intersect));
  tmp->dist = V_FAR;
  tmp->obj = NULL;
  tmp->pos = w_malloc(sizeof(t_coords));
  tmp->v.x = v->x;
  tmp->v.y = v->y;
  tmp->v.z = v->z;
  return (tmp);
}

static double	handle_limits(t_object_list *curr,
			   t_coords *v,
			   t_coords *f,
			   t_uint type)
{
  t_coords	npos;
  double	k;
  double	res;

  k = handle_matrix(curr, v, f, type);
  res = 42;
  while (res >= 1.0 && is_limited(curr, f, v, k) == TRUE)
    {
      npos.x = f->x + v->x * (k + 1.0);
      npos.y = f->y + v->y * (k + 1.0);
      npos.z = f->z + v->z * (k + 1.0);
      res = handle_matrix(curr, v, &npos, type);
      if (res >= 1.0)
	k += res;
    }
  if (res < 1.0)
    return (-1);
  return (k);
}

t_intersect	*list_inters(t_rt *this, t_coords *s, t_coords *v)
{
  t_object_list	*curr;
  t_intersect	*tmp;
  double	k;

  tmp = init_inter(v);
  curr = this->objs;
  unitarise(v);
  while (curr != 0)
    {
      k = handle_limits(curr, v, s, curr->obj->type % TYPE_NUM);
      if (is_positive(k, v) == TRUE
	  && k < tmp->dist)
	{
	  tmp->dist = k;
	  tmp->pos->x = s->x + v->x * k;
	  tmp->pos->y = s->y + v->y * k;
	  tmp->pos->z = s->z + v->z * k;
	  tmp->obj = curr->obj;
	  tmp->cur_tri = curr->obj->hitted;
	  tmp->color = get_txt_color(tmp->obj, tmp->pos, 1);
	}
      curr = curr->next;
    }
  return (tmp);
}
