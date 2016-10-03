#include "maths.h"

t_color	postfx_blurr(t_rt *this, t_color base, int x, int y)
{
  static t_color	prec[BLURR_MAX];
  int			r;
  int			g;
  int			b;
  int			i;

  (void)x;
  (void)y;
  if (this->pfx_val >= BLURR_MAX || this->pfx_val < 1)
    this->pfx_val = 10;
  i = this->pfx_val;
  while (--i > 0)
    prec[i] = prec[i - 1];
  prec[0] = base;
  i = 0;
  r = 0;
  g = 0;
  b = 0;
  while (i < this->pfx_val && y - i >= 0)
    {
      r += RED(prec[i]);
      g += GRE(prec[i]);
      b += BLU(prec[i++]);
    }
  return (form_color(r / i, g / i, b / i));
}
