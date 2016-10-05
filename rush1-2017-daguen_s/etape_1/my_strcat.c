/*
** my_strcat.c for strcat in /home/daguen_s//Jour_06/test
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Tue Oct  9 23:00:23 2012 simon daguenet
** Last update Sun Dec  2 16:51:30 2012 simon daguenet
*/
#include "get_next_line.h"

char	*my_strcat1(char *dest, char *src)
{
  int	i;
  int	lenght;

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
