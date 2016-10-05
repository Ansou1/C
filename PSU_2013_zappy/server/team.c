/**
 * \file team.c
 * \brief team.
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * team.
 *
 */

#include "zappy.h"

/**
 * \fn int get_number_of_players(const char *name, t_list_iterator *it)
 * \brief get the number of player per team.
 *
 * \param const char *name, t_list_iterator *it
 * \return int number of player per team
 */

int 	get_number_of_players(const char *name, t_list_iterator *it)
{
	int ret;

	ret = 0;
	while (it)
	{
		if (strcmp(name, ((t_player *)it->data)->team) == 0)
			++ret;
		it = it->next;
	}
	return (ret);
}

/**
 * \fn void put_teams(void *data)
 * \brief print data
 *
 * \param void *data
 * \return none.
 */

void put_teams(void *data)
{
	printf("%s\n", (char *)data);
}

/**
 * \fn int match_team(void *data, void *value)
 * \brief .
 *
 * \param void *data, void *value
 * \return int value true if data == value otherwise false
 */

int match_team(void *data, void *value)
{
	if (strcmp((char *)data, (char *)value) == 0)
		return (true);
	return (false);
}
