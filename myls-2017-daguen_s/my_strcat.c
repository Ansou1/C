/*
** my_strcat.c for strcat in /home/daguen_s//Jour_06/test
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Tue Oct  9 23:00:23 2012 simon daguenet
** Last update Tue Nov 27 14:26:41 2012 simon daguenet
*/
#include "my_ls.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	lenght;

  lenght = 0;
  lenght = my_strlen(dest);
  i = 0;
   while (src[i] != '\0')
    {
      dest[lenght + i] = src[i];
      i = i + 1;
    }
  dest[lenght + i] = '\0';
  return (dest);
}
