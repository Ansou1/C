#include <stdlib.h>
#include <math.h>

#include "maths.h"

static t_ftxt g_txt_color[] =
  {
    {TYPE_PLAN, txtcolor_plan},
    {TYPE_SPHERE, txtcolor_sphere},
    {TYPE_CUBE, txtcolor_cube},
    {-1, NULL}
  };

double	m_modulo(double nb, int mod)
{
  int	mlt;

  if (mod == 0)
    return (0);
  mlt = ABS(nb / mod) + 1;
  nb += mod * mlt;
  return (fmod(nb, mod));
}

t_color		txtcolor_plan(t_object *obj, t_coords *pos, t_img *t)
{
  t_uint	xpos;
  t_uint	ypos;

  (void)obj;
  if (t->rep == 0)
    t->rep = 100;
  xpos = m_modulo(pos->y, t->rep) * t->xsize / t->rep;
  ypos = m_modulo(pos->x, t->rep) * t->ysize / t->rep;
  return (t->val[ypos][xpos]);
}

t_color		txtcolor_sphere(t_object *obj, t_coords *pos, t_img *t)
{
  t_uint	fx;
  t_uint	fy;
  double	ax;
  double	ay;

  if (t->rep == 0)
    t->rep = 180;
  ax = acos(pos->z / obj->val1) * RAD_TO_DEG;
  ay = acos(pos->x / sqrt(pos->x * pos->x + pos->y * pos->y)) * RAD_TO_DEG;
  if (pos->y < 0)
    ay = 360.0 - ay;
  fx = m_modulo(ay, t->rep * 2) * t->xsize / t->rep / 2;
  fy = m_modulo(-ax, t->rep) * t->ysize / t->rep;
  return (t->val[fy][fx]);
}

t_color		txtcolor_cube(t_object *obj, t_coords *pos, t_img *t)
{
  t_uint	fx;
  t_uint	fy;

  if (t->rep == 0)
    t->rep = 100;
  if (ABS(pos->x) > obj->val1 * 0.99)
    {
      fx = pos->y;
      fy = pos->z;
    }
  else if (ABS(pos->y) > obj->val1 * 0.99)
    {
      fx = pos->x;
      fy = pos->z;
    }
  else
    {
      fx = pos->x;
      fy = pos->y;
    }
  fx = m_modulo(fx - t->rep / 2, t->rep) * t->xsize / t->rep;
  fy = m_modulo(fy - t->rep / 2, t->rep) * t->xsize / t->rep;
  return (t->val[fy][fx]);
}

t_color		get_txt_color(t_object *obj, t_coords *pos, int type)
{
  int		i;
  t_img		*t;
  t_coords	tmp;

  i = 0;
  if (type == 1)
    t = obj->texture;
  else
    t = obj->bumpmap;
  while (g_txt_color[i].ptr != NULL)
    {
      if (g_txt_color[i].type == obj->type && t != 0)
	{
	  my_translate(&tmp, pos, obj->pos);
	  my_rotate(&tmp, obj->r);
	  return (g_txt_color[i].ptr(obj, &tmp, t));
	}
      i++;
    }
  return (obj->color);
}
