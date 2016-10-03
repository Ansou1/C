/*
** my_show_list.c for listes chainées in /home/elegbe_m//programmation/tests_chained_lists
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Tue Oct 23 14:18:24 2012 martial elegbede
** Last update Tue Nov  6 23:24:02 2012 martial elegbede
*/

#include <stdlib.h>
#include "my.h"
#include "my_chained_list.h"

void	my_show_list(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (tmp->content == STRLIST)
	my_putchar(tmp->str);
      if (tmp->content == NBRLIST)
	my_putstr(tmp->nbr);
      my_putchar(' ');
      tmp = tmp->next;
    }
}

void	my_show_stack(t_stack *list)
{
  t_stack	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putchar(tmp->op);
      my_putchar(' ');
      tmp = tmp->next;
    }
  my_putchar('\n');
}

void	my_rev_list(t_list **begin)
{
  t_list	*prev;
  t_list	*tmp;
  t_list	*start;

  start = *begin;
  prev = NULL;
  tmp = NULL;
  while (start != NULL)
    {
      tmp = start;
      start = start->next;
      tmp->next = prev;
      prev = tmp;
    }
  *begin = tmp;
}
