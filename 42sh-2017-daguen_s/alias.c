/*
** alias.c for infectsh in /home/corrad_f//projet/infect/allias
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Thu Apr 11 14:25:57 2013 florian corradin
** Last update Thu May 23 13:51:14 2013 simon daguenet
*/

#include "42.h"

t_alias		*add_in_alias(char *alias, char *com, t_alias *list)
{
  t_alias	*tmp;
  t_alias	*add;

  tmp = list;
  add = malloc(sizeof (*add));
  if ((add->alias = my_strdup(alias)) == NULL)
    return (NULL);
  if ((add->com = my_strdup(com)) == NULL)
    return (NULL);
  add->next = NULL;
  if (list == NULL)
    return (add);
  while (list->next != NULL)
    {
      list = list->next;
    }
  list->next = add;
  return (tmp);
}

char	*my_replace_alias(char *str, char *del, char *rep)
{
  char	*ret;
  int	i;
  int	a;

  i = 0;
  a = 0;
  ret = malloc(my_strlen(rep) + my_strlen(str) + 1);
  while (rep[i] != '\0')
    ret[a++] = rep[i++];
  i = my_strlen(del);
  while (str[i] != '\0')
    ret[a++] = str[i++];
  ret[a] = '\0';
  free(str);
  return (ret);
}

char	*get_alias_loop(t_alias *alias, char *com)
{
  int	ctr;

  ctr = 0;
  if (alias == NULL)
    return (com);
  while (ctr != -1 && ctr < 10)
    {
      com = modif_com_line(alias, com, &ctr);
    }
  if (ctr >= 10)
    {
      my_put_error2("Alias loop.\n");
      return (NULL);
    }
  return (com);
}

int	alias_match(char *com, char *path)
{
  int	i;

  i = 0;
  while (com[i] != '\0' && path[i] != '\0')
    {
      if (com[i] != path[i])
	return (0);
      i++;
    }
  if (path[i] != '\0')
    return (0);
  if (com[i] != ' ' && com[i] != '\t' && com[i] != '\0')
    return (0);
  return (1);
}

char	*modif_com_line(t_alias *alias, char *com, int *ctr)
{
  char	check;

  check = 0;
  if (alias == NULL)
    return (com);
  while (alias != NULL)
    {
      if (alias_match(com, alias->alias) == 1 &&
	  my_strncmp(alias->com, com, my_strlen(alias->com)) != 1)
	{
	  check = 1;
	  *ctr = *ctr + 1;
	  com = my_replace_alias(com, alias->alias, alias->com);
	}
      if (com == NULL)
	return (NULL);
      alias = alias->next;
    }
  if (check == 0)
    *ctr = -1;
  return (com);
}
