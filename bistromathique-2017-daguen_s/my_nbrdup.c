/*
** my_nbrdup.c for bistrmathique in /home/elegbe_m//programmation/evalexp
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Tue Oct 30 12:10:50 2012 martial elegbede
** Last update Sat Nov 10 17:02:09 2012 martial elegbede
*/

#include <stdlib.h>
#include "my.h"

int	my_char_isbase(char c, char *base)
{
  while (*base)
    {
      if (c == *base)
	return (1);
      base = base + 1;
    }
  return (0);
}

int	my_nbr_charnb(char *str, char *base)
{
  int	i;

  i = 0;
  while (my_char_isbase(str[i], base))
    i = i + 1;
  return (i);
}

char	*my_nbrdup(char *str, char *base)
{
  char	*nbr;
  int	char_nb;
  int	i;

  i = 0;
  while (*str == *base && my_char_isbase(str[1], base))
    str = str + 1;
  char_nb = my_nbr_charnb(str, base);
  nbr = malloc(char_nb + 1);
  if (nbr == NULL)
    return (NULL);
  nbr[char_nb] = 0;
  while (i < char_nb)
    {
      nbr[i] = str[i];
      i = i + 1;
    }
  return (nbr);
}

void	ptr_swap(char **p1, char **p2)
{
  char	*swap;

  swap = *p1;
  *p1 = *p2;
  *p2 = swap;
}
