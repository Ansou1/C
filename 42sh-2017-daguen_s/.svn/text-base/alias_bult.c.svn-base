/*
** alias_bul.c for 42.h in /home/corrad_f//projet/infect
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Thu Apr 11 21:06:50 2013 florian corradin
** Last update Sun May 12 20:15:59 2013 florian corradin
*/

#include "42.h"
#include "script.h"

char	**get_back_quote_tab(char **com)
{
  int	i;

  i = 0;
  while (com[i] != NULL)
    {
      com[i] = replace_bq_str(com[i], 0);
      i++;
    }
  return (com);
}

char	is_set_alias(char *str)
{
  while (*str)
    {
      if (*str++ == '=')
	return (1);
    }
  return (0);
}

t_alias		*my_set_alias(char *com)
{
  t_alias	*tmp;
  char		*alias;
  char		*line;
  int		i;

  tmp = g_alias;
  alias = get_str_sep(com, '=');
  i = my_strlen(alias);
  line = my_strdup(&com[i + 1]);
  while (tmp != NULL)
    {
      if (my_str_comp(tmp->alias, alias) == 1)
	{
	  free (tmp->com);
	  tmp->com = line;
	  free(alias);
	  return (g_alias);
	}
      tmp = tmp->next;
    }
  g_alias = add_in_alias(alias, line, g_alias);
  free(alias);
  free(line);
  return (g_alias);
}

void		my_put_alias_var(char *com)
{
  t_alias	*tmp;
  char		check;

  tmp = g_alias;
  check = 0;
  while (tmp != NULL)
    {
      if (my_str_comp(com, tmp->alias) == 1)
	{
	  check = 1;
	  printf("%s=%s\n", tmp->alias, tmp->com);
	}
      tmp = tmp->next;
    }
  if (check == 0)
    {
      fprintf(stderr, "alias: %s not found.\n", com);
      fprintf(stderr, "Try alias to print all alias\n");
    }
}

t_alias	*alias_bult(char **com)
{
  int	i;

  i = 1;
  if (my_str_comp(com[0], "alias") == 0)
    return (g_alias);
  if (com[1] == NULL)
    my_put_alias();
  while (com[i] != NULL)
    {
      if (is_set_alias(com[i]))
	g_alias = my_set_alias(com[i]);
      else
	my_put_alias_var(com[i]);
      i++;
    }
  return (g_alias);
}
