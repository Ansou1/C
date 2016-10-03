/*
** manage_error.c for raytracer in /home/cheval_y//raytracer/sources/lib_functions
** 
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
** 
** Started on  Tue Apr  9 15:51:23 2013 franck chevallier
** Last update Tue Apr  9 15:51:38 2013 franck chevallier
*/

#include "raytracer.h"

void	manage_error(char *str)
{
  my_putstr("\033[31m");
  my_putstr(str);
  my_putstr("\n\033[0m");
  exit(EXIT_FAILURE);
}
