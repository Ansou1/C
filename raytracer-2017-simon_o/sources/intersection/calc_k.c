/*
** calc_k.c for raytracer in /home/cheval_y//raytracer/sources/intersection
** 
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
** 
** Started on  Thu Apr 11 11:18:04 2013 franck chevallier
** Last update Fri Jun  7 18:16:04 2013 antoine simon
*/

#include "raytracer.h"

int	calc_k(t_discriminant disc, double *k1, double *k2)
{
  if (disc.delta > 0)
    {
      (*k1) = (- disc.b - sqrt(disc.delta)) / (2 * disc.a);
      (*k2) = (- disc.b + sqrt(disc.delta)) / (2 * disc.a);
      return (0);
    }
  if (disc.delta == 0)
    {
      (*k1) = (disc.b * - 1) / 2 * disc.a;
      (*k2) = (*k1);
      return (0);
    }
  return (1);
}
