/*
** buitins_env.c for sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Thu Feb 28 11:12:47 2013 florian corradin
** Last update Tue May 21 13:42:49 2013 florian corradin
*/

#include "42.h"

char	*replace_setenv_line(char *env, char **com)
{
  int	i;
  char	*ret;

  i = my_strlen(com[1]) + 1;
  if (com[2] == NULL)
    {
      env[i] = '\0';
      return (env);
    }
  env[i] = '\0';
  ret = my_strcat(env, com[2]);
  free(env);
  return (ret);
}

char	**my_setenv_rep(char **com, char **env)
{
  char	*str;
  char	**ret;

  str = my_strcat(com[1], "=");
  if (com[2] != NULL)
    str = my_strcat(str, com[2]);
  ret = my_tabcat(env, str);
  return (ret);
}

char	**my_setenv(char **com, char **env)
{
  int	i;
  int	c;

  c = 0;
  i = 0;
  if (com[1] == NULL)
    my_put_tab(env);
  if (com[1] == NULL)
    return (env);
  while (env[i] != NULL)
    {
      if (my_strncmp(com[1], env[i], my_strlen(com[1])) == 1)
  	{
	  if (my_strlen(env[i]) > my_strlen(com[1]))
	    if (env[i][my_strlen(com[1])] == '=')
	      {
		env[i] = replace_setenv_line(env[i], com);
		c = 1;
	      }
  	}
      i++;
    }
  if (c == 0)
    env = my_setenv_rep(com, env);
  return (env);
}

int	sum_size(char **tabl)
{
  int	sum;
  int	i;

  i = 0;
  sum = 0;
  while (tabl[i] != NULL)
    {
      sum += my_strlen(tabl[i]);
      i++;
    }
  return (sum);
}

int	my_env_fct(char **com, int mod)
{
  if (com == NULL || info.env == NULL)
    return (0);
  if (sum_size(info.env) > 500000 && my_strncmp("setenv", com[0], 6) == 1)
    {
      fprintf(stderr, "Env is too big cannot alloc more space\n");
      return (-1);
    }
  if (my_strncmp("setenv", com[0], 6) == 1)
    info.env = my_setenv(com, info.env);
  else if (my_strncmp("unsetenv", com[0], 8) == 1)
    info.env = my_unsetenv(info.env, com, mod);
  if (info.env == NULL)
    return (-1);
  return (0);
}
