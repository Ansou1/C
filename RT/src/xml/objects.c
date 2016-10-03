#include "utils.h"
#include "maths.h"

void		add_cube(t_rt *this, t_node *node)
{
  t_object	*tmp;

  tmp = create_obj(this, node);
  tmp->type = TYPE_CUBE;
  tmp->val1 = get_value(get_node(node, "size"));
}

void		add_plan(t_rt *this, t_node *node)
{
  t_object	*tmp;

  tmp = create_obj(this, node);
  tmp->type = TYPE_PLAN;
}

void		add_cone(t_rt *this, t_node *node)
{
  t_object	*tmp;

  tmp = create_obj(this, node);
  tmp->type = TYPE_CONE;
  tmp->val1 = get_value(get_node(node, "angle"));
  tmp->val1 = my_tan(tmp->val1) * my_tan(tmp->val1);
}

void		add_sphere(t_rt *this, t_node *node)
{
  t_object	*tmp;

  tmp = create_obj(this, node);
  tmp->type = TYPE_SPHERE;
  tmp->val1 = get_value(get_node(node, "radius"));
}

void		add_cylinder(t_rt *this, t_node *node)
{
  t_object	*tmp;

  tmp = create_obj(this, node);
  tmp->type = TYPE_CYLINDER;
  tmp->val1 = get_value(get_node(node, "radius"));
}
