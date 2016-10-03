/*
** management_error.c for corewar in /home/corrad_f//projet/champion/commande
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Fri Feb  1 11:00:08 2013 florian corradin
** Last update Fri Mar 29 14:44:41 2013 simon daguenet
*/

#include "asm.h"

int	is_label(char *line)
{
  int	i;

  i = 0;
  while (line[i] != '\0' && line[i] != ':')
    {
      if (line[i] < 'a' || line[i] > 'z')
	if ((line[i] < '0' || line[i] > '9') && line[i] != '_')
	  return (0);
      i++;
    }
  if (line[i] != ':')
    return (0);
  return (1);
}

int	is_header(char	*line)
{
  if (line == NULL)
    return (0);
  if (line[0] == '\0')
    return (1);
  if (is_label(line) == 0 && check_mnemo(line) == 0)
    return (1);
  else
    return (0);
}

void	my_put_error(char *msg1, char *msg2, int line, int mode)
{
  if (line != -1)
    {
      my_putstr("line :");
      my_put_nbr(line);
      my_putstr(" :");
    }
  if (msg1 != NULL)
    {
      my_putstr(msg1);
      my_putchar('\n');
    }
  if (msg2 != NULL)
    {
      my_putstr(msg2);
      my_putchar('\n');
    }
  if (mode == 1)
    exit(0);
}

char	*get_mnemo(char *file)
{
  int	i;
  char	*ret;

  i = 0;
  while (file[i] != '\0' && file[i] != ' ' && file[i] != '\t')
    i++;
  ret = xmalloc(i + 1);
  ret[i] = '\0';
  i = 0;
  while (file[i] != '\0' && file[i] != ' ' && file[i] != '\t')
    {
      ret[i] = file[i];
      i++;
    }
  return (ret);
}

int	manag_eror(int line, char *av)
{
  int	fd;
  char	*s;
  char	**ret;
  int	i;

  i = 0;
  ret = malloc(sizeof (char **) * (line + 1));
  check_malloc(ret);
  fd = open(av, O_RDONLY);
  if (fd == -1)
    return (0);
  while ((s = get_next_line(fd)) != NULL && (i < line))
    {
      s = my_epurstr(s);
      ret[i] = s;
      i++;
    }
  ret[i] = NULL;
  my_check_the_file(ret);
  my_free_tab(ret);
  return (0);
}
