/*
** get_next_line1.c for get_next_line in /home/daguen_s//get_next_line2/1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Nov 25 11:25:34 2012 simon daguenet
** Last update Sat Dec  8 14:38:50 2012 simon daguenet
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"my_fdf.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	lenght;

  lenght = my_strlen(dest);
  i = 0;
  while (src[i] != '\0')
    {
      dest[lenght + i] = src[i];
      i = i + 1;
    }
  dest[lenght + i] = '\0';
  return (dest);
}

char	*my_realloc(char *str, int size)
{
  char	*new_str;

  if (size == 0)
    return (str);
  new_str = malloc((my_strlen(str) + size + 1) * sizeof(*str));
  if (new_str == NULL)
    return (NULL);
  *new_str = '\0';
  my_strcat(new_str, str);
  *str = '\0';
  free(str);
  return (new_str);
}

int	check_line(char *line, char *buff)
{
  int	nb;

  nb = 0;
  while (line[nb] != '\0')
    {
      if (line[nb] == '\n')
        {
          line[nb] = '\0';
          *buff = '\0';
          my_strcat(buff, &line[nb + 1]);
          return (-1);
        }
      nb++;
    }
  *buff = '\0';
  return (0);
}

char	*get_next_line(const int fd)
{
  int	i;
  char	*line;
  static char	buff[BUFF_S];

  if (READ_S <= 0)
    return (NULL);
  line = malloc(BUFF_S * sizeof(*line));
  if (fd < 0 || line == NULL)
    return (NULL);
  *line = '\0';
  my_strcat(line, buff);
  *buff = '\0';
  i = READ_S;
  while (check_line(line, buff) != -1 && i == READ_S)
    {
      i = read(fd, buff, READ_S);
      if (i == -1)
        exit(EXIT_FAILURE);
      buff[i] = '\0';
      line = my_realloc(line, i);
      my_strcat(line, buff);
    }
  if (*line == '\0' && my_strlen(buff) == 0 && i != READ_S)
    return (0);
  return (line);
}
