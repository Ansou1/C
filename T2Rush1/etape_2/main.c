/*
** main.c for  in /home/daguen_s/rendu/T2Rush1
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Fri Mar  7 20:35:35 2014 daguen_s
** Last update Sun Mar  9 19:03:06 2014 daguen_s
*/

#include "rush.h"

void	my_freetab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

char	**realloc_tab(char **tab, char *str)
{
  char	**ret;
  int	i;

  i = 0;
  if (tab != NULL)
    while (tab[i])
      i++;
  ret = xmalloc(sizeof (char *) * (i + 2));
  i = 0;
  if (tab == NULL)
    {
      ret[0] = str;
      ret[1] = NULL;
      return (ret);
    }
  while (tab[i])
    {
      ret[i] = tab[i];
      i++;
    }
  ret[i] = str;
  ret[i + 1] = NULL;
  free(tab);
  return (ret);
}

char	**get_map(char *file)
{
  char	**map;
  char	*s;
  int	fd;

  map = NULL;
  if ((fd = xopen(file, O_RDONLY)) != 0)
    while ((s = get_next_line(fd)) != NULL)
      {
	if (strlen(s) > 60)
	  {
	    fprintf(stderr, USAGE);
	    exit(EXIT_FAILURE);
	  }
	map = realloc_tab(map, s);
      }
  xclose(fd);
  return (map);
}

int	main()
{
  get_map_by_menu();
  return (EXIT_SUCCESS);
}

