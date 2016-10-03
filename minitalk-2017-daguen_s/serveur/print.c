/*
** print.c for serveur_minitalk in /home/daguen_s//talk/serveur
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Mar 24 00:36:08 2013 simon daguenet
** Last update Sun Mar 24 00:37:39 2013 simon daguenet
*/

#include "serveur.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

void	my_putnbr_base2(int nb, char *base)
{
  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
    }
  if (nb >= my_strlen(base))
    {
      my_putnbr_base2(nb / my_strlen(base), base);
    }
  my_putchar(base[nb % my_strlen(base)]);
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

void		my_printf(char *format, ...)
{
  va_list	ap;
  int		i;

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
