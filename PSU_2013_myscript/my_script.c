/*
** my_script.c for  in /home/daguen_s/Projets/my_script
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Fri Feb  7 17:27:22 2014 daguen_s
** Last update Wed Mar  5 15:55:50 2014 daguen_s
*/

#include "my_script.h"

int			my_openpty(int *aslave, t_opt *opt)
{
  int			master;
  int			slave;
  char			*path;

  master = my_posix_openpt(O_RDWR);
  path = my_ptsname(master);
  if (my_unlockpt(master) == -1)
    return (-1);
  slave = xopen(path, O_RDWR | O_NOCTTY);
  if (tcsetattr(slave, TCSAFLUSH, &opt->term) == -1)
    return (-1);
  if (ioctl(slave, TIOCGWINSZ, &opt->win) == -1)
    return (-1);
  opt->fd_master = master;
  *aslave = slave;
  return (0);
}

pid_t			my_forkpty(t_opt *opt)
{
  int			aslave;
  pid_t			pid;

  opt->term.c_lflag |= ECHO;
  if (my_openpty(&aslave, opt) != -1)
    {
      sigwinch(1);
      if ((pid = fork()) != -1)
	{
	  if (pid == 0)
	    {
	      xclose(opt->fd_master);
	      return (my_login_tty(aslave) == -1) ? (-1) : (0);
	    }
	  else
	    {
	      xclose(aslave);
	      return (pid);
	    }
	}
      fprintf(stderr, "ERROR fork in my_forkpty.\n");
      return (-1);
    }
  fprintf(stderr, "ERROR my_openpty in my_forkpty.\n");
  return (-1);
}

int			the_son(t_opt *opt)
{
  char			*shell;

  if ((shell = getenv("SHELL")) == NULL)
    shell = strdup("/bin/sh");
  if (opt->c == 1)
    {
      if (execlp(shell, shell, "-c", opt->command, NULL) == -1)
	fprintf(stderr, "ERROR in execlp, shell is [%s].\n", shell);
    }
  else
    if (execlp(shell, shell, NULL) == -1)
      fprintf(stderr, "ERROR in execlp, shell is [%s].\n", shell);
  return (-1);
}

int			the_father(t_opt *opt, pid_t pid)
{
  fd_set		fd_in;
  int			status;

  write_time(opt, 1);
  while (waitpid(pid, &status, WNOHANG) != pid)
    {
      FD_ZERO(&fd_in);
      FD_SET(0, &fd_in);
      FD_SET(opt->fd_master, &fd_in);
      if (select(opt->fd_master + 1, &fd_in, NULL, NULL, NULL) != -1
	  || errno == EINTR)
	{
	  if (writting_data(opt, &fd_in) == -1)
	    return (-1);
	}
      else
	{
	  fprintf(stderr, "Error on select in the_father.\n");
	  return (-1);
	}
    }
  return (0);
}

int			main(int ac, char **av)
{
  pid_t			pid;

  opt = xmalloc(sizeof(t_opt));
  if (get_params(ac, av, opt))
    {
      if ((pid = my_forkpty(opt)) < 0)
	{
	  fprintf(stderr, "ERROR with forkpty in main.\n");
	  set_back_termios(opt);
	  exit(EXIT_FAILURE);
	}
      if (pid == 0)
	the_son(opt);
      else
	the_father(opt, pid);
      write_time(opt, 0);
      xclose(opt->my_fd);
    }
  else
    fprintf(stderr, USAGE);
  set_back_termios(opt);
  return (EXIT_SUCCESS);
}
