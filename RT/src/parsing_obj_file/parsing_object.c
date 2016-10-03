#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "rt.h"
#include "utils.h"
#include "parsing.h"
#include "get_next_line.h"

static char *get_name(char *path)
{
  char	*name;
  int	i;

  i = 0;
  while (path[i])
    ++i;
  while (i >= 0 && path[i] != '/')
    --i;
  if ((name = x_strdup(path + i + 1)) == NULL)
    return (NULL);
  return (name);
}

static int	error_file(char *name)
{
  print_error("Error loading '");
  print_error(name);
  print_error("'\nExample of file: scene.obj\n");
  return (-1);
}

static int	open_file(char *path, t_obj *this)
{
  int	fd;
  int	size;

  if ((this->name = get_name(path)) == NULL)
    return (-1);
  if ((size = my_strlen(this->name)) < 5)
    return (error_file(this->name));
  if (my_strcmp(this->name + size - 4, ".obj") != 0)
    return (error_file(this->name));
  if ((fd = open(path, O_RDONLY)) != -1)
    return (fd);
  print_error("Error loading '");
  print_error(this->name);
  print_error("': Open 3D file failed.\n");
  return (-1);
}

static t_bool	fill_obj(t_obj *this, char **line, char *str)
{
  if (my_strcmp(line[0], "v") == 0)
    {
      if (get_point_token(this, line, str) == FALSE)
	return (FALSE);
    }
  else if (my_strcmp(line[0], "vn") == 0)
    {
      if (get_normal_token(this, line, str) == FALSE)
	return (FALSE);
    }
  else if (my_strcmp(line[0], "f") == 0)
    {
      if (get_tri_list_token(this, line, str) == FALSE)
	return (FALSE);
    }
  free(str);
  free(line);
  return (TRUE);
}

t_tri_list	*parsing_object(char *path)
{
  t_obj	this;
  char	**line;
  char	*str;

  this.triangle = NULL;
  this.point = NULL;
  this.normal = NULL;
  this.id_p = 0;
  this.id_n = 0;
  if ((this.fd = open_file(path, &this)) == -1)
    return (NULL);
  while ((str = get_next_line(this.fd)))
    {
      if ((line = str_to_wt(str)) == NULL)
	return (NULL);
      if (line == (void*)-1)
	free(str);
      else if (line != (void*)-1 && fill_obj(&this, line, str) == FALSE)
	return (NULL);
    }
  if (close(this.fd) == -1)
    print_error("Close error\n");
  return (fill_triangle_in_list(&this));
}
