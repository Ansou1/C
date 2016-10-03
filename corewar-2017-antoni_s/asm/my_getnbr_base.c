/*
** my_getnbr.c for my_getnbr.c in /home/corrad_f//tst
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Wed Oct 10 18:40:10 2012 florian corradin
** Last update Fri Mar 29 14:31:04 2013 simon daguenet
*/

#include "asm.h"

char	*my_check_neg2(char *str, char *neg)
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

int	digit_to_val(char c, char *base)
{
  int	i;

  i = 0;
  while (c != base[i])
    i++;
  return (i);
}

long long	my_getnbr_base(char *str, char *base)
{
  long long	number;
  int		i;
  long long	multiple;
  char		neg;

  neg = 0;
  str = my_check_neg2(str, &neg);
  i = 1;
  number = 0;
  multiple = 1;
  while (i++ < my_strlen(str))
    multiple = multiple * my_strlen(base);
  i = 0;
  while (str[i] != 0)
    {
      if (str[i] != base[0])
	number = number + digit_to_val(str[i], base) * multiple;
      i++;
      multiple = multiple / my_strlen(base);
    }
  if (neg == 1)
    number = number * -1;
  return (number);
}
