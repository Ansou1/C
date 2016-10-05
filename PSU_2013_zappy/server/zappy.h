/**
 * \file zappy.h
 * \brief All data for zappy
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * zappy.
 *
 */

#ifndef ZAPPY_H
#define ZAPPY_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <err.h>
#include <netdb.h>
#include <string.h>
#include <sys/time.h>
#include <signal.h>

#include "all.h"
#include "../liblist/list.h"
#include "log.h"
#include "map.h"
#include "player.h"

# define MAX_CLIENT (1024)
# define LEN_READ (4096)
# define FALSE (0)
# define TRUE (1)
# define USAGE	"USAGE: ./serveur -p [number of port] -x [width of word] -y [height of word] -n [name of team1, ...] -c [number of player per team max] -t [delay of time]"

//default
//p = 2000 t = 100, n = {"t1", "t2", "t3", "t4"}, x = 20 y = 20 c = 4
#define SEC_PER_FOOD (126)

/**
 * \struct t_fd
 * \brief struct fd
 *
 * Structure for file descriptor
 */

typedef struct 		s_fd
{
	int 			fd;
	t_list_iterator	*(*fct)();
	bool 			is_monitor;
}					t_fd;

/**
 * \struct t_buffer
 * \brief struct for buffer
 *
 */

typedef struct 		s_buffer
{
	void 			*msg;
	unsigned int 	size;
	int 			fd;
}					t_buffer;

/**
 * \struct t_zappy
 * \brief struct for all the zappy
 *
 */

typedef struct 		s_zappy
{
	unsigned short 	port;
	int 			socket;
	unsigned int	width;
  	unsigned int	height;
  	unsigned int	players_by_team;
  	unsigned int	t;
	list 			fd;
	list			team_name;
	list 			buffer; //buffer de reception
	list 			send; 	//buffer d'envoi
	list 			player;
	list 			monitor;
	t_map 			**map;
  	t_log			log;
  	int 			num; //numéro a attrubuer au noveu joueur
  	unsigned int 	min_ressource[7];
	unsigned int 	percent[7];
	char 			*error_log;
	char 			*log_file;
}					t_zappy;

/**
 * \struct t_command
 * \brief Structure t_command
 *
 * parse en execute the commande
 */

typedef struct		s_command
{
	char			*cmd;
  	int				time;
  	bool 			take_arg;
  	void 			(*execute)(t_zappy *, t_player *, char *arg);
  	void 			(*parse)(t_zappy *, t_list_iterator *, char *, const int);
}					t_command;

extern const t_command liste_cmd[];

typedef t_list_iterator *(*read_fct)(t_zappy *, t_list_iterator *it);

//parsing argument
int					get_name_team(int, char **, t_zappy *);
unsigned long int	get_value_from_arg(char *);
int					check_value_in_struct(t_zappy *);
int					get_argument(int, char **, t_zappy *);
void 				put_teams(void *data);

char 			*concat_str(char *s1, char *s2);
char 			*replace_str(const char *s1, int find, int replace);
char 			*realloc_str(char *s1, char *s2);
void 			*new_fd(const int fd, read_fct);
void 			free_fd(void *data);
void 			init_server(t_zappy *z, const unsigned short port);
t_list_iterator *read_client(t_zappy *z, t_list_iterator *it);
t_list_iterator *read_server(t_zappy *z, t_list_iterator *it);
void 			*new_buffer(void *msg, const unsigned int lenght,
				const int fd);
void 			free_buffer(void *data);
int 			match_fd(void *data, void *value);
void 			loop(t_zappy *z);
void 			send_response(t_zappy *z, t_list_iterator *fd);
void 			put_buffer(void *data);
void    		handling(t_zappy *z);
void            cmd_score(t_zappy *z, t_list_iterator *buf, char *arg, const int i);
void 			cmd_team_name(t_zappy *z, t_list_iterator *buf, char *cmd);
void    		stock_commande(t_zappy *z);
void    		cut_request(t_zappy *z, t_list_iterator *buf, char *cmd);
int 			get_number_of_players(const char *name, t_list_iterator *it);
void 			execute_commande(t_zappy *z);
void 			execute_commande_player(t_zappy *z, t_player *data);
void 			move(t_zappy *z, t_player *p, char *param);
void 			right(t_zappy *z, t_player *p, __attribute__((unused))char *param);
void 			left(t_zappy *z, t_player *p, __attribute__((unused))char *param);
int 			match_team(void *data, void *value);
void 			voir(t_zappy *z, t_player *p, __attribute__((unused))char *param);
bool 			its_time_to_death(t_zappy *z, t_player *p);
void 			gravedigger(t_zappy *z);

t_coord 		*view_line(t_coord c, e_direction d, t_coord *p, unsigned int n);
t_coord 		*view_all(t_coord c, e_direction d, int level);
void 			get_str_stuff(char **str, char *name, int nb);
char 			*get_stuff_on_case(t_zappy *z, t_coord c);
void  			take(t_zappy *z, t_player *p, char *param);
void  			put(t_zappy *z, t_player *p, char *param);
void 			inventory(t_zappy *z, t_player *p, __attribute__((unused))char *param);
void 			deport(t_zappy *z, t_player *p, __attribute__((unused))char *param);
void 			broadcast(t_zappy *z, t_player *p, char *param);
int 			get_direction(const t_position current, t_coord to, const e_direction d);
void 			send_broadcast(t_zappy *z, t_player *sender, t_player *to, const char *param);
unsigned int 	get_number_of_player_on(t_zappy *z, const unsigned int x, const unsigned int y);
unsigned long   get_end_time(unsigned long start, const int t, const int period);
unsigned long 	get_current_time();
bool 			check_ressource(const unsigned int nb, t_map *stuf, const unsigned char level);
void  			command_incantation(t_zappy *z, t_list_iterator *buf, char *cmd, const int i);
void 			incantation(t_zappy *z, t_player *p, __attribute__((unused))char *param);
void 			forkk(t_zappy *z, t_player *p, __attribute__((unused))char *param);
void 			eclosion(__attribute__((unused))t_zappy *z, __attribute__((unused))t_player *p, __attribute__((unused))char *param);
void 			connect_nbr(t_zappy *z, t_player *p, __attribute__((unused))char *param);
void 			cmd_graphic(t_zappy *z, t_list_iterator *buf, __attribute__((unused))char *cmd, __attribute__((unused))const int i);
void 			cmd_fork(t_zappy *z, t_list_iterator *buf, char *arg, const int i);
int 			match_fd_fd(void *data, void *fd);
void 			cmd_msz(t_zappy *z, t_list_iterator *buf, __attribute__((unused))char *cmd, __attribute__((unused))const int i);
void 			cmd_bct(t_zappy *z, t_list_iterator *buf, char *cmd, __attribute__((unused))const int i);
void 			cmd_mct(t_zappy *z, t_list_iterator *buf, __attribute__((unused))char *cmd, __attribute__((unused))const int i);
void            cmd_tna(t_zappy *z, t_list_iterator *buf, __attribute__((unused))char *cmd, __attribute__((unused))const int i);
void            cmd_ppo(t_zappy *z, t_list_iterator *buf, char *cmd, __attribute__((unused))const int i);
void            cmd_plv(t_zappy *z, t_list_iterator *buf, char *cmd, __attribute__((unused))const int i);
void            cmd_pin(t_zappy *z, t_list_iterator *buf, char *cmd, __attribute__((unused))const int i);
void            cmd_sgt(t_zappy *z, t_list_iterator *buf, __attribute__((unused))char *cmd, __attribute__((unused))const int i);
void            cmd_sst(t_zappy *z, t_list_iterator *buf, char *cmd, __attribute__((unused))const int i);
void 			send_all_monitor(t_zappy *z, char *msg);
void 			send_player_connect(t_zappy *z, t_player *p);
void 			send_player_expulse(t_zappy *z, t_player *p);
void 			send_player_broadcast(t_zappy *z, t_player *p, char *msg);
void 			send_player_incant(t_zappy *z, t_player *p, const unsigned int x, const unsigned int y);
void 			send_player_end_incant(t_zappy *z, const unsigned int x, const unsigned int y);
void 			send_player_pond(t_zappy *z, t_player *p);
void 			send_player_put(t_zappy *z, t_player *p, const char *r);
void 			send_player_take(t_zappy *z, t_player *p, const char *r);
void 			send_player_death(t_zappy *z, t_player *p);
void 			send_player_egg_pond_end(t_zappy *z, t_player *p, t_player *egg);
void 			send_player_egg_eclo(t_zappy *z, t_player *p);
void 			send_player_connect_for_egg(t_zappy *z, t_player *p);
void 			send_player_egg_dead(t_zappy *z, t_player *p);
void 			send_player_end_game(t_zappy *z, const char *team);
void 			send_player_position(t_zappy *z, t_player *p);
void 			send_all_player_position(t_zappy *z);
int 			remaining_food(const unsigned int periode ,const unsigned long start, const unsigned int food);
void 			put_stuf_when_dead(t_zappy *z, t_player *p);
void 			read_config(t_zappy *z);
void 			log_player(t_log *l, t_player *p, const char *str);
void 			log_player_request(t_log *l, t_player *p, const char *str);
void 			send_player_inventory(t_zappy *z, t_player *p);
void 			send_player_case(t_zappy *z, t_player *p);
char    		*get_map_content_graphic(const unsigned int x, const unsigned int y, t_map** map);

#endif
