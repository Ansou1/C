/*
** parser_script.c for infectsh in /home/corrad_f//projet/infect
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Wed Apr  3 11:08:46 2013 florian corradin
** Last update Sat May 11 21:30:50 2013 florian corradin
*/

#include "42.h"
#include "script.h"

t_script	*get_inst2(char **file, t_script **pars, int pos)
{
  if (is_keyword(file[pos]) == READ)
    return (get_read(file[pos], pos));
  else if (is_keyword(file[pos]) == FOR)
    return (get_for(file[pos], pos));
  else if (is_keyword(file[pos]) == TRAP)
    return (get_trap(file[pos], pos));
  else if (is_keyword(file[pos]) == UNTIL)
    return (get_until(file[pos], pos));
  return (get_other(file[pos], OTHER));
}

/* appelle la fonction de remplissage qui correspond à l'instruction */
/* il faut faire passer att */
t_script	*get_inst(char **file, t_script **pars, int pos)
{
  if (file[pos][0] == '\0')
    return (get_other(file[pos], OTHER));
  else if (is_keyword(file[pos]) == WHILE)
    return (get_key_while(file[pos], pos));
  else if (is_keyword(file[pos]) == DONE)
    return (get_key_done(pars, pos));
  else if (is_keyword(file[pos]) == LET)
    return (pars_let(file[pos], pos));
  else if (is_var_script(file[pos]) == 1)
    return (get_var(file[pos]));
  else if (is_keyword(file[pos]) == COM)
    return (get_com(file[pos]));
  else if (is_keyword(file[pos]) == IF)
    return (get_key_if(file[pos], pos));
  else if (is_keyword(file[pos]) == FI)
    return (get_fi(file[pos]));
  else if (is_keyword(file[pos]) == THEN)
    return (get_then(file[pos]));
  else if (is_keyword(file[pos]) == ELSE)
    return (get_else(file[pos]));
  else if (is_keyword(file[pos]) == ELSE_IF)
    return (get_else_if(file[pos], pos));
  return (get_inst2(file, pars, pos));
}

void	put_scri(t_script **scr)
{
  int	i;

  i = 0;
  while (scr[i] != NULL)
    {
      printf("inst = %s   name = %s   type = %d add = %d\n", scr[i]->inst,
	     scr[i]->name, scr[i]->type, scr[i]->add);
      i++;
    }
}

/* retourne le tableau de parsing */
t_script	**get_pars(char **file)
{
  int		i;
  t_script	**ret;

  g_add = -1;
  i = 0;
  while (file[i] != NULL)
    i++;
  if ((ret = xmalloc(sizeof (ret) * (i + 1))) == NULL)
    return (NULL);
  ret[i] = NULL;
  i = 0;
  while (file[i] != NULL)
    {
      if (is_keyword(file[i]) == FUNCTION)
      	ret = pars_function(file, &i, ret);
      else if (is_keyword(file[i]) == CASE)
	ret = get_case(file, ret, &i);
      else
	ret[i] = get_inst(file, ret, i);
      if (g_stop_script == -1)
	return (NULL);
      i++;
    }
  ret[i] = NULL;
  return (ret);
}
