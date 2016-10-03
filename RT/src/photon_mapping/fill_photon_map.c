#include <time.h>
#include <stdlib.h>

#include "rt.h"

void	fill_photon_map(t_photon_map *map,
		    t_light_list *light,
		    t_rt *this)
{
  map->cur = 0;
  while (light)
    {
      if (light->type == 0)
	launch_from_light(light, map, this);
      light = light->next;
    }
}
