/*
** multipipe.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sat Mar 30 21:40:35 2013 florian corradin
** Last update Sun May 26 14:17:17 2013 antoine simon
*/

#include "42.h"

/* ici si marche plus changer les my_wait par wait 3 */
int	is_multipipe(t_com *list)
{
  while (list->next != NULL)
    {
      if (list->redir != PIPE)
	return (0);
      list = list->next;
    }
  return (1);
}

void	multipipe(t_com *list)
{
  int	p[2];
  pid_t	pid;

  while (list->redir == PIPE)
    {
      if (list->commande == NULL || list->commande[0] == NULL)
      	my_put_error("invalide NULL commande\n");
      xpipe(p, 1);
      pid = xfork(1);
      if (pid == 0)
	{
	  xclose(p[0], 1);
	  xdup2(p[1], 1, 1);
	  my_exec(list->commande);
	  kill(getpid(), SIGKILL);
	}
      xclose(p[1], 1);
      xdup2(p[0], 0, 1);
      list = list->next;
    }
  if (list->commande == NULL)
    my_put_error("invalide NULL commande\n");
  else if (list->commande[0] == NULL)
    my_put_error("invalide NULL commande\n");
  my_exec(list->commande);
}

void	multipipe2(t_com *list)
{
  int	p[2];
  pid_t	pid;

  while (list->redir == PIPE)
    {
      xpipe(p, 1);
      pid = xfork(1);
      if (pid == 0)
	{
	  xclose(p[0], 1);
	  xdup2(p[1], 1, 1);
	  my_exec(list->commande);
	  kill(getpid(), SIGKILL);
	}
      xclose(p[1], 1);
      xdup2(p[0], 0, 1);
      list = list->next;
    }
  if (list->commande == NULL)
    my_put_error("invalide NULL commande\n");
  else if (list->commande[0] == NULL)
    my_put_error("invalide NULL commande\n");
  my_exec(list->commande);
}

void	multipipe_right2(t_com *list, int fd)
{
  pid_t	pid;

  pid = xfork(1);
  if (pid == 0)
    {
      xdup2(fd, 1, 1);
      multipipe(list);
      kill(getpid(), SIGKILL);
    }
  else
    my_wait();
}

void	multipipe_right(t_com *list, int cas)
{
  int	fd;
  t_com	*stock;

  stock = list;
  if (cas == 1)
    while (stock->next != NULL && stock->redir != RIGHT)
      stock = stock->next;
  else
    while (stock->next != NULL && stock->redir != D_RIGHT)
      stock = stock->next;
  if (stock->file == NULL)
    my_put_error("Missing name for redirect\n");
  if (cas == 1)
    fd = open(stock->file, O_WRONLY | O_CREAT | O_TRUNC, RIGHT_OPEN);
  else
    fd = open(stock->file, O_WRONLY | O_APPEND | O_CREAT, RIGHT_OPEN);
  if (fd == -1)
    {
      fprintf(stderr, "Cannot open %s\n", stock->file);
      g_statu = -1;
      kill(getpid(), SIGKILL);
    }
  multipipe_right2(list, fd);
  xclose(fd, 1);
  kill(getpid(), SIGKILL);
}
