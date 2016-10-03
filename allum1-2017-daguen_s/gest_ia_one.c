/*
** gest_ia_one.c for allum1 in /home/daguen_s//myalum1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Feb 10 19:27:11 2013 simon daguenet
** Last update Sun Feb 10 20:07:07 2013 simon daguenet
*/

#include "allum1.h"

int		get_victory(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp)
    {
      if (tmp->nbr > 0)
        tmp->nbr = 1;
      tmp = tmp->next;
    }
  return (0);
}

int		vic_pair(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp)
    {
      if (tmp->nbr > 1)
        tmp->nbr = 0;
      tmp = tmp->next;
    }
  return (0);
}

int		lose_ia(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp)
    {
      tmp->nbr = 0;
      tmp = tmp->next;
    }
  return (0);
}

int		check_two_one(t_list *list)
{
  t_list	*tmp;
  int		bol;

  bol = 0;
  tmp = list;
  while (tmp)
    {
      if (tmp->nbr == 1)
        bol++;
      tmp = tmp->next;
    }
  if (bol == 2)
    return (1);
  else
    return (0);
}
