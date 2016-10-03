/*
** reg.c for reg in /home/efilon/Projects/Cproject/Corewar
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Wed Mar 20 00:22:04 2013 sebastien antonico
** Last update Sun Mar 31 01:06:01 2013 sebastien antonico
*/

#include <unistd.h>
#include <stdlib.h>
#include "op.h"
#include "libmy/my.h"

int	tab_to_int(unsigned char *tab, int regsize)
{
  int	nb;
  int	i;
  char	c;

  nb = 0;
  i = 0;
  while (i < 32 && i < regsize * 8)
    {
      if (i % 8 == 0)
	c = tab[regsize - regsize + (i / 8)];
      nb <<= 1;
      if ((c & 0x80) != 0)
	nb += 1;
      c <<= 1;
      i++;
    }
  return (nb);
}

void	write_int(unsigned char *r, int regsize, int v)
{
  int	i;

  i = 0;
  my_memset(r, regsize);
  while (i < 4 && i < regsize)
    {
      r[regsize - 1 - i] = ((v & 0xFF));
      v >>= 8;
      i++;
    }
}
