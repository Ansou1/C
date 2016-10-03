/*
** script.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Fri Mar 29 13:30:25 2013 florian corradin
** Last update Thu May 23 15:03:20 2013 simon daguenet
*/

#include "42.h"
#include "script.h"

t_var	*get_arg_var(char **com, t_var *list)
{
  int	i;
  t_var	*var;
  char	*name;

  i = 0;
  while (com[i] != NULL)
    {
      if ((var = xmalloc(sizeof (*var))) == NULL)
	return (NULL);
      if ((name = xmalloc(13)) == NULL)
	return (NULL);
      sprintf(name, "%d", i + 1);
      var->name = name;
      var->type = V_STR;
      var->tab = NULL;
      if ((var->val = my_strdup(com[i])) == NULL)
	return (NULL);
      list = add_in_list(list, var);
      i++;
    }
  return (list);
}

int	script_exit(t_script **p, t_var *list)
{
  if (g_stop_script == -1)
    {
      g_trap.active = 0;
      my_free_list_script(list);
      my_free_scr(p);
      return (1);
    }
  return (0);
}

int		my_script2(char **t_file, t_var *list)
{
  t_script	**pars;

  if ((pars = get_pars(t_file)) == NULL)
    return (FAIL);
  get_trap_glob(pars, &list);
  my_free_tab(t_file);
  if (script_exit(pars, list))
    return (SUCCESS);
  list = get_var_len_tab(list, pars);
  ex_all(pars, &list);
  g_trap.active = 0;
  my_free_list_script(list);
  my_free_scr(pars);
  return (SUCCESS);
}

/* com sert pour les $1 $2 ... */
int		my_script(char **com)
{
  int		fd;
  char		*file;
  char		**t_file;
  t_var		*list;

  list = NULL;
  g_trap.active = 0;
  if ((fd = open(&com[0][2], O_RDONLY)) == -1)
    {
      fprintf(stderr, "Cannot open %s\n", com[0]);
      return (FAIL);
    }
  if ((file = get_next_file(fd)) == NULL)
    return (FAIL);
  close(fd);
  file = replace_by_in_str(file, ';', '\n');
  file = get_str_inhib(file);
  if ((t_file = my_word_tab(file, '\n')) == NULL)
    return (FAIL);
  if ((t_file = get_comment(t_file)) == NULL)
    return (FAIL);
  list = get_arg_var(&com[1], list);
  list = get_spe_var(&com[1], list, "@");
  list = get_var_all_arg(&com[1], list);
  return (my_script2(t_file, list));
}
