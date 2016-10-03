/*
** aff_matches.c for allum1 in /home/daguen_s//myalum1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Feb 10 19:22:35 2013 simon daguenet
** Last update Sun Feb 10 19:59:15 2013 simon daguenet
*/

#include "allum1.h"

void		aff_match(int nb_match, int nbr)
{
  static int	value = 1;
  int		i;

  my_putstr("\033[36m line ");
  if (value < 10)
    my_putchar('0');
  my_put_nbr(value);
  my_putstr(" ->  \033[37m");
  if (nb_match < 10)
    my_putchar('0');
  my_put_nbr(nb_match);
  my_putstr(": matches   ");
  if (nb_match > 0)
    {
      i = value;
      while (i++ < (nbr + 1))
        my_putstr(" ");
    }
  i = 0;
  while (i++ < nb_match)
    my_putstr("\033[35m|\033[37m");
  my_putchar('\n');
  value++;
  if (value == (nbr + 1))
    value = 1;
}
