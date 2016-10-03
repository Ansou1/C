/*
** my_strlen.c for raytracer in /home/cheval_y//raytracer/sources/lib_functions
** 
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
** 
** Started on  Tue Apr  9 15:50:59 2013 franck chevallier
** Last update Tue Apr  9 15:51:13 2013 franck chevallier
*/

#include "raytracer.h"

int	my_strlen(char *str)
{
  int	n;

  n = 0;
  while (str[n])
    n++;
  return (n);
}
