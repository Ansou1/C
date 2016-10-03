/*
** my_putnbr_base.c for my_printf in /home/antoni_s//Cproject/Unix/Printf/commit
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.net>
** 
** Started on  Thu Nov 15 21:53:06 2012 sebastien antonico
** Last update Thu Mar 21 09:20:20 2013 sebastien antonico
*/

#include "my.h"

int		my_putnbr_base(unsigned long i, char *base, char flag)
{
  unsigned int	l_base;
  int		rtrn;

  l_base = my_strlen(base);
  rtrn = 0;
  if (flag == '#')
    {
      if (l_base == 8)
	rtrn += my_putchar('0');
      if (l_base == 16 && base[10] == 'A')
	rtrn += my_putstr("0X");
      if (l_base == 16 && base[10] == 'a')
	rtrn += my_putstr("0x");
      flag = 0;
    }
  if (i >= l_base)
    {
      rtrn += my_putnbr_base((i / l_base), base, flag);
      return (rtrn + my_putchar(base[i % l_base]));
    }
  return (rtrn + my_putchar(base[i % l_base]));
}
