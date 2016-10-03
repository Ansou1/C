/*
** until.c for script in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Sat May 11 19:18:27 2013 florian corradin
** Last update Sat May 11 21:38:33 2013 florian corradin
*/

#include "42.h"
#include "script.h"

t_script	*get_until(char *file, int pos)
{
  int		i;
  t_script	*ret;

  ret = xmalloc(sizeof (t_script));
  ret->type = UNTIL;
  ret->name = NULL;
  i = 0;
  while (file[i] != ' ' && file[i] != '\0' && file[i] != '\t')
    i++;
  if (file[i] == '\0' || file[i + 1] != '[')
    {
      g_stop_script = -1;
      fprintf(stderr, "Error bad syntaxe in while line: %d %s\n",
	      pos + 1, file);
      return (NULL);
    }
  ret->att = -1;
  ret->add = g_add;
  ret->inst = my_epurstr_inib(my_strdup(&file[i]));
  ret->tab = NULL;
  return (ret);
}

int	exec_until(t_script **s, t_var **v, int *i)
{
  int	att;

  if (instruction(s[*i]->inst, *v))
    {
      while (s[*i] && s[*i]->type != DONE)
	*i = *i + 1;
      return (0);
    }
  *i = *i + 1;
  att = *i;
  while (instruction(s[*i]->inst, *v) != 1)
    {
      *i = att;
      while (s[*i] && s[*i]->type != DONE)
	{
	  ex_type(s, v, i);
	  *i = *i + 1;
	}
    }
  return (0);
}
