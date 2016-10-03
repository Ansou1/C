#include <stdlib.h>

#include "rt.h"

t_uint	count_tabtab(char **tab)
{
  t_uint	i;

  i = 0;
  while (tab[i])
    ++i;
  return (i);
}
