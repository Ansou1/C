/*
** elem_reflexion.c for elem_reflexion in /home/efilon/raytracer-2017-simon_o/xml/new_xml/sources/xml
** 
** Made by efilon
** Login   <efilon@Heisenbergs-RV>
** 
** Started on  Tue May 14 10:33:50 2013 efilon
** Last update Tue May 14 10:36:56 2013 franck chevallier
*/

#include "raytracer.h"

int	add_reflexion_obj(t_object *obj, char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (!my_strncmp_case(tab[i], "reflexion", 9) && my_strlen(tab[i]) > 12)
	obj->reflexion = atof(tab[i] + 11);
      i++;
    }
  return (1);
}

int	add_reflexion(t_mlx *rt, char **tab)
{
  if (is_obj_state(rt))
    return (add_reflexion_obj((rt->list), tab));
  return (0);
}
