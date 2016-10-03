/*
** my_putnbrbase.c for my_putnbrbase in /home/efilon/Projects/Cproject/Corewar/libmy
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Mon Mar 18 15:39:28 2013 sebastien antonico
** Last update Mon Mar 18 17:04:16 2013 sebastien antonico
*/

#include "my.h"

int	my_putnbrXX(int nb)
{
  char	*base;

  base = "0123456789ABCDEF";
  my_putchar(base[(nb / 16) % 16]);
  my_putchar(base[nb % 16]);
  return (1);
}
