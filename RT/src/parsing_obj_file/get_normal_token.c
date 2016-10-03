#include <stdlib.h>

#include "rt.h"
#include "utils.h"
#include "parsing.h"

t_bool	get_normal_token(t_obj *this, char **line, char *str)
{
  t_normal	*new;
  t_normal	*tmp;

  if (count_tabtab(line + 1) != 3 || !is_tab_number(line + 1, this))
    return (FALSE);
  if ((new = w_malloc(sizeof(*new))) == NULL)
    return (FALSE);
  new->line = line;
  new->str = str;
  ++line;
  ++this->id_n;
  new->id = this->id_n;
  new->n.x = my_get_double(line[0]);
  new->n.y = my_get_double(line[1]);
  new->n.z = my_get_double(line[2]);
  tmp = this->normal;
  this->normal = new;
  new->next = tmp;
  return (TRUE);
}
