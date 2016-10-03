/*
** delete_lists.c for bistromathique in /home/elegbe_m//programmation/evalexp
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Mon Oct 29 18:58:53 2012 martial elegbede
** Last update Wed Oct 31 18:58:41 2012 martial elegbede
*/

#include <stdlib.h>
#include "my_chained_list.h"

void	delete_list(t_list **list)
{
  t_list	*start;
  t_list	*next;

  next = *list;
  while (next != NULL)
    {
      start = next;
      next = next->next;
      if (start->content == NBRLIST)
      	free(start->nbr);
      free(start);
    }
}

void	delete_stack(t_stack **list)
{
  t_stack	*start;
  t_stack	*next;

  next = *list;
  while (next != NULL)
    {
      start = next;
      next = next->next;
      free(start);
    }
}
