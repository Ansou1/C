/*
** ex_com.c for script in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Tue Apr 23 10:00:55 2013 florian corradin
** Last update Thu May 23 14:52:49 2013 simon daguenet
*/

#include "42.h"
#include "script.h"

void	ex_com(t_script **p, t_var **list, int i)
{
  char	*com;
  char	*save;
  int	add;

  if ((add = is_call_fct(p, i)) != 0)
    exec_function(p, list, add);
  save = my_strdup(p[i]->inst);
  com = check_var_script(save, 0, *list);
  com = replace_bq_str(com, 0);
  com = desinhiber(com);
  if (my_str_comp(com, "exit"))
    g_stop_script = -1;
  else
    my_shell(com);
  free(com);
}

char	**get_for_trap_com(char *com)
{
  char	*rep;
  char	**tab;

  if ((rep = my_strdup(com)) == NULL)
    return (NULL);
  if ((rep = creat_file_bq(rep)) == NULL)
    return (NULL);
  tab = my_word_tab(rep, '\n');
  return (tab);
}
