#include <fcntl.h>
#include <unistd.h>

#include "utils.h"

static int	read_ssize(int size, void *ret, int fd)
{
  if (read(fd, ret, size) != size)
    return (1);
  return (0);
}

static int	ignore_header(int fd)
{
  int		i;
  int		tmp;
  int		tmp2;

  i = 0;
  i += read_ssize(4, &tmp, fd);
  i += read_ssize(2, &tmp2, fd);
  i += read_ssize(2, &tmp2, fd);
  i += read_ssize(4, &tmp, fd);
  i += read_ssize(4, &tmp, fd);
  i += read_ssize(4, &tmp, fd);
  i += read_ssize(4, &tmp, fd);
  i += read_ssize(2, &tmp2, fd);
  i += read_ssize(2, &tmp2, fd);
  i += read_ssize(4, &tmp, fd);
  i += read_ssize(4, &tmp, fd);
  i += read_ssize(4, &tmp, fd);
  i += read_ssize(4, &tmp, fd);
  i += read_ssize(4, &tmp, fd);
  i += read_ssize(4, &tmp, fd);
  return (i);
}

static int	**parse_error(char *path)
{
  (void)path;
  w_warning("Image parse error");
  return (0);
}

static int	**read_data(int fd, int xsize, int ysize, char *path)
{
  int	i;
  int	j;
  int	cur;
  int	**ret;

  cur = 0;
  i = ysize - 1;
  ret = w_malloc(sizeof(int *) * ysize);
  while (i >= 0)
    {
      j = 0;
      ret[i] = w_malloc(sizeof(int) * xsize);
      while (j < xsize)
	{
	  if (read_ssize(3, &cur, fd) != 0)
	    return (parse_error(path));
	  ret[i][j] = cur;
	  j++;
	}
      i--;
    }
  if (close(fd) == -1)
    w_warning("Close error.\n");
  return (ret);
}

int		**load_image(char *path, int xsize, int ysize)
{
  int		fd;
  unsigned char	magics[2];

  fd = open(path, O_RDONLY);
  if (fd < 0)
    return (parse_error(path));
  if (read_ssize(1, &magics[0], fd) != 0
      || read_ssize(1, &magics[1], fd) != 0)
    return (parse_error(path));
  if (magics[0] != 'B' || magics[1] != 'M')
    return (parse_error(path));
  if (ignore_header(fd) != 0)
    return (parse_error(path));
  if (xsize == 0)
    xsize = 100;
  if (ysize == 0)
    ysize = 100;
  return (read_data(fd, xsize, ysize, path));
}
