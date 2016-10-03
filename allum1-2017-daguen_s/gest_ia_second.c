/*
** gest_ia_second.c for allum1 in /home/daguen_s//myalum1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Feb 10 19:33:54 2013 simon daguenet
** Last update Sun Feb 10 20:08:32 2013 simon daguenet
*/

#include "allum1.h"

int		check_is_number_one(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp)
    {
      if (tmp->nbr == 1)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

int		creat_pair(t_list *list, int val)
{
  t_list	*tmp;

  tmp = list;
  while (tmp)
    {
      if (tmp->nbr > val)
        tmp->nbr = val;
      tmp = tmp->next;
    }
  return (0);
}

int		win_pair(t_list *list)
{
  t_list	*tmp;
  int		bol;

  tmp = list;
  bol = 0;
  while (tmp)
    {
      if (tmp->nbr > 0 && bol == 0)
        {
          tmp->nbr = 0;
          bol = 1;
        }
      tmp = tmp->next;
    }
  return (0);
}

int		lose_with_pair(t_list *list)
{
  t_list	*tmp;
  int		bol;

  tmp = list;
  bol = 0;
  while (tmp)
    {
      if (tmp->nbr != 0 && bol == 0)
        {
          tmp->nbr--;
          bol = 1;
        }
      tmp = tmp->next;
    }
  return (0);
}

int		get_victory_pair(t_list *list, int check_match)
{
  int		min_match;
  int		max_match;

  min_match = get_min_in_list(list);
  max_match = get_max_in_list(list);
  if (check_match == 2)
    win_pair(list);
  else if (check_match == 3)
    vic_pair(list);
  else if (check_is_number_one(list))
    vic_pair(list);
  else
    {
      if (min_match == max_match)
        lose_with_pair(list);
      else
        creat_pair(list, min_match);
    }
  return (0);
}
