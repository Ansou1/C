/*
** exec_for.c for script in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Sun May 12 11:26:52 2013 florian corradin
** Last update Sun May 12 11:27:31 2013 florian corradin
*/

#include "42.h"
#include "script.h"

int	exec_for(t_script **s, t_var **v, int *i)
{
  char	**cond;
  int	ind;
  char	*name;
  int	att;

  name = my_strdup(s[*i]->name);
  ind = 0;
  if ((cond = get_for_cond(s[*i]->inst, *v)) == NULL)
    return (0);
  init_for_var(s[*i]->name, v);
  *i = *i + 1;
  att = *i;
  while (cond[ind] != NULL)
    {
      *i = att;
      set_var(name, cond[ind], v);
      while (s[*i]->type != DONE)
	{
	  if (exec_instruc_for(s, v, i) == 0)
	    return (0);
	}
      ind++;
    }
  my_free_tab(cond);
  return (0);
}
