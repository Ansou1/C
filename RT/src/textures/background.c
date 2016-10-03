#include "rt.h"

t_color	get_background(t_rt *this, int x, int y, int scale)
{
  t_uint	max_x;
  t_uint	max_y;
  t_uint	tx;
  t_uint	ty;

  if (this->cam->background == NULL)
    return (0x0);
  max_x = this->cam->background->xsize;
  max_y = this->cam->background->ysize;
  if (max_x == 0 || max_y == 0)
    return (0x0);
  tx = x * max_x / WIN_WIDTH / scale;
  ty = y * max_y / WIN_HEIGHT / scale;
  if (tx >= max_x || ty >= max_y)
    return (0x0);
  return (this->cam->background->val[ty][tx]);
}
