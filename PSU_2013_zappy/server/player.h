/**
 * \file player.h
 * \brief header for player
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * header for player.
 *
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "../liblist/list.h"
#include "map.h"
#include "all.h"


/**
 * \enum e_status_player
 * \brief status player
 *
 * enum for the status of player
 */

typedef enum{NORMAL, EGG} e_status_player;

/**
 * \struct t_action
 * \brief type action
 *
 * struct for the action
 */

typedef struct 		s_action
{
	e_action 		type;
	unsigned long 	start;
	unsigned int 	t;
	char 			*param;
}					t_action;

/**
 * \struct t_player
 * \brief all for player
 *
 * struct for player
 */

typedef struct 		s_player
{
	int 			fd;
	unsigned int	number;
	char 			*team;
	unsigned char 	level;
	e_status_player status;
	unsigned int 	x;
	unsigned int 	y;
	t_map 			stuf;
	e_direction 	dir;
	list 			action;
	unsigned long 	time_start;
}					t_player;

void 	free_player(void *data);
void 	*new_player(int *num, const char *team, const unsigned int x, const unsigned int y, const int fd);
void 	*new_action(const char *param, const e_action type, const unsigned int t);
int 	match_player_fd(void *data, void *fd);
void 	put_player(void *data);
int 	match_player_free(void *data, void *team);
int 	match_player_num(void *data, void *num);
int 	player_win(void *data, void *value);

#endif
