#include "maths.h"

t_color		postfx_hcont(t_rt *this, t_color base, int x, int y)
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
  r += (r - 127) * 2;
  g += (g - 127) * 2;
  b += (b - 127) * 2;
  return (form_color(r, g, b));
}
