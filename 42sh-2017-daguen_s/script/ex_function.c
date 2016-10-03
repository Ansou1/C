/*
** ex_function.c for script in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Wed May  1 21:20:10 2013 florian corradin
** Last update Wed May  8 15:34:40 2013 florian corradin
*/

#include "42.h"
#include "script.h"

t_var	*get_tmp_fct_var(t_script *s)
{
  t_var	*ret;

  if ((ret = xmalloc(sizeof (t_var))) == NULL)
    return (NULL);
  return (ret);
}

int	is_call_fct(t_script **s, int i)
{
  char	*name;

  if (s[i]->inst == NULL)
    return (0);
  name = s[i]->inst;
  i = 0;
  while (s[i])
    {
      if (s[i]->name != NULL)
	if (my_str_comp(s[i]->name, name) && s[i]->type == FUNCTION)
	  return (i);
      i++;
    }
  return (0);
}

int	exec_function(t_script **s, t_var **v, int i)
{
  int	att;

  att = i;
  g_add = att;
  while (s[i])
    {
      if (s[i]->type == END_FUNC)
	{
	  g_add = -1;
	  return (SUCCESS);
	}
      if (s[i]->add == g_add)
	ex_type(s, v, &i);
      g_add = att;
      i = i + 1;
    }
  g_add = -1;
  fprintf(stderr, "Missing end of bloc in function\n");
  return (FAIL);
}
