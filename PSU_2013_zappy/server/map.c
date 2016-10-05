/**
 * \file map.c
 * \brief All about map
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * map.
 *
 */

#include "map.h"

/**
 * \fn void pop_on_line(t_map *line, const int size)
 * \brief proba pop elem
 *
 * \param t_map *line, const int size
 * \return none.
 */

void      pop_on_line(const unsigned int *percent, t_map *line, const int size)
{
  int     i;

  i = -1;
  while (++i < size)
  {
    line[i].linemate += (RANDOM_PERCENT(percent[LINEMATE]) ? 1 : 0);
    line[i].deraumere += (RANDOM_PERCENT(percent[DERAUMERE]) ? 1 : 0);
    line[i].sibur += (RANDOM_PERCENT(percent[SIBUR]) ? 1 : 0);
    line[i].mendiane += (RANDOM_PERCENT(percent[MENDIANE]) ? 1 : 0);
    line[i].phiras += (RANDOM_PERCENT(percent[PHIRAS]) ? 1 : 0);
    line[i].thystame += (RANDOM_PERCENT(percent[THYSTAME]) ? 1 : 0);
    line[i].food += (RANDOM_PERCENT(percent[FOOD]) ? 1 : 0);
  }
}

void            put_ressource_at_random(t_map **m, const unsigned int height, const unsigned int width, const e_ressource r)
{
  if (r == FOOD)
    m[rand() % height][rand() % width].food += 1;
  else if (r == LINEMATE)
    m[rand() % height][rand() % width].linemate += 1;
  else if (r == DERAUMERE)
    m[rand() % height][rand() % width].deraumere += 1;
  else if (r == SIBUR)
    m[rand() % height][rand() % width].sibur += 1;
  else if (r == MENDIANE)
    m[rand() % height][rand() % width].mendiane += 1;
  else if (r == PHIRAS)
    m[rand() % height][rand() % width].phiras += 1;
  else if (r == THYSTAME)
    m[rand() % height][rand() % width].thystame += 1;
}


void    fill_map_ressource(const unsigned int *min, t_map **m, const unsigned int height, const unsigned int width)
{
  int   i;
  int   j;

  i = -1;
  while (++i < 7)
  {
    j = -1;
    while (++j < min[i])
    {
      put_ressource_at_random(m, height, width, i);
    }
  }
}

/**
 * \fn t_map **init_map(const unsigned int height, const unsigned int width)
 * \brief initialisation map
 *
 * \param const unsigned int height, const unsigned int width
 * \return t_map**
 */

t_map			**init_map(const unsigned int *percent, const unsigned int *min, const unsigned int height, const unsigned int width)
{
  int			y;
  t_map   **map;

  srand(clock());
  if ((map = malloc(sizeof(t_map *) * (int)height)) == NULL)
    exit(EXIT_FAILURE);
  y = -1;
  while (++y < (int)height)
  {
    if ((map[y] = malloc(sizeof(t_map) * width)) == NULL)
      exit(EXIT_FAILURE);
    memset(map[y], 0, sizeof(t_map) * width);
    pop_on_line(percent, map[y], width);
  }
  fill_map_ressource(min, map, height, width);
  return (map);
}

/**
 * \fn void  free_map(t_map **map, const unsigned int height)
 * \brief free map
 *
 * \param t_map **map, const unsigned int height
 * \return none.
 */

void  free_map(t_map **map, const unsigned int height)
{
  int y;

  y = -1;
  while (++y < (int)height)
    free(map[y]);
  free(map);
}

/**
 * \fn t_position get_coord(int x, int y, const unsigned int height, const unsigned int width)
 * \brief get coordonne
 *
 * \param int x, int y, const unsigned int height, const unsigned int width
 * \return t_position coordonne
 */

t_position    get_coord(int x, int y, const unsigned int height, const unsigned int width)
{
  t_position  p;

  if (x < 0)
  {
    x = -x;
    x %= width;
    p.x = (width - x) % width;
  }
  else
    p.x = x % width;
  if (y < 0)
  {
    y = -y;
    y %= height;
    p.y = (height - y) % height;
  }
  else
    p.y = y % height;
  return (p);
}

/**
 * \fn e_direction rot_right(const e_direction d)
 * \brief change direction to right
 *
 * \param const e_direction d
 * \return e_direction
 */

//change la directon
e_direction rot_right(const e_direction d)
{
  if (d == UP)
    return (RIGHT);
  else if (d == RIGHT)
    return (DOWN);
  else if (d == DOWN)
    return (LEFT);
  else
    return (UP);
}

/**
 * \fn e_direction rot_left(const e_direction d)
 * \brief change direction to left
 *
 * \param const e_direction d
 * \return e_direction
 */

e_direction rot_left(const e_direction d)
{
  if (d == UP)
    return (LEFT);
  else if (d == RIGHT)
    return (UP);
  else if (d == DOWN)
    return (RIGHT);
  else
    return (DOWN);
}

/**
 * \fn t_coord go_to(const t_coord c, const e_direction d)
 * \brief move to position
 *
 * \param const t_coord c, const e_direction d
 * \return t_coord
 */

t_coord go_to(const t_coord c, const e_direction d)
{
  t_coord p;

  p = c;
  if (d == UP)
    --p.y;
  else if (d == DOWN)
    ++p.y;
  else if (d == LEFT)
    --p.x;
  else
    ++p.x;
  return (p);
}
