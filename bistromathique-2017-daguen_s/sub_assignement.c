/*
** sub_assignment.c for bistro in /home/elegbe_m//programmation/bistro/BISTRO
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Mon Nov  5 12:23:51 2012 martial elegbede
** Last update Mon Nov  5 15:30:23 2012 martial elegbede
*/

#include <stdlib.h>
#include "my_chained_list.h"
#include "my.h"
#include "memset.h"

int	sub_assignement_list(t_list *list)
{
  char	*new_nbr;

  new_nbr = malloc(my_strlen(list->nbr) + 2);
  if (new_nbr == NULL)
    return (0);
  new_nbr[0] = '-';
  new_nbr[my_strlen(list->nbr) + 1] = 0;
  my_strcat(new_nbr, list->nbr);
  free(list->nbr);
  list->nbr = new_nbr;
  return (1);
}

int	sub_assignement_nbr(char **nbr)
{
  char	*new_nbr;

  new_nbr = malloc(my_strlen(*nbr) + 2);
  if (new_nbr == NULL)
    return (0);
  my_memcharset(new_nbr, 0, my_strlen(*nbr) + 1);
  new_nbr[0] = '-';
  my_strcat(new_nbr, *nbr);
  free(*nbr);
  *nbr = new_nbr;
  return (1);
}
