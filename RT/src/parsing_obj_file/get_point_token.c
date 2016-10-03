#include <stdlib.h>

#include "rt.h"
#include "utils.h"
#include "parsing.h"

t_bool	get_point_token(t_obj *this, char **line, char *str)
{
  t_point	*new;
  t_point	*tmp;

  if (count_tabtab(line + 1) != 3 || !is_tab_number(line + 1, this))
    return (FALSE);
  if ((new = w_malloc(sizeof(*new))) == NULL)
    return (FALSE);
  new->line = line;
  new->str = str;
  ++line;
  ++this->id_p;
  new->id = this->id_p;
  new->p.x = my_get_double(line[0]);
  new->p.y = my_get_double(line[1]);
  new->p.z = my_get_double(line[2]);
  tmp = this->point;
  this->point = new;
  new->next = tmp;
  return (TRUE);
}
