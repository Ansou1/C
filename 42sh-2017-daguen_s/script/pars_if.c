/*
** pars_if.c for script in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Mon May  6 18:51:48 2013 florian corradin
** Last update Mon May  6 18:52:32 2013 florian corradin
*/

#include "42.h"
#include "script.h"

t_script	*get_fi(char *file)
{
  t_script	*ret;

  ret = xmalloc(sizeof (t_script));
  ret->type = FI;
  ret->name = NULL;
  ret->att = -1;
  ret->add = g_add;
  ret->inst = NULL;
  ret->tab = NULL;
  return (ret);
}

t_script	*get_then(char *file)
{
  t_script	*ret;

  ret = xmalloc(sizeof (t_script));
  ret->type = THEN;
  ret->name = NULL;
  ret->att = -1;
  ret->add = g_add;
  ret->inst = NULL;
  ret->tab = NULL;
  return (ret);
}

t_script	*get_else(char *file)
{
  t_script	*ret;

  ret = xmalloc(sizeof (t_script));
  ret->type = ELSE;
  ret->name = NULL;
  ret->att = -1;
  ret->add = g_add;
  ret->inst = NULL;
  ret->tab = NULL;
  return (ret);
}

t_script	*get_else_if(char *file, int pos)
{
  int		i;
  t_script	*ret;

  ret = xmalloc(sizeof (t_script));
  ret->type = ELSE_IF;
  ret->name = NULL;
  ret->att = -1;
  ret->tab = NULL;
  ret->add = g_add;
  i = 6;
  while (file[i] != ' ' && file[i] != '\0' && file[i] != '\t')
    i++;
  if (file[i] == '\0' || file[i + 1] != '[')
    {
      g_stop_script = -1;
      fprintf(stderr, "Error bad syntaxe in if line: %d %s\n", pos + 1, file);
      return (NULL);
    }
  ret->inst = my_strdup(&file[i]);
  return (ret);
}

t_script	*get_key_if(char *file, int pos)
{
  int		i;
  t_script	*ret;

  ret = xmalloc(sizeof (t_script));
  ret->type = IF;
  ret->name = NULL;
  ret->att = -1;
  ret->add = g_add;
  ret->tab = NULL;
  i = 0;
  while (file[i] != ' ' && file[i] != '\0' && file[i] != '\t')
    i++;
  if (file[i] == '\0' || file[i + 1] != '[')
    {
      g_stop_script = -1;
      fprintf(stderr, "Error bad syntaxe in if line: %d %s\n", pos + 1, file);
      return (NULL);
    }
  ret->inst = my_strdup(&file[i]);
  return (ret);
}
