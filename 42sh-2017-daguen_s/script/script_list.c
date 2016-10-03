/*
** script_list.c for infectsh in /home/corrad_f//projet/infect/script
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sun Apr  7 10:49:50 2013 florian corradin
** Last update Fri May 10 21:32:38 2013 florian corradin
*/

#include "42.h"
#include "script.h"

t_var	*add_in_list(t_var *list, t_var *add)
{
  t_var	*stock;

  if (add == NULL)
    return (list);
  if (list == NULL)
    {
      add->next = list;
      return (add);
    }
  stock = list;
  add->next = NULL;
  while (list->next != NULL)
    {
      list = list->next;
    }
  list->next = add;
  return (stock);
}

void	my_put_list(t_var *list)
{
  while (list != NULL)
    {
      printf("type = %d\t\tname = %s\t\tval = %s\n", list->type,
	     list->name, list->val);
      list = list->next;
    }
}

void	my_free_list_script(t_var *list)
{
  t_var	*tmp;

  while (list != NULL)
    {
      tmp = list;
      list = list->next;
      if (tmp->name != NULL)
      	free(tmp->name);
      if (tmp->tab != NULL)
      	my_free_tab(tmp->tab);
      if (tmp->val != NULL)
      	free(tmp->val);
      free(tmp);
    }
}
