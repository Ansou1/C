/**
 * \file serveur.h
 * \brief data for serveur
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * data parameter.
 *
 */

#ifndef _SERVER_H_
# define _SERVER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <errno.h>
#include <err.h>
#include "../liblist/list.h"

#define			USAGE	"USAGE: ./serveur -p [number of port] -x [width of word] -y [height of word] -n [name of team1, ...] -c [number of player per team max] -t [delay of time]"

/**
 * \struct t_param
 * \brief param for server
 *
 * Data get from parameter set in this stucture
 */

typedef struct		s_param
{
  unsigned long int	_port;
  unsigned long int	_width;
  unsigned long int	_height;
  list				_team_name;
  unsigned long int	_nbr_max_client;
  unsigned long int	_time_action;
}					t_param;

int					get_name_team(int, char **, t_zappy *);
unsigned long int	get_value_from_arg(char *);
int					check_value_in_struct(t_zappy *);
int					get_argument(int, char **, t_zappy *);
void 				put_teams(void *data);

#endif /* _SERVER_H_ */
