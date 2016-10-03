/*
** function.c for script in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Mon Apr 22 17:37:54 2013 florian corradin
** Last update Thu May 23 14:54:48 2013 simon daguenet
*/

#include "42.h"
#include "script.h"

int	is_function(char *line)
{
  int	i;

  i = 0;
  if (my_strncmp("function", line, 8))
    return (1);
  while (line[i] != '\0' && (is_digit(line[i]) || is_alpha(line[i]) ||
			     line[i] == '_'))
    i++;
  if (line[i] == '\0')
    return (0);
  else if (line[i] == '(')
    return (1);
  return (0);
}

t_script	*get_function(char *file, int pos)
{
  t_script	*pars;
  char		c;
  int		i;

  i = 0;
  pars = xmalloc(sizeof (*pars));
  pars->type = FUNCTION;
  if (my_strncmp("function", file, 8))
    i = 9;
  if ((pars->name = get_str_sep(&file[i], '(')) == NULL)
    kill(getpid(), SIGKILL);
  pars->inst = NULL;
  pars->att = -1;
  pars->add = g_add;
  pars->tab = NULL;
  while ((c = *file++) != '(' && c);
  if (file[0] != ')')
    fprintf(stderr, "Bad syntaxe unexpected token near %s line:%d\n",
	    pars->name, pos);
  return (pars);
}

t_script	*get_end_function(char *file)
{
  t_script	*pars;

  if (my_str_comp(file, "}") == 0)
    {
      g_stop_script = -1;
      return (NULL);
    }
  pars = xmalloc(sizeof (*pars));
  pars->type = END_FUNC;
  pars->inst = NULL;
  pars->att = -1;
  pars->add = g_add;
  pars->tab = NULL;
  pars->name = NULL;
  return (pars);
}

t_script	*get_fct_start(char *file, int i)
{
  t_script	*pars;

  pars = xmalloc(sizeof (*pars));
  pars->type = OTHER;
  pars->inst = my_strdup("{");
  pars->att = -1;
  pars->add = g_add;
  pars->tab = NULL;
  pars->name = NULL;
  return (pars);
}

t_script	**pars_function(char **file, int *i, t_script **pars)
{
  int		att;

  att = *i;
  g_add = att;
  pars[*i] = get_function(file[*i], *i);
  pars[*i + 1] = get_fct_start(file[*i], *i);
  *i = *i + 2;
  while (file[*i] && is_keyword(file[*i]) != END_FUNC)
    {
      if (is_keyword(file[*i]) == FUNCTION)
	pars = pars_function(file, i, pars);
      else
	pars[*i] = get_inst(file, pars, *i);
      if (g_stop_script == -1)
	return (pars);
      g_add = att;
      *i = *i + 1;
    }
  if (file[*i] == NULL)
    my_put_error_script("Error missing '}'", *i);
  pars[*i] = get_end_function(file[*i]);
  g_add = -1;
  return (pars);
}
