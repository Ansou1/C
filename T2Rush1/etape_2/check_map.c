/*
** check_map.c for  in /home/daguen_s/rendu/T2Rush1/etape_1
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Sat Mar  8 10:39:31 2014 daguen_s
** Last update Sun Mar  9 17:52:40 2014 daguen_s
*/

#include "rush.h"

int	check_inside(char **map, int width, int tab[4])
{
  while (map[++tab[2]])
    {
      if (width != (int)strlen(map[tab[2]]))
	{
	  fprintf(stderr, "ERROR in map.\n");
	  return (0);
	}
      tab[3] = -1;
      while (map[tab[2]][++tab[3]])
	{
	  if ((strchr("wsmoiklg.", map[tab[2]][tab[3]])) == NULL)
	    {
	      fprintf(stderr, "ERROR in map.\n");
	      return (0);
	    }
	  if (map[tab[2]][tab[3]] == 'i')
	    tab[0]++;
	  if (map[tab[2]][tab[3]] == 'o')
	    tab[1]++;
	}
    }
  if (tab[0] != 1 || tab[1] != 1)
    return (0);
  return (1);
}

int	check_in_map(char **map, int width)
{
  int	tab[4];
  int	result;

  tab[0] = 0;
  tab[1] = 0;
  tab[2] = -1;
  result = check_inside(map, width, tab);
  if (result == 8)
    {
      fprintf(stderr, "ERROR in map.\n");
      return (0);
    }
  return (result);
}

int	check_validity_map(char **map)
{
  int	width;
  int	i;

  if (((width = strlen(map[0])) < 3) || (get_h(map) < 3))
    {
      fprintf(stderr, "ERROR in map.\n");
      return (0);
    }
  i = -1;
  while (map[0][++i])
    if (map[0][i] != 'w' || map[get_h(map) - 1][i] != 'w')
      {
	fprintf(stderr, "ERROR in map.\n");
	return (0);
      }
  i = -1;
  while (map[++i])
    {
      if (map[i][0] != 'w' || map[i][strlen(map[i]) - 1] != 'w')
	{
	  fprintf(stderr, "ERROR in map.\n");
	  return (0);
	}
    }
  return (check_in_map(map, width));
}

int		call_map(char *file)
{
  char		**map;

  map = get_map(file);
  if (map != NULL && check_validity_map(map))
    display_by_sdl(map);
  return (0);
}

int		chosen_map(int x, int y)
{
  if ((x > 10 && x < 245) && (y > 10 && y < 70))
    return (call_map("./map/map1.map"));
  else if ((x > 10 && x < 245) && (y > 90 && y < 150))
    return (call_map("./map/map2.map"));
  else if ((x > 10 && x < 245) && (y > 170 && y < 230))
    return (call_map("./map/map3.map"));
  else if ((x > 10 && x < 245) && (y > 250 && y < 310))
    return (call_map("./map/map4.map"));
  else if ((x > 10 && x < 245) && (y > 330 && y < 390))
    return (call_map("./map/map5.map"));
  return (1);
}
