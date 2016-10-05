/*
** xfunction.c for  in /home/daguen_s/rendu/nm-objdump/src_obj
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Mar 13 12:27:00 2014 daguen_s
** Last update Sat Mar 15 15:59:19 2014 daguen_s
*/

#include "nm.h"

int		xaccess(char *file)
{
  if (access(file, F_OK) == -1)
    {
      fprintf(stderr, "ERROR access.\n");
      return (-1);
    }
  return (0);
}

int		xopen(char *pathname, int flags)
{
  int		fd;

  fd = open(pathname, flags);
  if (fd >= 0)
    return (fd);
  fprintf(stderr, "ERROR in open function (file: %s)\n", pathname);
  return (-1);
}

int		xclose(int fd)
{
  int		my_fd;

  my_fd = close(fd);
  if (my_fd != 0)
    fprintf(stderr, "ERROR with close function.\n");
  return (0);
}

long		xlseek(int fd)
{
  long		size;

  if ((size = lseek(fd, 0, SEEK_END)) == -1)
    {
      fprintf(stderr, "ERROR in lseek: %s\n", strerror(errno));
      return (-1);
    }
  return (size);
}

void		*xmmap(int fd, char *file, unsigned int size)
{
  void		*data;

  if ((data = mmap(NULL, size, PROT_READ, MAP_SHARED, fd, 0)) == MAP_FAILED)
    {
      xclose(fd);
      fprintf(stderr, "ERROR in mmap with file [%s].\n", file);
      return (MAP_FAILED);
    }
  return (data);
}
