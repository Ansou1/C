/*
** list_chainee.c for my_select in /home/daguen_s//charlotte/rendu
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Jan 19 22:41:56 2013 simon daguenet
** Last update Sat Jan 19 23:49:03 2013 simon daguenet
*/

#include "my_select.h"

void	my_first_time(t_list **list, char *word, t_list *elem, int i)
{
  elem->next = elem;
  elem->prev = elem;
  elem->word = word;
  elem->x = i;
  elem->u_s = 1;
  elem->m_r = 0;
}

void	my_other_time(t_list **list, char *word, t_list *elem, int i)
{
  elem->word = word;
  elem->u_s = 0;
  elem->m_r = 0;
  elem->x = i;
  elem->next = *list;
  (*list)->prev->next = elem;
  elem->prev = (*list)->prev;
  (*list)->prev = elem;
}

void	my_put_in_list(t_list **list, char *word, int i, int taille)
{
  t_list	*elem;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    my_put_error(4);
  if (*list == NULL)
    my_first_time(list, word, elem, i);
  else
    my_other_time(list, word, elem, i);
  *list = elem;
}

t_list	*my_params_in_list(int ac, char **av)
{
  t_list	*list;
  int		i;

  i = ac - 1;
  list = NULL;
  while (ac > 1)
    {
      my_put_in_list(&list, av[ac - 1], ac - 2, i);
      ac--;
    }
  return (list);
}
