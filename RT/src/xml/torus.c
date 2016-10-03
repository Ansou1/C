#include	"obj.h"

void		add_torus(t_rt *this, t_node *node)
{
  t_object	*tmp;

  tmp = create_obj(this, node);
  tmp->type = TYPE_TORUS;
  tmp->val1 = get_value(get_node(node, "radius"));
  tmp->val2 = get_value(get_node(node, "width"));
}
