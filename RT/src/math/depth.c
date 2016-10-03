#include "utils.h"
#include "maths.h"

static void	randomize(t_rt *this, int *xmod, int *ymod, int def)
{
  int	aa;

  aa = this->cam->ratio_pixel;
  *xmod = rand() % (def * 2) - def;
  *ymod = rand() % (def * 2) - def;
  *xmod = *xmod / aa / 1.5;
  *ymod = *ymod / aa / 1.5;
  *xmod += this->temps.d_sample[this->temps.cpos].x;
  *ymod += this->temps.d_sample[this->temps.cpos].y;
  this->temps.cpos++;
  if ((int)this->temps.cpos >= aa * aa)
    this->temps.cpos = 0;
}

void	depth_field(t_rt *this, t_coords *pos, t_coords *v)
{
  double	ratio;
  int		depth;
  int		def;
  int		xmod;
  int		ymod;

  depth = this->cam->depth_field;
  if (depth < 50)
    return ;
  def = this->cam->depth_deform;
  randomize(this, &xmod, &ymod, def);
  ratio = (double)depth / (double)WIN_WIDTH;
  v->x *= ratio;
  v->y *= ratio;
  v->z *= ratio;
  v->y += xmod;
  pos->y = xmod;
  v->z += ymod;
  pos->z = ymod;
}
