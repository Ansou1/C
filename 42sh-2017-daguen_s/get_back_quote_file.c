/*
** get_back_quote_file.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sat Mar 30 21:34:11 2013 florian corradin
** Last update Thu May 23 14:12:38 2013 simon daguenet
*/

#include "42.h"

char	*get_next_file(int fd)
{
  char	*buf;
  char	*save;
  int	ctr;

  if ((buf = malloc(4096)) == NULL)
    return (NULL);
  if ((ctr = read(fd, buf, 4095)) == -1)
    return (NULL);
  buf[ctr] = '\0';
  while (ctr == 4096)
    {
      if ((save = malloc(4096)) == NULL)
	return (NULL);
      if ((ctr = read(fd, save, 4095)) == -1)
	return (NULL);
      save[ctr] = '\0';
      if ((buf = my_strcat_free_all(buf, save)) == NULL)
	return (NULL);
    }
  return (buf);
}

char	*get_bq_rep(char *com)
{
  char	*rep;
  int	i;
  int	pos;

  i = 0;
  while (com[i] != '\0' && is_c(com, i, '`') == 0)
    i++;
  if (com[i] == '\0')
    return (NULL);
  pos = i;
  pos++;
  i = 0;
  while (is_c(com, i + pos, '`') == 0 && com[i + pos] != '\0')
    i++;
  if ((rep = malloc(i + 1)) == NULL)
    return (NULL);
  i = 0;
  while (is_c(com, i + pos, '`') == 0 && com[i + pos] != '\0')
    {
      rep[i] = com[pos + i];
      i++;
    }
  rep[i] = '\0';
  return (rep);
}
