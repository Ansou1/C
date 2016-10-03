/*
** polonianize.c for bistromathique in /home/elegbe_m//programmation/evalexp
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Mon Oct 29 17:51:35 2012 martial elegbede
** Last update Sat Nov 10 17:03:40 2012 martial elegbede
*/

#include <stdlib.h>
#include "my_chained_list.h"
#include "my_strdup.h"
#include "my.h"

void	my_finish_stack(t_stack **stack, t_list *npi)
{
  t_stack	*tmp;

  while (*stack != NULL)
    {
      my_put_str_in_list(&npi, (*stack)->op);
      tmp = *stack;
      *stack = (*stack)->next;
      free(tmp);
    }
}

void	my_put_op_in_npi(t_stack **stack, t_list *npi, t_list *list)
{
  t_stack	*tmp;

  while (*stack != NULL && (*stack)->op_prio >= list->op_prio)
    {
      my_put_str_in_list(&npi, (*stack)->op);
      tmp = *stack;
      *stack = tmp->next;
      free(tmp);
    }
  if (*stack != NULL && (*stack)->op == '(' && list->str == ')')
    {
      tmp = *stack;
      *stack = (*stack)->next;
      free(tmp);
      return;
    }
  my_put_in_stack(stack, list);
}

void	my_brackets(t_stack **stack, t_list *npi)
{
  t_stack	*tmp;

  while ((*stack)->op != '(')
    {
      my_put_str_in_list(&npi, (*stack)->op);
      tmp = *stack;
      *stack = (*stack)->next;
      free(tmp);
    }
  tmp = *stack;
  *stack = (*stack)->next;
  free(tmp);
}

void	my_stack(t_list *list, t_stack **stack, t_list *npi)
{
  if (*stack == NULL)
    {
      my_put_in_stack(stack, list);
      return ;
    }
  if (list->str == '(')
    {
      my_put_in_stack(stack, list);
      return ;
    }
  if (list->str == ')')
    {
      my_brackets(stack, npi);
      return ;
    }
  if (list->op_prio > (*stack)->op_prio)
    {
      my_put_in_stack(stack, list);
      return ;
    }
  if (list->op_prio <= (*stack)->op_prio)
    {
      my_put_op_in_npi(stack, npi, list);
    }
}

t_list	*polonianizer(t_list *list)
{
  t_list	*npi;
  t_stack	*stack;
  t_list	*tmp;

  npi = NULL;
  stack = NULL;
  tmp = list;
  while (tmp != NULL)
    {
      if (tmp->content == NBRLIST)
	if (my_put_nb_in_list(&npi, my_strdup(tmp->nbr)) == -1)
	  return (NULL);
      if (tmp->content == STRLIST)
	{
	  my_stack(tmp, &stack, npi);
	}
      tmp = tmp->next;
    }
  my_finish_stack(&stack, npi);
  delete_stack(&stack);
  delete_list(&list);
  return (npi);
}
