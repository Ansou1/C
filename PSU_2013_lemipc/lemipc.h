/*
** lemipc.h for  in /home/daguen_s/rendu/PSU_2013_lemipc
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Sun Mar 23 15:37:08 2014 daguen_s
** Last update Sat Mar 29 20:41:51 2014 daguen_s
*/

#ifndef _LEMIPC_H_
# define _LEMIPC_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <errno.h>
#include <err.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SDL/SDL.h>
#include <math.h>
#include <time.h>

# define USAGE			"./lemipc -t [team_player between 1 and 9]\n"
# define OUT			(255)
# define IN			(0)
# define TRUE			(1)
# define FALSE			(0)
# define START			(0)
# define WAIT_FOR_PLAYER	(0x1)
# define IN_GAME		(0x2)
# define ALIVE			(0x1)
# define SERVER			(0x2)
# define GRAPHIC_MODE		(0x4)
# define FLAG		        SDL_HWSURFACE | SDL_DOUBLEBUF
# define RW			SHM_R | SHM_W
# define MAP			this->map_size
# define TEAM			this->team_player
# define ALL			this->all

# define R			around.right
# define L			around.left
# define T			around.top
# define B			around.bottom

# define TR			around.top_right
# define TL			around.top_left
# define BR			around.bottom_right
# define BL			around.bottom_left

typedef struct		s_point
{
  unsigned int		x;
  unsigned int		y;
}			t_point;

typedef struct		s_around
{
  t_point		left;
  t_point		right;
  t_point		top;
  t_point		bottom;
  t_point		top_left;
  t_point		top_right;
  t_point		bottom_left;
  t_point		bottom_right;
}			t_around;

typedef struct          s_display
{
  SDL_Surface           *screen;
  SDL_Surface           *background;
  SDL_Surface           *team1;
  SDL_Surface           *team2;
  SDL_Surface           *team3;
  SDL_Surface           *team4;
  SDL_Surface           *team5;
  SDL_Surface           *team6;
  SDL_Surface           *team7;
  SDL_Surface           *team8;
  SDL_Surface           *team9;
}                       t_display;

typedef struct		s_lemipc
{
  short			team_player;
  unsigned char		map_size;
  key_t			key;
  int			shm_id;
  int			sem_id;
  unsigned char		*map;
  char			status;
  t_point		position;
  t_display		*all;
}			t_lemipc;

int			get_arg(t_lemipc *, int, char **);
void			init_the_game(t_lemipc *);
key_t			get_key();
int			pop_at_random(t_lemipc *);
int			put_in_map(t_lemipc *, unsigned int);
unsigned char		case_is_free(t_lemipc *, t_point *);
unsigned char		get_value(t_lemipc *, t_point *);
unsigned char		aff_map(t_lemipc *);
t_around		get_around(int, int);
int			set_position(t_lemipc *, t_point);
int			loop(t_lemipc *, t_around);
int			pop_near_friend(t_lemipc *);
void			lets_go(t_lemipc *);
unsigned char		get_number_of_team(t_lemipc *);
unsigned char		get_number_of_teamate(t_lemipc *, unsigned char);
double			get_dist(int, int, int, int);
t_point			get_closest_opponents(t_lemipc *);
t_point			get_closest_friends(t_lemipc *);
int			am_near_friend(t_lemipc *);
void			mmove(t_lemipc *);
int			display_by_sdl(t_lemipc *);
unsigned int		get_number_of_players(t_lemipc *);
void			end_sdl(t_lemipc *);
int			init_sdl(t_lemipc *);
unsigned char		display_map(t_lemipc *);
void			fill_data(t_lemipc *);

#endif /* _LEMIPC_H_ */
