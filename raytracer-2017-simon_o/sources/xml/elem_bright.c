/*
** elem_bright.c for elem_bright in /home/efilon/raytracer-2017-simon_o/xml/xml
** 
** Made by efilon
** Login   <efilon@Heisenbergs-RV>
** 
** Started on  Fri May 10 16:48:53 2013 efilon
** Last update Sun Jun  9 14:56:57 2013 efilon
*/

#include "raytracer.h"

int		add_bright_cube(t_mlx *mlx, char **tab)
{
  t_object	*tmp;
  int		i;
  int		j;

  i = 0;
  tmp = OBJECT;
  while (tmp != NULL && i < 6)
    {
      j = 0;
      while (tab[j] != NULL)
	{
	  if (!my_strncmp_case(tab[j], "brillance=", 10))
	    tmp->brightness = atof(tab[j] + 11);
	  j++;
	}
      i++;
      tmp = tmp->next;
    }
  return (1);
}

int	add_bright_obj(t_object *obj, char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (!my_strncmp_case(tab[i], "brillance=", 10))
	obj->brightness = atof(tab[i] + 11);
      i++;
    }
  obj->brightness = MAX(0.0, MIN(1.0, obj->brightness));
  return (1);
}

int	add_bright(t_mlx *rt, char **tab)
{
  if (is_obj_state(rt))
    return (add_bright_obj((rt->list), tab));
  else if (rt->xml->state == CUBE)
    return (add_bright_cube(rt, tab));
  return (0);
}
