#include <math.h>

#include "utils.h"
#include "maths.h"

static int	get_type(int type)
{
  static int	tmp;

  if (type != 0)
    tmp = type;
  return (tmp);
}

static int	pos_mod(int pos)
{
  while (pos < 0)
    pos += DEF_TXT_SIZE;
  return (pos % DEF_TXT_SIZE);
}

static t_color	get_curve(t_color cur, t_color cn, t_uint x, t_uint y)
{
  double	dist;

  x = DEPR_RANGE - x;
  y = DEPR_RANGE - y;
  if (get_type(0) == 5)
    dist = sqrt(x * x + y * y) / (double)DEPR_RANGE;
  else
    dist = 0.0f;
  return (ratioed_color(cur, cn, dist));
}

static void	create_depression(t_img *img,
			     t_color base,
			     t_color oposite,
			     double height)
{
  unsigned int	i;
  unsigned int	j;
  unsigned int	x;
  unsigned int	y;
  t_color	tmp;
  t_color	*mod;

  x = rand() % DEF_TXT_SIZE;
  y = rand() % DEF_TXT_SIZE;
  i = 0;
  while (i < DEPR_RANGE * 2)
    {
      j = 0;
      while (j < DEPR_RANGE * 2)
	{
	  mod = &(img->val[pos_mod(i + y)][pos_mod(j + x)]);
	  tmp = ratioed_color(base, oposite, height);
	  *mod = get_curve(*mod, tmp, i, j);
	  j++;
	}
      i++;
    }
}

void		gen_perlin(t_color base, t_color oposite, t_img *img, int type)
{
  unsigned int	i;
  unsigned int	j;
  unsigned int	max;

  get_type(type);
  i = 0;
  while (i < img->ysize)
    {
      j = 0;
      while (j < img->xsize)
	{
	  img->val[i][j] = ratioed_color(base, oposite, 0.5);
	  j++;
	}
      i++;
    }
  if (type == 4)
    max = 200;
  if (type == 5)
    max = 500;
  while (max > 0)
    {
      create_depression(img, base, oposite, (double)(rand() % 100) / 100.0);
      max--;
    }
}
