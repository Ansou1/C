/*
** my_putstr_unprintable.c for unprintable in /home/daguen_s//myownprintf
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Tue Nov 13 16:21:24 2012 simon daguenet
** Last update Sun Nov 18 21:52:35 2012 simon daguenet
*/
#include "my_printf.h"

int	my_putstr_unprintable(char *s)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (s[i] != '\0')
    {
      if (s[i] < 32 || s[i] >= 127)
        {
	  nb = nb + my_putchar('\\');
	  nb = nb + my_putnbr_base2((s[i] + '0'), "01234567");
        }
      else
        nb = nb + my_putchar(s[i]);
      i++;
    }
  return (nb);
}
