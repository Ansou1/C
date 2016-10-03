/*
** tmy_aff_comb.c for tmy_aff_comb.c in /home/corrad_f//tst/Jour3
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Wed Oct  3 15:55:31 2012 florian corradin
** Last update Sat Mar 16 18:31:56 2013 simon daguenet
*/

#include "asm.h"

void	my_eror_nbr(int nb)
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
  my_eror_nbr(nb);
  while (nb / a > 0)
    a = a * 10;
  while (a > 1)
    {
      i = (nb % a) / (a / 10);
      a = a / 10;
      my_putchar(i + 48);
    }
}
