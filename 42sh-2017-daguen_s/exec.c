/*
** exec.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sat Mar 30 21:38:29 2013 florian corradin
** Last update Thu May 23 12:46:51 2013 florian corradin
*/

#include "42.h"

char	my_test_com(char *path_bin, char **com)
{
  if (path_bin == '\0' || path_bin == NULL)
    return (0);
  if (access(path_bin, X_OK) == 0)
    {
      execve(path_bin, com, info.env);
      return (1);
    }
  return (0);
}

void	command_not_found(char check, char **com)
{
  if (check == 0)
    {
      put_file(ZOMBIE, YELLOW);
      fprintf(stderr, "%s : command not found\n", com[0]);
      g_statu = -1;
    }
}

void	my_exec(char **com)
{
  char	*path_bin;
  int	i;
  char	check;

  signal(SIGINT, SIG_DFL);
  if (com == NULL || com[0] == NULL)
    kill(getpid(), SIGKILL);
  i = 0;
  check = 0;
  check = my_test_com(com[0], com);
  while (info.path[i] != NULL)
    {
      path_bin = my_strcat(info.path[i], com[0]);
      check = my_test_com(path_bin, com);
      i++;
      free(path_bin);
    }
  if (is_buitins(com) == 1)
    {
      my_bultins(com);
      check = 1;
    }
  check = my_str_comp(com[0], "history") ? 1 : check;
  command_not_found(check, com);
  kill(getpid(), SIGKILL);
}
