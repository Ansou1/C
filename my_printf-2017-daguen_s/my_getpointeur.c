/*
** my_getpointeur.c for pointeur in /home/daguen_s//myownprintf
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Wed Nov 14 16:28:48 2012 simon daguenet
** Last update Sun Nov 18 18:08:23 2012 simon daguenet
*/
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "my_printf.h"

int	my_pointeur(va_list ap, char *format)
{
  int	nb;

  nb = 0;
  nb = nb + my_putstr("0x7fff");
  nb = nb + my_putnbr_base2(va_arg(ap, unsigned int), "0123456789abcdef");
  return (nb);
}
