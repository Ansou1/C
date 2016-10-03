#include <stdlib.h>

#include "utils.h"
#include "maths.h"

static t_ffx g_fx[] =
  {
    {"neg", postfx_neg},
    {"grey", postfx_grey},
    {"blurr", postfx_blurr},
    {"chuck", postfx_chuck},
    {"crazy", postfx_crazy},
    {"decomp", postfx_decomp},
    {"highcontrast", postfx_hcont},
    {"posterisation", postfx_postr},
    {0, 0}
  };

static t_intersect	*list_intersects(t_rt *this, int x, int y, int r)
{
  t_coords	v;
  t_coords	npos;

  this->temps.rdepth = 0;
  this->temps.tdepth = 0;
  this->temps.last_tr = 0;
  npos.x = 0;
  npos.y = 0;
  npos.z = 0;
  v.x = WIN_WIDTH;
  v.y = (WIN_WIDTH * r / 2 - x)
    / (double)r;
  v.z = (WIN_HEIGHT * r / 2 - y)
    / (double)r;
  depth_field(this, &npos, &v);
  my_rotate(&npos, this->cam->angle);
  my_translate(&npos, &npos, this->cam->pos);
  my_rotate(&v, this->cam->angle);
  return (list_inters(this, &npos, &v));
}

t_color		app_fx(t_rt *this, t_color base, int x, int y)
{
  t_color	tmp;
  int		j;

  tmp = base;
  j = 0;
  while (g_fx[j].name != 0 && this->cam->effects_active)
    {
      if (my_strcmp(g_fx[j].name, this->pfx) == 0)
	tmp = g_fx[j].ptr(this, tmp, x, y);
      j++;
    }
  return (tmp);
}

t_color		gcalc_color(t_rt *this,
		   t_intersect *inter,
		   t_coords *from,
		   t_color base)
{
  t_color	lighted;

  lighted = base;
  if (inter->obj != NULL)
    {
      lighted = calc_light(this, inter);
      lighted = get_illumination(inter, this, lighted);
      lighted = calc_ref(this, from, inter, lighted);
      lighted = calc_transparency(this, from, inter, lighted);
    }
  lighted = calc_phong(this, inter, from, lighted);
  lighted = calc_fog(this, inter, lighted);
  return (lighted);
}

t_color		calc_color(t_rt *this, int x, int y)
{
  t_color	color[256];
  int		i;
  int		j;
  int		tmp;
  t_intersect	*inter_list;

  tmp = this->cam->ratio_pixel;
  if (this->cam->effects_active == FALSE)
    tmp = 1;
  i = 0;
  while (i < tmp)
    {
      j = 0;
      while (j < tmp)
	{
	  inter_list = list_intersects(this, x * tmp + i, y * tmp + j, tmp);
	  color[i * tmp + j] = gcalc_color(this, inter_list,
					   this->cam->pos,
					   get_background(this, x, y, tmp));
	  free_intersect(inter_list);
	  j++;
	}
      i++;
    }
  return (get_mid(this, color, tmp));
}
