/*
** eval_expr.c for script in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Tue Apr 30 21:20:57 2013 florian corradin
** Last update Thu May 23 14:51:11 2013 simon daguenet
*/

#include "42.h"
#include "script.h"

t_op	op [] =
  {
    {'+', 1, op_plus},
    {'-', 1, op_moins},
    {'/', 2, op_div},
    {'*', 2, op_mul},
    {'%', 2, op_mod},
    {0, 0, 0}
  };

void	init_eval(int *ret, int *par, int *pos, char *str)
{
  *ret = -2;
  *par = 0;
  *pos = my_strlen(str) - 1;
}

int	find_last_op(char *str, int p, int i)
{
  int	pos;
  int	ret;
  int	par;

  init_eval(&ret, &par, &pos, str);
  while (pos >= 0)
    {
      if (str[pos] == ')')
	par++;
      if (str[pos] == '(')
	par--;
      i = 0;
      while (!par && op[i].c)
	{
	  if (op[i].c == str[pos])
	    {
	      ret = -1;
	      if (op[i].p == p)
		return (pos);
	    }
	  i++;
	}
      pos--;
    }
  return (ret);
}

int	is_nb(char *str)
{
  if (*str == '(')
    {
      str[my_strlen(str) - 1] = 0;
      return (eval_expr_sub(str + 1, 0));
    }
  return (my_atoi(str));
}

int	eval_expr_sub(char *str, int p)
{
  int	pos;
  char	save;
  int	nb2;
  int	i;

  i = 0;
  if ((pos = find_last_op(str, p, i)) == -1)
    return (eval_expr_sub(str, p + 1));
  if (pos == -2)
    return (is_nb(str));
  nb2 = eval_expr_sub(str + pos + 1, p + 1);
  save = str[pos];
  str[pos] = 0;
  pos = 0;
  while (op[pos].c)
    {
      if (save == op[pos].c)
	return (op[pos].f(eval_expr_sub(str, p), nb2));
      pos ++;
    }
  return (0);
}

int	eval_expr(char *str)
{
  return (eval_expr_sub(str, 0));
}
