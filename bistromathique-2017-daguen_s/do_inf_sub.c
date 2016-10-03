/*
** soustraction.c for soustraction in /home/daguen_s//bistromatique
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Thu Nov  1 17:13:25 2012 simon daguenet
** Last update Sat Nov 10 17:58:05 2012 simon daguenet
*/

#include <stdlib.h>
#include "my.h"
#include "get_base.h"
#include "memset.h"
#include "sub_assignement.h"
#include "my_inf_fcts.h"
#include "my_sub_res.h"
#include "my_ptr_fcts.h"

int	res_isneg(char *op1, char *op2, char *base)
{
  if (*op1 == base[0] && my_strlen(op1) > 1)
    while (*op1 == base[0])
      op1++;
  if (*op2 == base[0] && my_strlen(op2) > 1)
    while (*op2 == base[0])
      op2++;
  if (my_strlen(op1) < my_strlen(op2))
    return (1);
  if (my_strlen(op1) > my_strlen(op2))
    return (0);
  if (*op1 == *op2)
    while (*op1 == *op2 && *op1 != '\0')
      {
	op1++;
	op2++;
      }
  if (*op1 < *op2)
    return (1);
  return (0);
}

char	*my_exept(t_sub *ele, char *op1, char *op2)
{
  ele->result = malloc(my_strlen(op1) + 1);
  if (ele->result == NULL)
    return (NULL);
  my_memcharset(ele->result, 0, my_strlen(op1));
  my_revstr(op1);
  my_revstr(op2);
  ele->index = 0;
  ele->retenue = 0;
  return (ele->result);
}

void	my_count_sub(t_sub *ele, char *op1, char *op2, char *base)
{
 while (op1[ele->index] != '\0')
    {
      ele->position1 = get_base(base, op1[ele->index]);
      ele->position2 = (ele->index >= (my_strlen(op2)))
	? 0 : get_base(base, op2[ele->index]);
      ele->position2 += ele->retenue;
      ele->retenue = 0;
      if (ele->position1 < ele->position2)
	{
	  ele->position1 += my_strlen(base);
	  op1[ele->index] = ele->index;
	  ele->retenue = 1;
	}
      ele->result_position = ele->position1 - ele->position2;
      ele->result[ele->index] = base[ele->result_position % my_strlen(base)];
      ele->index++;
    }
}

char	*my_delete(char *result, int index, char *base)
{
  result[index + 1] = '\0';
  if (index > 1)
    {
      index--;
      while (result[index] == base[0] && index > 0)
        {
          result[index] = '\0';
          index--;
        }
    }
  my_revstr(result);
  return (result);
}

char	*do_inf_sub(char *base, char *op1, char *op2)
{
  t_sub	ele;

  ele.neg = res_isneg(op1, op2, base);
  if (*op2 == '-')
    return (do_inf_add(base, op1, op2 + 1));
  else if (*op1 == '-')
    {
      sub_assignement_nbr(&op2);
      return (do_inf_add(base, op1, op2));
    }
  if (ele.neg)
    ptr_swap(&op1, &op2);
  if (!my_exept(&ele, op1, op2))
    return (NULL);
  my_count_sub(&ele, op1, op2, base);
  my_delete(ele.result, ele.index, base);
  if (ele.neg == 1)
    sub_assignement_nbr(&ele.result);
  return (ele.result);
}
