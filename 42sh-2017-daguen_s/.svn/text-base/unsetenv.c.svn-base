/*
** unsetenv.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sat Mar 30 21:36:23 2013 florian corradin
** Last update Wed May  8 10:41:52 2013 florian corradin
*/

#include "42.h"

char	*is_unset(char **env, char *com)
{
  int	is;
  int	i;
  char	*check;

  i = 0;
  is = 0;
  if ((check = my_strcat(com, "=")) == NULL)
    return (NULL);
  i = 0;
  while (env[i] != NULL)
    {
      if (my_strncmp(check, env[i], my_strlen(check)) == 1)
  	is = 1;
      i++;
    }
  if (is != 1)
    {
      free(check);
      return (NULL);
    }
  else
    return (check);
}

char	**dell_env_line(char **env, char *com)
{
  int	i;
  char	*check;
  char	**ret;
  int	ctr;

  ctr = 0;
  if ((check = is_unset(env, com)) == NULL)
    return (env);
  i = 0;
  if ((ret = malloc(sizeof (char *) * (my_tablen(env) + 1))) == NULL)
    return (NULL);
  while (env[i] != NULL)
    {
      if (my_strncmp(check, env[i], my_strlen(check)) == 1)
	i++;
      if (env[i] == NULL)
	ret[ctr] = NULL;
      else if ((ret[ctr] = my_strdup(env[i])) == NULL)
	return (env);
      ctr++;
      if (env[i] != NULL)
	i++;
    }
  ret[ctr] = NULL;
  return (ret);
}

char	**my_unsetenv(char **env, char **com, int mod)
{
  int	i;

  i = 1;
  if (env[0] == NULL)
    return (env);
  if (com[1] == NULL)
    {
      if (mod == 1)
	my_putstr("unsetenv: Too few arguments.\n");
      return (env);
    }
  if (com[1][0] == '*')
    {
      my_free_tab(env);
      env = xmalloc(sizeof (char *));
      env[0] = NULL;
      return (env);
    }
  while (com[i] != NULL)
    {
      env = dell_env_line(env, com[i]);
      i++;
    }
  return (env);
}
