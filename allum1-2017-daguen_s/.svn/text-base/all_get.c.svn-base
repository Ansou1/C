/*
** all_get.c for allum1 in /home/daguen_s//myalum1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Feb 10 19:29:08 2013 simon daguenet
** Last update Sun Feb 10 20:02:14 2013 simon daguenet
*/

#include "allum1.h"

int		get_line_possible(t_list *list, int line_nbr)
{
  t_list	*tmp;

  tmp = list;
  while (--line_nbr)
    tmp = tmp->next;
  if (tmp->nbr == 0)
    return (0);
  return (1);
}

int		get_match_possible(t_list *list, int matches_nbr, int line)
{
  t_list	*tmp;

  tmp = list;
  while (--line)
    tmp = tmp->next;
  if (tmp->nbr < matches_nbr)
    return (0);
  return (1);
}

int		get_all_match(t_list *list)
{
  t_list	*tmp;
  int		check_match;

  check_match = 0;
  tmp = list;
  while (tmp)
    {
      check_match = check_match + tmp->nbr;
      tmp = tmp->next;
    }
  return (check_match);
}

int		get_min_in_list(t_list *list)
{
  t_list	*tmp;
  int		min_match;

  min_match = 100;
  tmp = list;
  while (tmp)
    {
      if ((tmp->nbr < min_match) && (tmp->nbr != 0))
        min_match = tmp->nbr;
      tmp = tmp->next;
    }
  return (min_match);
}

int		get_max_in_list(t_list *list)
{
  t_list	*tmp;
  int		max_match;

  max_match = 0;
  tmp = list;
  while (tmp)
    {
      if (tmp->nbr > max_match)
        max_match = tmp->nbr;
      tmp = tmp->next;
    }
  return (max_match);
}
