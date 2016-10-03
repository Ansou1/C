/*
** elem_angle.c for elem_angle in /home/efilon/raytracer-2017-simon_o/xml/xml
** 
** Made by efilon
** Login   <efilon@Heisenbergs-RV>
** 
** Started on  Fri May 10 14:42:44 2013 efilon
** Last update Mon May 13 15:47:08 2013 efilon
*/

#include "raytracer.h"

int	add_angle_obj(t_object *obj, char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (!my_strncmp_case(tab[i], "x", 1) && my_strlen(tab[i]) > 4)
	obj->r_x = atoi(tab[i] + 3);
      if (!my_strncmp_case(tab[i], "y", 1) && my_strlen(tab[i]) > 4)
	obj->r_y = atoi(tab[i] + 3);
      if (!my_strncmp_case(tab[i], "z", 1) && my_strlen(tab[i]) > 4)
	obj->r_z = atoi(tab[i] + 3);
      i++;
    }
  return (1);
}

int	add_angle_eye(t_eye *eye, char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (!my_strncmp_case(tab[i], "x", 1) && my_strlen(tab[i]) > 4)
	eye->r_x = atoi(tab[i] + 3);
      if (!my_strncmp_case(tab[i], "y", 1) && my_strlen(tab[i]) > 4)
	eye->r_y = atoi(tab[i] + 3);
      if (!my_strncmp_case(tab[i], "z", 1) && my_strlen(tab[i]) > 4)
	eye->r_z = atoi(tab[i] + 3);
      i++;
    }
  return (1);
}

int	add_angle(t_mlx *rt, char **tab)
{
  if (is_obj_state(rt))
    return (add_angle_obj((rt->list), tab));
  else if ((rt->xml)->state == STATE_CAM)
    return (add_angle_eye(rt->eye, tab));
  return (0);
}

