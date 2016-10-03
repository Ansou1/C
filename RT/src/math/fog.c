#include <math.h>

#include "maths.h"

t_color	calc_fog(t_rt *this, t_intersect *inter, t_color base)
{
  double	ratio;

  if (this->cam->fog_depth <= 0)
    return (base);
  if (this->cam->fog_style == 1)
    ratio = inter->dist / this->cam->fog_depth;
  else
    ratio = (inter->dist - this->cam->fog_depth / 2)
      / this->cam->fog_depth * 2;
  if (ratio > 1.0)
    ratio = 1.0;
  if (ratio < 0.0)
    ratio = 0.0;
  base = ratioed_color(this->cam->fog_color, base, ratio);
  return (base);
}
