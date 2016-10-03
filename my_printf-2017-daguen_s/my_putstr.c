/*
** my_putstr.c for my_putstr in /home/daguen_s//afs/rendu/piscine/Jour_04
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Thu Oct  4 11:47:19 2012 simon daguenet
** Last update Sun Nov 18 18:09:01 2012 simon daguenet
*/
#include <stdio.h>
#include <stdlib.h>
#include "my_printf.h"

int	my_putstr(char	*str)
{
  int	i;

  i = 0;
  if (str == NULL)
    {
      return (my_putstr("(null)"));
    }
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (i);
}
