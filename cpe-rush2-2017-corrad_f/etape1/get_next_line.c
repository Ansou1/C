/*
** get_next_line.c for sudoku_bi in /home/daguen_s//rush
**
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
**
** Started on  Fri Apr 19 20:44:44 2013 simon daguenet
** Last update Sun Apr 21 10:47:21 2013 simon daguenet
*/

#include "sudoku.h"

int	new_line(char *str)
{
  int	cnt;

  cnt = -1;
  while (str[++cnt])
    if (str[cnt] == '\n')
      return (1);
  return (0);
}

char	*my_cpy(char *buff, char *out)
{
  int	cnt1;
  int	cnt2;
  char	buf_cpy[4097];

  cnt1 = -1;
  cnt2 = -1;
  memset(buf_cpy, 0, 4097);
  while (out[++cnt1]);
  while (buff[++cnt2] && buff[cnt2] != '\n')
    out[cnt1++] = buff[cnt2];
  cnt1 = -1;
  while (++cnt1 <= 4096)
    if (++cnt2 <= 4096)
      buff[cnt1] = buff[cnt2];
    else
      buff[cnt1] = 0;
  return (out);
}

char		*my_realloc(char *str, int size)
{
  static int	realloc_size;

  if (str != NULL)
    {
      str = realloc(str, (realloc_size + size));
      realloc_size += 4096;
    }
  if (str == NULL)
    {
      realloc_size = 0;
      return (NULL);
    }
  return (str);
}

char		*get_next_line(const int fd)
{
  static char	buffer[4097];
  char		*out;

  out = xmalloc((4097) * sizeof(*out));
  memset(out, 0, 4097);
  while (new_line(buffer) == 0)
    {
      if ((out = my_realloc(out, 4097)) == NULL)
	return (NULL);
      out = my_cpy(buffer, out);
      if (read(fd, buffer, 4096) < 1)
	if (buffer[0] == 0)
	  {
	    if (out != NULL && out[0] && my_realloc(NULL, 0) == NULL)
	      return (out);
	    else
	      {
		free(out);
		return (NULL);
	      }
	  }
    }
  if ((out = my_realloc(out, 4097)) == NULL)
    return (NULL);
  return (my_cpy(buffer, out));
}
