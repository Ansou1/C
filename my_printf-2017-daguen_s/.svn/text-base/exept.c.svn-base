/*
** exept.c for exept_printf in /home/daguen_s//myownprintf
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Fri Nov 16 11:56:06 2012 simon daguenet
** Last update Sun Nov 18 21:48:17 2012 simon daguenet
*/
#include "my_printf.h"

int	*init_var(int *tab)
{
  tab[0] = 0;
  tab[1] = 0;
  return (tab);
}

int	exeption(char *format, int tab)
{
  int	value;

  value = 0;
  if (format[tab] == 'c' || format[tab] == 's' || format[tab] == 'd'
 || format[tab] == 'o' || format[tab] == 'x' || format[tab] == 'X'
 || format[tab] == 'b' || format[tab] == 'u' || format[tab] == 'S'
      || format[tab] == 'p')
    value = 1;
  return (value);
}

int	flag(char *format, int tab)
{
  int	value;

  value = 0;
  if (format[tab] == '#' || format[tab] == '%' || format[tab] == '\0')
    value = 1;
  return (value);
}
