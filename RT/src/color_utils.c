#include"maths.h"

t_color	adapt_light_color(t_color light, t_color obj, double tr)
{
  int	r;
  int	g;
  int	b;
  int	ratio;

  if (tr == 0.0f)
    return (obj);
  if (tr == 1.0f)
    return (light);
  ratio = 256.0f * tr;
  r = MIN(RED(light), RED(obj)) * (256 - ratio);
  g = MIN(GRE(light), GRE(obj)) * (256 - ratio);
  b = MIN(BLU(light), BLU(obj)) * (256 - ratio);
  r += RED(light) * (ratio);
  g += GRE(light) * (ratio);
  b += BLU(light) * (ratio);
  r >>= 8;
  g >>= 8;
  b >>= 8;
  return (form_color(r, g, b));
}

t_color	form_color(int r, int g, int b)
{
  if (r > 255)
    r = 255;
  else if (r < 0)
    r = 0;
  if (g > 255)
    g = 255;
  else if (g < 0)
    g = 0;
  if (b > 255)
    b = 255;
  else if (b < 0)
    b = 0;
  return ((r << 16) + (g << 8) + b);
}
