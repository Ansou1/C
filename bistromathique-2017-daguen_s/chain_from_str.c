/*
** str_to_polonian_tab.c for evalexpr in /home/elegbe_m//programmation/evalexp
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Fri Oct 26 09:32:25 2012 martial elegbede
** Last update Sat Nov 10 18:12:52 2012 martial elegbede
*/

#include <stdlib.h>
#include "my_chained_list.h"
#include "my.h"
#include "my_strdup.h"
#include "sub_assignement.h"

void	assign_prio(t_list *list)
{
  while (list != NULL)
    {
      if (list->content == STRLIST)
	{
	  if (list->str == '+' || list->str == '-')
	    list->op_prio = 4;
	  if (list->str == '*' || list->str == '/' || list->str == '%')
            list->op_prio = 5;
	  if (list->str == ')')
	    list->op_prio = 2;
	  if (list->str == '(')
	    list->op_prio = 0;
	}
      list = list->N;
    }
}

void	less_mult(t_list *list)
{
  t_list	*tmp;

  list->nbr = my_strdup("-1");
  list->content = NBRLIST;
  tmp = malloc(sizeof(*tmp));
  tmp->content = STRLIST;
  tmp->str = '*';
  tmp->N = list->N;
  list->N = tmp;
}

void	remove_unaries(t_list **list)
{
  t_list	*tmp;
  t_list	*to_free;

  tmp = *list;
  if (tmp->str == '-')
    {
      less_mult(tmp);
    }
  while (tmp->N != NULL)
    {
      if (tmp->str == '(' && tmp->N->str == '-' && tmp->N->N->str == '(')
	less_mult(tmp->N);
      else if ((tmp->str == '(') && (tmp->N->str == '-'))
	{
	  to_free = tmp->N;
	  tmp->N = tmp->N->N;
	  free(to_free);
	  sub_assignement_list(tmp->N);
	}
      tmp = tmp->N;
    }
}

t_list	*str_to_list(char *str, char *base)
{
  t_list	*list;

  list = NULL;
  while (*str != '\0')
    {
      if (my_char_isbase(*str, base))
	{
	  if (my_put_nb_in_list(&list, my_nbrdup(str, base)) == -1)
	    return (NULL);
	  while (my_char_isbase(*str, base))
	    str = str + 1;
	}
      else
	{
	  if (*str == '+' || *str == '-' || *str == '*' || *str == '/'
	      || *str == '%' || *str == '(' || *str == ')')
	    if (my_put_str_in_list(&list, *str) == -1)
	      return (NULL);
	  str = str + 1;
	}
    }
  remove_unaries(&list);
  assign_prio(list);
  return (list);
}
