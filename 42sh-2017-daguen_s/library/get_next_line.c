/*
** get_next_line.c for my_get_next_line.c in /home/corrad_f//projet/getnextline
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Fri Nov 16 16:17:02 2012 florian corradin
** Last update Thu May 23 14:18:08 2013 simon daguenet
*/

#include "42.h"

void	error_read()
{
  my_putstr("cannot read\n");
  exit(0);
}

char	*my_memset(char *str, char c, int size)
{
  int	i;

  str = malloc(size + 1);
  str[size] = '\0';
  if (str == NULL)
    return (NULL);
  i = 0;
  while (i < size)
    {
      str[i] = c;
      i++;
    }
  return (str);
}

char	*my_strcopy(char *ret, char *copy)
{
  char	*new_str;
  int	i;
  int	a;
  int	len2;

  len2 = my_strlen(copy);
  i = 0;
  a = 0;
  new_str = malloc(my_strlen(ret) + len2 + 1);
  while (ret[i] != 0)
    {
      new_str[i] = ret[i];
      i++;
    }
  while (copy[a] != 0)
    {
      new_str[i] = copy[a];
      i++;
      a++;
    }
  new_str[i] = 0;
  free(ret);
  free(copy);
  return (new_str);
}

char	*next_line(char *buf, int *pos, char *ret)
{
  int	i;
  char	*copy;

  copy = malloc(4096 + 1);
  i = 0;
  while (buf[*pos] != 0 && buf[*pos] != '\n')
    {
      copy[i] = buf[*pos];
      i++;
      *pos = *pos + 1;
    }
  if (buf[*pos] == 0)
    *pos = 0;
  else
    *pos = *pos + 1;
  copy[i] = 0;
  ret = my_strcopy(ret, copy);
  return (ret);
}

char		*get_next_line(const int fd)
{
  static char	buf[4096 + 1];
  static int	pos;
  static int	a;
  int		check;
  char		*ret;

  if (a == 1)
    return (NULL);
  check = 4096;
  ret = my_memset(ret, 0, 4096 + 1);
  if (ret == 0)
    return (NULL);
  if (buf[pos - 1] == '\n' && pos != 0)
    ret = next_line(buf, &pos, ret);
  while (check == 4096 && pos == 0)
    {
      check = read(fd, buf, 4096);
      buf[check] = '\0';
      if (check == -1)
	error_read();
      ret = next_line(buf, &pos, ret);
    }
  if (my_strlen(buf) != 4096 && pos == 0)
    a = 1;
  return (ret);
}
