/*
** for_floriant.c for 42sh in /home/daguen_s/
**
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
**
** Started on  Thu May  2 16:56:36 2013 simon daguenet
** Last update Thu May 23 15:00:06 2013 simon daguenet
*/

#include "42.h"
#include "script.h"

void		my_put_list_cond(t_cond **list, char *data, int type)
{
  t_cond	*elem;
  t_cond	*tmp;

  elem = malloc(sizeof(*elem));
  elem->data = my_strdup(data);
  elem->type = type;
  elem->next = NULL;
  if (*list != NULL)
    {
      tmp = *list;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elem;
    }
  else
    *list = elem;
}

int		get_size(char *str)
{
  int		i;

  i = 0;
  while (str[i] != ']' && str[i])
    i++;
  if (str[i] == '\0')
    {
      g_stop_script = -1;
      return (0);
    }
  return (i);
}

t_cond		*get_cond_list(char *s)
{
  t_cond	*list;
  int		i;
  char		*val;

  list = NULL;
  i = 0;
  while (s[i])
    {
      if (s[i] == '[')
	{
	  val = get_str_sep(&s[i + 1], ']');
	  my_put_list_cond(&list, val, 1);
	}
      else if ((s[i] == '|' || s[i] == '&') &&
	       (s[i + 1] == '|' || s[i + 1] == '&'))
	{
	  if (s[i] == '|')
	    my_put_list_cond(&list, NULL, 3);
	  else
	    my_put_list_cond(&list, NULL, 2);
	}
      i++;
    }
  return (list);
}
