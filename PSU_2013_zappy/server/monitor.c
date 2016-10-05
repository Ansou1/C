/**
 * \file monitor.c
 * \brief monitor.
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * nonitor.
 *
 */

#include "zappy.h"

/**
 * \fn void send_all_monitor(t_zappy *z, char *msg)
 * \brief send data to monitor.
 *
 * \param t_zappy *z, char *msg
 * \return none.
 */

void 				send_all_monitor(t_zappy *z, char *msg)
{
	t_list_iterator *it;

	it = z->fd.begin(&z->fd);
	while (it)
	{
		if (((t_fd *)it->data)->is_monitor)
		{
			z->send.push_back(&z->send, new_buffer(msg, strlen(msg),
			 ((t_fd *)it->data)->fd));
		}
		it = it->next;
	}
}

/**
 * \fn void send_all_player_position(t_zappy *z)
 * \brief send all player position
 *
 * \param void send_all_player_position(t_zappy *z)
 * \return none
 */

void send_all_player_position(t_zappy *z)
{
    t_list_iterator *it;

    it = z->player.begin(&z->player);
    while (it)
    {
        send_player_position(z, it->data);
        it = it->next;
    }
}

void send_player_case(t_zappy *z, t_player *p)
{
  char *s;

    if (p == NULL)
        return ;
    s = get_map_content_graphic(p->x, p->y, z->map);
    if (s == NULL)
        return ;
    send_all_monitor(z, s);
    free(s);
}

void send_player_inventory(t_zappy *z, t_player *p)
{
  char *s;

    if (p == NULL)
        return ;
    if ((s = malloc(200)) == NULL)
        return ;
    memset(s, 0, 200);
    sprintf(s, "pin %d %d %d %d %d %d %d %d %d %d\n", p->number, p->x, p->y,
   p->stuf.linemate, p->stuf.deraumere, p->stuf.sibur, p->stuf.mendiane,
    p->stuf.phiras, p->stuf.thystame, p->stuf.food);
    send_all_monitor(z, s);
    free(s);
}

/**
 * \fn void send_player_position(t_zappy *z, t_player *p)
 * \brief send to player position
 *
 * \param t_zappy *z, t_player *p
 * \return none.
 */

void send_player_position(t_zappy *z, t_player *p)
{
    char *s;

    if (p == NULL)
        return ;
    if ((s = malloc(100)) == NULL)
        return ;
    memset(s, 0, 100);
    sprintf(s, "ppo %d %d %d %d\n", p->number, p->x, p->y, p->dir + 1);
    send_all_monitor(z, s);
    free(s);
}

/**
 * \fn void send_player_connect(t_zappy *z, t_player *p)
 * \brief send to player to connect.
 *
 * \param t_zappy *z, t_player *p
 * \return none.
 */

void send_player_connect(t_zappy *z, t_player *p)
{
	char *s;

	if (p == NULL)
		return ;
	if ((s = malloc(100)) == NULL)
        return ;
    memset(s, 0, 100);
    sprintf(s, "pnw %d %d %d %d %d %s\n", p->number, p->x, p->y, p->dir + 1,
     p->level, p->team);
    send_all_monitor(z, s);
    free(s);
}

/**
 * \fn void send_player_expulse(t_zappy *z, t_player *p)
 * \brief send to player expulse
 *
 * \param t_zappy *z, t_player *p
 * \return none.
 */

void send_player_expulse(t_zappy *z, t_player *p)
{
	char *s;

	if (p == NULL)
		return ;
	if ((s = malloc(100)) == NULL)
        return ;
    memset(s, 0, 100);
    sprintf(s, "pex %d\n", p->number);
    send_all_monitor(z, s);
    free(s);
}

/**
 * \fn void send_player_broadcast(t_zappy *z, t_player *p, char *msg)
 * \brief send to player broadcast.
 *
 * \param t_zappy *z, t_player *p, char *msg
 * \return none.
 */

void send_player_broadcast(t_zappy *z, t_player *p, char *msg)
{
	char *s;

	if (p == NULL || msg == NULL)
		return ;
	if ((s = malloc(100 + strlen(msg))) == NULL)
        return ;
    memset(s, 0, 100 + strlen(msg));
    sprintf(s, "pex %d %s\n", p->number, msg);
    send_all_monitor(z, s);
    free(s);
}

/**
 * \fn void send_player_incant(t_zappy *z, t_player *p, const unsigned int x, const unsigned int y)
 * \brief send to player incantation
 *
 * \param t_zappy *z, t_player *p, const unsigned int x, const unsigned int y
 * \return none.
 */

void send_player_incant(t_zappy *z, t_player *p, const unsigned int x, const unsigned int y)
{
	char *s;

	if (p == NULL)
		return ;
	if ((s = malloc(100)) == NULL)
        return ;
    memset(s, 0, 100);
    sprintf(s, "pic %d %d %d %d\n", x, y, p->level, p->number);
    send_all_monitor(z, s);
    free(s);
}

/**
 * \fn void send_player_end_incant(t_zappy *z, const unsigned int x, const unsigned int y)
 * \brief send to player end of incantation
 *
 * \param t_zappy *z, const unsigned int x, const unsigned int y
 * \return none.
 */

void send_player_end_incant(t_zappy *z, const unsigned int x, const unsigned int y)
{
	char *s;

	if ((s = malloc(100)) == NULL)
        return ;
    memset(s, 0, 100);
    sprintf(s, "pie %d %d %d\n", x, y, 1);
    send_all_monitor(z, s);
    free(s);
}

/**
 * \fn void send_player_pond(t_zappy *z, t_player *p)
 * \brief send to player pond.
 *
 * \param t_zappy *z, t_player *p
 * \return none.
 */

void send_player_pond(t_zappy *z, t_player *p)
{
	char *s;

	if (p == NULL)
		return ;
	if ((s = malloc(100)) == NULL)
        return ;
    memset(s, 0, 100);
    sprintf(s, "pfk %d\n", p->number);
    send_all_monitor(z, s);
    free(s);
}

/**
 * \fn int get_type_res_by_str(const char *param)
 * \brief send to player type of param
 *
 * \param const char *param
 * \return int for which type and -1 for an error.
 */

int get_type_res_by_str(const char *param)
{
    if (strcmp(param, "linemate") == 0)
        return (0);
    else if (strcmp(param, "deraumere") == 0)
        return (1);
    else if (strcmp(param, "sibur") == 0)
        return (2);
    else if (strcmp(param, "mendiane") == 0)
        return (3);
    else if (strcmp(param, "phiras") == 0)
        return (4);
    else if (strcmp(param, "thystame") == 0)
        return (5);
    else if (strcmp(param, "food") == 0)
        return (6);
    return (-1);
}

/**
 * \fn void send_player_put(t_zappy *z, t_player *p, const char *r)
 * \brief send to player action put.
 *
 * \param t_zappy *z, t_player *p, const char *r
 * \return none.
 */

void send_player_put(t_zappy *z, t_player *p, const char *r)
{
	char   *s;

	if (p == NULL)
		return ;
	if ((s = malloc(100)) == NULL)
        return ;
    memset(s, 0, 100);
    sprintf(s, "pdr %d %d\n", p->number, get_type_res_by_str(r));
    send_all_monitor(z, s);
    free(s);
}

/**
 * \fn void send_player_take(t_zappy *z, t_player *p, const char *r)
 * \brief send to player action take.
 *
 * \param t_zappy *z, t_player *p, const char *r
 * \return none.
 */

void send_player_take(t_zappy *z, t_player *p, const char *r)
{
	char *s;

	if (p == NULL)
		return ;
	if ((s = malloc(100)) == NULL)
        return ;
    memset(s, 0, 100);
    sprintf(s, "pgt %d %d\n", p->number, get_type_res_by_str(r));
    send_all_monitor(z, s);
    free(s);
}

/**
 * \fn void send_player_death(t_zappy *z, t_player *p)
 * \brief send to player death.
 *
 * \param t_zappy *z, t_player *p
 * \return none.
 */

void send_player_death(t_zappy *z, t_player *p)
{
	char *s;

	if (p == NULL)
		return ;
	if ((s = malloc(100)) == NULL)
        return ;
    memset(s, 0, 100);
    sprintf(s, "pdi %d\n", p->number);
    send_all_monitor(z, s);
    free(s);
}

/**
 * \fn void send_player_egg_pond_end(t_zappy *z, t_player *p, t_player *egg)
 * \brief send to player that eggs creation is finished
 *
 * \param t_zappy *z, t_player *p, t_player *egg
 * \return none.
 */

void send_player_egg_pond_end(t_zappy *z, t_player *p, t_player *egg)
{
	char *s;

	if (p == NULL)
		return ;
	if ((s = malloc(100)) == NULL)
        return ;
    memset(s, 0, 100);
    sprintf(s, "enw %d %d %d %d\n", p->number, egg->number, egg->x, egg->y);
    send_all_monitor(z, s);
    free(s);
}

/**
 * \fn void send_player_egg_eclo(t_zappy *z, t_player *p)
 * \brief send to player that eggs is born
 *
 * \param t_zappy *z, t_player *p
 * \return none.
 */

void send_player_egg_eclo(t_zappy *z, t_player *p)
{
	char *s;

	if (p == NULL)
		return ;
	if ((s = malloc(100)) == NULL)
        return ;
    memset(s, 0, 100);
    sprintf(s, "eht %d\n", p->number);
    send_all_monitor(z, s);
    free(s);
}

/**
 * \fn void send_player_connect_for_egg(t_zappy *z, t_player *p)
 * \brief connect for an eggs
 *
 * \param t_zappy *z, t_player *p
 * \return none.
 */

void send_player_connect_for_egg(t_zappy *z, t_player *p)
{
	char *s;

	if (p == NULL)
		return ;
	if ((s = malloc(100)) == NULL)
        return ;
    memset(s, 0, 100);
    sprintf(s, "ebo %d\n", p->number);
    send_all_monitor(z, s);
    free(s);
}

/**
 * \fn void send_player_egg_dead(t_zappy *z, t_player *p)
 * \brief send to player that eggs is dead.
 *
 * \param t_zappy *z, t_player *p
 * \return none.
 */

void send_player_egg_dead(t_zappy *z, t_player *p)
{
	char *s;

	if (p == NULL)
		return ;
	if ((s = malloc(100)) == NULL)
        return ;
    memset(s, 0, 100);
    sprintf(s, "edi %d\n", p->number);
    send_all_monitor(z, s);
    free(s);
}

/**
 * \fn void send_player_end_game(t_zappy *z, const char *team)
 * \brief send to player end of game.
 *
 * \param t_zappy *z, const char *team
 * \return none.
 */

void send_player_end_game(t_zappy *z, const char *team)
{
	char *s;

	if (team == NULL)
		return ;
	if ((s = malloc(strlen(team) + 6)) == NULL)
        return ;
    memset(s, 0, strlen(team) + 6);
    sprintf(s, "seg %s\n", team);
    send_all_monitor(z, s);
    free(s);
}
