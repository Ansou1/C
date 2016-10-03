/*
** trap.c for script in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Sat May 11 14:23:22 2013 florian corradin
** Last update Sun May 12 11:12:45 2013 florian corradin
*/

#include "42.h"
#include "script.h"

t_script	*get_trap(char *file, int pos)
{
  int		i;
  t_script	*ret;

  i = 0;
  if ((ret = xmalloc(sizeof (t_script))) == NULL)
    return (NULL);
  while (file[i] && file[i] != ' ' && file[i] != '\t')
    i++;
  ret->name = get_next_word(&file[i]);
  ret->inst = NULL;
  ret->att = -1;
  ret->add = g_add;
  ret->tab = NULL;
  ret->type = TRAP;
  g_trap.active = 1;
  return (ret);
}

void	get_call_trap(t_script **s, char *name)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if (s[i]->type == FUNCTION && my_str_comp(name, s[i]->name))
	g_trap.i = i;
      i++;
    }
}

int	get_trap_glob(t_script **s, t_var **v)
{
  int	stop;
  char	*name;
  int	i;

  name = NULL;
  stop = -1;
  g_trap.s = s;
  g_trap.v = v;
  i = 0;
  while (s[i] && stop == -1)
    {
      if (s[i]->type == TRAP)
	{
	  stop = i;
	  name = my_strdup(s[i]->name);
	}
      i++;
    }
  if (stop != -1)
    get_call_trap(s, name);
  if (name != NULL)
    free(name);
  return (0);
}
