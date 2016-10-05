/**
 * \file map.h
 * \brief header for map
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * map.
 *
 */

#ifndef MAP_H
#define MAP_H

#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <time.h>
#include "all.h"

#define RANDOM_PERCENT(x) ((rand() % 100) < x)

/**
 * \struct t_map
 * \brief element on map
 *
 * This structure is one part of the map
 */

typedef struct	s_map
{
  unsigned char linemate;
  unsigned char deraumere;
  unsigned char sibur;
  unsigned char mendiane;
  unsigned char phiras;
  unsigned char thystame;
  unsigned char food;
}				        t_map;

/**
 * \struct t_position
 * \brief position
 *
 * position x et y for an element
 */

typedef struct 		s_position
{
	unsigned int 	   x;
	unsigned int 	   y;
}					         t_position;

/**
 * \struct t_coord
 * \brief coordonnee
 *
 * coordonnee x et y for un element
 */

typedef struct 		s_coord
{
	int 		 	      x;
	int 			      y;
}					        t_coord;

void  		  free_map(t_map **map, const unsigned int height);
t_position 	get_coord(int x, int y, const unsigned int height, const unsigned int width);
e_direction rot_right(const e_direction d);
e_direction rot_left(const e_direction d);
t_coord     go_to(const t_coord c, const e_direction d);
void        pop_on_line(const unsigned int *percent, t_map *line, const int size);
t_map       **init_map(const unsigned int *percent, const unsigned int *min, const unsigned int height, const unsigned int width);

#endif
