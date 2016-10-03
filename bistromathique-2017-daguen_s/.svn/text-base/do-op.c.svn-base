/*
** do-op.c for do-op in /home/elegbe_m//programmation/fichiers_source_piscine/1ere_iteration/rendu/piscine/Jour_11
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Mon Oct 22 14:27:38 2012 martial elegbede
** Last update Sat Nov 10 16:55:39 2012 martial elegbede
*/

#include <stdlib.h>
#include "my.h"
#include "my_inf_fcts.h"

int	my_what(char c)
{
  if (c == '+')
    return (0);
  else if (c == '-')
    return (1);
  else if (c == '*')
    return (2);
  else if (c == '/')
    return (42);
  else if (c == '%')
    return (42);
  else
    return (42);
}

char	*do_inf_op(char *nb1, char *nb2, char op, char *base)
{
  int	i;
  char	*(**fptr)(char* , char*, char*);
  char	*str;

  fptr = malloc(5 * sizeof(*fptr));
  fptr[0] = &do_inf_add;
  fptr[1] = &do_inf_sub;
  fptr[2] = &do_inf_mult;
  i = my_what(op);
  if (i == 42)
    return (NULL);
  str = fptr[i](base, nb1, nb2);
  free(fptr);
  return (str);
}
