#include "maths.h"

t_color		postfx_crazy(t_rt *this, t_color base, int x, int y)
{
  int		r;
  int		g;
  int		b;

  if (this->pfx_val == 0)
    this->pfx_val = 3;
  (void)x;
  (void)y;
  r = RED(base);
  g = GRE(base);
  b = BLU(base);
  r = r * 2 + (r * (int)this->pfx_val % 77 * 77) % 256;
  r /= 3;
  g = g * 2 + (g * (int)this->pfx_val % 41 * 41) % 256;
  g /= 3;
  b = b * 2 + (b * (int)this->pfx_val % 131 * 131) % 256;
  b /= 3;
  return (form_color(r, g, b));
}
