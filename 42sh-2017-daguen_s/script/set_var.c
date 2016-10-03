/*
** set_var.c for infectsh in /home/corrad_f//projet/infect/script
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Tue Apr  9 14:32:29 2013 florian corradin
** Last update Sat May 11 10:26:23 2013 florian corradin
*/

#include "42.h"
#include "script.h"

int	is_in_list(char *name, t_var **list)
{
  t_var	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (my_str_comp(tmp->name, name) == 1)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

void	set_var(char *name, char *value, t_var **list)
{
  t_var	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (my_str_comp(tmp->name, name) == 1)
	{
	  free(tmp->val);
	  tmp->val = my_strdup(value);
	}
      tmp = tmp->next;
    }
}
