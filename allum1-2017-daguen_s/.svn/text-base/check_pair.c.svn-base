/*
** check_pair.c for allum1 in /home/daguen_s//myalum1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Feb 10 19:37:58 2013 simon daguenet
** Last update Sun Feb 10 20:03:59 2013 simon daguenet
*/

#include "allum1.h"

int		check_is_pair(t_list *list)
{
  t_list	*tmp;
  int		ret[3];
  int		i;

  ret[0] = 100;
  ret[1] = 101;
  ret[2] = 102;
  i = 0;
  tmp = list;
  while (tmp)
    {
      if (tmp->nbr > 1)
        ret[i++] = tmp->nbr;
      tmp = tmp->next;
    }
  if ((ret[0] == ret[1]) || (ret[0] == ret[2]) || (ret[1] == ret[2]))
    return (1);
  else
    return (0);
}

int		get_diff_pair(t_list *list)
{
  t_list	*tmp;
  int		ret[3];
  int		i;

  ret[0] = 100;
  ret[1] = 101;
  ret[2] = 102;
  i = 0;
  tmp = list;
  while (tmp)
    {
      if (tmp->nbr > 1)
        ret[i++] = tmp->nbr;
      tmp = tmp->next;
    }
  if (ret[0] == ret[1])
    return (ret[2]);
  else if (ret[0] == ret[2])
    return (ret[1]);
  else if (ret[1] == ret[2])
    return (ret[0]);
  return (0);
}

int		nbr_line_pair(t_list *list)
{
  t_list	*tmp;
  int		bol;

  bol = 0;
  tmp = list;
  while (tmp)
    {
      if ((tmp->nbr > 1) && (bol == 0))
        {
          bol = 1;
          tmp->nbr--;
        }
      tmp = tmp->next;
    }
  if (bol == 0)
    lose_with_pair(list);
  return (0);
}

int		nbr_line_impair(t_list *list)
{
  t_list	*tmp;
  int		bol;

  bol = 0;
  tmp = list;
  while (tmp)
    {
      if ((tmp->nbr > 1) && (bol == 0))
        {
          bol = 1;
          tmp->nbr = 0;
        }
      tmp = tmp->next;
    }
  if (bol == 0)
    lose_with_pair(list);
  return (0);
}
