/*
** change_directory.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sat Mar 30 21:29:24 2013 florian corradin
** Last update Tue May 21 13:55:03 2013 florian corradin
*/

#include "42.h"

char	*my_get_pwd(void)
{
  char	*pwd;

  pwd = malloc(1000);
  if (pwd == NULL)
    return (NULL);
  pwd = getcwd(pwd, 1000);
  return (pwd);
}

int	replace_env(void)
{
  char	**tabl;
  char	*pwd;

  if ((pwd = my_get_pwd()) == NULL)
    return (FAIL);
  if ((tabl = malloc(sizeof (char **) * 4)) == NULL)
    return (FAIL);
  tabl[3] = NULL;
  if ((pwd = my_get_pwd()) == NULL)
    return (FAIL);
  if ((tabl[0] = my_strdup("setenv")) == NULL)
    return (FAIL);
  if ((tabl[1] = my_strdup("PWD")) == NULL)
    return (FAIL);
  tabl[2] = pwd;
  info.env = my_setenv(tabl, info.env);
  if (info.env == NULL)
    return (FAIL);
  if (info.env[0] == NULL)
    return (FAIL);
  my_free_tab(tabl);
  return (SUCCESS);
}

/* ne peut pas echouer */
void	replace_old_pwd(char *rep)
{
  if (info.old_pwd != NULL)
    free(info.old_pwd);
  info.old_pwd = rep;
}

int	go_home(int mod)
{
  char	*pwd;
  char	*home;

  pwd = my_get_pwd();
  home = my_getenv("HOME");
  if (chdir(home) == 0)
    {
      replace_old_pwd(pwd);
      return (replace_env());
    }
  else
    {
      if (mod == 1)
	fprintf(stderr, "Cannot find home.\n");
      g_statu = -1;
      return (SUCCESS);
    }
  return (SUCCESS);
}

int	go_back(int mod)
{
  char	*pwd;

  if (info.old_pwd == NULL)
    {
      if (mod == 1)
	{
	  put_file(DOG, GREEN);
	  fprintf(stderr, "Old_pwd is empty.\n");
	}
      g_statu = -1;
      return (SUCCESS);
    }
  if ((pwd = my_get_pwd()) == NULL)
    return (FAIL);
  if (chdir(info.old_pwd) == 0)
    {
      replace_old_pwd(pwd);
      return (replace_env());
    }
  else
    g_statu = -1;
  put_file(WOLF, GREEN);
  if (mod == 1)
    fprintf(stderr, "Cannot change directory.\n");
  return (SUCCESS);
}
