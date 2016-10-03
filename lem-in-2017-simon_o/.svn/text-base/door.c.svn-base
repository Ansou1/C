/*
** door.c for lem_in in /home/daguen_s//final_lemin/tar
**
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
**
** Started on  Tue Apr 23 17:11:25 2013 simon daguenet
** Last update Sun Apr 28 18:32:43 2013 simon daguenet
*/

#include "lemin.h"

int		check_door(char *s, int door)
{
  static int	cmd_1 = 0;
  static int	cmd_2 = 0;

  if ((my_strstr(s, "##start") != NULL) && cmd_1 == 0)
    {
      cmd_1 = 1;
      door = door + 1;
    }
  else if ((my_strstr(s, "##end") != NULL) && cmd_2 == 0)
    {
      cmd_2 = 1;
      door = door + 2;
    }
  return (door);
}

void	result_door(int door)
{
  if (door != 3)
    {
      if (door == 0)
	my_puterror("\033[1;31mIt miss end and start\033[0;m\n");
      else
	(door == 2) ? my_puterror(ERROR1) : my_puterror(ERROR2);
    }
}
