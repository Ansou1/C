/*
** my_strlen.c for strlen in /home/daguen_s//myownprintf
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Tue Nov 13 11:32:45 2012 simon daguenet
** Last update Sun Nov 18 18:10:37 2012 simon daguenet
*/
#include "my_printf.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
