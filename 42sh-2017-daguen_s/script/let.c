/*
** let.c for infectsh in /home/corrad_f//projet/infect/script
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Tue Apr  9 14:45:19 2013 florian corradin
** Last update Thu May 23 14:59:18 2013 simon daguenet
*/

#include "42.h"
#include "script.h"

char	*get_let_name(char *file, int pos)
{
  int	i;
  char	*ret;

  i = 0;
  while (file[i] && !is_operator(file[i]) && file[i] != '=')
    i++;
  if (file[i] == '\0')
    {
      g_stop_script = -1;
      fprintf(stderr, "Error missing operator line%d\n", pos);
    }
  if ((ret = malloc(i + 1)) == NULL)
    {
      fprintf(stderr, "Could not alloc more memory space\n");
      g_stop_script = -1;
      return (NULL);
    }
  i = 0;
  while (file[i] && !is_operator(file[i]) && file[i] != '=')
    {
      ret[i] = file[i];
      i++;
    }
  ret[i] = '\0';
  return (ret);
}

t_script	*pars_let(char *file, int pos)
{
  int		i;
  t_script	*ret;

  if (file[3] == '\0')
    {
      g_statu = -1;
      fprintf(stderr, "Error miising argument for let line %d\n", pos);
      kill(getpid(), SIGKILL);
    }
  i = 4;
  ret = xmalloc(sizeof (t_script));
  ret->type = LET;
  ret->name = get_let_name(&file[i], pos);
  ret->att = -1;
  ret->add = g_add;
  i += my_strlen(ret->name);
  ret->inst = my_strdup(&file[i]);
  ret->tab = NULL;
  return (ret);
}

int	unaire(char *inst, int name)
{
  if (inst[0] == '+' && inst[1] == '=')
    return (name + eval_expr(&inst[2]));
  else if (inst[0] == '-' && inst[1] == '=')
    return (name - eval_expr(&inst[2]));
  else if (inst[0] == '+' && inst[1] == '+')
    return (name + 1);
  else if (inst[0] == '-' && inst[1] == '-')
    return (name + 1);
  fprintf(stderr, "WARNING Syntaxe error\n");
  return (0);
}

t_script	*exec_let(t_script *s, t_var **list, int pos)
{
  int		result;
  int		val;
  char		*inst;
  char		*save;
  char		*res;
  char		*name;

  result = 0;
  name = my_strdup(s->name);
  save = my_strdup(s->inst);
  inst = check_var_script_op(save, 0, *list);
  val = my_atoi(check_var_script_op(name, 0, *list));
  if (is_operator(s->inst[0]))
    result = unaire(inst, val);
  else if (s->inst[0] == '=')
    result = eval_expr(&inst[1]);
  res = malloc(12);
  sprintf(res, "%d", result);
  set_var(s->name, res, list);
  return (s);
}
