/*
** my_putchar.c for putchar in /home/daguen_s/
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Wed Oct 10 09:50:35 2012 simon daguenet
** Last update Sun Nov 18 18:08:43 2012 simon daguenet
*/
#include "my_printf.h"

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (1);
}
