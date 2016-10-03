#include <math.h>

#include "maths.h"

double	mod_txt_light(t_intersect *it, double ratio)
{
  t_uint	mid;
  double	res;

  if (it->obj->texture == 0 || ratio >= 1.0f || ratio <= 0.0f)
    return (ratio);
  if (it->obj->type != TYPE_PLAN)
    ratio = sqrt(ratio);
  mid = RED(it->color) + GRE(it->color) + BLU(it->color);
  mid /= 3;
  res = ratio / ratio / ratio * mid;
  res += ratio * ratio * ratio * (256 - mid);
  res /= 256;
  if (res <= 0.0)
    return (0.0);
  if (res >= 1.0)
    return (1.0);
  return (res);
}
