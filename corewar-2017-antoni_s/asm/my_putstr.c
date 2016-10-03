/*
** tmy_swap.c for tmy_swap.c in /home/corrad_f//tst/Jour4
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Thu Oct  4 11:13:34 2012 florian corradin
** Last update Sat Mar 16 18:32:44 2013 simon daguenet
*/

#include "asm.h"

void	my_putstr(char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str = str + 1;
    }
}
