#include "maths.h"

t_color		postfx_neg(t_rt *this, t_color base, int x, int y)
{
  int		r;
  int		g;
  int		b;

  (void)this;
  (void)x;
  (void)y;
  r = RED(base);
  g = GRE(base);
  b = BLU(base);
  r = 255 - r;
  g = 255 - g;
  b = 255 - b;
  return (form_color(r, g, b));
}
