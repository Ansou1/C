/*
** allum1.c for allum1 in /home/daguen_s//myalum1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Jan 28 09:27:24 2013 simon daguenet
** Last update Sun Feb 10 19:58:03 2013 simon daguenet
*/

#include "allum1.h"

int		main(int ac, char **av, char **env)
{
  t_list	*list;
  int		player;
  int		nbr_player;
  int		nbr_line;

  check_ac_av(ac, av, env);
  nbr_line = get_nbr_of_line();
  list = my_params_in_list(nbr_line);
  my_rev_list(&list);
  aff_list(list, nbr_line);
  nbr_player = get_nbr_of_player();
  if (nbr_player == 1)
    {
      player = get_player();
      gere_player(list, player, nbr_line);
    }
  else
    gere_player_vs_player(list, nbr_line);
  free_list(list);
  return (0);
}
