/*
** my_putthing.c for my_printf in /home/antoni_s//Cproject/Unix/Printf/commit
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.net>
** 
** Started on  Thu Nov 15 21:58:37 2012 sebastien antonico
** Last update Wed Mar 27 12:35:17 2013 sebastien antonico
*/

#include <stdarg.h>
#include "my.h"

int	my_putthing(char c, va_list list, char flag)
{
  char	*spec;
  int	type;

  spec = "diuoxXbcsSp%";
  type = my_find(c, spec);
  if (type == -1)
    return (my_putchar('%') + my_putchar(flag) + my_putchar(c));
  if (type <= 1)
    return (my_putnbr(va_arg(list, int), flag));
  if (type <= 6)
    return (my_putnbr_us(va_arg(list, unsigned long), c, 0, flag));
  if (type == 7)
    return (my_putchar(va_arg(list, int)));
  if (type == 8)
    return (my_putstr(va_arg(list, char *)));
  if (type == 9)
    return (my_putstr_spec(va_arg(list, char *)));
  if (type == 10)
    return (my_putptr(va_arg(list, unsigned long)));
  return (my_putchar('%'));
}
