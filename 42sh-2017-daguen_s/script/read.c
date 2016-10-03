/*
** read.c for script in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Sun May  5 11:04:05 2013 florian corradin
** Last update Sun May  5 11:44:49 2013 florian corradin
*/

#include "42.h"
#include "script.h"

t_script	*get_read(char *file, int pos)
{
  int		i;
  t_script	*ret;

  i = 0;
  while (file[i] != '\0' && file[i] != ' ' && file[i] != '\t')
    i++;
  if (file[i] == '\0')
    my_put_error_script("Error missing variable in read", pos);
  if ((ret = malloc(sizeof (*ret))) == NULL)
    {
      g_stop_script = -1;
      return (NULL);
    }
  ret->name = get_next_word(&file[i]);
  ret->tab = NULL;
  ret->type = READ;
  ret->att = -1;
  ret->add = g_add;
  ret->inst = NULL;
  ret->name = get_str_inhib(ret->name);
  return (ret);
}

int	ex_read(t_script *s, t_var **v)
{
  char	*str;
  char	*name;
  t_var	*add;

  str = get_next_line(0);
  name = my_strdup(s->name);
  name = check_var_script(name, 0, *v);
  name = desinhiber(name);
  if (is_in_list(name, v))
    {
      set_var(name, str, v);
      free(name);
      free(str);
    }
  else
    {
      if ((add = malloc(sizeof (*add))) == NULL)
	return (0);
      add->name = name;
      add->tab = NULL;
      add->val = str;
      add->type = V_STR;
      *v = add_in_list(*v, add);
    }
  return (0);
}
