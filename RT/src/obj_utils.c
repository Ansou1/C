#include "utils.h"
#include "maths.h"

#define PADDING	2.0f

t_bool	is_same_coord(t_coords *a, t_coords *b)
{
  if (a->x + PADDING < b->x || a->x - PADDING > b->x)
    return (FALSE);
  if (a->y + PADDING < b->y || a->y - PADDING > b->y)
    return (FALSE);
  if (a->z + PADDING < b->z || a->z - PADDING > b->z)
    return (FALSE);
  return (TRUE);
}

t_bool	is_positive(double k, t_coords *v)
{
  if (k <= 0)
    return (FALSE);
  if (ABS(v->x * k) > PADDING)
    return (TRUE);
  if (ABS(v->y * k) > PADDING)
    return (TRUE);
  if (ABS(v->z * k) > PADDING)
    return (TRUE);
  return (FALSE);
}
