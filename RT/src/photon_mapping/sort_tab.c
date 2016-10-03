#include "rt.h"

static void swap_photons(int left, int right, t_photon **tab)
{
  t_photon *tmp;

  tmp = tab[left];
  tab[left] = tab[right];
  tab[right] = tmp;
}

void qsort_photons(t_photon **tab,
		  int axis,
		  int begin,
		  int end)
{
  double	median;
  int		right;
  int		left;

  if (begin >= end)
    return ;
  left = begin - 1;
  right = end + 1;
  median = ((double*)(tab[begin]->pos))[axis];
  while (left < right)
    {
      while (((double*)(tab[--right]->pos))[axis] > median);
      while (((double*)(tab[++left]->pos))[axis] < median);
      if (left < right)
	swap_photons(left, right, tab);
    }
  qsort_photons(tab, axis, begin, right);
  qsort_photons(tab, axis, right + 1, end);
}
