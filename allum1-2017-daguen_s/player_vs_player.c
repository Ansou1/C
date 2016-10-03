/*
** player_vs_player.c for allum1 in /home/daguen_s//myalum1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Feb 10 19:18:57 2013 simon daguenet
** Last update Mon Feb 11 09:38:43 2013 simon daguenet
*/

#include "allum1.h"

int		delete_match_pp(t_list *list, int line, int matches)
{
  t_list	*tmp;

  tmp = list;
  while (--line)
    tmp = tmp->next;
  if (tmp->nbr >= matches)
    tmp->nbr = tmp->nbr - matches;
  return (0);
}

void	round_player_pp(t_list *list, int nbr_line)
{
  int	line_nbr;
  int	matches_nbr;
  int	check_match;

  check_match = get_all_match(list);
  if (check_match > 0)
    {
      aff_list(list, nbr_line);
      line_nbr = get_line_player(list, nbr_line);
      matches_nbr = get_matches_player(list, line_nbr);
      delete_match_pp(list, line_nbr, matches_nbr);
    }
}

int	gere_player_vs_player(t_list *list, int nbr_line)
{
  int	check_match;
  int	bol;

  bol = 0;
  check_match = get_all_match(list);
  while (check_match > 0)
    {
      my_putstr("\n\033[31m PLAYER 1\033[37m\n");
      round_player_pp(list, nbr_line);
      check_match = get_all_match(list);
      if (check_match > 0)
        my_putstr("\n\033[31m PLAYER 2\033[37m\n");
      if (check_match == 0)
        {
          my_putstr("\n\033[31m PLAYER 1 LOSE \033[37m\n");
          bol = 1;
        }
      round_player_pp(list, nbr_line);
      check_match = get_all_match(list);
      if (check_match == 0 && bol == 0)
        my_putstr("\n\033[31m PLAYER 2 LOSE \033[37m\n");
    }
  my_putstr("\n\033[31mEnd of game\033[37m\n\n");
  return (0);
}
