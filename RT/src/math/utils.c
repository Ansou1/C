#include <math.h>

#include "utils.h"
#include "maths.h"

double	get_scal(t_coords *v1, t_coords *v2)
{
  double	scal;

  unitarise(v1);
  unitarise(v2);
  scal = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
  return (scal);
}

double	get_dist(t_coords *a, t_coords *b)
{
  double	dist;

  dist = (b->x - a->x) * (b->x - a->x);
  dist += (b->y - a->y) * (b->y - a->y);
  dist += (b->z - a->z) * (b->z - a->z);
  dist = sqrt(dist);
  return (dist);
}

void	unitarise(t_coords *v)
{
  double	norm;

  norm = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
  if (norm == 0)
    return ;
  v->x /= norm;
  v->y /= norm;
  v->z /= norm;
}

t_color	get_mid(t_rt *this, t_color *colors, int ratio)
{
  int	r;
  int	g;
  int	b;
  int	i;
  int	nb;

  (void)this;
  nb = ratio * ratio;
  i = 0;
  r = 0;
  g = 0;
  b = 0;
  while (i < nb)
    {
      r += RED(colors[i]);
      g += GRE(colors[i]);
      b += BLU(colors[i]);
      i++;
    }
  r /= nb;
  g /= nb;
  b /= nb;
  return (form_color(r, g, b));
}

double	simple_poly_resolve(double a, double b, double c, t_coords *v)
{
  double	delta;
  double	r1;
  double	r2;

  delta = b * b - 4 * a * c;
  if (delta < 0)
    return (-1);
  if (a == 0)
    return (-1);
  r1 = (-b + sqrt(delta)) / (2 * a);
  r2 = (-b - sqrt(delta)) / (2 * a);
  if (is_positive(r2, v) != TRUE)
    return (r1);
  return (r2);
}
