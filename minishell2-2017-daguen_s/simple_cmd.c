/*
** simple_cmd.c for mysh in /home/daguen_s//secminishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar  9 12:28:46 2013 simon daguenet
** Last update Sun Mar 10 19:33:09 2013 simon daguenet
*/

#include "mysh.h"

void	processus_son(char **my_env, char **tab_co)
{
  char	**tab_path;
  int	i;

  tab_path = wordtab_dbp(get_path(my_env));
  if (tab_path == NULL)
    my_put_error("Sorry no PATH.\n");
  else
    {
      i = 0;
      while (tab_path[i] != '\0')
        {
          tab_path[i] = my_strcat(tab_path[i], tab_co[0]);
          if (access(tab_path[i], X_OK) == 0)
            {
              execve(tab_path[i], tab_co, my_env);
              exit (0);
            }
          i++;
        }
      if (execve(tab_co[0], tab_co, my_env) == -1)
        {
          my_printf("%s: Command not found.\n", tab_co[0]);
          exit(EXIT_FAILURE);
        }
    }
}

void	processus_father(pid_t pid)
{
  int	status;

  pid = pid;
  wait3(&status, 0, 0);
  if (!WIFEXITED(status))
    {
      if (status == SIGSEGV)
        my_printf("Segmentation fault\n");
      else
        my_printf("Procces quit anormaly\n");
    }
}

void	guid_other_command(char **my_env, char **tab_co)
{
  pid_t	pid;

  if ((pid = fork()) == -1)
    {
      my_putstr("Error: fork problem\n");
      exit(EXIT_FAILURE);
    }
  if (pid == 0)
    processus_son(my_env, tab_co);
  else
    processus_father(pid);
}

void	guid_command(char **my_env, char **tab_co)
{
  tab_co = clean_tab(tab_co);
  if (my_strcmp(tab_co[0], "exit") == 0)
    exit(EXIT_SUCCESS);
  else if (my_strcmp(tab_co[0], "env") == 0)
    my_builtin_env(my_env);
  else if (my_strcmp(tab_co[0], "setenv") == 0)
    my_builtin_setenv(my_env, tab_co);
  else if (my_strcmp(tab_co[0], "unsetenv") == 0)
    my_builtin_unsetenv(my_env, tab_co);
  else if (my_strcmp(tab_co[0], "cd") == 0)
    my_builtin_cd(my_env, tab_co);
  else
    guid_other_command(my_env, tab_co);
}

void	gestion_cmd_other(char **env, char *cmd)
{
  char	**tab_cmd;
  int	redirection;

  redirection = get_redirection(cmd);
  if (redirection != 4)
    gestion_redirection(env, cmd, redirection);
  else
    {
      cmd = my_epurstr(cmd);
      tab_cmd = str_to_wordtab(cmd, " ");
      guid_command(env, tab_cmd);
    }
}

