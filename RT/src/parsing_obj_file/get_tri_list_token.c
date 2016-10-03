#include <stdlib.h>

#include "rt.h"
#include "utils.h"
#include "parsing.h"

static t_bool	is_normal(char *line, t_obj *this)
{
  if (corrupt_file(line, this))
    {
      print_error("One or more 'f' line of '");
      print_error(this->name);
      print_error("' contains no normal\n");
      return (FALSE);
    }
  return (TRUE);
}

static int	jump_slash(char **line)
{
  int	i;

  i = 0;
  while (line[0][i] && is_num(line[0][i]))
    ++i;
  while (line[0][i] && line[0][i] == '/')
    ++i;
  return (i);
}

t_bool	get_tri_list_token(t_obj *this, char **line, char *str)
{
  t_tri_list	*new;
  t_tri_list	*tmp;
  int	i;

  if (count_tabtab(line + 1) != 3 || !is_tab_number(line + 1, this))
    return (FALSE);
  if ((new = w_malloc(sizeof(*new))) == NULL)
    return (FALSE);
  if ((new->val = w_malloc(sizeof(*new->val))) == NULL)
    return (FALSE);
  new->line = line;
  new->str = str;
  ++line;
  new->val->id_p[0] = my_atoi(line[0]);
  new->val->id_p[1] = my_atoi(line[1]);
  new->val->id_p[2] = my_atoi(line[2]);
  i = jump_slash(line);
  if (!is_normal(line[0] + i, this))
    return (FALSE);
  new->val->id_n = my_atoi(line[0] + i);
  tmp = this->triangle;
  this->triangle = new;
  new->next = tmp;
  return (TRUE);
}
