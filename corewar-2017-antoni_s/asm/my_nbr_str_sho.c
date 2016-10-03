/*
** my_nbr_str.c for lib in /home/corrad_f//lib
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Thu Jan 24 13:27:11 2013 florian corradin
** Last update Fri Mar 29 14:32:33 2013 simon daguenet
*/

#include "asm.h"

char	*my_eror1(short nb, int *ctr, char *ret)
{
  if (nb == 0)
    {
      ret[*ctr] = '0';
      *ctr = *ctr + 1;
    }
  return (ret);
}

char	*my_nbr_str_sho(short nb)
{
  int	i;
  long	a;
  char	*ret;
  int	ctr;

  ctr = 0;
  ret = xmalloc(11);
  a = 1;
  i = 0 ;
  if (nb < 0)
    {
      nb = nb * -1;
      ret[ctr++] = '-';
    }
  ret = my_eror1(nb, &ctr, ret);
  while (nb / a > 0)
    a = a * 10;
  while (a > 1)
    {
      i = (nb % a) / (a / 10);
      a = a / 10;
      ret[ctr++] = i + 48;
    }
  ret[ctr] = 0;
  return (ret);
}
