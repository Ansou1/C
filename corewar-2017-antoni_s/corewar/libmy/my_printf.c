/*
** my_printf.c for my_printf in /home/antoni_s//Cproject/Unix/Printf
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.net>
** 
** Started on  Tue Nov 13 22:19:38 2012 sebastien antonico
** Last update Sat Nov 17 18:08:04 2012 sebastien antonico
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int	my_printf(char *str, ...)
{
  int	i;
  int	nb;
  va_list list;

  i = 0;
  nb = 0;
  va_start(list, str);
  while (str[i])
    {
      if (str[i] != '%')
	  nb += my_putchar(str[i]);
      else
	nb += parsing(str, &i, list);
      i++;
    }
  va_end(list);
  return (nb);
}
