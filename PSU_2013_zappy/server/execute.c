/**
 * \file execute.c
 * \brief all execution
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * all execution.
 *
 */

#include "zappy.h"
#include "time.h"

/**
 * \fn void execute_commande(t_zappy *z)
 * \brief execute a commande
 *
 * \param t_zappy *z
 * \return none.
 */

void 				execute_commande(t_zappy *z)
{
	t_list_iterator *it;

	it = z->player.begin(&z->player);
	while (it)
	{
		execute_commande_player(z, it->data);
		it = it->next;
	}
}

/**
 * \fn void execute_commande_player(t_zappy *z, t_player *data)
 * \brief execute a commande of player
 *
 * \param t_zappy *z, t_player *data
 * \return none.
 */

void 				execute_commande_player(t_zappy *z, t_player *data)
{
	t_list_iterator *it;
	t_action 		*a;
	unsigned long 	t;

	if ((it = data->action.begin(&data->action)) == NULL)
		return ;
	a = (t_action *)it->data;
	t = get_current_time();
	if (t >= get_end_time(a->start, a->t, z->t))
		{
			(liste_cmd[a->type].execute)(z, data, a->param);
			data->action.erase(&data->action, it);
			if ((it = data->action.begin(&data->action)) != NULL)
			{
				a = (t_action *)it->data;
				a->start = get_current_time();
			}
		}
}

/**
 * \fn void move(t_zappy *z, t_player *p, __attribute__((unused))char *param)
 * \brief action move.
 *
 * \param t_zappy *z, t_player *p, __attribute__((unused))char *param
 * \return none.
 */

void 			move(t_zappy *z, t_player *p, __attribute__((unused))char *param)
{
	t_position 	pos;
	int 		x;
	int 		y;

	x = p->x;
	y = p->y;
	if (p->dir == UP)
		--y;
	else if (p->dir == DOWN)
		++y;
	else if (p->dir == LEFT)
		--x;
	else
		++x;
	pos = get_coord(x, y, z->height, z->width);
	p->x = pos.x;
	p->y = pos.y;
	z->send.push_back(&z->send, new_buffer("ok\n", 3, p->fd));
	send_player_position(z, p);
	log_player(&z->log, p, "avance");
}

/**
 * \fn void 	right(t_zappy *z, t_player *p, __attribute__((unused))char *param)
 * \brief move player on right
 *
 * \param t_zappy *z, t_player *p, __attribute__((unused))char *param
 * \return none.
 */

void 	right(t_zappy *z, t_player *p, __attribute__((unused))char *param)
{
	p->dir = rot_right(p->dir);
	z->send.push_back(&z->send, new_buffer("ok\n", 3, p->fd));
	send_player_position(z, p);
	log_player(&z->log, p, "tourne à droite");
}

/**
 * \fn void left(t_zappy *z, t_player *p, __attribute__((unused))char *param)
 * \brief move player on left
 *
 * \param t_zappy *z, t_player *p, __attribute__((unused))char *param
 * \return none.
 */

void 	left(t_zappy *z, t_player *p, __attribute__((unused))char *param)
{
	p->dir = rot_left(p->dir);
	z->send.push_back(&z->send, new_buffer("ok\n", 3, p->fd));
	send_player_position(z, p);
	log_player(&z->log, p, "tourne à gauche");
}

/**
 * \fn void get_inventory_str(char **str, const char *name, const unsigned char nbr)
 * \brief get a str of inventaire.
 *
 * \param char **str, const char *name, const unsigned char nbr
 * \return none.
 */

void 		get_inventory_str(char **str, const char *name, const unsigned char nbr)
{
	int 	lenght;
	char 	*s;

	lenght = strlen(name) + 5;
	s = malloc(lenght);
	memset(s, 0, lenght);
	sprintf(s, "%s %d", name, nbr);
	if (*str == NULL)
	{
		*str = strdup(s);
		free(s);
		return ;
	}
	*str = realloc_str(*str, ",");
	*str = realloc_str(*str, s);
	free(s);
}

/**
 * \fn void inventory(t_zappy *z, t_player *p, __attribute__((unused))char *param)
 * \brief action player inventaire
 *
 * \param t_zappy *z, t_player *p, __attribute__((unused))char *param
 * \return none.
 */

void 		inventory(t_zappy *z, t_player *p, __attribute__((unused))char *param)
{
	char 	*s;

	s = NULL;
	get_inventory_str(&s, "linemate", p->stuf.linemate);
	get_inventory_str(&s, "deraumere", p->stuf.deraumere);
	get_inventory_str(&s, "sibur", p->stuf.sibur);
	get_inventory_str(&s, "mendiane", p->stuf.mendiane);
	get_inventory_str(&s, "phiras", p->stuf.phiras);
	get_inventory_str(&s, "thystame", p->stuf.thystame);
	get_inventory_str(&s, "food", remaining_food(z->t, p->time_start, p->stuf.food));
	s = realloc_str(s, "\n");
	z->send.push_back(&z->send, new_buffer(s, strlen(s), p->fd));
	free(s);
	log_player(&z->log, p, "regarde l'inventaire");
}

/**
 * \fn void swap_object(unsigned char *to, unsigned char *from, bool *c)
 * \brief take an object from a place to an other.
 *
 * \param unsigned char *to, unsigned char *from, bool *c
 * \return none.
 */

//prend un objet d'un emplacement from pour le stocker dans to
void 	swap_object(unsigned char *to, unsigned char *from, bool *c)
{
	if (*from == 0)
		return ;
	++(*to);
	--(*from);
	*c = true;
}

/**
 * \fn void take(t_zappy *z, t_player *p, char *param)
 * \brief commande take
 *
 * \param t_zappy *z, t_player *p, char *param
 * \return none.
 */

void		take(t_zappy *z, t_player *p, char *param)
{
	bool 	take;

	take = false;
	if (param == NULL)
		return ;
	if (strcmp(param, "linemate") == 0)
		swap_object(&p->stuf.linemate, &z->map[p->y][p->x].linemate, &take);
	else if (strcmp(param, "deraumere") == 0)
		swap_object(&p->stuf.deraumere, &z->map[p->y][p->x].deraumere, &take);
	else if (strcmp(param, "sibur") == 0)
		swap_object(&p->stuf.sibur, &z->map[p->y][p->x].sibur, &take);
	else if (strcmp(param, "mendiane") == 0)
		swap_object(&p->stuf.mendiane, &z->map[p->y][p->x].mendiane, &take);
	else if (strcmp(param, "phiras") == 0)
		swap_object(&p->stuf.phiras, &z->map[p->y][p->x].phiras, &take);
	else if (strcmp(param, "thystame") == 0)
		swap_object(&p->stuf.thystame, &z->map[p->y][p->x].thystame, &take);
	else if (strcmp(param, "food") == 0)
		swap_object(&p->stuf.food, &z->map[p->y][p->x].food, &take);
	if (take)
	{
		z->send.push_back(&z->send, new_buffer("ok\n", 3, p->fd));
		send_player_take(z, p, param);
		send_player_inventory(z, p);
		send_player_case(z, p);
	}
	else
		z->send.push_back(&z->send, new_buffer("ko\n", 3, p->fd));
	log_player(&z->log, p, "prend objet");
}

/**
 * \fn void put(t_zappy *z, t_player *p, char *param)
 * \brief commande put.
 *
 * \param t_zappy *z, t_player *p, char *param
 * \return none.
 */

void		put(t_zappy *z, t_player *p, char *param)
{
	bool 	take;

	take = false;
	//chekc use
	if (param == NULL)
		return ;
	if (strcmp(param, "linemate") == 0)
		swap_object(&z->map[p->y][p->x].linemate, &p->stuf.linemate, &take);
	else if (strcmp(param, "deraumere") == 0)
		swap_object(&z->map[p->y][p->x].deraumere, &p->stuf.deraumere, &take);
	else if (strcmp(param, "sibur") == 0)
		swap_object(&z->map[p->y][p->x].sibur, &p->stuf.sibur, &take);
	else if (strcmp(param, "mendiane") == 0)
		swap_object(&z->map[p->y][p->x].mendiane, &p->stuf.mendiane, &take);
	else if (strcmp(param, "phiras") == 0)
		swap_object(&z->map[p->y][p->x].phiras, &p->stuf.phiras, &take);
	else if (strcmp(param, "thystame") == 0)
		swap_object(&z->map[p->y][p->x].thystame, &p->stuf.thystame, &take);
	else if (strcmp(param, "food") == 0)
		swap_object(&z->map[p->y][p->x].food, &p->stuf.food, &take);
	if (take)
	{
		z->send.push_back(&z->send, new_buffer("ok\n", 3, p->fd));
		send_player_put(z, p, param);
		send_player_inventory(z, p);
		send_player_case(z, p);
	}
	else
		z->send.push_back(&z->send, new_buffer("ko\n", 3, p->fd));
	log_player(&z->log, p, "pose objet");
}

/**
 * \fn void deport_to(t_zappy *z, t_player *p, const e_direction e)
 * \brief move to
 *
 * \param t_zappy *z, t_player *p, const e_direction e
 * \return none.
 */

void 			deport_to(t_zappy *z, t_player *p, const e_direction e)
{
	t_coord 	to;
	t_position 	current;
	int 		dir;
	char 		str[16];

	memset(str, 0, 16);
	current.x = p->x;
	current.y = p->y;
	to.x = p->x;
	to.y = p->y;
	to = go_to(to, e);
	dir = get_direction(current, to, p->dir);
	current = get_coord(to.x, to.y, z->height, z->width);
	p->x = current.x;
	p->y = current.y;
	sprintf(str, "deplacement: %d\n", dir);
	z->send.push_back(&z->send, new_buffer(str, strlen(str), p->fd));
	send_player_expulse(z, p);
	log_player(&z->log, p, "expulse");
}

/**
 * \fn void deport(t_zappy *z, t_player *p, __attribute__((unused))char *param)
 * \brief deport
 *
 * \param t_zappy *z, t_player *p, __attribute__((unused))char *param
 * \return none.
 */

void 				deport(t_zappy *z, t_player *p, __attribute__((unused))char *param)
{
	t_list_iterator *it;
	t_player 		*ind;

	it = z->player.begin(&z->player);
	while (it)
		{
			ind = (t_player *)it->data;
			if (p->fd != ind->fd && ind->x == p->x && ind->y == p->y && ind->fd != -1)
			{
				deport_to(z, ind, p->dir);
				send_all_player_position(z);
			}
			it = it->next;
		}
	z->send.push_back(&z->send, new_buffer("ok\n", 3, p->fd));
}

/**
 * \fn void broadcast(t_zappy *z, t_player *p, char *param)
 * \brief commande broadcast.
 *
 * \param t_zappy *z, t_player *p, char *param
 * \return none.
 */

void 				broadcast(t_zappy *z, t_player *p, char *param)
{
	t_list_iterator *it;
	t_player 		*ind;

	it = z->player.begin(&z->player);
	while (it)
		{
			ind = (t_player *)it->data;
			if (ind->fd != -1 && p->fd != ind->fd)
			{
				send_broadcast(z, p, ind, param);
				send_player_broadcast(z, p, param);
			}
			it = it->next;
		}
	z->send.push_back(&z->send, new_buffer("ok\n", 3, p->fd));
	log_player(&z->log, p, "broadcast");
}

/**
 * \fn void incantation(t_zappy *z, t_player *p, __attribute__((unused))char *param)
 * \brief commande incantation.
 *
 * \param t_zappy *z, t_player *p, __attribute__((unused))char *param
 * \return none.
 */

void 				incantation(t_zappy *z, t_player *p, __attribute__((unused))char *param)
{
	z = z;
	++(p->level);
	send_player_end_incant(z, p->x, p->y);
	log_player(&z->log, p, "incante");
}

/**
 * \fn void forkk(t_zappy *z, t_player *p, __attribute__((unused))char *param)
 * \brief commande fork.
 *
 * \param t_zappy *z, t_player *p, __attribute__((unused))char *param
 * \return none.
 */

void 				forkk(t_zappy *z, t_player *p, __attribute__((unused))char *param)
{
	unsigned long 	tt;
	unsigned int 	teamate;
	int 			num_egg;
	t_player 		*egg;

	teamate = get_number_of_players(p->team, z->player.begin(&z->player));
	if (teamate >= z->players_by_team)
	{
		z->send.push_back(&z->send, new_buffer("ko\n", 3, p->fd));
		return ;
	}
	//ajouter un joueur en oeuf
	num_egg = z->num;
	z->player.push_back(&z->player, new_player(&z->num, p->team, p->x, p->y, -1));
	egg = z->player.get(&z->player, match_player_num,&num_egg);
	egg->status = EGG;
	egg->action.push_back(&egg->action, new_action(NULL, ECLOSION, 600));
	tt = get_current_time() + 600000 / z->t;
	egg->time_start = tt;
	z->send.push_back(&z->send, new_buffer("ok\n", 3, p->fd));
	send_player_egg_pond_end(z, p, egg);
	log_player(&z->log, p, "pond un oeuf pourri");
}

/**
 * \fn void eclosion(t_zappy *z, t_player *p, __attribute__((unused))char *param)
 * \brief action eclosion
 *
 * \param t_zappy *z, t_player *p, __attribute__((unused))char *param
 * \return none.
 */

void eclosion(t_zappy *z, t_player *p, __attribute__((unused))char *param)
{
	printf("%s\n", "eclosion");
	p->status = NORMAL;
	send_player_egg_eclo(z, p);
	log_player(&z->log, p, "l'oeuf éclot");
}

/**
 * \fn void connect_nbr(t_zappy *z, t_player *p, __attribute__((unused))char *param)
 * \brief commande connect_nbr
 *
 * \param t_zappy *z, t_player *p, __attribute__((unused))char *param
 * \return none.
 */

void 		connect_nbr(t_zappy *z, t_player *p, __attribute__((unused))char *param)
{
	int 	nb;
	char 	*send;

	send = malloc(50);
	memset(send, 0, 50);
	nb = get_number_of_players(p->team, z->player.begin(&z->player));
	nb = z->players_by_team - nb;
	sprintf(send, "%d\n", nb);
	z->send.push_back(&z->send, new_buffer(send, strlen(send), p->fd));
	free(send);
	log_player(&z->log, p, "recupere le nombre de joueur connecté");
}
