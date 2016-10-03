/*
** pile.c for pile in /home/efilon/Projets/Projects/Cproject/xml
** 
** Made by sebastien antonico
** Login   <efilon@heisenberg>
** 
** Started on  Sat May  4 15:50:25 2013 sebastien antonico
** Last update Mon May 13 13:28:51 2013 efilon
*/

#include <unistd.h>
#include <stdlib.h>
#include "raytracer.h"

void		add_in_pile(t_pile **pile, char *data)
{
  t_pile	*new_pile;

  if ((new_pile = malloc(sizeof(t_pile))) == NULL)
    my_puterr("Erreur malloc.\n");
  new_pile->str = my_strdup(data);
  new_pile->next = *pile;
  *pile = new_pile;
}

int		pop_in_pile(t_pile **pile)
{
  t_pile	*tmp;

  if (*pile == NULL)
    return (0);
  tmp = (*pile)->next;
  free((*pile)->str);
  free(*pile);
  (*pile) = tmp;
  return (1);
}
