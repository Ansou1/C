/*
** grimly.c for grinmly in /home/daguen_s//rush
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Fri Mar  1 20:14:10 2013 simon daguenet
** Last update Sun Mar  3 14:31:12 2013 simon daguenet
*/

#include "rush.h"

char	**map_in_tab(char **map, int fd, int taille, int *width)
{
  int	var[4];
  char	*s;

  var[0] = 0;
  var[1] = 0;
  while ((s = get_next_line(fd)))
    {
      if (var[1] == 0)
      	get_first_line(s, &var[3], width, 0);
      if (var[3] == 0 || *width == 0 || (var[3] != taille - 1))
	my_print_error("MAP ERROR\n");
      if ((var[1] != 0) && ((var[2] = my_strlen(s)) != *width))
	my_print_error("MAP ERROR\n");
      if (var[1] != 0)
	check_map(s);
      if (var[1] != 0)
	var[0] = var[0] + check_door(s);
      map[var[1]] = s;
      var[1]++;
    }
  map[var[1]] = NULL;
  if (var[0] != 3)
    my_print_error("MAP ERROR\n");
  return (map);
}

int	**put_in_map(char **tab, int taille, int width, int i)
{
  int	j;
  int	**map;

  map = xmalloc(sizeof(int**) * (taille + 1));
  while (tab[i])
    {
      map[i] = xmalloc(sizeof(int*) * (width + 1));
      j = 0;
      while (tab[i][j])
	{
	  if (tab[i][j] == '1')
	    map[i][j] = 1;
	  else if (tab[i][j] == '2')
	    map[i][j] = -2;
	  else if (tab[i][j] == '*')
	    map[i][j] = -3;
	  else if (tab[i][j] == ' ')
	    map[i][j] = -4;
	  j++;
	}
      map[i][j] = 0;
      i++;
    }
  map[i] = 0;
  return (map);
}

int	**get_map(char *av, t_laby *s)
{
  int	**map;
  int	fd;
  char	**tab;
  int	taille;
  int	width;

  taille = get_line(av);
  tab = xmalloc(sizeof (char **) * (taille + 1));
  fd  = open(av, O_RDONLY);
  if (fd != -1)
    tab = map_in_tab(tab, fd, taille, &width);
  else
    my_print_error("cannot read\n");
  map = put_in_map(tab, taille, width, 0);
  xclose(fd);
  s->size_x = width;
  s->size_y = taille;
  return (map);
}

int		main(int ac, char **av)
{
  char		*str;
  int		**map;
  t_laby	s;

  if ((ac != 3) || (my_strcmp(av[1], "-f") != 0)
      || ((str = strstr(av[2], ".map")) == NULL))
    my_print_error("Usage: ./grimly -f fichier.map\n");
  map = get_map(av[2], &s);
  s.tab = map;
  s.algo = map;
  aff_tab(&s);
  return (0);
}
