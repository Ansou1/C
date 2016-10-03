/*
** for.c for script in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Fri May 10 18:30:18 2013 florian corradin
** Last update Sun May 12 11:27:34 2013 florian corradin
*/

#include "42.h"
#include "script.h"

void	check_error_for(t_script *ret, int line)
{
  if (ret->name == NULL)
    my_put_error_script("Could not alloc\n", line);
  else if (ret->name[0] == '\0')
    my_put_error_script("Missing variable in for\n", line);
  if (ret->inst == NULL)
    my_put_error_script("Could not alloc\n", line);
  else if (ret->inst[0] == '\0')
    my_put_error_script("Missing instruction in for\n", line);
}

t_script	*get_for(char *file, int pos)
{
  int		i;
  t_script	*ret;

  i = 0;
  while (file[i] != ' ' && file[i] != '\t' && file[i] != '\0')
    i++;
  if (file[i] != '\0')
    i++;
  ret = xmalloc(sizeof(t_script));
  ret->type = FOR;
  ret->name = get_next_word(&file[i]);
  i += my_strlen(ret->name);
  if (file[i] != '\0')
    i++;
  while (file[i] != ' ' && file[i] != '\t' && file[i] != '\0')
    i++;
  if (file[i] != '\0')
    i++;
  ret->inst = my_epurstr_inib(my_strdup(&file[i]));
  ret->tab = NULL;
  ret->att = -1;
  ret->add = g_add;
  check_error_for(ret, pos);
  return (ret);
}

char	**get_for_cond(char *inst, t_var *list)
{
  char	*ret;
  char	**tab;

  if (inst[0] == '$' && inst[1] == '(')
    {
      ret = get_str_sep(&inst[2], ')');
      ret = check_var_script(ret, 0, list);
      ret = my_epurstr_inib(ret);
      ret = desinhiber(ret);
      tab = get_for_trap_com(ret);
      free(ret);
      return (tab);
    }
  ret = my_strdup(inst);
  ret = check_var_script(ret, 0, list);
  ret = replace_bq_str(ret, 0);
  ret = desinhiber(ret);
  tab = my_str_to_wordtab(ret);
  free(ret);
  return (tab);
}

void	init_for_var(char *name, t_var **v)
{
  t_var	*add;

  if (!is_in_list(name, v))
    {
      add = xmalloc(sizeof (t_var));
      add->name = my_strdup(name);
      add->tab = NULL;
      add->val = my_strdup("\0");
      add->type = V_STR;
      *v = add_in_list(*v, add);
    }
}

int	exec_instruc_for(t_script **s, t_var **v, int *i)
{
  ex_type(s, v, i);
  if (s[*i] != NULL)
    *i = *i + 1;
  if (s[*i] == NULL)
    {
      my_put_error_script("Missing done\n", *i);
      return (0);
    }
  return (1);
}
