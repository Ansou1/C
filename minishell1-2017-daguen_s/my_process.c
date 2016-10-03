/*
** my_fonction7.c for mysh in /home/daguen_s//my_minishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Dec 23 12:31:08 2012 simon daguenet
** Last update Sun Dec 23 12:38:34 2012 simon daguenet
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <unistd.h>
#include <dirent.h>
#include <signal.h>
#include "mysh.h"

void	processus_son(char **my_env, char **tab_co)
{
  char	**tab_path;
  int	i;

  tab_path = wordtab_dbp(get_path(my_env));
  if (tab_path == NULL)
    my_putstr("Sorry no PATH.\n");
  i = 0;
  while (tab_path[i] != '\0')
    {
      if (access(my_strcat_furui(tab_path[i], tab_co[0]), X_OK) == 0)
        execve(tab_path[i], tab_co, my_env);
      i++;
    }
  if (execve(tab_co[0], tab_co, my_env) == -1)
    {
      my_printf("%s: Command not found.\n", tab_co[0]);
      exit(EXIT_FAILURE);
    }
}

void	processus_father(pid_t pid)
{
  int	status;

  pid = pid;
  wait(&status);
  if (!WIFEXITED(status))
    {
      if (status == SIGSEGV)
        my_printf("Segmentation fault\n");
      else
        my_printf("Procces quit anormaly\n");
    }
}

char	*get_pwd_for_oldpwd(char **my_env, char *command)
{
  int	i;
  char	*tab;

  i = 0;
  while (my_env[i])
    {
      if (my_strncmp(my_env[i], command, 3) == 0)
        {
          tab = my_strdup_oldpwd(my_env[i]);
          i++;
        }
      else
        i++;
    }
  return (tab);
}

void	put_my_oldpwd(char **my_env, char **env_for_cd)
{
  env_for_cd[0] = "setenv";
  env_for_cd[1] = "OLDPWD";
  env_for_cd[2] = get_pwd_for_oldpwd(my_env, "PWD");
  env_for_cd[3] = NULL;
  my_builtin_setenv(my_env, env_for_cd);
}

char	*get_value_user(char **my_env, char *command)
{
  int	i;
  char	*tab;

  i = 0;
  while (my_env[i])
    {
      if (my_strncmp(my_env[i], command, 5) == 0)
        {
          tab = my_strdup_user(my_env[i]);
          i++;
        }
      else
        i++;
    }
  tab = my_strcat(tab, "/");
  return (tab);
}
