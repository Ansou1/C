/*
** case.c for script in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Sat May  4 18:57:10 2013 florian corradin
** Last update Sun May  5 20:37:04 2013 florian corradin
*/

#include "42.h"
#include "script.h"

t_script	*get_case_header(char *file, int line)
{
  t_script	*ret;
  int		i;

  i = 0;
  if ((ret = xmalloc(sizeof (*ret))) == NULL)
    {
      g_stop_script = -1;
      return (NULL);
    }
  while (file[i] != ' ' && file[i] != '\t' && file[i])
    i++;
  if (file[i] == '\0')
    my_put_error_script("Error missing value for case", line);
  ret->inst = get_next_word(&file[i]);
  ret->name = NULL;
  ret->tab = NULL;
  ret->add = g_add;
  ret->att = -1;
  ret->type = CASE;
  return (ret);
}

t_script	*get_one_case(char *file, int line)
{
  t_script	*ret;
  int		i;

  i = 0;
  if ((ret = xmalloc(sizeof (*ret))) == NULL)
    {
      g_stop_script = -1;
      return (NULL);
    }
  ret->name = get_str_sep(file, ')');
  i = my_strlen(ret->name);
  if (file[i] != ')')
    my_put_error_script("Error missing ) for case", line);
  if (file[i] == ')')
    i++;
  while (file[i] == ' ' || file[i] == '\t')
    i++;
  ret->inst = get_str_inhib(my_strdup(&file[i]));
  ret->tab = NULL;
  ret->add = g_add;
  ret->att = -1;
  ret->type = CASE;
  return (ret);
}

t_script	*get_case_end(char *file, int line)
{
  t_script	*ret;

  if ((ret = xmalloc(sizeof (*ret))) == NULL)
    {
      g_stop_script = -1;
      return (NULL);
    }
  ret->inst = NULL;
  ret->name = NULL;
  ret->tab = NULL;
  ret->add = g_add;
  ret->att = -1;
  ret->type = ESAC;
  return (ret);
}

t_script	**get_case(char **file, t_script **p, int *pos)
{
  p[*pos] = get_case_header(file[*pos], *pos);
  *pos = *pos + 1;
  while (my_strncmp(file[*pos], "esac", 4) != 1)
    {
      p[*pos] = get_one_case(file[*pos], *pos);
      *pos = *pos + 1;
      if (file[*pos] == NULL)
	{
	  my_put_error_script("Error missing end of case", *pos);
	  return (p);
	}
    }
  p[*pos] = get_case_end(file[*pos], *pos);
  return (p);
}

int	ex_case(t_script **s, t_var **v, int *i)
{
  char	*cas;

  cas = my_strdup(s[*i]->inst);
  cas = check_var_script(cas, 0, *v);
  cas = replace_bq_str(cas, 0);
  while (s[*i] != NULL)
    {
      if (s[*i]->type == ESAC)
	return (0);
      if (s[*i]->name != NULL)
	{
	  if (my_str_comp(cas, s[*i]->name))
	    ex_com(s, v, *i);
	}
      *i = *i + 1;
    }
  return (0);
}
