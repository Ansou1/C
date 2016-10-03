/*
** my_putnbr_us.c for my_printf in /home/antoni_s//Cproject/Unix/Printf/commit
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.net>
** 
** Started on  Thu Nov 15 21:54:46 2012 sebastien antonico
** Last update Thu Mar 21 09:20:54 2013 sebastien antonico
*/

#include "my.h"

int	my_putnbr_us(unsigned long i, char c, int precision, char flag)
{
  char	*base;
  int	l_nb;
  int	nb;

  if (c == 'u')
    base = "0123456789";
  if (c == 'o')
    base = "01234567";
  if (c == 'x')
    base = "0123456789abcdef";
  if (c == 'X')
    base = "0123456789ABCDEF";
  if (c == 'b')
    base = "01";
  l_nb = my_nblen(i);
  nb = 0;
  while (precision > l_nb)
    {
      nb += my_putchar('0');
      precision--;
    }
  return (nb + my_putnbr_base(i, base, flag));
}
