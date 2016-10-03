/*
** ia.c for allum1 in /home/daguen_s//myalum1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Feb 10 19:20:39 2013 simon daguenet
** Last update Sun Feb 10 20:11:20 2013 simon daguenet
*/

#include "allum1.h"

int	algo_ia(t_list *list, int check_match, int nbr_line)
{
  if (nbr_line == 1 && check_match != 1)
    get_victory(list);
  else if (check_match == 1)
    lose_ia(list);
  else if (nbr_line == 2)
    get_victory_pair(list, check_match);
  else if (nbr_line == 3)
    get_victory_third(list, check_match);
  else if ((nbr_line % 2 == 0) && (nbr_line > 3))
    nbr_line_pair(list);
  else if ((nbr_line % 2 != 0) && (nbr_line > 3))
    nbr_line_impair(list);
  else
    lose_with_pair(list);
  check_end(check_match);
  return (0);
}

void	round_ia(t_list *list, int i, int nbr_line)
{
  int	check_match;
  int	nbr_line1;

  if (i != 0)
    my_putstr("\n\033[31mIA\033[37m\n\n");
  check_match = get_all_match(list);
  if (check_match > 0)
    {
      aff_list(list, nbr_line);
      nbr_line1 = nbr_line_in_list_current(list);
      algo_ia(list, check_match, nbr_line1);
    }
}
