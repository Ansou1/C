/*
** elem_bump.c for rt in /home/antoni_s//raytracer-2017-simon_o/rt/sources/xml
**
** Made by sebastien antonico
** Login   <antoni_s@epitech.net>
**
** Started on  Sun Jun  9 02:01:45 2013 sebastien antonico
** Last update Sun Jun  9 14:53:50 2013 efilon
*/

#include "raytracer.h"

void	enable_or_not(double *bump, char *val)
{
  if (!my_strncmp_case(val, "actif\"", 6))
    *bump = 1;
  else if (!my_strncmp_case(val, "inactif\"", 8))
    *bump = 0;
}

int	add_bump_obj(t_object *obj, char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (!my_strncmp_case(tab[i], "x=", 2))
	enable_or_not(&(obj->bump.x), tab[i] + 3);
      if (!my_strncmp_case(tab[i], "y=", 2))
	enable_or_not(&(obj->bump.y), tab[i] + 3);
      if (!my_strncmp_case(tab[i], "z=", 2))
	enable_or_not(&(obj->bump.z), tab[i] + 3);
      i++;
    }
  return (1);
}

int	add_bump(t_mlx *rt, char **tab)
{
  if (is_obj_state(rt))
    return (add_bump_obj((rt->list), tab));
  return (0);
}
