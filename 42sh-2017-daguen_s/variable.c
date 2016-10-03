/*
** variable.c for infectsh in /home/corrad_f//projet/infect
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Sun Apr 28 09:56:33 2013 florian corradin
** Last update Sun May 26 14:17:16 2013 antoine simon
*/

#include "42.h"

char	*get_not_env_var(char *str)
{
  char	*ret;

  if (my_strncmp(&str[1], "SECONDS", 7))
    {
      ret = malloc(30);
      sprintf(ret, "%d", get_seconds());
      return (ret);
    }
  else if (my_strncmp(&str[1], "RANDOM", 6))
    {
      ret = malloc(30);
      sprintf(ret, "%d", get_rand());
      return (ret);
    }
  return (NULL);
}

char	*get_other_shell_var(char *str)
{
  char	*ret;

  if (str[0] != '$')
    return (NULL);
  if (str[1] == '$')
    {
      if ((ret = malloc(12)) == NULL)
	return (NULL);
      sprintf(ret, "%d", getpid());
      return (ret);
    }
  if (str[1] == '?')
    {
      if ((ret = malloc(12)) == NULL)
	return (NULL);
      sprintf(ret, "%d", g_old_com);
      return (ret);
    }
  return (get_not_env_var(str));
}
