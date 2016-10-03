#include <stdio.h>
#include <stdlib.h>

#include "maths.h"

double	resolve_quart(t_equation *eq)
{
  t_complex	z[4];
  size_t	i;
  double	k;

  quartique(eq, z);
  i = 0;
  k = -1;
  while (i < 4)
    {
      if (z[i].img == 0)
	{
	  if (z[i].re > 0.0 && (z[i].re < k || (k == -1)))
	    k = z[i].re;
	}
      ++i;
    }
  return (k);
}
