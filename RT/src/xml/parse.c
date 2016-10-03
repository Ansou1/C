#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include "utils.h"
#include "maths.h"

static char	buff_read(int fd)
{
  static char	buffer[PARSE_MAX_SIZE + 1];
  static int	max = 0;
  static int	still = 0;

  if (still < 1)
    {
      still = read(fd, (char *)buffer, PARSE_MAX_SIZE);
      max = still - 1;
    }
  if (still < 1)
    return (-1);
  still--;
  return (buffer[max - still]);
}

static int	read_val(int fd, char *stock, char lim)
{
  char		c;
  int		i;

  i = 0;
  c = buff_read(fd);
  while (c != lim && c != -1 && i < PARSE_MAX_SIZE)
    {
      if (stock != 0)
	stock[i] = c;
      c = buff_read(fd);
      i++;
    }
  if (stock != 0)
    stock[i] = '\0';
  if (c != -1)
    return (1);
  return (0);
}

static t_bool	is_closing(char *name, t_node *parent)
{
  int		i;

  if (parent == 0)
    return (FALSE);
  if (name[0] != '/')
    return (FALSE);
  i = 1;
  while (name[i] && parent->name[i - 1])
    {
      if (name[i] != parent->name[i - 1])
	return (FALSE);
      i++;
    }
  if (name[i] != '\0' || parent->name[i - 1] != '\0')
    return (FALSE);
  return (TRUE);
}

static t_node	*read_nodes(int fd, t_node *parent, int flag)
{
  t_node	*prec;
  t_node	*ret;

  ret = 0;
  while (flag > 0)
    {
      prec = ret;
      ret = w_malloc(sizeof(t_node));
      ret->next = prec;
      if (parent != 0)
	flag = read_val(fd, parent->value, '<');
      else
	flag = read_val(fd, 0, '<');
      flag = read_val(fd, ret->name, '>');
      if (is_closing(ret->name, parent) == TRUE)
	{
	  w_free((void **)&ret);
	  return (prec);
	}
      else if (flag > 0)
	ret->fils = read_nodes(fd, ret, 1);
    }
  w_free((void **)&ret);
  return (prec);
}

void		parse_xml(t_rt *this, char *path)
{
  t_node	*dtree;
  int		fd;

  fd = open(path, O_RDONLY);
  if (fd == -1)
    w_error("Could not open scene-file");
  dtree = read_nodes(fd, 0, 1);
  interpret_dtree(this, dtree);
  free_dtree(dtree);
  (void)close(fd);
}
