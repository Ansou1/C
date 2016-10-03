/*
** my_putchar.c for my_putchar.c in /home/corrad_f/
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Tue Oct  9 11:53:33 2012 florian corradin
** Last update Sun May 12 13:45:21 2013 florian corradin
*/

#include "42.h"

int	my_putchar(unsigned char c)
{
  return (write (1, &c, 1));
}

void	my_putstr(char *str)
{
  if (str != NULL)
    while (*str && my_putchar(*str++) != -1);
}

int	my_putvoidc(const void *c)
{
  return (write (1, c, 1));
}

void	my_putvoid(void *str)
{
  while (str && my_putvoidc(str++) != -1);
}
