#include <math.h>
#include <stdlib.h>

#include "maths.h"
#include "utils.h"
#include "rt.h"

static void	photons_sampling(t_coords *pt)
{
  double	angle_x;
  double	angle_y;

  angle_x = ((double)(rand() % 360000)) / 1000.0;
  angle_y = ((double)(rand() % 180000)) / 1000.0;
  angle_x *= DEG_TO_RAD;
  angle_y *= DEG_TO_RAD;
  pt->x = cos(angle_x) * sin(angle_y);
  pt->y = sin(angle_x) * sin(angle_y);
  pt->z = cos(angle_y);
}

static t_coords	*normalise_vector(t_coords *vec)
{
  t_coords	*ret;
  double	len;

  ret = w_malloc(sizeof(t_coords));
  len = sqrt(POW2(vec->x) + POW2(vec->y) + POW2(vec->z));
  ret->x = vec->x / len;
  ret->y = vec->y / len;
  ret->z = vec->z / len;
  return (ret);
}

static int	launch_new_photons(t_photon_info *launch,
			     t_photon_map *map,
			     t_rt *this)
{
  t_intersect	*inter;

  if (map->cur == map->map_size)
    return (0);
  inter = list_inters(this, launch->pt, launch->vec);
  launch->power *= RATIO(launch->power / inter->dist);
  if (inter->obj == NULL || launch->power < 0)
    {
      free(inter->pos);
      free(inter);
      return (1);
    }
  map->map[map->cur] = w_malloc(sizeof(t_photon));
  map->map[map->cur]->pos = inter->pos;
  map->map[map->cur]->vec = normalise_vector(launch->vec);
  map->map[map->cur]->power = launch->power;
  map->map[map->cur]->color = launch->color;
  free(inter);
  map->cur += 1;
  return (0);
}

void	launch_from_light(t_light_list *light,
		      t_photon_map *map,
		      t_rt *this)
{
  t_photon_info	launch;
  t_coords	pt;
  int		j;
  int		len;

  len = light->photons;
  j = map->cur;
  while (map->cur < map->map_size &&
	 map->cur - j < len)
    {
      photons_sampling(&pt);
      launch.pt = light->pos;
      launch.vec = &pt;
      launch.color = light->color;
      launch.power = light->watt;
      if (launch_new_photons(&launch, map, this) == 1)
	{
	  --map->map_size;
	  --len;
	}
    }
}
