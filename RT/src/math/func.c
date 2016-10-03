#include <math.h>

#include "maths.h"

#define DOFFSET		10
#define DATA_SIZE	(3600)

static int	my_pos(double value)
{
  int	pos;

  pos = (int)(value * DOFFSET) % DATA_SIZE;
  while (pos < 0)
    pos += DATA_SIZE;
  return (pos);
}

double	my_cos(double value)
{
  static int	loaded = 0;
  static double	values[DATA_SIZE];

  if (loaded == 0)
    loaded = try_load((double *)values, "data/pcv/cos.pcv", DATA_SIZE);
  if (loaded == 2)
    return (values[my_pos(value)]);
  return (cos(value * DEG_TO_RAD));
}

double	my_sin(double value)
{
  static int	loaded = 0;
  static double	values[DATA_SIZE];

  if (loaded == 0)
    loaded = try_load((double *)values, "data/pcv/sin.pcv", DATA_SIZE);
  if (loaded == 2)
    return (values[my_pos(value)]);
  return (sin(value * DEG_TO_RAD));
}

double	my_tan(double value)
{
  double	tmp;

  tmp = tan(value * DEG_TO_RAD);
  return (tmp);
}

void	my_rotate(t_coords *c, t_coords *r)
{
  t_coords	t;

  t.x = c->x;
  t.y = c->y;
  t.z = c->z;
  c->y = t.y * my_cos(r->x) - t.z * my_sin(r->x);
  c->z = t.y * my_sin(r->x) + t.z * my_cos(r->x);
  t.x = c->x;
  t.y = c->y;
  t.z = c->z;
  c->x = t.x * my_cos(r->y) + t.z * my_sin(r->y);
  c->z = -t.x * my_sin(r->y) + t.z * my_cos(r->y);
  t.x = c->x;
  t.y = c->y;
  t.z = c->z;
  c->x = my_cos(r->z) * t.x - my_sin(r->z) * t.y;
  c->y = my_sin(r->z) * t.x + my_cos(r->z) * t.y;
}
