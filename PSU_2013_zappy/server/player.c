/**
 * \file player.c
 * \brief tools for player.
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * player.
 *
 */

#include "player.h"
#include "time.h"

/**
 * \fn void *new_action(const char *param, const e_action type, const unsigned int t)
 * \brief create an element t_action
 *
 * \param const char *param, const e_action type, const unsigned int t
 * \return void *
 */

void 			*new_action(const char *param, const e_action type,
 				const unsigned int t)
{
	t_action 	*c;

	if ((c = malloc(sizeof(t_action))) == NULL)
		return (NULL);
	c->t = t;
	c->type = type;
	c->start = get_current_time();
	c->param = NULL;
	if (param)
		c->param = strdup(param);
	return (c);
}

/**
 * \fn void free_action(void *data)
 * \brief free struct action.
 *
 * \param void *data.
 * \return none.
 */

void 			free_action(void *data)
{
	t_action 	*c;

	c = (t_action *)data;
	if (c->param)
		free(c->param);
	if (data)
		free(data);
}

/**
 * \fn void *new_player(int *num, const char *team, const unsigned int x, const unsigned int y, const int fd)
 * \brief create a new player
 *
 * \param int *num, const char *team, const unsigned int x, const unsigned int y, const int fd
 * \return void *
 */

void 			*new_player(int *num, const char *team, const unsigned int x, const unsigned int y, const int fd)
{
	t_player 	*p;

	if ((p = malloc(sizeof(t_player))) == NULL)
		return (NULL);
	p->fd = fd;
	p->team = strdup(team);
	p->level = 1;
	p->x = x;
	p->y = y;
	p->status = NORMAL;
	p->number = *num;
	++(*num);
	memset(&p->stuf, 0, sizeof(t_map));
	p->stuf.food = 10;
	p->dir = rand() % 4;
	init_list(&p->action);
	p->action.free = free_action;
	p->time_start = get_current_time();
	return (p);
}

/**
 * \fn void put_player(void *data)
 * \brief put a player
 *
 * \param void *data
 * \return none.
 */

void 			put_player(void *data)
{
	t_player 	*p;

	p = (t_player *)data;
	printf("team = %s fd = %d\n", p->team, p->fd);
}

/**
 * \fn void free_player(void *data)
 * \brief free player.
 *
 * \param void *data
 * \return none.
 */

void 			free_player(void *data)
{
	t_player 	*p;

	p = (t_player *)data;
	free(p->team);
	p->action.clear(&p->action);
	free(data);
}

/**
 * \fn int match_player_fd(void *data, void *fd)
 * \brief return match between to fd player
 *
 * \param void *data, void *fd
 * \return return 0 or 1.
 */

int match_player_fd(void *data, void *fd)
{
	return (((t_player *)data)->fd == *(int *)fd);
}

/**
 * \fn int match_player_free(void *data, void *team)
 * \brief match player free
 *
 * \param void *data, void *team
 * \return int match
 */

int 			match_player_free(void *data, void *team)
{
	t_player 	*p;

	p = (t_player*)data;
	return (p->team != NULL && team != NULL && strcmp(p->team, (char *)team) == 0 && p->fd == -1);
}

/**
 * \fn int match_player_num(void *data, void *num)
 * \brief match player num
 *
 * \param void *data, void *num
 * \return int match
 */

int 			match_player_num(void *data, void *num)
{
	t_player 	*p;

	p = (t_player*)data;
	return (p->number == *(unsigned int *)num);
}

/**
 * \fn int player_win(void *data, __attribute__((unused))void *value)
 * \brief check si player get level at 8 or more
 *
 * \param void *data, __attribute__((unused))void *value
 * \return int win
 */

int player_win(void *data, __attribute__((unused))void *value)
{
	return (((t_player *)data)->level >= 8);
}
