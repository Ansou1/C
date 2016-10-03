#include "utils.h"
#include "maths.h"

t_img		*get_image(t_node *node)
{
  int		x;
  int		y;
  int		**val;
  char		*path;
  t_img		*new;

  if (node == 0)
    return (0);
  node = node->fils;
  if (get_node(node, "path") == 0)
    return (0);
  x = ABS(get_value(get_node(node, "xsize")));
  y = ABS(get_value(get_node(node, "ysize")));
  path = get_node(node, "path")->value;
  val = load_image(path, x, y);
  if (val == 0)
    return (0);
  new = w_malloc(sizeof(t_img));
  new->xsize = x;
  new->ysize = y;
  new->rep = ABS(get_value(get_node(node, "rep")));
  new->amp = ABS(get_value(get_node(node, "amp")));
  new->val = val;
  return (new);
}

static t_object	*more_options(t_rt *this, t_node *node, t_object *new)
{
  new->color_mod = get_value(get_node(node, "color_mod"));
  new->norml_mod = get_value(get_node(node, "normal_mod"));
  generate_modifiers(this, new);
  return (new);
}

t_object	*create_obj(t_rt *this, t_node *node)
{
  t_object_list	*tmp;
  t_object	*new;

  tmp = this->objs;
  this->objs = w_malloc(sizeof(t_object_list));
  this->objs->next = tmp;
  this->objs->obj = w_malloc(sizeof(t_object));
  new = this->objs->obj;
  new->model = 0;
  new->l_pos = get_coords(node, "limit_pos");
  new->l_rot = get_coords(node, "limit_rotation");
  new->l_type = get_value(get_node(node, "limit_type"));
  new->l_value = get_value(get_node(node, "limit_value"));
  new->pos = get_coords(node, "pos");
  new->r = get_coords(node, "rotation");
  new->color = get_color_val(get_node(node, "color"));
  new->tr = get_value(get_node(node, "transparency"));
  new->ind = get_value(get_node(node, "r-indice"));
  if (new->ind <= 0)
    new->ind = 1.0;
  new->bright = get_value(get_node(node, "bright"));
  new->reflexion = get_value(get_node(node, "reflexion"));
  new->texture = get_image(get_node(node, "texture"));
  new->bumpmap = get_image(get_node(node, "bumpmap"));
  return (more_options(this, node, new));
}
