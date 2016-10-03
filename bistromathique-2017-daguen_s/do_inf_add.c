/*
** addition.c for addition in /home/daguen_s//bistromatique
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Thu Nov  1 12:26:50 2012 simon daguenet
** Last update Sat Nov 10 17:55:26 2012 simon daguenet
*/

#include <stdlib.h>
#include <my_inf_add_struct.h>
#include "my.h"
#include "get_base.h"
#include "memset.h"
#include "sub_assignement.h"
#include "my_inf_fcts.h"

char	*retenue_sup(int retenue, char *result, int id, char *base)
{
  if (retenue == 1)
    result[id] = base[1];
  result[id + 1] = '\0';
  my_revstr(result);
  return (result);
}

void	struct_init(t_element *elem)
{
  elem->result = NULL;
  elem->swap = NULL;
  elem->id = 0;
  elem->pos1 = 0;
  elem->pos2 = 0;
  elem->result_position = 0;
  elem->retenue = 0;
}

void	my_count1(char *op1, char *op2, char *base, t_element *ele)
{
  struct_init(ele);
  my_revstr(op1);
  my_revstr(op2);
  if (my_strlen(op1) < my_strlen(op2))
    {
      ele->swap = op1;
      op1 = op2;
      op2 = ele->swap;
    }
  ele->result = malloc(my_strlen(op1) + 2);
  my_memcharset(ele->result, 0, my_strlen(op1) + 1);
  while (op1[ele->id] != '\0')
    {
      ele->pos1 = get_base(base, op1[ele->id]);
      ele->pos2 =
	(ele->id >= (my_strlen(op2))) ? 0 : get_base(base, op2[ele->id]);
      ele->result_position = ele->pos1 + ele->pos2 + ele->retenue;
      ele->result[ele->id] = base[ele->result_position % my_strlen(base)];
      ele->retenue = (ele->result_position >= my_strlen(base)) ? 1 : 0;
      ele->id++;
    }
}

char	*do_inf_add(char *base, char *op1, char *op2)
{
  t_element	*ele;
  char	*res;
  int	neg;

  neg = 0;
  if (*op1 == '-' && *op2 == '-')
    {
      neg = 1;
      op1++;
      op2++;
    }
  else if (*op1 == '-')
    return (do_inf_sub(base, op2, op1 + 1));
  else if (*op2 == '-')
    return (do_inf_sub(base, op1, op2 + 1));
  ele = malloc(sizeof(t_element));
  if (ele == NULL)
    return (NULL);
  my_count1(op1, op2, base, ele);
  retenue_sup(ele->retenue, ele->result, ele->id, base);
  res = ele->result;
  free(ele);
  if (neg)
    sub_assignement_nbr(&res);
  return (res);
}
