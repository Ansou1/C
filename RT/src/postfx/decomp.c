#include "utils.h"
#include "maths.h"

t_color		postfx_decomp(t_rt *this, t_color base, int x, int y)
{
  static int	*img = NULL;
  int		r;
  int		g;
  int		b;
  int		decal;

  (void)this;
  if (img == NULL)
    img = w_malloc(sizeof(int) * WIN_HEIGHT * WIN_WIDTH);
  if (this->pfx_val > 200 || this->pfx_val < 1)
    this->pfx_val = 10;
  decal = (int)this->pfx_val;
  img[x * WIN_HEIGHT + y] = base;
  r = RED(img[y]);
  if (x - decal >= 0)
    r = RED(img[(x - decal) * WIN_HEIGHT + y]);
  g = GRE(img[x * WIN_HEIGHT]);
  if (y - decal >= 0)
    g = GRE(img[x * WIN_HEIGHT + y - decal]);
  b = BLU(base);
  return (form_color(r, g, b));
}
