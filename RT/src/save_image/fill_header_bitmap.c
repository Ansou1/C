#include"rt.h"

static t_bool	write_size_img(int fd)
{
  int	val;

  val = WIN_WIDTH;
  if (x_write(fd, &val, 4) == -1)
    return (FALSE);
  val = WIN_HEIGHT;
  if (x_write(fd, &val, 4) == -1)
    return (FALSE);
  val = 1;
  if (x_write(fd, &val, 1) == -1)
    return (FALSE);
  val = 0;
  if (x_write(fd, &val, 1) == -1)
    return (FALSE);
  val = 32;
  if (x_write(fd, &val, 2) == -1)
    return (FALSE);
  return (TRUE);
}

t_bool	fill_header_bitmap(int fd)
{
  int	val;
  int	i;

  val = 40;
  if (x_write(fd, &val, 4) == -1)
    return (FALSE);
  if (!write_size_img(fd))
    return (FALSE);
  i = 0;
  val = 0;
  while (i < 6)
    {
      if (x_write(fd, &val, 4) == -1)
	return (FALSE);
      ++i;
    }
  return (TRUE);
}
