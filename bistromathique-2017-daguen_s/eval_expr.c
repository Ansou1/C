/*
** main.c for do-op in /home/elegbe_m//programmation/bistro/do-op
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Wed Oct 31 11:12:47 2012 martial elegbede
** Last update Sat Nov 10 16:30:34 2012 martial elegbede
*/

#include <stdlib.h>
#include "my_chained_list.h"
#include "my_polonian.h"
#include "my.h"
#include "calc_algo.h"
#include "my_strdup.h"
#include "replace_ops.h"
#include "bistromathique.h"

int	ops_are_valids(char *ops)
{
  int i;

  while (ops[1] != '\0')
    {
      i = 1;
      while (ops[i] != '\0')
	{
	  if (ops[i] == *ops)
	    return (0);
	  i++;
	}
      ops++;
    }
  return (1);
}

int	base_is_valid(char *base, char *ops)
{
  int i;

  while (base[1] != '\0')
    {
      i = 1;
      while (base[i] != '\0')
	{
	  if (base[i] == *base && !my_char_isbase(*base, ops))
	    return (0);
	  i++;
	}
      base++;
    }
  return (1);
}

int	expr_is_valid(char *base, char *ops, char *expr)
{
  int	brackets;

  brackets = 0;
  if (!my_char_isbase(*expr, base) && *expr != '(' && *expr != '-')
    return (0);
  while (*expr != '\0')
    {
      if (my_char_isbase(*expr, ops) && my_char_isbase(expr[1], ops)
	  && !(*expr == '(' || *expr == ')' || expr[1] == '('))
	return (0);
      if (!(my_char_isbase(*expr, base) || my_char_isbase(*expr, ops)))
	return (0);
      if (*expr == '(')
	brackets++;
      if (*expr == ')')
	brackets--;
      if (brackets < 0)
	return (0);
      expr++;
    }
  if (brackets > 0)
    return (0);
  if (my_char_isbase(expr[-1], ops) && expr[-1] != ')')
    return (0);
  return (1);
}

char	*error(char *base, char *ops, char *expr, unsigned int size)
{
  if (size <= 0)
    return (SYNTAXE_ERROR_MSG);
  if (!(ops_are_valids(ops) && base_is_valid(base, ops)))
    return (SYNTAXE_ERROR_MSG);
  if (!(expr_is_valid(base, ops, expr)))
    return (SYNTAXE_ERROR_MSG);
  while (*expr != '\0')
    {
      if (*expr == '/')
        return ("Erreur: division non implementée.");
      if (*expr == '%')
        return ("Erreur: modulo non implémenté.");
      expr++;
    }
  return (NULL);
}

char	*eval_expr(char *base, char *ops, char *expr, unsigned int size)
{
  t_list	*list;
  t_list	*npi;
  char	*result;
  char	*errors;

  replace_ops(expr, ops);
  my_strcpy(ops, "()+-*/%");
  errors = error(base, ops, expr, size);
  if (errors)
    return (errors);
  list = str_to_list(expr, base);
  free(expr);
  if (!list)
    return ("error while computing expression.");
  npi = polonianizer(list);
  if (!npi)
    return ("error while computing expression.");
  if (!calc_algo(npi, base))
    return ("error while computing expression.");
  result = my_strdup(npi->nbr);
  delete_list(&npi);
  return (result);
}
