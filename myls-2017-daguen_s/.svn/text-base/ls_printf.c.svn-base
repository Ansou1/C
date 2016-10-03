/*
** ls_printf.c for ls in /home/daguen_s//ls/my_ls
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Fri Nov 30 20:45:30 2012 simon daguenet
** Last update Fri Nov 30 23:03:46 2012 simon daguenet
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdarg.h>
#include "my_ls.h"

void	init_var(char *var)
{
  var[0] = 1;
  var[1] = 0;
}

void	my_print_char(va_list ap, char format)
{
  if (format == 'c')
    my_putchar(va_arg(ap, int));
  else if (format == 's')
    my_putstr(va_arg(ap, char *));
  else if (format == 'd')
    my_putnbr_base2(va_arg(ap, int), "0123456789");
}

int	my_printf(char *format, ...)
{
  va_list	ap;
  int	i;

  va_start(ap, format);
  i = 0;
  while (format[i] != '\0')
    {
      if (format[i] == '%')
	{
	  i++;
	  if (format[i] == 'c' || format[i] == 's' || format[i] == 'd')
	      my_print_char(ap, format[i]);
	}
      else
	my_putchar(format[i]);
      i++;
    }
  va_end(ap);
}
