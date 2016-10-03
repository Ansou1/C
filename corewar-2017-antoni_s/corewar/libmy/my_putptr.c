/*
** my_putptr.c for my_printf in /home/antoni_s//Cproject/Unix/Printf/commit
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.net>
** 
** Started on  Fri Nov 16 11:46:05 2012 sebastien antonico
** Last update Thu Mar 21 09:23:20 2013 sebastien antonico
*/

#include "my.h"

int	my_putptr(unsigned long i)
{
  if (i == 0)
    return (my_putstr("(nil)"));
  return (my_putstr("0x") + my_putnbr_us(i, 'x', 0, 0));
}
