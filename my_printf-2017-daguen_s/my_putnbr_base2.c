/*
** my_putnbr_base2.c for printf in /home/daguen_s/
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Fri Nov  9 10:06:11 2012 simon daguenet
** Last update Sun Nov 18 18:09:22 2012 simon daguenet
*/
#include "my_printf.h"

int	my_putnbr_base2(long nb, char *base)
{
  int	result;
  int	diviseur;
  int	size_base;
  int	i;

  i = 0;
  size_base = my_strlen(base);
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
      i++;
    }
  diviseur = 1;
  while ((nb / diviseur) >= size_base)
    diviseur = diviseur * size_base;
  while (diviseur > 0)
    {
      result = (nb /diviseur) % size_base;
      my_putchar(base[result]);
      diviseur = diviseur / size_base;
      i++;
    }
  return (i);
}

