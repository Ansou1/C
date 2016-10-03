/*
** tmy_swap.c for tmy_swap.c in /home/corrad_f//tst/Jour4
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Thu Oct  4 11:13:34 2012 florian corradin
** Last update Sat Mar 16 18:34:17 2013 simon daguenet
*/

#include "asm.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
