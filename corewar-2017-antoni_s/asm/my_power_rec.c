/*
** my_power_it.c for my_power_it.c in /home/corrad_f//tst/Jour5
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sun Oct  7 21:56:01 2012 florian corradin
** Last update Sat Mar 16 18:39:29 2013 simon daguenet
*/

#include "asm.h"

long	my_power_rec(int nb, int power)
{
  long	i;

  if ((power < 0) || (nb == 0 && power != 0))
    {
      return (0);
    }
  if (power == 0)
    {
      return (1);
    }
  i = nb * my_power_rec(nb, power - 1);
  return (i);
}
