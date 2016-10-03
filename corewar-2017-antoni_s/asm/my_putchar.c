/*
** my_putchar.c for my_putchar.c in /home/corrad_f/
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Tue Oct  9 11:53:33 2012 florian corradin
** Last update Sat Mar 16 18:31:08 2013 simon daguenet
*/

#include "asm.h"

void	my_putchar(char c)
{
  write(0, &c, 1);
}

