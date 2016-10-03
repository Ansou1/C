/*
** elem_radius.c for elem_radius in /home/efilon/raytracer-2017-simon_o/xml/xml
** 
** Made by efilon
** Login   <efilon@Heisenbergs-RV>
** 
** Started on  Fri May 10 16:23:15 2013 efilon
** Last update Sat Jun  8 18:18:46 2013 efilon
*/

#include "raytracer.h"

int	add_radius_obj(t_object *obj, char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (!my_strncmp_case(tab[i], "rayon=", 6))
	(obj->radius) = atoi(tab[i] + 7);
      i++;
    }
  obj->radius = MAX(0, obj->radius);
  return (1);
}

int	add_radius(t_mlx *rt, char **tab)
{
  if (is_obj_state(rt))
    return (add_radius_obj((rt->list), tab));
  else if (rt->xml->state == STATE_CUBE)
    return (change_size_cube(rt->list, tab));
  return (0);
}
