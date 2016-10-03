#include "utils.h"
#include "rt.h"

static int	count_photons(t_light_list *light)
{
  int	ret;

  ret = 0;
  while (light)
    {
      if (light->type == 0)
	ret += light->photons;
      light = light->next;
    }
  return (ret);
}

t_photon_map	*launch_photons(t_light_list *light, t_rt *this)
{
  t_photon_map	*ret;

  ret = w_malloc(sizeof(t_photon_map));
  ret->map_size = count_photons(light);
  if (ret->map_size == 0)
    {
      free(ret);
      return (NULL);
    }
  my_putstr("Photon tracing...\n");
  ret->map = w_malloc(sizeof(t_photon*) * ret->map_size);
  fill_photon_map(ret, light, this);
  my_putstr("Creating kdtree...\n");
  ret->tree = create_kdtree(ret->map, 0, 0, ret->map_size - 1);
  my_putstr("Photon tracing end...\n");
  return (ret);
}
