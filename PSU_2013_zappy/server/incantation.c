/**
 * \file incantation.c
 * \brief incantation
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * incantation.
 *
 */

#include "zappy.h"

static const unsigned char incant[7][7]= {
	{1, 1, 0, 0, 0, 0, 0},
	{2, 1, 1, 1, 0, 0, 0},
	{2, 2, 0, 1, 0, 2, 0},
	{4, 1, 1, 2, 0, 1, 0},
	{4, 1, 2, 1, 3, 0, 0},
	{6, 1, 2, 3, 0, 1, 0},
	{6, 2, 2, 2, 2, 2, 1}
};

/**
 * \fn unsigned int get_number_of_player_on(t_zappy *z, const unsigned int x, const unsigned int y)
 * \brief get the number of player
 *
 * \param t_zappy *z, const unsigned int x, const unsigned int y
 * \return unsigned int nbr of player
 */

unsigned int get_number_of_player_on(t_zappy *z, const unsigned int x, const unsigned int y)
{
	t_list_iterator *it;
	t_player 		*p;
	unsigned int 	nbr;

	nbr = 0;
	it = z->player.begin(&z->player);
	while (it)
	{
		p = (t_player *)it->data;
		if (p->x == x && p->y == y)
			++nbr;
		it = it->next;
	}
	return (nbr);
}

/**
 * \fn bool check_ressource(const unsigned int nb, t_map *stuf, const unsigned char level)
 * \brief check the ressource
 *
 * \param const unsigned int nb, t_map *stuf, const unsigned char level
 * \return bool {true or false}
 */

bool 		check_ressource(const unsigned int nb, t_map *stuf, const unsigned char level)
{
	int 	i;

	if (level == 0 || level > 7)
		return (false);
	i = level - 1;
	if (incant[i][0] > nb)
		return (false);
	if (incant[i][1] > stuf->linemate)
		return (false);
	if (incant[i][2] > stuf->deraumere)
		return (false);
	if (incant[i][3] > stuf->sibur)
		return (false);
	if (incant[i][4] > stuf->mendiane)
		return (false);
	if (incant[i][5] > stuf->phiras)
		return (false);
	if (incant[i][6] > stuf->thystame)
		return (false);
	return (true);
}
