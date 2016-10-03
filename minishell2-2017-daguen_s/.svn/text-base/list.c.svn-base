/*
** list.c for mysh in /home/daguen_s//secminishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar  9 12:03:59 2013 simon daguenet
** Last update Sat Mar  9 12:05:37 2013 simon daguenet
*/

#include "mysh.h"

void	aff_list(t_list **list)
{
  while (*list)
    {
      my_putstr((*list)->data);
      my_putchar('\n');
      *list = (*list)->next;
    }
}

int		my_rev_list(t_list **begin)
{
  t_list	*pprev;
  t_list	*pdebut;
  t_list	*psuivant;

  pprev = NULL;
  pdebut = NULL;
  psuivant = NULL;
  if (NULL == begin)
    {
      return (1);
    }
  pdebut = *begin;
  while (NULL != pdebut)
    {
      psuivant = pdebut->next;
      pdebut->next = pprev;
      pprev = pdebut;
      pdebut = psuivant;
    }
  *begin = pprev;
  return (0);
}

void		free_list(t_list *list)
{
  t_list	*tmp;

  while (list)
    {
      tmp = list;
      xfree(tmp->data);
      xfree(tmp);
      list = list->next;
    }
}

t_list		*my_put_in_list(t_list **list, char *data)
{
  t_list	*elem;

  elem = xmalloc(sizeof(*elem));
  elem->data = my_strdup(data);
  elem->next = *list;
  *list = elem;
  return (*list);
}
