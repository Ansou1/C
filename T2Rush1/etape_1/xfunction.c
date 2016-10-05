/*
** xfunction.c for  in /home/daguen_s/rendu/T2Rush1/etape_1
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Sat Mar  8 10:37:44 2014 daguen_s
** Last update Sat Mar  8 10:38:06 2014 daguen_s
*/

#include "rush.h"

void	*xmalloc(size_t taille)
{
  void	*ptr;

  if (taille == 0)
    return (NULL);
  ptr = malloc(taille);
  if (ptr == NULL)
    {
      fprintf(stderr, "Error in Xmalloc.\n");
      exit(EXIT_FAILURE);
    }
  return (ptr);
}

int	xopen(char *pathname, int flags)
{
  int	fd;

  fd = open(pathname, flags);
  if (fd >= 0)
    return (fd);
  fprintf(stderr, "Error in open function (file: %s)\n", pathname);
  exit(EXIT_FAILURE);
}

int	xclose(int fd)
{
  int	my_fd;

  my_fd = close(fd);
  if (my_fd != 0)
    fprintf(stderr, "Error with close function.\n");
  return (0);
}
