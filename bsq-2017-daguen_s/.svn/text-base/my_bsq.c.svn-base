/*
** my_bsq.c for bsq in /home/daguen_s/
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Dec  3 19:13:53 2012 simon daguenet
** Last update Sun Dec  9 21:12:36 2012 simon daguenet
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	get_line(char *av)
{
  int	fd = open(av, O_RDONLY);
  char	*s;
  int	i;

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
    exit(EXIT_FAILURE);
  close(fd);
  return (i);
}

char	**get_file(char *av, char **tab, int nbr_line)
{
  int	fd = open(av, O_RDONLY);
  char	*s;
  int	i;

  s = NULL;
  tab = malloc(sizeof(*tab) * (nbr_line + 1));
  if (fd != -1)
    {
      i = 0;
      while ((s = get_next_line(fd)))
        {
          tab[i] = my_strdup(s);
	  i++;
	  free(s);
        }
      tab[i] = NULL;
    }
  else
    exit (EXIT_FAILURE);
  close(fd);
  return (tab);
}

void	get_square(t_data *elem, char **tab, int nbr_line)
{
  int	x;
  int	y;

  x = elem->x + 1;
  y = elem->y + 1;
  while (x != 0)
    {
      if (tab[y][x] == '.')
	x--;
      else
	elem->x++;
    }
  while (y != 0)
    {
      if (tab[y][x] == '.')
	y--;
      else
	elem->x++;
    }
}

void	get_files(char **tab, int nbr_line)
{
  t_data	elem;

  elem.y = 0;
  while (tab[elem.y])
    {
      elem.x = 0;
      while (tab[elem.y][elem.x] == '\0')
	{
	  if (tab[elem.y][elem.x] == '.')
	    get_square(&elem, tab, nbr_line);
	  else
	    elem.x++;
	}
      elem.y++;
    }
}

int	main(int ac, char **av, char **env)
{
  int	nbr_line;
  char	**tab;
  int	i;

  nbr_line = 0;
  if (ac > 2 || av[1] == NULL || env[0] == NULL)
    exit(EXIT_FAILURE);
  else
    {
      nbr_line = get_line(av[1]);
      tab = get_file(av[1], tab, nbr_line);
      get_files(tab, nbr_line);
     }
  return (0);
}
