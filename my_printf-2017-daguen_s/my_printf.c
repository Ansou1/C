/*
** test1.c for test in /home/daguen_s/
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Thu Nov  8 16:16:21 2012 simon daguenet
** Last update Sun Nov 18 19:56:10 2012 simon daguenet
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "my_printf.h"

int	my_flag(va_list ap, char format)
{
  int	nbr;

  nbr = 0;
  if (format == 'o')
    {
      nbr = nbr + my_putchar('0');
      nbr = nbr + my_putnbr_base2(va_arg(ap, unsigned int), "01234567");
    }
  else if (format == 'x')
    {
      nbr = nbr + my_putstr("0x");
      nbr += my_putnbr_base2(va_arg(ap, unsigned int), "0123456789abcdef");
    }
  else if (format == 'X')
    {
      nbr = nbr + my_putstr("0X");
      nbr += my_putnbr_base2(va_arg(ap, unsigned int), "0123456789ABCDEF");
    }
  else if (format == '%')
    nbr = nbr + my_putchar('%');
  return (nbr);
}

int	my_print_char(va_list ap, char format)
{
  int	nbr;

  nbr = 0;
  if (format == 'c')
    nbr = nbr + my_putchar(va_arg(ap, int));
  else if (format == 's')
    nbr = nbr + my_putstr(va_arg(ap, char *));
  else if (format == 'd' || format == 'i')
    nbr = nbr + my_putnbr_base2(va_arg(ap, int), "0123456789");
  else if (format == 'o')
    nbr = nbr + my_putnbr_base2(va_arg(ap, unsigned int), "01234567");
  else if (format == 'x')
    nbr = nbr + my_putnbr_base2(va_arg(ap, unsigned int), "0123456789abcdef");
  else if (format == 'X')
    nbr = nbr + my_putnbr_base2(va_arg(ap, unsigned int), "0123456789ABCDEF");
  else if (format == 'b')
    nbr = nbr + my_putnbr_base2(va_arg(ap, unsigned int), "01");
  else if (format == 'u')
    nbr = nbr + my_putnbr_base2(va_arg(ap, unsigned int), "0123456789");
  else if (format == 'S')
    nbr = nbr + my_putstr_unprintable(va_arg(ap, char *));
  else if (format == 'p')
    nbr = nbr + my_pointeur(ap, format);
  return (nbr);
}

int	fonction(char *format, int *j)
{
  int	nbr;

  nbr = 0;
  if (format[*j] == ' ')
    {
      (*j)++;
      nbr = nbr + my_putchar(' ');
      while (format[*j] == ' ')
	(*j)++;
    }
  return (nbr);
}

int	my_printf(char *format, ...)
{
  va_list	ap;
  int	tab[2];

  init_var(tab);
  va_start(ap, format);
  while (format[tab[1]] != '\0')
    {
      if (format[tab[1]] == '%')
        {
	  tab[1]++;
	  tab[0] = tab[0] + fonction(format, &tab[1]);
	  if (flag(format, tab[1]))
	    {
	      tab[1]++;
	      tab[0] = tab[0] + my_flag(ap, format[tab[1]]);
	    }
	  else if (exeption(format, tab[1]))
	    tab[0] = tab[0] + my_print_char(ap, format[tab[1]]);
        }
      else
	tab[0] = tab[0] + my_putchar(format[tab[1]]);
      tab[1]++;
    }
  va_end(ap);
  return (tab[0]);
}
