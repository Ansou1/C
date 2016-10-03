/*
** variable_script.c for script in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Sat May  4 17:50:51 2013 florian corradin
** Last update Thu May 23 15:05:31 2013 simon daguenet
*/

#include "42.h"
#include "script.h"

t_var	*get_spe_var(char **com, t_var *list, char *name)
{
  int	nb;
  char	*nbr;
  t_var	*add;

  if ((add = xmalloc(sizeof (*add))) == NULL)
    return (list);
  if ((nbr = xmalloc(11)) == NULL)
    {
      g_stop_script = -1;
      return (list);
    }
  nb = my_tablen(com);
  sprintf(nbr, "%d", nb);
  add->name = my_strcat("#", name);
  add->type = V_INT;
  add->tab = NULL;
  add->val = nbr;
  list = add_in_list(list, add);
  return (list);
}

t_var	*get_var_all_arg(char **com, t_var *list)
{
  t_var	*ret;
  char	*value;
  int	i;

  if ((ret = malloc(sizeof (*ret))) == NULL)
    return (list);
  value = malloc(1);
  value[0] = '\0';
  i = 0;
  while (com[i])
    {
      if ((value = my_strcat_free_strt(value, com[i])) == NULL)
	return (list);
      i++;
      if (com[i] != NULL)
	if ((value = my_strcat_free_strt(value, " ")) == NULL)
	  return (list);
    }
  if ((ret->name = my_strdup("@")) == NULL)
    return (list);
  ret->val = value;
  ret->type = V_STR;
  ret->tab = NULL;
  list = add_in_list(list, ret);
  return (list);
}

t_var	*get_var_len_tab(t_var *list, t_script **p)
{
  int	i;

  i = 0;
  while (p[i])
    {
      if (p[i]->tab != NULL)
	{
	  list = get_spe_var(p[i]->tab, list, p[i]->name);
	}
      i++;
    }
  return (list);
}
