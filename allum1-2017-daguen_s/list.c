/*
** list.c for allum1 in /home/daguen_s//myalum1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Feb 10 18:49:51 2013 simon daguenet
** Last update Sun Feb 10 20:11:57 2013 simon daguenet
*/

#include "allum1.h"

void		my_put_in_list(t_list **list)
{
  t_list	*elem;
  static int	nbr = 1;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    my_put_error(1);
  elem->nbr = nbr;
  elem->next = *list;
  *list = elem;
  nbr = nbr + 2;
}

t_list		*my_params_in_list(int nbr)
{
  int		i;
  t_list	*list;

  i = 1;
  list = NULL;
  while (i <= nbr)
    {
      my_put_in_list(&list);
      i = i + 1;
    }
  return (list);
}

void	aff_list(t_list *list, int nbr)
{
  while (list)
    {
      aff_match(list->nbr, nbr);
      list = list->next;
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
      list = list->next;
      free(tmp);
    }
}
