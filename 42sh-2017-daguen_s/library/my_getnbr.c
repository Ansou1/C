/*
** my_getnbr.c for my_getnbr.c in /home/corrad_f//tst
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Wed Oct 10 18:40:10 2012 florian corradin
** Last update Wed Apr 10 09:27:45 2013 florian corradin
*/

#include "42.h"

int	my_atoi(char *str)
{
  int	ret;
  char	neg;
  char	c;

  ret = 0;
  neg = (*str == '-') ? -1 : 1;
  if (neg == -1)
    *str++;
  while ((c = *str++) && c >= '0' && c <= '9')
    ret = ret * 10 + (c - '0');
  return (ret * neg);
}
