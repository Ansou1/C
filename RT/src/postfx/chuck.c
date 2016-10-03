#include "maths.h"

t_color			postfx_chuck(t_rt *this, t_color base, int x, int y)
{
  static int		loaded = 0;
  static int		**img = 0;
  int			imgcolor;
  int			r;
  int			g;
  int			b;

  (void)this;
  if (loaded == 0)
    {
      loaded = 1;
      img = load_image("data/chuck.bmp", IMG_WIDTH, IMG_HEIGHT);
    }
  if (img == 0)
    return (base);
  imgcolor = img[y * IMG_HEIGHT / WIN_HEIGHT][x * IMG_WIDTH / WIN_WIDTH];
  if (imgcolor < 0xffffff)
    return (imgcolor);
  r = (RED(base) + RED(imgcolor) * 1) / 2;
  g = (GRE(base) + GRE(imgcolor) * 1) / 2;
  b = (BLU(base) + BLU(imgcolor) * 1) / 2;
  return (form_color(r, g, b));
}
