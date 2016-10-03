/*
** elem_limit.c for elem_limit in /home/efilon/eretay/raytracer-2017-simon_o/rt/sources/xml
** 
** Made by efilon
** Login   <efilon@Heisenbergs-RV>
** 
** Started on  Fri Jun  7 02:09:07 2013 efilon
** Last update Sun Jun  9 04:39:58 2013 efilon
*/

#include "raytracer.h"

int	add_limit_obj(t_object *obj, char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (!my_strncmp_case(tab[i], "largeur=", 8))
	(obj->width_limit) = atoi(tab[i] + 9);
      else if (!my_strncmp_case(tab[i], "longueur=", 9))
	(obj->length_limit) = atoi(tab[i] + 10);
      i++;
    }
  obj->width_limit = (obj->width_limit <= 0 ? -1 : obj->width_limit);
  obj->length_limit = (obj->length_limit <= 0 ? -1 : obj->length_limit);
  return (1);
}

int	add_limit(t_mlx *rt, char **tab)
{
  if (is_obj_state(rt))
    return (add_limit_obj((rt->list), tab));
  return (0);
}
