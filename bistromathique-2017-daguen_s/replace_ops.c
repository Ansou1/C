/*
** replace_ops.c for bistro in /home/elegbe_m//programmation/bistro/bistro
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Sun Nov  4 11:26:49 2012 martial elegbede
** Last update Sat Nov 10 17:05:13 2012 martial elegbede
*/

#include "my_ptr_fcts.h"

int	index(char c, char *ops)
{
  int	i;

  i = 0;
  while (ops[i] != '\0')
    {
      if (ops[i] == c)
	return (i);
      i = i + 1;
    }
  return (-1);
}

void	replace_ops(char *expr, char *ops)
{
  while (*expr != '\0')
    {
      if (my_char_isbase(*expr, ops))
	{
	  if (index(*expr, ops) == 0)
	    *expr = '(';
	  else if (index(*expr, ops) == 1)
	    *expr = ')';
	  else if (index(*expr, ops) == 2)
	    *expr = '+';
	  else if (index(*expr, ops) == 3)
	    *expr = '-';
	  else if (index(*expr, ops) == 4)
	    *expr = '*';
	  else if (index(*expr, ops) == 5)
	    *expr = '/';
	  else if (index(*expr, ops) == 6)
	    *expr = '%';
	}
      expr = expr + 1;
    }
}
