/*
** my_getnbr.c for my_getnbr in /home/daguen_s//save_lib
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Oct 22 16:33:25 2012 simon daguenet
** Last update Sun Dec  2 16:50:21 2012 simon daguenet
*/
#include "get_next_line.h"

int     my_getnbr(char *str)
{
  int   i;
  long  nbr;
  int   f;

  i = 0;
  f = 0;
  nbr = 0;
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
        {
          f = f + 1;
        }
      i = i + 1;
    }
  while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
      nbr = ((str[i] - '0') + (nbr * 10));
      i = i + 1;
    }
  if (f % 2 != 0)
    nbr = nbr * (-1);
  if (nbr > 2147483647 || nbr < -2147483648)
    nbr = 0;
  return (nbr);
}
