/*
** list_double.c for 42sh in /home/corrad_f//myselect-2017-corrad_f
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Tue Feb 26 08:42:13 2013 florian corradin
** Last update Sun May 26 14:09:37 2013 antoine simon
*/

#include "42.h"

void		my_get_list_double(t_com **list)
{
  t_com		*elem;
  static int	t = 0;

  elem = malloc(sizeof (*elem));
  check_malloc(elem);
  elem->file = NULL;
  elem->commande = NULL;
  elem->redir = 0;
  elem->next = *list;
  if (t == 0)
    elem->previous = elem;
  else
    (*list)->previous = elem;
  *list = elem;
}

t_com	*recup_list(int size)
{
  int	i;
  t_com	*ret;

  ret = NULL;
  i = 0;
  while (i < size)
    {
      my_get_list_double(&ret);
      i++;
    }
  ret->previous = NULL;
  return (ret);
}

void	my_free_list(t_com *list)
{
  t_com	*save;

  if (list != NULL)
    {
      save = list->next;
      while (list != NULL)
	{
	  my_free_tab(list->commande);
	  free(list->file);
	  free(list);
	  list = save;
	  if (list != NULL)
	    save = list->next;
	}
    }
}
