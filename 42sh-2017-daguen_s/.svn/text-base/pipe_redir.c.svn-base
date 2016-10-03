/*
** pipe_redir.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Fri Mar 15 20:22:25 2013 florian corradin
** Last update Sun May 26 14:04:47 2013 antoine simon
*/

#include "42.h"

int	get_nbr_of_redir(t_com *list)
{
  while (list)
    {
      if (list->redir == 5 || list->redir == 3)
	return (1);
      list = list->next;
    }
  return (0);
}

void	multipipe_left_file(t_com *list, int cas)
{
  int	fd;
  t_com	*stock;
  char	*bif;
  char	*file;

  bif = NULL;
  stock = list;
  fd = -1;
  file = list->file;
  while (list->next != NULL && list->redir != RIGHT && list->redir != D_RIGHT)
    list = list->next;
  if (list->file == NULL)
    my_put_error("Missing name for redirect.\n");
  else if (list->redir == RIGHT)
    fd = open(list->file, O_CREAT | O_WRONLY | O_TRUNC, RIGHT_OPEN);
  else if (list->redir == D_RIGHT)
    fd = open(list->file, O_CREAT | O_WRONLY | O_APPEND, RIGHT_OPEN);
  if (fd == -1)
    fprintf(stderr, "%s: %s\n", list->file, strerror(errno));
  if (stock->redir == D_LEFT)
    if ((bif = get_buf_redir_left(file)) == NULL)
      kill(getpid(), SIGKILL);
  xdup2(fd, 1, 1);
  multipipe_left(stock, cas, bif);
  xclose(fd, 1);
}

char	*eror_multiredir(t_com *list)
{
  char	*bif;

  bif = NULL;
  if (list->file == NULL)
    my_put_error("Missing name for redirect.\n");
  if (list->commande == NULL)
    my_put_error("Missing name for redirect commande.\n");
  if (list->next->file == NULL)
    my_put_error("Missing name for redirect.\n");
  if (list->next->commande == NULL)
    my_put_error("Missing name for redirect commande.\n");
  if (list->redir == D_LEFT)
    bif = get_buf_redir_left(list->file);
  return (bif);
}

void	multiredir(t_com *list)
{
  int	fd1;
  pid_t	pid;
  int	status;
  char	*bif;

  bif = eror_multiredir(list);
  pid = xfork(1);
  if (pid == 0)
    {
      if (list->next->redir == RIGHT)
	fd1 = open(list->next->file, O_CREAT | O_TRUNC | O_WRONLY, RIGHT_OPEN);
      else
	fd1 = open(list->next->file, O_CREAT | O_APPEND | O_WRONLY, RIGHT_OPEN);
      if (fd1 == -1)
	my_put_error("Cannot open.\n");
      xdup2(fd1, 1, 1);
      if (list->redir == LEFT)
	redir_left(list);
      else
	double_left(list, bif);
      kill(getpid(), SIGKILL);
    }
  else
    wait3(&status, 0, 0);
  kill(getpid(), SIGKILL);
}
