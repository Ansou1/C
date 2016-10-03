#include <stdlib.h>

#include "rt.h"
#include "utils.h"

static t_bool	is_in(char c)
{
  if (c == '-' || (c >= '0' && c <= '9') ||
      (c >= 'a' && c <= 'z') ||
      (c >= 'A' && c <= 'Z') ||
      c == '.' || c == '/')
    return (FALSE);
  return (TRUE);
}

static int	nb_part(const char *str)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (str[i])
    {
      if (i == 0)
	{
	  if (is_in(str[i]) == FALSE)
	    ++count;
	}
      else
	if (is_in(str[i - 1]) == TRUE && is_in(str[i]) == FALSE)
	  ++count;
      ++i;
    }
  return (count);
}

char		**str_to_wt(char *str)
{
  char		**res;
  int		size;
  int		i;
  int		k;

  k = 0;
  i = 0;
  if ((size = nb_part(str)) == 0)
    return ((void*)-1);
  if ((res = w_malloc((size + 1) * sizeof(*res))) == NULL)
    return (NULL);
  while (i < size)
    {
      while (is_in(str[k]) && str[k])
	++k;
      res[i] = str + k;
      while (is_in(str[k]) == FALSE && str[k])
	++k;
      str[k] = '\0';
      ++k;
      ++i;
    }
  res[i] = NULL;
  return (res);
}
