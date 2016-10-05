/**
 * \file main.c
 * \brief Start of programme
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * Start
 *
 */

#include "zappy.h"

static t_zappy *g_zappy = NULL;

/**
 * \fn static void init_zappy(t_zappy *z, t_param *p)
 * \brief initialisation of t_zappy by t_param.
 *
 * \param t_zappy *z, t_param *p
 * \return none.
 */

static void 	init_zappy(t_zappy *z, int ac, char **av)
{
	z->port = 2000;
	z->width = 5;
	z->height = 5;
	z->players_by_team = 1;
	z->t = 1;
	z->num = 0;
	z->error_log = strdup("error.log");
	z->log_file = strdup("zappy.log");
	init_list(&z->fd);
	z->fd.free = free_fd;
	init_list(&z->send);
	z->send.free = free_buffer;
	init_list(&z->buffer);
	z->buffer.free = free_buffer;
	init_list(&z->player);
	z->player.free = free_player;
	init_list(&z->team_name);

	read_config(z);
	if (get_argument(ac, av, z) == -1)
    	errx(EXIT_FAILURE, "\033[31mERROR in argument: %s\033[0m", USAGE);
	construct_log(&z->log, z->error_log, z->log_file);
	init_server(z, z->port);
	z->map = init_map(z->percent, z->min_ressource, z->height, z->width);
}

/**
 * \fn static void destruct_zappy(t_zappy *z)
 * \brief free close all champ
 *
 * \param t_zappy *z
 * \return none.
 */

static void destruct_zappy(t_zappy *z)
{
  	z->fd.clear(&z->fd);
	z->team_name.clear(&z->team_name);
	z->buffer.clear(&z->buffer);
	z->send.clear(&z->send);
	z->player.clear(&z->player);
	z->log.close(&z->log);
	close(z->socket);
	free_map(z->map, z->height);
}

/**
 * \fn . static void sig_handler(int sig)
 * \brief ctrl-c catch.
 *
 * \param int sig
 * \return none.
 */

static void	sig_handler(int sig)
{
  sig = sig;
  destruct_zappy(g_zappy);
  printf("%s\n", "Server interrupted");
  exit(EXIT_SUCCESS);
}

/**
 * \fn int main(int ac, char **av)
 * \brief Enter programme
 *
 * \param int ac, char **av
 * \return EXIT_SUCCESS finish normaly and EXIT_FAILURE finish anormaly
 */

int			main(int ac, char **av)
{
  t_zappy		z;

  g_zappy = &z;
  signal(SIGINT, sig_handler);
 
  init_zappy(&z, ac, av);
  printf("%s\n", "teams:");
  z.team_name.for_each(&z.team_name, put_teams);
  printf("nb = %d, x = %dy = %d\n", z.players_by_team, z.width, z.height);
  loop(&z);
  return (EXIT_SUCCESS);
}
