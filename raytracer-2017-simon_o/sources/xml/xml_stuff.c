/*
** xml_stuff.c for xml_stuff in /tmp/CACA/raytracer-2017-simon_o/rt
** 
** Made by efilon
** Login   <efilon@Heisenbergs-RV>
** 
** Started on  Sat Jun  8 19:42:11 2013 efilon
** Last update Sat Jun  8 19:42:32 2013 efilon
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "raytracer.h"

void		add_empty_light(t_mlx *rt)
{
  t_light	*new;

  if ((new = malloc(sizeof(t_light))) == NULL)
    my_puterr("Erreur malloc\n");
  new->color = 0xFFFFFF;
  new->pos_light.x = 0;
  new->pos_light.y = 0;
  new->pos_light.z = 0;
  new->next = NULL;
  add_in_list_light(new, &(rt->light));
  rt->nb_lights++;
}

void	fill_intersec_ptr(t_object *obj)
{
  if (obj->def_object == SPHERE)
    obj->intersection = inter_sphere;
  else if (obj->def_object == PLANE)
    obj->intersection = inter_plan;
  else if (obj->def_object == CONE)
    obj->intersection = inter_cone;
  else if (obj->def_object == CYLINDER)
    obj->intersection = inter_cylinder;
  else
    obj->intersection = inter_sphere;
}
