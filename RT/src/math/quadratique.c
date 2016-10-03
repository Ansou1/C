#include <math.h>

#include "maths.h"

double	quadratique(t_equation *eq,
		  t_complex *z0,
		  t_complex *z1)
{
  double	delta;

  delta = eq->b * eq->b - 4 * eq->a * eq->c;
  if (delta < 0.0)
    {
      z0->re = z1->re = - eq->b / (2.0 * eq->a);
      z0->img = -sqrt(-delta) / (2.0 * eq->a);
      z1->img = -z0->img;
    }
  else if (delta > 0.0)
    {
      z0->img = z1->img = 0.0;
      z0->re = (-eq->b - sqrt(delta)) / (2.0 * eq->a);
      z1->re = (-eq->b + sqrt(delta)) / (2.0 * eq->a);
    }
  else
    {
      z0->img = z1->img = 0.0;
      z0->re = z1->re = -eq->b / (2.0 * eq->a);
    }
  return (delta);
}
