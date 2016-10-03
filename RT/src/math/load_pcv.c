#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include "maths.h"
#include "utils.h"

static double	read_val(int fd, int *error)
{
  double	val;

  if (read(fd, &val, 8) <= 0)
    {
      w_warning("Read .pcv failed");
      *error = -1;
    }
  return (val);
}

int	try_load(double *values, char *path, int data_size)
{
  int	fd;
  int	i;

  fd = open(path, O_RDONLY);
  if (fd == -1)
    {
      w_warning("Open .pcv failed");
      return (-1);
    }
  i = 0;
  while (i < data_size && i != -1)
    {
      values[i] = read_val(fd, &i);
      if (i != -1)
	i++;
    }
  if (close(fd) == -1)
    w_warning("Close .pcv failed");
  if (i == -1)
    return (-1);
  return (1);
}
