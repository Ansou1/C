/*
** clean_command.c for 42sh in /home/daguen_s//42sh-2017-daguen_s
**
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
**
** Started on  Thu May  2 10:07:32 2013 simon daguenet
** Last update Wed May  8 14:24:18 2013 florian corradin
*/

#include "42.h"

int	check_nbr(char *commande)
{
  int	value;

  value = my_atoi(commande);
  if (value == 1 || (value <= 4 && value >= 16))
    return (1);
  return (0);
}

void	get_cmd2(int nbr)
{
  if (nbr == 10)
    g_msg_error = my_strdup("User signal 1");
  else if (nbr == 11)
    g_msg_error = my_strdup("Segmentation fault");
  else if (nbr == 12)
    g_msg_error = my_strdup("User signal 2");
  else if (nbr == 13)
    g_msg_error = my_strdup("Broken pipe");
  else if (nbr == 14)
    g_msg_error = my_strdup("Alarm clock");
  else if (nbr == 16)
    g_msg_error = my_strdup("Stack limit exceeded");
}

void	get_cmd(char *command1)
{
  int	nbr;

  nbr = my_atoi(&command1[1]);
  if (nbr == 1)
    g_msg_error = my_strdup("Hangup");
  else if (nbr == 4)
    g_msg_error = my_strdup("Illegal instruction");
  else if (nbr == 5)
    g_msg_error = my_strdup("Trace/BPT trap");
  else if (nbr == 6)
    g_msg_error = my_strdup("Abort");
  else if (nbr == 7)
    g_msg_error = my_strdup("Bus error");
  else if (nbr == 8)
    g_msg_error = my_strdup("Floating exception");
  else if (nbr == 9)
    g_msg_error = my_strdup("Killed");
  else
    get_cmd2(nbr);
}

char	**change_command(char **command)
{
  if (my_tablen(command) == 3)
    {
      if (my_str_comp(command[2], "0") == 1)
	{
	  if (command[1][0] == '-' && is_strnum(&command[1][1]))
	    {
	      if (check_nbr(&command[1][1]))
		return (command);
	      free(command[0]);
	      command[0] = my_strdup("echo");
	      get_cmd(command[1]);
	      free(command[2]);
	      command[2] = NULL;
	      free(command[1]);
	      command[1] = my_strdup("-n");
	      return (command);
	    }
	  else
	    return (command);
	}
      else
	return (command);
    }
  else
    return (command);
}

t_com	*clean_command(t_com *list)
{
  t_com	*tmp;

  tmp = list;
  if (!(count_pipe(list)))
    return (list);
  while (list)
    {
      if (list->commande != NULL)
	if (list->commande[0] != NULL)
	  if ((my_strncmp(list->commande[0], "/bin/kill", 9) == 1) ||
	      (my_strncmp(list->commande[0], "kill", 4) == 1))
	    list->commande = change_command(list->commande);
      list = list->next;
    }
  return (tmp);
}
