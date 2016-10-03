/*
** my_putstr_spec.c for my_printf in /home/antoni_s//Cproject/Unix/Printf/commit
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.net>
** 
** Started on  Thu Nov 15 21:49:23 2012 sebastien antonico
** Last update Thu Mar 21 09:23:38 2013 sebastien antonico
*/

#include <stdlib.h>
#include "my.h"

int	my_putstr_spec(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  if (str == NULL)
    return (my_putstr("(null)"));
  while (str[i])
    {
      if (str[i] >= 32 && str[i] < 127)
	nb += my_putchar(str[i]);
      else
	nb += my_putchar('\\') + my_putnbr_us(str[i], 'o', 3, 0);
      i++;
    }
  return (nb);
}
