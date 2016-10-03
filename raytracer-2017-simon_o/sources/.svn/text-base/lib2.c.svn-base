/*
** lib2.c for lib in /home/simon_o//raytracer-2017-simon_o/rt/sources
**
** Made by antoine simon
** Login   <simon_o@epitech.net>
**
** Started on  Sat Jun  8 15:44:49 2013 antoine simon
** Last update Sat Jun  8 15:45:31 2013 antoine simon
*/

#include <unistd.h>
#include <stdlib.h>
#include "raytracer.h"

void	my_puterr(char *str)
{
  write(2, str, my_strlen(str));
  exit(-1);
}

char	*my_strdup(char *src)
{
  char	*mem;
  int	i;

  if ((mem = malloc(my_strlen(src) + 1)) == NULL)
    my_puterr("Fail malloc\n");
  i = 0;
  while (src[i])
    {
      mem[i] = src[i];
      i++;
    }
  mem[i] = 0;
  return (mem);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i])
    {
      if (s1[i] - s2[i] != 0)
	return (s1[i] - s2[i]);
      i++;
    }
  return (s1[i] - s2[i]);
}

int	is_alpha_num(char c)
{
  if (c >= 'a' && c <= 'z')
    return (1);
  if (c >= 'A' && c <= 'Z')
    return (1);
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

char	to_lower(char c)
{
  if (c >= 'A' && c <= 'Z')
    return (c + 32);
  return (c);
}
