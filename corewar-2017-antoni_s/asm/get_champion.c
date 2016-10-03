/*
** get_champion.c for corewar in /home/daguen_s//corewar/my_corewar
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Wed Jan 23 15:05:43 2013 simon daguenet
** Last update Fri Mar 29 14:12:06 2013 simon daguenet
*/

#include "asm.h"

int	get_line(char *av)
{
  int	fd;
  char	*s;
  int	i;

  fd  = open(av, O_RDONLY);
  i = 0;
  s = NULL;
  if (fd != -1)
    {
      while (s = get_next_line(fd))
        {
	  i++;
          free(s);
        }
    }
  else
    {
      my_putstr("cannot read\n");
      exit(EXIT_FAILURE);
    }
  xclose(fd);
  return (i);
}

char	***get_file(char *name)
{
  char	***ret;
  int	line;
  int	fd;
  char	*s;
  int	ctr;

  ctr = 0;
  line = get_line(name);
  ret = malloc(sizeof (char ***) * (line + 1));
  ret[line] = NULL;
  check_malloc(ret);
  line = 0;
  if ((fd = open(name, O_RDONLY)) == -1)
    exit(EXIT_FAILURE);
  while ((s = get_next_line(fd)) != NULL)
    {
      s = my_epurstr(s);
      if (s[0] != '\0')
	ret[line++] = my_str_to_wordtab(s);
      free(s);
    }
  ret[line] = NULL;
  xclose(fd);
  return (ret);
}

void	put_word_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      my_putchar(' ');
      i++;
    }
}

void	put_file_tab(char ***tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      put_word_tab(tab[i]);
      my_putchar('\n');
      i++;
    }
}
