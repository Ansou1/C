/*
** if.c for script in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Tue Apr 30 18:02:11 2013 florian corradin
** Last update Thu May 23 14:55:54 2013 simon daguenet
*/

#include "42.h"
#include "script.h"

int	exit_bloc_if(t_script **s, int *i)
{
  int	bloc;

  bloc = 1;
  while (bloc != 0 && s[*i])
    {
      if (s[*i]->type == IF)
	bloc++;
      else if (s[*i]->type == FI)
	bloc--;
      *i = *i + 1;
    }
  *i = *i - 1;
  if (bloc == 0)
    return (SUCCESS);
  fprintf(stderr, "Missing end of bloc line %d\n", *i);
  return (FAIL);
}

int	goto_next_bloc_if(t_script **s, int *i)
{
  int	bloc;

  bloc = 1;
  *i = *i + 1;
  while (s[*i])
    {
      if (s[*i]->type == IF)
	bloc++;
      else if (s[*i]->type == FI && bloc == 1)
	return (SUCCESS);
      else if (s[*i]->type == FI)
	bloc--;
      else if ((s[*i]->type == ELSE || s[*i]->type == ELSE_IF) && bloc == 1)
	return (SUCCESS);
      *i = *i + 1;
    }
  fprintf(stderr, "Missing end of bloc line %d\n", *i);
  return (FAIL);
}

int	exec_if(t_script **s, t_var **v, int *i)
{
  while (s[*i])
    {
      if (s[*i]->type == ELSE || instruction(s[*i]->inst, *v))
	{
	  *i = *i + 1;
	  while (s[*i] && s[*i]->type != ELSE &&
		 s[*i]->type != ELSE_IF && s[*i]->type != FI)
	    {
	      ex_type(s, v, i);
	      if (s[*i] == NULL || s[*i]->type == ELSE ||
		  s[*i]->type == ELSE_IF || s[*i]->type == FI)
		return (exit_bloc_if(s, i));
	      *i = *i + 1;
	    }
	  return (exit_bloc_if(s, i));
	}
      else
	goto_next_bloc_if(s, i);
      if (s[*i] == NULL || s[*i]->type == FI)
	return (SUCCESS);
    }
  fprintf(stderr, "Missing end of bloc line %d\n", *i);
  return (SUCCESS);
}
