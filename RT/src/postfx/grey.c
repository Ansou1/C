#include "maths.h"

t_color		postfx_grey(t_rt *this, t_color base, int x, int y)
{
  int		r;
  int		g;
  int		b;
  int		s;

  (void)this;
  (void)x;
  (void)y;
  r = RED(base);
  g = GRE(base);
  b = BLU(base);
  s = r + g + b;
  s /= 3;
  r = s;
  g = s;
  b = s;
  return (form_color(r, g, b));
}
