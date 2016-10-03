#include <stdlib.h>
#include <unistd.h>

#include "utils.h"
#include "get_next_line.h"

static int	get_strlen(char *s)
{
  int		i;

  i = 0;
  while (s[i] != '\0')
    i++;
  return (i);
}

static int	set_next(char *prec, char *new, char *res)
{
  int		i;
  int		tmp;

  i = 0;
  tmp = 0;
  while (new[tmp] != '\0')
    {
      if (new[tmp] != '\n' || tmp != 0)
	prec[i++] = new[tmp++];
      else
	tmp++;
    }
  prec[i] = '\0';
  *res = '\0';
  return (0);
}

static int	bufferize(char *read, char *ret, char* prec, int size)
{
  int		i;
  int		cur_p;
  int		prec_p;

  i = 0;
  cur_p = 0;
  prec_p = get_strlen(ret);
  read[size] = '\0';
  while (prec[i] != '\0' && prec[i] != '\n' && prec_p + cur_p < MAX_LSIZE)
    ret[prec_p + cur_p++] = prec[i++];
  if (prec[i] == '\n' || prec_p + cur_p == MAX_LSIZE)
    return (set_next(prec, &(prec[i]), &(ret[prec_p + cur_p])));
  i = 0;
  while (i < size && read[i] > '\0' &&
	 read[i] != '\n' && prec_p + cur_p < MAX_LSIZE)
    ret[prec_p + cur_p++] = read[i++];
  if (read[i] == '\n' || prec_p + cur_p == MAX_LSIZE)
    return (set_next(prec, &(read[i]), &(ret[prec_p + cur_p])));
  set_next(prec, &(read[i]), &(ret[prec_p + cur_p]));
  return (1);
}

static int	init_tmps(char **buffer,
		    char **result,
		    char **not_read,
		    int *tmp)
{
  if (*not_read == 0)
    {
      *not_read = w_malloc(sizeof(char) * READ_SIZE + 1);
      if (*not_read != 0)
	(*not_read)[0] = '\0';
    }
  *result = w_malloc(sizeof(char) * (MAX_LSIZE + 1));
  *buffer = w_malloc(sizeof(char) * (READ_SIZE + 1));
  if (*buffer == 0 || *result == 0 || *not_read == 0)
    return (0);
  *tmp = 1;
  (*result)[0] = '\0';
  (*buffer)[0] = '\0';
  return (1);
}

char		*get_next_line(const int fd)
{
  static char	*not_read = 0;
  char		*buffer;
  char		*result;
  int		tmp;
  int		i;

  if (init_tmps(&buffer, &result, &not_read, &tmp) == 0)
    return (0);
  i = 0;
  while (tmp > 0)
    {
      tmp = bufferize(buffer, result, not_read, tmp);
      if (tmp > 0 && (i++ >= 0))
	{
	  tmp = read(fd, buffer, READ_SIZE);
	  if (tmp == -1 || (tmp == 0 && i - 1 == 0 && result[0] == '\0'))
	    {
	      free(buffer);
	      free(result);
	      return (0);
	    }
	}
    }
  free(buffer);
  return (result);
}
