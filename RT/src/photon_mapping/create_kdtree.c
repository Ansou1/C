#include "utils.h"
#include "rt.h"

t_kdtree	*create_kdtree(t_photon **map,
		       int axis,
		       int begin,
		       int end)
{
  int		median;
  t_kdtree	*new;

  if (begin >= end)
    return (NULL);
  new = w_malloc(sizeof(t_kdtree));
  qsort_photons(map, axis, begin, end);
  median = ((end - begin) >> 1) + begin;
  new->photon = map[median];
  new->axis = axis;
  INCAXIS(axis);
  new->left = create_kdtree(map, axis, begin, median - 1);
  new->right = create_kdtree(map, axis, median + 1, end);
  return (new);
}
