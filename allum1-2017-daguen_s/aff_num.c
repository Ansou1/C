/*
** aff_num.c for allum1 in /home/daguen_s//myalum1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Feb 10 18:59:01 2013 simon daguenet
** Last update Sun Feb 10 20:00:26 2013 simon daguenet
*/

#include "allum1.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_put_nbr(int nb)
{
  int	div;

  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
      my_putchar(nb);
    }
  div = 1;
  while (nb / div > 9)
    div = div * 10;
  while (div != 0)
    {
      my_putchar('0' + (nb / div) % 10);
      nb = nb % div;
      div = div /10;
    }
}

int	my_getnbr(char *str)
{
  int	i;
  long	nbr;
  int	f;

  i = 0;
  f = 0;
  nbr = 0;
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
          f++;
      i++;
    }
  while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
      nbr = ((str[i] - '0') + (nbr * 10));
      i++;
    }
  if (f % 2 != 0)
    nbr = nbr * (-1);
  if (nbr > 2147483647 || nbr < -2147483648)
    nbr = 0;
  return (nbr);
}
