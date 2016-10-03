/*
** calc_algo.c for bistro-calc-algo in /home/elegbe_m//programmation/bistro/calc_algo
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Wed Oct 31 12:46:39 2012 martial elegbede
** Last update Thu Nov  8 13:41:58 2012 martial elegbede
*/

#include <stdlib.h>
#include "my_chained_list.h"
#include "do_inf_ops.h"
#include "my.h"

void	my_free(t_list *nb1, t_list *nb2, t_list *op)
{
  free(nb1->nbr);
  free(nb2->nbr);
  free(nb2);
  free(op);
}

char	*do_op_send(t_list **tmp, t_list *npi, char *base)
{
  t_list	*nbr1;
  t_list	*nbr2;
  char	*res;

  my_rev_list(&npi);
  nbr2 = (*tmp)->next;
  nbr1 = nbr2->next;
  res = do_inf_op(nbr1->nbr, nbr2->nbr, (*tmp)->str, base);
  if (res == NULL)
    return (NULL);
  my_rev_list(&npi);
  nbr1->next = (*tmp)->next;
  my_free(nbr1, nbr2, *tmp);
  nbr1->nbr = res;
  *tmp = nbr1;
  return (res);
}

char	*calc_algo(t_list *npi, char *base)
{
  t_list	*tmp;
  char	*res;

  tmp = npi;
  res = NULL;
  while (tmp != NULL)
    {
      if (tmp->content == STRLIST)
	{
	  res = do_op_send(&tmp, npi, base);
	  if (res == NULL)
	    return (NULL);
	}
      else
	tmp = tmp->next;
    }
  return (npi->nbr);
}
