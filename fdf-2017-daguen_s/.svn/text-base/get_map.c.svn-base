/*
** fdf.c for fdf in /home/daguen_s//Ighaph/fdf
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Dec  2 21:53:49 2012 simon daguenet
** Last update Sat Dec  8 17:23:05 2012 simon daguenet
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_fdf.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

int	get_nbr_line(char *av)
{
  int	fd;
  char	*s;
  int	i;

  fd = open(av, O_RDONLY);
  s = NULL;
  i = 0;
  if (fd == -1)
      exit(EXIT_FAILURE);
  if (fd != -1)
    {
      while ((s = get_next_line(fd)))
        {
	  i++;
          free(s);
	}
    }
  close(fd);
  return (i);
}

char	***get_map(char *av, int i)
{
  int	fd;
  char	*s;
  char	***tab;

  fd = open(av, O_RDONLY);
  s = NULL;
  tab = malloc(sizeof(*tab) * (i + 2));
  if (tab == NULL)
    exit(EXIT_FAILURE);
  i = 0;
  if (fd == -1)
      exit(EXIT_FAILURE);
  if (fd != -1)
    {
      while ((s = get_next_line(fd)))
        {
	  tab[i] = my_str_to_wordtab(s);
	  i++;
          free(s);
	}
      tab[i] = NULL;
    }
  close(fd);
  return (tab);
}

int	main(int ac, char **av, char **env)
{
  int	i;
  char	***tab;

  i = 0;
  if (ac > 2 || av[1] == NULL || env[0] == NULL)
    {
      my_putstr("Failure entry argument\n");
      exit(EXIT_FAILURE);
    }
  else
    {
      i = get_nbr_line(av[1]);
      tab = get_map(av[1], i);
      if (i > 20)
      	{
      	  my_putstr("too heavy for my software\n");
      	  exit(EXIT_FAILURE);
      	}
      display_screen(tab, i);
    }
  return (0);
}
