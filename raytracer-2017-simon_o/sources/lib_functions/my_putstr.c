/*
** my_putstr.c for raytracer in /home/cheval_y//raytracer/sources/lib_functions
** 
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
** 
** Started on  Tue Apr  9 15:50:28 2013 franck chevallier
** Last update Tue Apr  9 15:50:48 2013 franck chevallier
*/

#include "raytracer.h"

void	my_putchar(char c)
{
  write (1, &c, 1);
}

void	my_putstr(char *str)
{
  int	n;

  n = 0;
  while (str[n])
    {
      my_putchar(str[n]);
      n++;
    }
}
