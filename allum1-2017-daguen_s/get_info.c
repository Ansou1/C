/*
** get_info.c for allum1 in /home/daguen_s//myalum1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Feb 10 19:05:28 2013 simon daguenet
** Last update Mon Feb 11 09:36:20 2013 simon daguenet
*/

#include "allum1.h"

int	get_player()
{
  int	player;
  char	buffer[4096];
  int	ret;

  player = 0;
  while (42)
    {
      my_putstr("\033[32m");
      my_putstr("Do you want to be the first player?\nYes(1), No(2): ");
      my_putstr("\033[37m");
      ret = read(0, buffer, 4095);
      if (ret == -1 || ret == 0)
	my_put_error(4);
      buffer[ret] = '\0';
      player = my_getnbr(buffer);
      if (player == 1 || player == 2)
	return (player);
    }
}

int	get_line_player(t_list *list, int nbr_line)
{
  int	line_nbr;
  char	buffer[4096];
  int	ret;

  line_nbr = 0;
  while (42)
    {
      my_putstr("\033[32m");
      my_putstr("On which line do you want to take matches?\n");
      my_putstr("\033[37m");
      ret = read(0, buffer, 4095);
      if (ret == -1 || ret == 0)
	my_put_error(4);
      buffer[ret] = '\0';
      line_nbr = my_getnbr(buffer);
      if (line_nbr > 0 && line_nbr <= nbr_line)
	if (get_line_possible(list, line_nbr))
	  return (line_nbr);
    }
}

int	get_matches_player(t_list *list , int line_nbr)
{
  int	matches;
  char	buffer[4096];
  int	ret;

  matches = 0;
  while (42)
    {
      my_putstr("\033[32m");
      my_putstr("How many matches?\n");
      my_putstr("\033[37m");
      ret = read(0, buffer, 4095);
      if (ret == -1 || ret == 0)
	my_put_error(4);
      buffer[ret] = '\0';
      matches = my_getnbr(buffer);
      if (matches > 0 && matches < 40)
	if (get_match_possible(list, matches, line_nbr))
	  return (matches);
    }
}

int	get_nbr_of_player()
{
  int	nbr_player;
  char	buffer[4096];
  int	ret;

  nbr_player = 0;
  while (42)
    {
      my_putstr("\033[32m");
      my_putstr("How many players?\nONE(1), TWO(2): ");
      my_putstr("\033[37m");
      ret = read(0, buffer, 4095);
      if (ret == -1 || ret == 0)
	my_put_error(4);
      buffer[ret] = '\0';
      nbr_player = my_getnbr(buffer);
      if (nbr_player == 1 || nbr_player == 2)
	return (nbr_player);
    }
}

int	get_nbr_of_line()
{
  int	nbr_line;
  char	buffer[4096];
  int	ret;

  nbr_line = 0;
  while (42)
    {
      my_putstr("\033[32m");
      my_putstr("How many lines of matches?\nBetween 4 and 20: ");
      my_putstr("\033[37m");
      ret = read(0, buffer, 4095);
      if (ret == -1 || ret == 0)
	my_put_error(4);
      buffer[ret] = '\0';
      nbr_line = my_getnbr(buffer);
      if (nbr_line >= 4 && nbr_line <= 20)
	return (nbr_line);
    }
}
