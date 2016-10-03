/*
** elem_position.c for elem_position in /home/efilon/raytracer-2017-simon_o/xml/xml
** 
** Made by efilon
** Login   <efilon@Heisenbergs-RV>
** 
** Started on  Fri May 10 14:43:47 2013 efilon
** Last update Sat Jun  8 13:23:16 2013 efilon
*/

#include "raytracer.h"

int	add_position_obj(t_object *obj, char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (!my_strncmp_case(tab[i], "x=", 2))
	obj->x = atoi(tab[i] + 3);
      if (!my_strncmp_case(tab[i], "y=", 2))
	obj->y = atoi(tab[i] + 3);
      if (!my_strncmp_case(tab[i], "z=", 2))
	obj->z = atoi(tab[i] + 3);
      i++;
    }
  return (1);
}

int	add_position_light(t_light *light, char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (!my_strncmp_case(tab[i], "x=", 2))
	(light->pos_light).x = atoi(tab[i] + 3);
      if (!my_strncmp_case(tab[i], "y=", 2))
	(light->pos_light).y = atoi(tab[i] + 3);
      if (!my_strncmp_case(tab[i], "z=", 2))
	(light->pos_light).z = atoi(tab[i] + 3);
      i++;
    }
  return (1);
}

int	add_position_eye(t_eye *eye, char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (!my_strncmp_case(tab[i], "x=", 2))
	(eye->eye_pos).x = atoi(tab[i] + 3);
      if (!my_strncmp_case(tab[i], "y=", 2))
	(eye->eye_pos).y = atoi(tab[i] + 3);
      if (!my_strncmp_case(tab[i], "z=", 2))
	(eye->eye_pos).z = atoi(tab[i] + 3);
      i++;
    }
  return (1);
}

int	add_position(t_mlx *rt, char **tab)
{
  if (is_obj_state(rt))
    return (add_position_obj((rt->list), tab));
  else if ((rt->xml)->state == STATE_CUBE)
    return (add_position_cube(rt->list, tab));
  else if ((rt->xml)->state == STATE_LIGHT)
    return (add_position_light(rt->light, tab));
  else if ((rt->xml)->state == STATE_CAM)
    return (add_position_eye(rt->eye, tab));
  return (0);
}

