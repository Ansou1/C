/*
** my_putnbr.c for my_printf in /home/antoni_s//Cproject/Unix/Printf/commit
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.net>
** 
** Started on  Thu Nov 15 21:51:25 2012 sebastien antonico
** Last update Thu Mar 21 09:20:42 2013 sebastien antonico
*/

#include "my.h"

int	my_putnbr(int i, char flag)
{
  int	rtrn;

  rtrn = 0;
  if ((flag == '+' || flag == ' ') && i >= 0)
    {
      rtrn += my_putchar(flag);
      flag = 0;
    }
  if (i < 0)
    return (my_putchar('-') + my_putnbr(i * -1, 0));
  if (i > 9)
    return (rtrn + my_putnbr(i / 10, flag) + my_putchar((i % 10) + 48));
  return (rtrn + my_putchar((i % 10) + 48));
}
