/*
** my_getnbr.c for my_getnbr in /home/cheval_y//dibmoomooo
**
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
**
** Started on  Wed Oct 10 18:32:29 2012 franck chevallier
** Last update Thu Apr 11 15:54:35 2013 franck chevallier
*/

#include "raytracer.h"

int	sign(char *str)
{
  int cnt;
  int sign;

  cnt = 0;
  sign = 1;
  while (str[cnt] == '-' || str[cnt] == '+')
    {
      if (str[cnt] == '-')
	{
	  sign = sign * -1;
	}
      cnt = cnt + 1;
    }
  return (sign);
}

int	my_getnbr(char *str)
{
  int	result;
  int	index;
  int	s;

  index = 0;
  result = 0;

  if (str == NULL)
    manage_error("Missing parameters");
  s = sign(str);
  while (str[index] == '-' ||
	 str [index] == '+'|| (str[index] > 47 && str[index] < 58))
    {
      if (str[index] > 47 && str[index] < 58)
	result = (result * 10) + str[index] - 48;
      index = index + 1;
    }
  result = result * s;
  return (result);
}
