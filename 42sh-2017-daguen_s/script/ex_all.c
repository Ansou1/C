/*
** ex_all.c for script in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Tue Apr 23 10:17:13 2013 florian corradin
** Last update Sat May 11 21:34:12 2013 florian corradin
*/

#include "42.h"
#include "script.h"

int	ex_type(t_script **s, t_var **v, int *i)
{
  if (s[*i]->add != g_add)
    return (0);
  if (is_call_fct(s, *i) != 0)
    exec_function(s, v, is_call_fct(s, *i));
  else if (s[*i]->type == COM)
    ex_com(s, v, *i);
  else if (s[*i]->type == ASIGN)
    ex_asign(s[*i], v);
  else if (s[*i]->type == LET)
    exec_let(s[*i], v, *i);
  else if (s[*i]->type == WHILE)
    exec_while(s, *v, i);
  else if (s[*i]->type == DONE)
    exec_done(s[*i], *v, i);
  else if (s[*i]->type == IF)
    exec_if(s, v, i);
  else if (s[*i]->type == CASE)
    ex_case(s, v, i);
  else if (s[*i]->type == READ)
    ex_read(s[*i], v);
  else if (s[*i]->type == FOR)
    exec_for(s, v, i);
  else if (s[*i]->type == UNTIL)
    exec_until(s, v, i);
  return (0);
}

int	ex_all(t_script **s, t_var **v)
{
  int	i;

  g_add = -1;
  i = 0;
  while (s[i])
    {
      ex_type(s, v, &i);
      if (g_stop_script == -1)
	return (0);
      if (s[i] != NULL)
	i++;
    }
  return (0);
}
