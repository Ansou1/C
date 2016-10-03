/*
** pipe.c for mysh in /home/daguen_s//secminishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar  9 12:14:39 2013 simon daguenet
** Last update Sat Mar  9 12:15:41 2013 simon daguenet
*/

#include "mysh.h"

void	exec_pipe(char **my_env, char *tab_co)
{
  char	**tab_path;
  char	**tab;
  int	i;

  tab = str_to_wordtab(tab_co, " ");
  tab_path = wordtab_dbp(get_path(my_env));
  if (tab_path == NULL)
    my_putstr("Sorry no PATH.\n");
  else
    {
      i = 0;
      while (tab_path[i] != '\0')
        {
          tab_path[i] = my_strcat(tab_path[i], tab[0]);
          if (access(tab_path[i], X_OK) == 0)
            {
              execve(tab_path[i], tab, my_env);
	      exit(0);
	    }
          i++;
        }
    }
  exit(0);
}

void	my_dup(int old, int new)
{
  int	error;

  error = dup2(old, new);
  if (error == -1)
    error_with_function(3);
}

void	inf_pipe(char **env, char **pipe_cmd, int nbr_pipe)
{
  int	pipefd[2];
  int	pid;
  int	i;

  i = 0;
  while (i < nbr_pipe - 1)
    {
      xpipe(pipefd);
      pid = xfork();
      if (pid == 0)
        {
          xclose(pipefd[0]);
          my_dup(pipefd[1], 1);
	  exec_pipe(env, pipe_cmd[i]);
	  exit(1);
        }
      xclose(pipefd[1]);
      my_dup(pipefd[0], 0);
      i++;
    }
  if (my_strstr(pipe_cmd[i], ">") == NULL)
    exec_pipe(env, pipe_cmd[i]);
  else
    gestion_cmd_other(env, pipe_cmd[i]);
  exit (0);
}

void	gestion_cmd_pipe(char **env, char **pipe_cmd, int taille)
{
  int	pid;

  if (taille == 1)
    my_putstr("invalid null command\n");
  pid = xfork();
  if (pid == 0)
    inf_pipe(env, pipe_cmd, taille);
  else
    waitpid(pid, NULL, 0);
}
