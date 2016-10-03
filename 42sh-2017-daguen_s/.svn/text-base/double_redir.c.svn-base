/*
** double_redir.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sat Mar 16 12:30:51 2013 florian corradin
** Last update Thu May 23 17:52:22 2013 simon daguenet
*/

#include "42.h"

int	is_continue(char *file, char *buf)
{
  if (my_str_comp(file, "EOF") == 1 && buf[0] == 0)
    return (1);
  else if (buf[0] == 0)
    return (1);
  if (my_strncmp(file, buf, my_strlen(file)) == 1)
    return (1);
  return (0);
}

char	*get_buf_redir_left(char *file)
{
  char	*bif;
  char	buf[1001];
  int	fd;

  bif = malloc(1);
  bif[0] = '\0';
  my_putstr("? ");
  if ((fd = read(0, buf, 999)) == -1)
    return (NULL);
  buf[fd] = '\0';
  if (is_continue(file, buf) != 1)
    if ((bif = my_strcat_free_strt(bif, buf)) == NULL)
      return (NULL);
  while (is_continue(file, buf) != 1)
    {
      my_putstr("? ");
      if ((fd = read(0, buf, 999)) == -1)
        return (NULL);
      buf[fd] = '\0';
      if (is_continue(file, buf) != 1)
	if ((bif = my_strcat_free_strt(bif, buf)) == NULL)
	  return (NULL);
    }
  bif = module_str(bif);
  return (bif);
}

void	double_left(t_com *list, char *bif)
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
      my_putstr(bif);
      kill(getpid(), SIGKILL);
    }
  else
    {
      wait3(&status, 0, 0);
      free(bif);
      xclose(p[1], 1);
      xdup2(p[0], 0, 1);
      my_exec(list->commande);
      kill(getpid(), SIGKILL);
    }
}

void	redir_right(t_com *list, int cas)
{
  int	fd;

  if (cas == RIGHT)
    fd = open(list->file, O_CREAT | O_WRONLY | O_TRUNC, RIGHT_OPEN);
  else
    fd = open(list->file, O_CREAT | O_APPEND | O_WRONLY, RIGHT_OPEN);
  if (fd == -1)
    {
      fprintf(stderr, "%s: %s\n", list->file, strerror(errno));
      kill(getpid(), SIGKILL);
    }
  xdup2(fd, 1, 1);
  my_exec(list->commande);
  xclose(fd, 1);
  kill(getpid(), SIGKILL);
}

void	redir_simple(t_com *list, int cas)
{
  char	*bif;

  if (list->file == NULL)
    my_put_error("Missing name for redirect.\n");
  if (list->commande == NULL)
    my_put_error("Invalide null commande.\n");
  if (cas == D_LEFT)
    {
      if ((bif = get_buf_redir_left(list->file)) == NULL)
	kill(getpid(), SIGKILL);
      double_left(list, bif);
    }
  else if (cas == LEFT)
    redir_left(list);
  else
    redir_right(list, cas);
}
