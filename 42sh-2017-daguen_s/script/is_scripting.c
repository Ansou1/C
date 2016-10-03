/*
** is_scripting.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Fri Mar 29 18:58:42 2013 florian corradin
** Last update Thu May 23 14:58:47 2013 simon daguenet
*/

#include "42.h"

char	is_scripting2(int fd1, char *buf)
{
  if (buf == NULL)
    return (0);
  xclose(fd1, 1);
  if (buf[0] == '\0')
    return (0);
  else if (my_strncmp("#!infect", buf, 8))
    return (1);
  return (0);
}

int	free_and_ret(char *s, int ret)
{
  free(s);
  return (ret);
}

char		is_scripting(char *com)
{
  int		fd1;
  int		fd;
  char		*file;
  unsigned int	i;
  char		buf[250];

  i = 0;
  while (com[i] != '\0' && com[i] != ' ' && com[i] != '\t')
    i++;
  if ((file = malloc(i + 1)) == NULL)
    return (0);
  i = 0;
  while (com[i] != '\0' && com[i] != ' ' && com[i] != '\t')
    {
      file[i] = com[i];
      i++;
    }
  file[i] = '\0';
  if ((fd1 = open(file, O_RDONLY)) == -1)
    return (free_and_ret(file, 0));
  free(file);
  if ((fd = read(fd1, &buf, 249)) == -1)
    return (0);
  buf[fd] = '\0';
  return (is_scripting2(fd1, my_strdup(buf)));
}
