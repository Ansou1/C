/*
** remplace_for_hist.c for 42sh in /home/daguen_s//42sh-2017-daguen_s
**
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
**
** Started on  Thu May 23 09:51:18 2013 simon daguenet
** Last update Thu May 23 09:52:55 2013 simon daguenet
*/

#include "42.h"

char		*remplace_nbr_cmd_neg(int nbr, char *str)
{
  t_hist	*list;
  int		nbr_in_list;

  nbr_in_list = nbr_in_list_histo();
  if (nbr > nbr_in_list)
    return (str);
  else
    {
      list = info.hist;
      while (nbr - 1)
	{
	  list = list->next;
	  nbr--;
	}
      return (strdup(list->data));
    }
}

char		*remplace_nbr_cmd_pos(int nbr, char *str)
{
  t_hist	*l;
  int		nbr_in_list;

  nbr_in_list = nbr_in_list_histo();
  if (nbr > nbr_in_list)
    return (str);
  else
    {
      l = info.hist;
      while (l != NULL && l->next != NULL && (l = l->next));
      while (nbr - 1)
	{
	  l = l->previous;
	  nbr--;
	}
      return (strdup(l->data));
    }
}

char		*remplace_chaine_cmd(char *str)
{
  t_hist	*list;

  list = info.hist;
  if (str != NULL)
    {
      while (list)
	{
	  if (strncmp(list->data, str, my_strlen(str)) == 0)
	    return (strdup(list->data));
	  list = list->next;
	}
    }
  return (strdup(str));
}

char	*replace_cmd_hist(char *str)
{
  if (str != NULL)
    {
      if (str[1] == '-')
	{
	  if (is_number(&str[2]) && my_atoi(&str[2]) != 0)
	    str = remplace_nbr_cmd_neg(my_atoi(&str[2]), str);
	}
      else if (is_number(&str[1]) && my_atoi(&str[1]) != 0)
	str = remplace_nbr_cmd_pos(my_atoi(&str[1]), str);
      else
	str = remplace_chaine_cmd(&str[1]);
    }
  return (str);
}
