/*
** var_env.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Wed Mar 20 14:39:36 2013 florian corradin
** Last update Sun Apr 28 11:50:42 2013 florian corradin
*/

#include "42.h"

char	*other_shell_var(char *com)
{
  if (my_strncmp("$$", com, 2))
    return (my_strdup("$$"));
  if (my_strncmp("$?", com, 2))
    return (my_strdup("$?"));
  return (NULL);
}

char	*get_del_var(char *com)
{
  char	*ret;
  int	i;

  i = 1;
  if ((ret = other_shell_var(com)) != NULL)
    return (other_shell_var(com));
  while (com[i] != '\0' && (is_digit(com[i]) != 0 || is_alpha(com[i]) != 0))
    i++;
  ret = malloc(i + 1);
  if (ret == NULL)
    return (NULL);
  ret[0] = '$';
  i = 1;
  while (com[i] != '\0' && (is_digit(com[i]) != 0 || is_alpha(com[i]) != 0))
    {
      ret[i] = com[i];
      i++;
    }
  ret[i] = '\0';
  return (ret);
}

int	is_var(char *str, int pos)
{
  if (is_digit(str[pos + 1]) == 0 && is_alpha(str[pos + 1]) == 0)
    {
      if (str[pos + 1] != '?' && str[pos + 1] != '$')
	return (0);
    }
  return (1);
}

char	*check_var(char *com, int pos)
{
  int	i;
  char	*ret;
  char	*del;
  char	*rep;

  ret = NULL;
  i = pos;
  while (com[i] != '\0')
    {
      if (is_c(com, i, '$') == 1 && is_var(com, i) == 1)
	{
	  if ((del = get_del_var(&com[i])) == NULL)
	    return (NULL);
	  if ((rep = get_value_of_var(del)) == NULL)
	    return (com);
	  ret = replace_in_str(com, del, rep, i);
	  return (check_var(ret, i));
	}
      i++;
    }
  if (ret != NULL)
    return (ret);
  else
    return (com);
}
