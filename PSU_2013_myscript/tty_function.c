/*
** tty_function.c for  in /home/daguen_s/rendu/PSU_2013_myscript
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Fri Feb 28 17:08:18 2014 daguen_s
** Last update Sat Mar  1 16:27:49 2014 daguen_s
*/

#include "my_script.h"

int			my_login_tty(int fd)
{
  if (setsid() != -1)
    {
      if (ioctl(fd, TIOCSCTTY, 0) != -1)
	{
	  xclose(0);
	  xclose(1);
	  xclose(2);
	  xdup2(fd, 0);
	  xdup2(fd, 1);
	  xdup2(fd, 2);
	  return (0);
	}
      fprintf(stderr, "Error with ioctl in my_login_tty.\n");
      return (-1);
    }
  fprintf(stderr, "Error with setsid in my_login_tty.\n");
  return (-1);
}

int			my_posix_openpt(int flags)
{
  return (xopen("/dev/ptmx", flags));
}

char			*my_ptsname(int fd_master)
{
  int			fd_slave;
  char			*path_name;

  if (ioctl(fd_master, TIOCGPTN, &fd_slave) != -1)
    {
      path_name = xmalloc(20 * sizeof(char));
      sprintf(path_name, "/dev/pts/%d", fd_slave);
      return (path_name);
    }
  else
    fprintf(stderr, "Error with ioctl in my_ptsname.\n");
  return (NULL);
}

int			my_grantpt(int fd_master)
{
  char			*path_slave;

  path_slave = my_ptsname(fd_master);
  if (path_slave != NULL && chown(path_slave, getuid(), getgid()) != -1
      && chmod(path_slave, S_IRUSR | S_IWUSR | S_IWGRP) != -1)
    return (0);
  fprintf(stderr, "Error with my_grantpt.\n");
  return (-1);
}

int			my_unlockpt(int fd_master)
{
  int			a;

  a = 0;
  if (ioctl(fd_master, TIOCSPTLCK, &a) != -1)
    return (0);
  fprintf(stderr, "Error with my_unlockpt.\n");
  return (-1);
}
