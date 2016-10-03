/*
** player.c for allum1 in /home/daguen_s//myalum1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Feb 10 19:23:48 2013 simon daguenet
** Last update Mon Feb 11 09:40:41 2013 simon daguenet
*/

#include "allum1.h"

int	outc(int c)
{
  write(1, &c, 1);
  return (0);
}

void	my_clear_screen()
{
  char	*cl;

  cl = tgetstr("cl", NULL);
  if (cl == NULL)
    my_put_error_term(2);
  tputs(cl, 0, outc);
}

int		delete_match(t_list *list, int line, int matches, int all)
{
  t_list	*tmp;

  tmp = list;
  while (--line)
    tmp = tmp->next;
  if (tmp->nbr >= matches)
    tmp->nbr = tmp->nbr - matches;
  if (all == 1)
    {
      my_putstr("\033[31m");
      my_putstr("You LOSE!!!\n");
      my_putstr("\033[37m");
      return (0);
    }
  return (0);
}

void	round_player(t_list *list, int i, int nbr_line)
{
  int	line_nbr;
  int	matches_nbr;
  int	check_match;

  if (i != 0)
    my_putstr("\n\033[31mplayer\033[37m\n\n");
  check_match = get_all_match(list);
  if (check_match > 0)
    {
      aff_list(list, nbr_line);
      line_nbr = get_line_player(list, nbr_line);
      matches_nbr = get_matches_player(list, line_nbr);
      delete_match(list, line_nbr, matches_nbr, check_match);
    }
}

void	gere_player(t_list *list, int player, int nbr_line)
{
  int	check_match;

  check_match = get_all_match(list);
  if (player == 1)
    {
      while (check_match > 0)
        {
          round_player(list, check_match, nbr_line);
          check_match = get_all_match(list);
          round_ia(list, check_match, nbr_line);
          check_match = get_all_match(list);
        }
    }
  if (player == 2)
    {
      while (check_match > 0)
        {
          round_ia(list, check_match, nbr_line);
          check_match = get_all_match(list);
          round_player(list, check_match, nbr_line);
          check_match = get_all_match(list);
        }
    }
  my_putstr("\n\033[31mEnd of game\033[37m\n\n");
}
