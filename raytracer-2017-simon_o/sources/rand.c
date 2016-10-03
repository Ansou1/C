/*
** rand.c for rand in /home/simon_o//raytracer-2017-simon_o/rt/sources
**
** Made by antoine simon
** Login   <simon_o@epitech.net>
**
** Started on  Sat Jun  8 16:19:12 2013 antoine simon
** Last update Sat Jun  8 16:19:27 2013 antoine simon
*/

#include <unistd.h>
#include <stdlib.h>
#include "raytracer.h"

int	get_rand(int min, int max)
{
  if (max - min == 0)
    return (0);
  return ((rand() % (max - min)) + min);
}

