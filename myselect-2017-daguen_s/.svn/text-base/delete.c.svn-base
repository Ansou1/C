/*
** delete.c for my_select in /home/daguen_s//charlotte/rendu
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Jan 19 23:01:46 2013 simon daguenet
** Last update Sat Jan 19 23:46:51 2013 simon daguenet
*/

#include "my_select.h"

void	check_size(int *taille)
{
  char	*str;
  char	*str1;

  if (*taille == 1)
    {
      if ((str1 = tgetstr("cl", NULL)) == NULL)
        my_put_error_2(1);
      if ((str = tgetstr("ve", NULL)) == NULL)
        my_put_error_2(1);
      my_putstr(str1);
      my_putstr(str);
      exit (0);
    }
}

int	delete_elem(t_list **list, int *taille)
{
  t_list	*tmp;
  int	indice;

  tmp = (*list);
  (*list)->prev->next = (*list)->next;
  (*list)->next->prev = (*list)->prev;
  free(tmp);
  *taille = *taille - 1;
  indice = *taille - (*list)->x;
  move_down(list);
  return (indice);
}

void	aff_list_with_bool(t_list *list)
{
  t_list	*tmp;
  int		i;

  tmp = list;
  i = 0;
  while (i == 0 || tmp != list)
    {
      i++;
      print(&tmp);
      tmp = tmp->next;
    }
}

void	disp(t_list **list)
{
  underline(list);
  move_down(list);
  move_up(list);
}

int	press_delete(t_list **list, int *taille)
{
  t_list	*tmp;
  int		indice;
  char		*str;

  check_size(taille);
  indice = delete_elem(list, taille);
  if ((str = tgetstr("cl", NULL)) == NULL)
    my_put_error_2(1);
  tputs(str, 1, outc);
  tmp = (*list);
  while (indice--)
    {
      tmp->x--;
      tmp = tmp->next;
    }
  tmp = (*list);
  underline(&tmp);
  while ((tmp)->x != 0)
    tmp = tmp->next;
  aff_list_with_bool(tmp);
  disp(list);
  return (0);
}
