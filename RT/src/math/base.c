#include "rt.h"

double	set_bounds(double val, double min, double max)
{
  if (val < min)
    return (min);
  if (val > max)
    return (max);
  return (val);
}

void	copy_coords(t_coords *dest, t_coords *src)
{
  dest->x = src->x;
  dest->y = src->y;
  dest->z = src->z;
}
