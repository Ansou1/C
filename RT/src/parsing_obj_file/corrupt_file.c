#include "rt.h"
#include "parsing.h"
#include "utils.h"

t_bool	corrupt_file(char *str, t_obj *this)
{
  if (str == NULL || str[0] == '\0')
    {
      print_error("Error loading '");
      print_error(this->name);
      print_error("'\n");
      return (TRUE);
    }
  if (is_num(str[0]) || (str[0] == '-' && is_num(str[1])))
    return (FALSE);
  print_error("Error loading '");
  print_error(this->name);
  print_error("'\n");
  return (TRUE);
}

t_bool	is_tab_number(char **line, t_obj *this)
{
  if (corrupt_file(line[0], this))
    return (FALSE);
  if (corrupt_file(line[1], this))
    return (FALSE);
  if (corrupt_file(line[2], this))
    return (FALSE);
  return (TRUE);
}
