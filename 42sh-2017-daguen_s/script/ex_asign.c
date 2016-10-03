/*
** ex_asign.c for script in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Tue Apr 23 10:37:23 2013 florian corradin
** Last update Sun May 12 18:13:48 2013 florian corradin
*/

#include "42.h"
#include "script.h"

t_var	*get_tab_var_mail(t_script *s)
{
  t_var	*ret;

  ret = malloc(sizeof (t_var));
  if (ret == NULL)
    return ((t_var *)NULL);
  ret->tab = my_tabdup(s->tab);
  ret->name = my_strdup(s->name);
  ret->val = NULL;
  ret->type = V_TAB;
  return (ret);
}

t_var	*get_var_mail(t_script *s, t_var *v)
{
  t_var	*ret;
  char	*val;

  val = my_strdup(s->inst);
  if (s->tab != NULL)
    return (get_tab_var_mail(s));
  ret = malloc(sizeof (t_var));
  if (ret == NULL)
    return ((t_var *)NULL);
  ret->val = desinhiber(check_var_script(val, 0, v));
  ret->val = replace_bq_str(ret->val, 0);
  ret->name = my_strdup(s->name);
  ret->tab = NULL;
  ret->type = get_var_type(ret->val);
  return (ret);
}

void	ex_asign(t_script *s, t_var **v)
{
  char	*set;
  t_var	*add;

  if (is_in_list(s->name, v))
    {
      set = desinhiber(check_var_script(s->inst, 0, *v));
      set_var(s->name, set, v);
    }
  else
    {
      add = get_var_mail(s, *v);
      *v = add_in_list(*v, add);
    }
}
