#include <stdlib.h>

#include "rt.h"
#include "utils.h"
#include "parsing.h"

static t_bool	get_point_tri(t_coords *p, t_uint id, t_point *point)
{
  while (point)
    {
      if (id == point->id)
	{
	  p->x = point->p.x;
	  p->y = point->p.y;
	  p->z = point->p.z;
	  return (TRUE);
	}
      point = point->next;
    }
  return (FALSE);
}

static t_bool	get_normal_tri(t_coords *n,
			    t_uint id,
			    t_normal *normal)
{
  while (normal)
    {
      if (id == normal->id)
	{
	  n->x = normal->n.x;
	  n->y = normal->n.y;
	  n->z = normal->n.z;
	  return (TRUE);
	}
      normal = normal->next;
    }
  return (FALSE);
}

static void	*ret_error(t_obj *this)
{
  print_error("Error loading '");
  print_error(this->name);
  print_error("'\nCorrupt file\n");
  if (this->name)
    free(this->name);
  return (NULL);
}

t_tri_list	*fill_triangle_in_list(t_obj *this)
{
  t_tri_list	*tmp;

  tmp = this->triangle;
  while (tmp)
    {
      if (!get_point_tri(&tmp->val->p1, tmp->val->id_p[0], this->point))
	return (ret_error(this));
      if (!get_point_tri(&tmp->val->p2, tmp->val->id_p[1], this->point))
	return (ret_error(this));
      if (!get_point_tri(&tmp->val->p3, tmp->val->id_p[2], this->point))
	return (ret_error(this));
      if (!get_normal_tri(&tmp->val->n, tmp->val->id_n, this->normal))
	return (ret_error(this));
      tmp = tmp->next;
    }
  if (this->name)
    free(this->name);
  return (this->triangle);
}
