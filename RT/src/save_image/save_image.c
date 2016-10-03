#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#include"rt.h"
#include"utils.h"

static t_bool	fill_header_file(int fd)
{
  int	val;

  if (x_write(fd, "BM", 2) == -1)
    return (FALSE);
  val = 54 + ((WIN_HEIGHT * WIN_WIDTH));
  if (x_write(fd, &val, 4) == -1)
    return (FALSE);
  val = 42;
  if (x_write(fd, &val, 4) == -1)
    return (FALSE);
  val = 54;
  if (x_write(fd, &val, 4) == -1)
    return (FALSE);
  return (TRUE);
}

static t_bool	fill_image(t_rt *this, int fd)
{
  t_color	color;
  t_uint	x;
  t_uint	y;

  y = WIN_HEIGHT;
  while (y > 0)
    {
      x = 0;
      while (x < WIN_WIDTH)
	{
	  color = get_pixel_color(this->win, x, y);
	  if (x_write(fd, &color, 4) == -1)
	    return (FALSE);
	  ++x;
	}
      --y;
    }
  return (TRUE);
}

void	save_image(t_rt *this, char *name_file)
{
  int	fd;

  if (name_file == NULL)
    return ;
  if ((fd = open(name_file, O_CREAT | O_TRUNC | O_WRONLY, 0664)) == -1)
    {
      print_error("Open failed\n");
      return ;
    }
  fill_header_file(fd);
  fill_header_bitmap(fd);
  fill_image(this, fd);
}
