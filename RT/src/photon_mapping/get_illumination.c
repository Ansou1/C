#include "maths.h"
#include "obj.h"
#include "rt.h"

static void	free_near(t_near_photon *near)
{
  t_photon_list	*tmp;
  t_photon_list	*next;

  tmp = near->begin;
  while (tmp)
    {
      next = tmp->next;
      free(tmp);
      tmp = next;
    }
  free(near);
}

double	get_photon_ratio(t_photon_list *tmp, t_intersect *inter)
{
  t_coords	*norm;
  double	acos;

  norm = get_normal(inter);
  acos = get_scal(norm, tmp->cur->vec);
  free(norm);
  return (RATIO(acos));
}

static t_color	get_final_radiance(t_near_photon *near,
				 t_intersect *inter,
				 t_rt *this)
{
  double	area;
  t_color	final;
  t_color	photon;
  t_photon_list	*tmp;
  double	ratio;

  final = 0;
  area = POW2(near->last_dist) * RPI;
  tmp = near->begin;
  while (tmp)
    {
      ratio = get_photon_ratio(tmp, inter);
      photon = ratioed_color(tmp->cur->color,
			     inter->color, inter->obj->bright);
      ratio = tmp->cur->power / area * ratio * this->cam->diff_fact;
      photon = ratioed_color(photon, 0x00, ratio);
      if (final)
	final = ratioed_color(photon, final, 1.0 / near->len);
      else
	final = photon;
      tmp = tmp->next;
    }
  return (final);
}

t_color		get_illumination(t_intersect *inter,
			t_rt *this,
			t_color cur)
{
  t_near_photon	*near;
  t_color	final;

  if (this->photons == NULL || this->photons->map_size < 10)
    return (cur);
  near = get_nearest_photons(this->cam->used_photon,
			     this->photons, inter->pos);
  final = get_final_radiance(near, inter, this);
  free_near(near);
  return (ratioed_color(final, cur, this->cam->photon_mapped));
}
