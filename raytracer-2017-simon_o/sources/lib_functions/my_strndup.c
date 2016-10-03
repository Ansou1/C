/*
** my_strndup.c for my_strndup in /home/cheval_y/
** 
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
** 
** Started on  Fri Oct 19 15:08:09 2012 franck chevallier
** Last update Thu Apr 11 15:54:34 2013 franck chevallier
*/

#include "raytracer.h"

char	*my_strndup(char *str, int size)
{
  char	*dest;
  int	index;

  index = 0;
  while (str[index])
    index = index  + 1;
  if (index < size)
    {
      if ((dest = malloc(index + 1)) == NULL)
	return (NULL);
    }
  else
    {
      if ((dest = malloc(size + 1)) == NULL)
	return (NULL);
    }
  index = 0;
  while (str[index] && index < size)
    {
      dest[index] = str[index];
      index = index + 1;
    }
  dest[index] = '\0';
  return (dest);
}
