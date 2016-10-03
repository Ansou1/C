/*
** strtoll.c for script in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Tue Apr 30 21:12:44 2013 florian corradin
** Last update Thu May 23 15:04:32 2013 simon daguenet
*/

#include "42.h"

int	digit(char *base, char c)
{
  int	i;

  i = 0;
  while (base[i] != c && base[i] != '\0')
    i++;
  return (base[i] == '\0' ? 0 : i);
}

int		my_strtoll(const char *nptr, char *base)
{
  long		a;
  char		c;

  a = 0;
  if (*nptr == '-')
    return (-my_strtoll(&nptr[1], base));
  while ((c = *nptr++) != '\0' && is_digit(c))
    a = a * my_strlen(base) + digit(base, c);
  return (a);
}
