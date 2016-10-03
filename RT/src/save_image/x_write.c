#include<unistd.h>

#include"utils.h"

int	x_write(int fd, const void *buf, int count)
{
  if (write(fd, buf, count) == -1)
    {
      print_error("Write Failed\n");
      return (-1);
    }
  return (0);
}
