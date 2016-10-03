/*
** my_strdup.c for libmy in /home/elegbe_m//programmation/fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Wed Oct 17 10:51:56 2012 martial elegbede
** Last update Wed Oct 17 11:34:03 2012 martial elegbede
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  int	size;
  char	*dest;

  size = my_strlen(src);
  dest = malloc(size + 1);
  dest[size] = 0;
  if (dest == NULL)
    return (dest);
  my_strcpy(dest, src);
  return (dest);
}
