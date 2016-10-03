#include <stdlib.h>

#include "rt.h"
#include "parsing.h"

static void	destroy_point_normal(t_obj *this)
{
  t_point	*point;
  t_normal	*normal;

  while (this->point)
    {
      point = this->point->next;
      free(this->point);
      this->point = point;
    }
  while (this->normal)
    {
      normal = this->normal->next;
      free(this->normal);
      this->normal = normal;
    }
}

void	destroy_all(t_obj *this, t_tri_list *tri_list)
{
  t_tri_list	*triangle;

  if (this && this->name)
    free(this->name);
  if (this)
    destroy_point_normal(this);
  while (tri_list)
    {
      triangle = tri_list->next;
      free(tri_list->val);
      free(tri_list);
      tri_list = triangle;
    }
}
