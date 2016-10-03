#include <stdio.h>
#include "maths.h"

static double	tri_inter(t_triangle *cur,
		       t_coords *v,
		       t_coords *f)
{
  double	Ir;
  double	Iu;
  double	Iv;
  t_coords	vector_w;
  t_coords	vector_u;
  t_coords	vector_v;
  t_coords	vector_n;
  t_coords	tmp;

  get_vector(&vector_w, &cur->p1, f);
  get_vector(&vector_u, &cur->p1, &cur->p3);
  get_vector(&vector_v, &cur->p1, &cur->p2);
  get_normal_to_triangle(&vector_n, &vector_u, &vector_v);
  Ir = (-1) * prod_scal(&vector_n, &vector_w) / prod_scal(&vector_n, v);
  get_normal_to_triangle(&tmp, &vector_w, &vector_v);
  Iu = prod_scal(&tmp, v) / prod_scal(&vector_n, v);
  get_normal_to_triangle(&tmp, &vector_u, &vector_w);
  Iv = prod_scal(&tmp, v) / prod_scal(&vector_n, v);
  if (Iu + Iv <= 1 && Iu > 0 && Iv > 0)
    return (Ir);
  return (-1);
}

void	get_normal_init(t_coords *n,
		    t_coords p1,
		    t_coords p2,
		    t_coords p3)
{
  t_coords	a;
  t_coords	b;

  get_vector(&a, &p1, &p2);
  get_vector(&b, &p1, &p3);
  n->x = a.y * b.z - a.z * b.y;
  n->y = a.z * b.x - b.z * a.x;
  n->z = a.x * b.y - a.y * b.x;
}

void	init_normal(t_tri_list *triangles)
{
  while (triangles)
    {
      get_normal_init(&(triangles->val->n),
		      triangles->val->p1,
		      triangles->val->p2,
		      triangles->val->p3);
      triangles = triangles->next;
    }
}

double	model_inter(t_object_list *cur,
		  t_coords *v,
		  t_coords *f)
{
  t_object	*tmp;
  t_tri_list	*triangles;
  double	k;
  double	last;

  k = -1;
  last = -1;
  tmp = cur->obj;
  tmp->hitted = NULL;
  triangles = cur->obj->model;
  while (triangles != NULL)
    {
      k = tri_inter(triangles->val, v, f);
      if (k > 0 && (k < last || last == -1))
	{
	  if (k != last)
	    tmp->hitted = triangles;
	  last = k;
	}
      triangles = triangles->next;
    }
  return (last);
}
