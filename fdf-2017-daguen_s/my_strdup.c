/*
** my_strdup.c for my_strdup in /home/daguen_s//Jour_06/test
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Wed Oct 10 14:29:46 2012 simon daguenet
** Last update Sun Dec  2 23:16:04 2012 simon daguenet
*/

#include <stdlib.h>
#include "my_fdf.h"

char	*my_strdup(char *src)
{
  int	i;
  char	j;
  char	*chaine;

  i = 0;
  i = my_strlen(src);
  chaine = malloc(i + 1);
  if (chaine == NULL)
    return (NULL);
  j = 0;
  while (src[j] != '\0')
    {
      chaine[j] = src[j];
      j = j + 1;
    }
  chaine[j] = '\0';
  return (chaine);
}
