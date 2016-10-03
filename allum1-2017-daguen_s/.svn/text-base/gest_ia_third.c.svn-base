/*
** gest_ia_third.c for allum1 in /home/daguen_s//myalum1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Feb 10 19:30:28 2013 simon daguenet
** Last update Sun Feb 10 20:10:09 2013 simon daguenet
*/

#include "allum1.h"

int		take_one_in_max(t_list *list)
{
  t_list	*tmp;
  int		max_match;
  int		bol;

  bol = 0;
  max_match = get_max_in_list(list);
  tmp = list;
  while (tmp)
    {
      if ((tmp->nbr == max_match) && (bol == 0))
        {
          tmp->nbr--;
          bol = 1;
        }
      tmp = tmp->next;
    }
  return (0);
}

int		put_at_one(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp)
    {
      if (tmp->nbr > 1)
        tmp->nbr = 1;
      tmp = tmp->next;
    }
  return (0);
}

int		take_the_diff_pair(t_list *list, int val)
{
  t_list	*tmp;

  tmp = list;
  while (tmp)
    {
      if (tmp->nbr == val)
        tmp->nbr = 0;
      tmp = tmp->next;
    }
  return (0);
}

int	put_third_win(t_list *list)
{
  int	pair;
  int	one;
  int	val;

  one = check_two_one(list);
  pair = check_is_pair(list);
  val = get_diff_pair(list);
  if (one)
    put_at_one(list);
  else if (pair)
    take_the_diff_pair(list, val);
  else
    take_one_in_max(list);
  return (0);
}

int	get_victory_third(t_list *list, int check_match)
{
  int	two_one;
  int	check_pair;

  two_one = check_two_one(list);
  check_pair = check_is_pair(list);
  if (check_match == 3)
    win_pair(list);
  else if (two_one || check_pair)
    put_third_win(list);
  else
    take_one_in_max(list);
  return (0);
}
