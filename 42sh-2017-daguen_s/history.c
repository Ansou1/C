/*
** history.c for 42sh in /home/daguen_s//42sh-2017-daguen_s
**
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
**
** Started on  Thu May 23 09:49:37 2013 simon daguenet
** Last update Thu May 23 10:27:01 2013 florian corradin
*/

#include "42.h"

void		free_list_histo(t_hist *list)
{
  t_hist	*tmp;

  while (list)
    {
      tmp = list->next;
      free(list->data);
      free(list);
      list = tmp;
    }
  info.hist = NULL;
}

void	print_just_histo(t_hist *l, int opt, int nbr)
{
  while (l != NULL && l->next != NULL && (l = l->next));
  if (opt == 0)
    {
      while (l && nbr != 0)
	{
	  printf("%6d %.2d:%.2d %s\n", l->nbr, l->hr, l->min, l->data);
	  l = l->previous;
	  nbr--;
	}
    }
  if (opt == 2)
    {
      while (l && nbr != 0)
	{
	  printf("%s\n", l->data);
	  l = l->previous;
	  nbr--;
	}
    }
}

void	print_just_reverse(t_hist *l, int opt, int nbr)
{
  if (opt == 1)
    {
      while (l && nbr != 0)
	{
	  printf("%6d %.2d:%.2d %s\n", l->nbr, l->hr, l->min, l->data);
	  l = l->next;
	  nbr--;
	}
    }
  if (opt == 3)
    {
      while (l && nbr != 0)
	{
	  printf("%s\n", l->data);
	  l = l->next;
	  nbr--;
	}
    }
}
void	gestion_histo(t_hist *l, int option, int nbr)
{
  if (option == 0 || option == 2)
    print_just_histo(l, option, nbr);
  else if (option == 1 || option == 3)
    print_just_reverse(l, option, nbr);
  else if (option >= 4 && option <= 7)
    free_list_histo(l);
}

void	my_history(char **com, t_hist *list)
{
  int	option;

  option = 0;
  if (com[1] == NULL)
    gestion_histo(list, 0, 10000);
  else if (com[1][0] == '-')
    {
      option = get_options(&com[1][1]);
      if (com[2] != NULL)
	(is_number(com[2]) && my_atoi(com[2]) >= 0) ?
	  gestion_histo(list, option, my_atoi(com[2]))
	  : my_putstr("history: Badly formed number.\n");
      else
	gestion_histo(list, option, 10000);
    }
  else if (is_number(com[1]))
    (my_atoi(com[1]) >= 0) ? gestion_histo(list, 0, my_atoi(com[1]))
      : my_putstr("history: Badly formed number.\n");
  else
    my_putstr("Usage: history [-chr] [# number of events].\n");
}

