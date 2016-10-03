/*
** my_put_in_list.c for liste chainées in /home/elegbe_m//programmation/tests_chained_lists
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Tue Oct 23 13:51:06 2012 martial elegbede
** Last update Thu Nov  1 14:57:06 2012 martial elegbede
*/

#include <stdlib.h>
#include "my.h"
#include "my_chained_list.h"

int	my_put_in_stack(t_stack **stack, t_list	*list)
{
  t_stack	*elem;

  if (list == NULL)
    return (-1);
  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (-1);
  elem->op = list->str;
  elem->op_prio = list->op_prio;
  elem->next = *stack;
  *stack = elem;
  return (0);
}

int	my_put_nb_in_list(t_list **list, char *nbr)
{
  t_list	*elem;
  t_list	*tmp;

  if (nbr == NULL)
    return (-1);
  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (-1);
  elem->content = NBRLIST;
  elem->nbr = nbr;
  elem->next = NULL;
  if (*list == NULL)
    *list = elem;
  else
    {
      tmp = *list;
      while (tmp->next != NULL)
  	{
  	  tmp = tmp->next;
  	}
      tmp->next = elem;
    }
  return (0);
}

int	my_put_str_in_list(t_list **list, char str)
{
  t_list	*elem;
  t_list	*tmp;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (-1);
  elem->content = STRLIST;
  elem->str = str;
  elem->next = NULL;
  if (*list == NULL)
    *list = elem;
  else
    {
      tmp = *list;
      while (tmp->next != NULL)
	{
	  tmp = tmp->next;
	}
      tmp->next = elem;
    }
  return (0);
}
