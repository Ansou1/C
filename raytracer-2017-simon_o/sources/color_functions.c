/*
** color_functions.c for raytracer in /home/racaud_j/Documents/Work/svn/raytracer-2017-simon_o/rt
**
** Made by jonathan racaud
** Login   <racaud_j@epitech.net>
**
** Started on  Sun Jun  9 12:31:06 2013 jonathan racaud
** Last update Sun Jun  9 15:05:56 2013 jonathan racaud
*/

#include "raytracer.h"

int		add_color2(int color, int color2)
{
  int		rr;
  int		gg;
  int		bb;

  rr = 0;
  gg = 0;
  bb = 0;
  rr = RED(color) + RED(color2);
  gg = GREEN(color) + GREEN(color2);
  bb = BLUE(color) + BLUE(color2);
  rr = (rr > 255) ? 255 : rr;
  gg = (gg > 255) ? 255 : gg;
  bb = (bb > 255) ? 255 : bb;
  return (rr * 0x10000 + gg * 0x100 + bb);
}

int		calc_right_color(int *color, int cnt)
{
  int		rr;
  int		gg;
  int		bb;
  int		index;

  index = 0;
  rr = 0;
  gg = 0;
  bb = 0;
  while (index < cnt)
  {
    rr += RED(color[index]);
    gg += GREEN(color[index]);
    bb += BLUE(color[index++]);
  }
  rr = (rr > 255) ? 255 : rr;
  gg = (gg > 255) ? 255 : gg;
  bb = (bb > 255) ? 255 : bb;
  return (rr * 0x10000 + gg * 0x100 + bb);
}

int	little_point(int color, double cos)
{
  int	rr;
  int	gg;
  int	bb;

  rr = cos * RED(color);
  gg = cos * GREEN(color);
  bb = cos * BLUE(color);
  rr = (rr > 255) ? 255 : rr;
  gg = (gg > 255) ? 255 : gg;
  bb = (bb > 255) ? 255 : bb;
  return (rr * 0x10000 + gg * 0x100 + bb);
}

int		speculaire(t_mlx *mlx, t_object *select_object, int color,
			   t_spec spec)
{
  double	ispec;
  double	kspec;
  double	n;
  double	save;
  double	cos_b;
  t_coord	vision;
  t_coord	reflechie;
  double	scalaire;

  ispec = 0;
  kspec = select_object->spec_int;
  n = select_object->material;
  vision = EYE->v_eye;
  scalaire = get_scalaire(&vision, &spec.normal);
  reflechie.x = -(2 * spec.normal.x * (scalaire) - vision.x);
  reflechie.y = -(2 * spec.normal.y * (scalaire) - vision.y);
  reflechie.z = -(2 * spec.normal.z * (scalaire) - vision.z);
  cos_b = (spec.light.x * reflechie.x + spec.light.y * reflechie.y
	   + spec.light.z * reflechie.z);
  if (cos_b < 0.f)
    return (color);
  save = pow(cos_b, n);
  ispec = kspec * save;
  check_cos(mlx, &color, ispec, select_object);
  return (color);
}
