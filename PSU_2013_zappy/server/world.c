/**
 * \file world.c
 * \brief world.
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * world.
 *
 */

#include "zappy.h"
#include "time.h"

/**
 * \fn bool its_time_to_death(t_zappy *z, t_player *p)
 * \brief know if it's time to dead.
 *
 * \param t_zappy *z, t_player *p
 * \return bool true if it's okay otherwise false
 */
//renvoie si le joueur p est mort
bool 				its_time_to_death(t_zappy *z, t_player *p)
{
	unsigned long 	diff;

	diff = ((SEC_PER_FOOD * 1000) / z->t) * p->stuf.food;
	if (p->time_start + diff < get_current_time())
	{
		z->send.push_back(&z->send, new_buffer("mort\n", 5, p->fd));
		return (true);
	}
	return (false);
}

/**
 * \fn void gravedigger(t_zappy *z)
 * \brief dead.
 *
 * \param t_zappy *z
 * \return none.
 */
//Passe sur tout les joueur pour voir si il sont mort
void 				gravedigger(t_zappy *z)
{
	t_list_iterator *it;
	t_list_iterator *tmp;
	t_player 		*p;

	it = z->player.begin(&z->player);
	while (it)
	{
		tmp = it;
		it = it->next;
		if (its_time_to_death(z, tmp->data))
		{
			p = (t_player *)tmp->data;
			if (p->status == EGG)
				send_player_egg_pond_end(z, p, p);
			else
				send_player_death(z, p);
			put_stuf_when_dead(z, p);
			z->player.erase(&z->player, tmp);
			printf("%s\n", "player dead");
		}
	}
}

/**
 * \fn void get_str_stuff(char **str, char *name, int nb)
 * \brief get str from stuff
 *
 * \param char **str, char *name, int nb
 * \return none.
 */
//a tester
void 		get_str_stuff(char **str, char *name, int nb)
{
	char 	*ret;
	char 	*tmp;

	if (nb <= 0)
		return ;
	ret = concat_str(NULL, name);
	while (--nb > 0)
	{
		tmp = ret;
		ret = concat_str(ret, " ");
		free(tmp);
		tmp = ret;
		ret = concat_str(ret, name);
		free(tmp);
	}
	if (*str != NULL)
	{
		tmp = ret;
		ret = concat_str(" ", ret);
		free(tmp);
	}
	*str = realloc_str(*str, ret);
	free(ret);
}

/**
 * \fn char *get_stuff_on_case(t_zappy *z, t_coord c)
 * \brief get elem on case
 *
 * \param t_zappy *z, t_coord c
 * \return char *
 */

char 			*get_stuff_on_case(t_zappy *z, t_coord c)
{
	char 		*str;
	t_position 	p;

	str = NULL;
	p = get_coord(c.x, c.y, z->height, z->width);
	get_str_stuff(&str, "linemate", z->map[p.y][p.x].linemate);
	get_str_stuff(&str, "deraumere", z->map[p.y][p.x].deraumere);
	get_str_stuff(&str, "sibur", z->map[p.y][p.x].sibur);
	get_str_stuff(&str, "mendiane", z->map[p.y][p.x].mendiane);
	get_str_stuff(&str, "phiras", z->map[p.y][p.x].phiras);
	get_str_stuff(&str, "deraumere", z->map[p.y][p.x].deraumere);
	get_str_stuff(&str, "thystame", z->map[p.y][p.x].thystame);
	get_str_stuff(&str, "food", z->map[p.y][p.x].food);
	return (str);
}

/**
 * \fn void check_end_game(t_zappy *z)
 * \brief check for the end of the game
 *
 * \param t_zappy *z
 * \return none.
 */

void 			check_end_game(t_zappy *z)
{
	t_player 	*p;

	if ((p = z->player.get(&z->player, player_win, NULL)) != NULL)
	{
		send_player_end_game(z, p->team);
		exit(EXIT_SUCCESS);
	}
}

/**
 * \fn int remaining_food(const unsigned int periode ,const unsigned long start, const unsigned int food)
 * \brief know the food
 *
 * \param const unsigned int periode ,const unsigned long start, const unsigned int food
 * \return int
 */

int 				remaining_food(const unsigned int periode ,
					const unsigned long start, const unsigned int food)
{
	unsigned long 	t;
	float 			div;

	t = get_current_time();
	div = 1000.0 * ((float)SEC_PER_FOOD / (float)periode);
	t = (t - start) / div;
	return (food - t);
}

/**
 * \fn void put_stuf_when_dead(t_zappy *z, t_player *p)
 * \brief relaese stuff when dead
 *
 * \param t_zappy *z, t_player *p
 * \return none.
 */

void 	put_stuf_when_dead(t_zappy *z, t_player *p)
{
	z->map[p->y][p->x].linemate += p->stuf.linemate;
	z->map[p->y][p->x].deraumere += p->stuf.deraumere;
	z->map[p->y][p->x].sibur += p->stuf.sibur;
	z->map[p->y][p->x].mendiane += p->stuf.mendiane;
	z->map[p->y][p->x].phiras += p->stuf.phiras;
	z->map[p->y][p->x].thystame += p->stuf.thystame;
	z->map[p->y][p->x].food += p->stuf.food - 10;
}
