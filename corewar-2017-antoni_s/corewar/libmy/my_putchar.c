/*
** my_putchar.c for my_printf in /home/antoni_s//Cproject/Unix/Printf/commit
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.net>
** 
** Started on  Thu Nov 15 21:47:30 2012 sebastien antonico
** Last update Thu Mar 21 09:20:04 2013 sebastien antonico
*/

#include <unistd.h>

int	my_putchar(char c)
{
  if (c == 0)
    return (0);
  return (write(1, &c, 1));
}
