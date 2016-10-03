/*
** convert_base.c for convert in /home/daguen_s//Prog_Elem
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Wed Jan 23 14:19:41 2013 simon daguenet
** Last update Fri Mar 29 14:06:33 2013 simon daguenet
*/

#include "asm.h"

int	get_i_from_base(char c, char *base_from)
{
  int	i;

  i = 0;
  while (base_from[i] != c && base_from[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

long	convert_base_from_to_10(char *nbr, char *base_from)
{
  int	base_size;
  long	res;
  int	i;
  int	puiss;
  long	result;

  base_size = my_strlen(base_from);
  res = 0;
  i = 0;
  puiss = my_strlen(nbr) - 1;
  while (i < my_strlen(nbr))
    {
      result =  my_power_rec(base_size, puiss);
      res = res + (get_i_from_base(nbr[i], base_from) * result);
      i = i + 1;
      puiss = puiss - 1;
    }
  return (res);
}

char	*convert_from_10_to_base(long long nbr, char *base_to)
{
  char	*res;
  int	i;
  int	base_size;
  int	a;

  res = malloc(33);
  check_malloc(res);
  i = 0;
  base_size = my_strlen(base_to);
  a = 0;
  while (nbr > 0)
    {
      a = nbr % base_size;
      nbr = nbr / base_size;
      res[i] = base_to[a];
      i = i + 1;
    }
  res[i] = '\0';
  my_revstr(res);
  return (res);
}

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
  long	nb10;

  nb10 = convert_base_from_to_10(nbr, base_from);
  return (convert_from_10_to_base(nb10, base_to));
}
