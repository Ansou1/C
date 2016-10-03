/*
** my_getnbr.c for my_getnbr.c in /home/corrad_f//tst
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Wed Oct 10 18:40:10 2012 florian corradin
** Last update Fri Mar 29 14:31:37 2013 simon daguenet
*/

#include "asm.h"

char	*my_check_neg(char *str, char *neg)
{
  int	i;

  i = 0;
  while (str[i] != 0 && str[i] == '-')
    {
      *neg = *neg + 1;
      i = i + 1;
    }
  return (&(str[i]));
}

int	my_getnbr(char *str)
{
  int	number;
  int	i;
  int	multiple;
  char	neg;

  neg = 0;
  str = my_check_neg(str, &neg);
  i = 0;
  number = 0;
  multiple = my_power_rec(10, my_strlen(str) - 1);
  while (str[i] != 0)
    {
      if (str[i] != '0')
	{
	  number = number + (str[i] - '0') * multiple;
	}
      i = i + 1;
      multiple = multiple / 10;
    }
  if (neg % 2 == 1)
    {
      number = number * -1;
    }
  return (number);
}
