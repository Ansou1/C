#include "utils.h"
#include "maths.h"

static void	scale_model(t_object *mod)
{
  t_tri_list	*tmp;
  t_triangle	*t;
  double	s;

  s = mod->val1;
  tmp = mod->model;
  while (tmp && tmp->val)
    {
      t = tmp->val;
      t->p1.x *= s;
      t->p1.y *= s;
      t->p1.z *= s;
      t->p2.x *= s;
      t->p2.y *= s;
      t->p2.z *= s;
      t->p3.x *= s;
      t->p3.y *= s;
      t->p3.z *= s;
      tmp = tmp->next;
    }
}

void		add_model(t_rt *this, t_node *node)
{
  char		*path;
  t_node	*path_node;
  t_object	*tmp;

  tmp = create_obj(this, node);
  tmp->type = TYPE_MODEL;
  tmp->val1 = get_value(get_node(node, "scale"));
  path_node = get_node(node, "file");
  if (path_node != 0)
    path = path_node->value;
  if (path != 0)
    tmp->model = parsing_object(path);
  else
    tmp->model = 0;
  tmp->hitted = 0;
  scale_model(tmp);
}
