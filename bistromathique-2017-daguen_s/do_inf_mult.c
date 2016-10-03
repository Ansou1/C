/*
** main.c for main in /home/daguen_s//bistromatique
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Oct 29 10:13:01 2012 simon daguenet
** Last update Sat Nov 10 17:51:05 2012 simon daguenet
*/

#include <stdlib.h>
#include "my_inf_mult_defines.h"
#include "my.h"
#include "sub_assignement.h"
#include "memset.h"

int	*mk_r(int size)
{
  int	*r;

  r = malloc((size * sizeof(*r)) + 1);
  if (r == NULL)
    return (NULL);
  my_memset(r, 0, size);
  return (r);
}

char	*mk_res(int size)
{
  char	*res;

  res = malloc(size + 1);
  if (res == NULL)
    return (NULL);
  my_memcharset(res, 0, size);
  return (res);
}

int	digit_to_val(char *base, char d)
{
  int	r;

  r = 0;
  while (base[r] != d)
    r++;
  return (r);
}

int	*my_count(int *r, char *base, char *n1, char *n2)
{
  int	p1;
  int	p2;

  p1 = my_strlen(n1) - 1;
  while (p1 >= 0)
    {
      p2 = my_strlen(n2) - 1;
      while (p2 >= 0)
        {
	  r[p1 + p2 + 1] += DIGIT_TO_VAL(n1[p1]) * DIGIT_TO_VAL(n2[p2]);
	  r[p1 + p2] += r[p1 + p2 + 1] / BASE_LEN;
          r[p1 + p2 + 1] = r[p1 + p2 + 1] % BASE_LEN;
	  p2--;
        }
      p1--;
    }
  return (r);
}

char	*do_inf_mult(char *base, char *n1, char *n2)
{
  t_type	ele;

  ele.neg = ((*n1 == '-' || *n2 == '-') ? 1 : 0);
  ele.neg = ((*n1 == '-' && *n2 == '-') ? 0 : ele.neg);
  if (*n1 == '-')
    n1++;
  if (*n2 == '-')
    n2++;
  ele.r = mk_r(my_strlen(n1) + my_strlen(n2));
  ele.res = mk_res(my_strlen(n1) + my_strlen(n2));
  if (ele.r == NULL || ele.res == NULL)
    return (NULL);
  my_count(ele.r, base, n1, n2);
  ele.p1 = ele.p2 = 0;
  while (ele.p1 < (my_strlen(n1) + my_strlen(n2)))
    {
      if (ele.p2
	  || ele.r[ele.p1] || ele.p1 == (my_strlen(n1) + my_strlen(n2) - 1))
        ele.res[ele.p2++] = VAL_TO_DIGIT(ele.r[ele.p1]);
      ele.p1++;
    }
  free(ele.r);
  if (ele.neg)
    sub_assignement_nbr(&ele.res);
  return (ele.res);
}
