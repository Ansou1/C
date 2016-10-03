#include "maths.h"

t_color	postfx_postr(t_rt *this, t_color base, int x, int y)
{
  int	r;
  int	g;
  int	b;
  int	lvl;

  (void)x;
  (void)y;
  if (this->pfx_val > 200 || this->pfx_val < 1)
    this->pfx_val = 32;
  lvl = (int)this->pfx_val;
  r = RED(base);
  r = r / lvl * lvl;
  g = GRE(base);
  g = g / lvl * lvl;
  b = BLU(base);
  b = b / lvl * lvl;
  return (form_color(r, g, b));
}
