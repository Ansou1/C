/*
** new_hist.c for 42sh in /home/daguen_s//42sh-2017-daguen_s
**
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
**
** Started on  Thu May 23 09:54:32 2013 simon daguenet
** Last update Fri May 24 15:40:10 2013 simon daguenet
*/

#include "42.h"

int	is_number(char *str)
{
  int	i;
  int	result;

  i = 0;
  result = 1;
  while (str[i] != '\0')
    {
      if (!(str[i] >= 48 && str[i] <= 57))
	result = 0;
      i++;
    }
  return (result);
}

t_hist	*get_cmd_for_history(t_hist *list, char *cmd)
{
  if (cmd[0] != '\0')
    {
      if (list != NULL)
	{
	  if (strcmp(list->data, cmd) != 0)
	    list = put_cmd_in_history(list, cmd);
	}
      else
	list = put_cmd_in_history(list, cmd);
    }
  return (list);
}

int		nbr_in_list_histo()
{
  t_hist	*list;
  int		nbr;

  nbr = 0;
  list = info.hist;
  while (list)
    {
      nbr++;
      list = list->next;
    }
  return (nbr);
}

t_hist		*put_cmd_in_history(t_hist *l, char *cmd)
{
  static int	nbr = 1;
  t_hist	*elem;
  time_t	timestamp;
  struct tm	*t;

  timestamp = time(NULL);
  t = localtime(&timestamp);
  if ((elem = malloc(sizeof(*elem))) != NULL)
    {
      while (l != NULL && l->previous != NULL && (l = l->previous));
      elem->previous = NULL;
      elem->hr = t->tm_hour;
      elem->min = t->tm_min;
      elem->nbr = nbr++;
      elem->data = my_strdup(cmd);
      if (l != NULL)
	{
	  elem->next = l;
	  l->previous = elem;
	}
      else
	elem->next = NULL;
      l = elem;
    }
  return (l);
}

char	*get_cmd_all()
{
  char	*command_line;

  command_line = NULL;
  command_line = get_next_line(0);
  command_line = ex_history(command_line);
  return (command_line);
}

