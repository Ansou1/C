/*
** get_k_min.c for rtv1 in /home/daguen_s//prepa_rtv1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Mar 17 16:13:08 2013 simon daguenet
** Last update Sun Mar 17 16:14:38 2013 simon daguenet
*/

#include "rtv1.h"

double	get_min_in_two(double a, double b)
{
  if (a > 0 && b > 0)
    {
      if (a <= b)
	return (a);
      else
	return (b);
    }
  else
    {
      if (a > 0 && b < 0)
	return (a);
      else if (a < 0 && b > 0)
	return (b);
      else
	return (-1.0);
    }
}

int		get_k_min(double a, double b, double c, double d)
{
  double	min1;
  double	min2;
  double	result;

  min1 = get_min_in_two(a, b);
  min2 = get_min_in_two(c, d);
  result = get_min_in_two(min1, min2);
  if (result == a)
    return (RED);
  else if (result == b)
    return (BLUE);
  else if (result == c)
    return (YELLOW);
  else if (result == d)
    return (GREEN);
}

