/*
** pipe.c for minishell2 in /home/corrad_f//projet/minishell2
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sat Feb  9 11:32:30 2013 florian corradin
** Last update Sat May 25 14:19:55 2013 florian corradin
*/

#include "42.h"

void	redir_left(t_com *list)
{
  int	fd;
  pid_t	pid;
  int	status;

  if (list->file == NULL)
    my_put_error("Missing file name for redirect.\n");
  if (list->commande[0] == NULL)
    my_put_error("Invalide null command.\n");
  fd = open(list->file, O_RDONLY);
  if (fd == -1)
    {
      fprintf(stderr, "%s: %s\n", list->file, strerror(errno));
      kill(getpid(), SIGKILL);
    }
  pid = xfork(1);
  if (pid == 0)
    {
      xdup2(fd, 0, 1);
      my_exec(list->commande);
      kill(getpid(), SIGKILL);
    }
  else
    wait3(&status, 0, 0);
  xclose(fd, 1);
}

void	multi_pipe_left_s(t_com *list)
{
  pid_t	pid;
  int	p[2];
  int	status;

  xpipe(p, 1);
  pid = xfork(1);
  if (pid == 0)
    {
      xclose(p[0], 1);
      xdup2(p[1], 1, 1);
      redir_left(list);
      kill(getpid(), SIGKILL);
    }
  else
    {
      wait3(&status, 0, 0);
      xclose(p[1], 1);
      xdup2(p[0], 0, 1);
      list = list->next;
      list = list->next;
    }
  multipipe2(list);
}

void	multi_pipe_left_d(t_com *list, char *bif)
{
  pid_t	pid;
  int	p[2];
  int	status;

  xpipe(p, 1);
  pid = xfork(1);
  if (pid == 0)
    {
      xclose(p[0], 1);
      xdup2(p[1], 1, 1);
      double_left(list, bif);
      kill(getpid(), SIGKILL);
    }
  else
    {
      wait3(&status, 0, 0);
      xclose(p[1], 1);
      xdup2(p[0], 0, 1);
      list = list->next;
      list = list->next;
      multipipe2(list);
    }
}

void	multipipe_left(t_com *list, int cas, char *bif)
{
  if (cas == LEFT)
    multi_pipe_left_s(list);
  else if (cas == D_LEFT)
    {
      if (bif == NULL)
	bif = get_buf_redir_left(list->file);
      multi_pipe_left_d(list, bif);
      kill(getpid(), SIGKILL);
    }
}
