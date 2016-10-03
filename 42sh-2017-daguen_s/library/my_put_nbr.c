/*
** tmy_aff_comb.c for tmy_aff_comb.c in /home/corrad_f//tst/Jour3
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Wed Oct  3 15:55:31 2012 florian corradin
** Last update Thu Apr 25 09:26:09 2013 florian corradin
*/

#include "lib.h"

void	my_eror(int nb)
{
  if (nb == 0)
    {
      my_putchar('0');
    }
}

void	my_put_nbr(int nb)
{
  int	i;
  long	a;

  a = 1;
  i = 0 ;
  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
    }
  my_eror(nb);
  while (nb / a > 0)
    a = a * 10;
  while (a > 1)
    {
      i = (nb % a) / (a / 10);
      a = a / 10;
      my_putchar(i + 48);
    }
}
