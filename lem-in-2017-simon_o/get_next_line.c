/*
** get_next_line.c for lemin in /home/daguen_s//my_lemin
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Apr  1 20:46:07 2013 simon daguenet
** Last update Mon Apr  1 20:46:10 2013 simon daguenet
*/

#include "lemin.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = src[i];
  return (dest);
}

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (dest[n] != '\0')
    n++;
  while (src[i] != '\0')
    {
      dest[n + i] = src[i];
      i = i + 1;
    }
  dest[n + i] = '\0';
  return (dest);
}

int	my_buf(char *buffer, char *buffer_s, int ret)
{
  int	i;

  i = 0;
  if (ret == 0)
    return (1);
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '\n')
	{
	  buffer[i] = '\0';
	  my_strcpy(buffer_s, &buffer[i + 1]);
	  return (1);
	}
      i++;
    }
  return (0);
}

char	*my_realloc(char *buffer, int size)
{
  char	*buffer_tmp;

  buffer_tmp = NULL;
  if (size > 0)
    if ((buffer_tmp = malloc(size * sizeof(*buffer_tmp))) == NULL)
      {
	free(buffer);
	return (NULL);
      }
  if (buffer != NULL)
    {
      my_strcpy(buffer_tmp, buffer);
      free(buffer);
    }
  return (buffer_tmp);
}

char		*get_next_line(const int fd)
{
  int		ret;
  static char	buffer_s[SIZE_READ + 1];
  char		*buff;
  char		buffer_tmp[SIZE_READ + 1];
  int		i;

  i = 2;
  if ((buff = malloc((i++ * SIZE_READ + 1))) == NULL)
    return (NULL);
  my_strcpy(buff, buffer_s);
  buffer_s[0] = '\0';
  ret = 1;
  while (my_buf(buff, buffer_s, ret) != 1)
    {
      if ((ret = read(fd, buffer_tmp, SIZE_READ)) == -1)
	return (NULL);
      buffer_tmp[ret] = '\0';
      my_strcat(buff, buffer_tmp);
      if ((buff = my_realloc(buff, i++ * SIZE_READ + 1)) == NULL
	  || (buff[0] == 0))
	return (NULL);
      if (ret == 0)
	return (buff);
    }
  return (buff);
}
