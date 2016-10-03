/*
** my_revstr.c for lib in /home/corrad_f//lib
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sun Dec  9 11:26:53 2012 florian corradin
** Last update Sat Mar 16 18:33:26 2013 simon daguenet
*/

#include "asm.h"

char	*my_revstr(char *str)
{
  char	swap;
  int	i;
  int	len;

  i = 0;
  len = my_strlen(str);
  if (len > 0)
    while (i < len / 2)
      {
	swap = str[i];
	str[i] = str[len - 1 - i];
	str[len - i - 1] = swap;
	i = i + 1;
      }
  return (str);
}
