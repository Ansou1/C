/*
** add_in_list.c for add_in_list in /home/efilon/raytracer-2017-simon_o/xml/new_xml/sources/xml
** 
** Made by efilon
** Login   <efilon@Heisenbergs-RV>
** 
** Started on  Mon May 13 10:15:13 2013 efilon
** Last update Mon May 13 15:48:39 2013 efilon
*/

#include <unistd.h>
#include <stdlib.h>
#include "raytracer.h"

void		add_in_list(t_object *add, t_object **list)
{
  t_object	*elem;

  if ((elem = malloc(sizeof(t_object))) == NULL)
    my_puterr("Erreur malloc\n");
  elem = add;
  elem->next = (*list);
  (*list) = elem;
}

void		add_in_list_light(t_light *add, t_light **list)
{
  t_light	*elem;

  if ((elem = malloc(sizeof(t_light))) == NULL)
    my_puterr("Erreur malloc\n");
  elem = add;
  elem->next = (*list);
  (*list) = elem;
}
