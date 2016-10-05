/*
** xfunction.c for  in /home/daguen_s/rendu/PSU_2013_myscript
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Fri Feb 28 17:06:35 2014 daguen_s
** Last update Fri Feb 28 17:31:09 2014 daguen_s
*/

#include "my_script.h"

int			xopen(char *pathname, int flags)
{
  int			fd;

  fd = open(pathname, flags);
  if (fd >= 0)
    return (fd);
  fprintf(stderr, "Error in open function (file: %s)\n", pathname);
  return (0);
}

int			xclose(int fd)
{
  int			my_fd;

  my_fd = close(fd);
  if (my_fd != 0)
    fprintf(stderr, "Error with close function.\n");
  return (0);
}

int			xdup2(int fd_old, int fd_new)
{
  if (dup2(fd_old, fd_new) != -1)
    return (0);
  fprintf(stderr, "Error with dup2 function.\n");
  exit(EXIT_FAILURE);
}

int			xread(int fd, char *str, size_t size)
{
  int			i;

  i = read(fd, str, size);
  if (i == -1)
    {
      fprintf(stderr, "Error with read.\n");
      return (-1);
    }
  return (i);
}

int			xwrite(int fd, char *str, size_t size)
{
  int			i;

  i = write(fd, str, size);
  if (i == -1)
    {
      fprintf(stderr, "Error with write.\n");
      return (-1);
    }
  return (i);
}
