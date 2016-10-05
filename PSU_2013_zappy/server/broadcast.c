/**
 * \file broadcast.c
 * \brief Commande broadcast.
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * Commande broadcast.
 *
 */

#include "zappy.h"
#include <math.h>

static float 	compare_distance(t_coord d[9])
{
	float 		res[9];
	int 		i;

	i = 0;
	while (i < 9)
	{
		res[i] = sqrtf(d[i].x * d[i].x + d[i].y * d[i].y);
		if (res[i] < res[0])
			res[0] = res[i];
		++i;
	}
	return (res[0]);
}

/**
 * \fn float 	get_distance(t_position p1, t_position p2, const unsigned int xmax, const unsigned int ymax)
 * \brief Use to know the distance between two point.
 *
 * \param t_position p1, t_position p2, const unsigned int xmax, const unsigned int ymax
 * \return the distance in float
 */

float 		get_distance(t_position p1, t_position p2, const unsigned int xmax, const unsigned int ymax)
{
	t_coord d[9];

	d[0].y = p1.y + ymax - p2.y;
	d[0].x = p1.x + xmax - p2.x;
	d[1].y = d[0].y;
	d[1].x = p2.x + xmax - p1.x;
	d[2].y = d[0].y;
	d[2].x = p1.x - p2.x;
	d[3].y = p2.y + ymax - p1.y;
	d[3].x = p1.x + xmax - p2.x;
	d[4].y = d[3].y;
	d[4].x = p2.x + xmax - p1.x;
	d[5].y = d[3].y;
	d[5].x = p1.x - p2.x;
	d[6].y = p2.y - p1.y;
	d[6].x = p1.x + xmax - p2.x;
	d[7].y = d[6].y;
	d[7].x = p2.x + xmax - p1.x;
	d[8].y = d[6].y;
	d[8].x = p1.x - p2.x;
	/*for (i = 0; i < 9; ++i)
	{
		res[i] = sqrtf(d[i].x * d[i].x + d[i].y * d[i].y);
		if (res[i] < res[0])
			res[0] = res[i];
	}
	return (res[0]);*/
	return (compare_distance(d));
}

/**
 * \fn t_coord 	*get_around(const t_coord c)
 * \brief Obtain all element around the point c
 *
 * \param const t_coord c
 * \return t_coord
 */

t_coord 	*get_around(const t_coord c)
{
	t_coord *ret;

	if ((ret = malloc(sizeof(t_coord) * 8)) == NULL)
		return (NULL);
	ret[0].x = c.x + 1;
	ret[0].y = c.y;
	ret[1].x = c.x + 1;
	ret[1].y = c.y - 1;
	ret[2].x = c.x;
	ret[2].y = c.y - 1;
	ret[3].x = c.x - 1;
	ret[3].y = c.y - 1;
	ret[4].x = c.x - 1;
	ret[4].y = c.y;
	ret[5].x = c.x - 1;
	ret[5].y = c.y + 1;
	ret[6].x = c.x;
	ret[6].y = c.y + 1;
	ret[7].x = c.x + 1;
	ret[7].y = c.y + 1;
	return (ret);
}

/**
 * \fn t_coord 	get_closest_case(const unsigned int height, const unsigned int width, const t_coord here, const t_coord there)
 * \brief get the closest case
 *
 * \param const unsigned int height, const unsigned int width, const t_coord here, const t_coord there
 * \return t_coord
 */

t_coord 	get_closest_case(const unsigned int height, const unsigned int width, const t_coord here, const t_coord there)
{
	t_coord *t;
	t_coord ret;
	float 	min;
	float 	tmp;
	int 	i;

	i = -1;
	min = height > width ? height : width;
	t = get_around(there);
	ret = t[0];
	while (++i < 8)
	{
		tmp = get_distance(get_coord(here.x, here.y, height, width),
		 get_coord(t[i].x, t[i].y, height, width), width, height);
		if (tmp < min)
		{
			min = tmp;
			ret = t[i];
		}
	}
	free(t);
	return (ret);
}

/**
 * \fn int get_direction(const t_position current, t_coord to, const e_direction d)
 * \brief get the direction.
 *
 * \param const t_position current, t_coord to, const e_direction d
 * \return The direction int and 0 if something wrong happened
 */

//retourne 0 en cas de merde
int 			get_direction(const t_position current, t_coord to, const e_direction d)
{
	t_coord 	around[8];
	e_direction e;
	int 		i;

	i = -1;
	e = d;
	around[0].x = current.x;
	around[0].y = current.y;
	around[0] = go_to(around[0], d);
	around[1] = go_to(around[0], e = rot_left(e));
	around[2] = go_to(around[1], e = rot_left(e));
	around[3] = go_to(around[2], e);
	around[4] = go_to(around[3], e = rot_left(e));
	around[5] = go_to(around[4], e);
	around[6] = go_to(around[5], e = rot_left(e));
	around[7] = go_to(around[6], e);
	while (++i < 8)
	{
		if (to.x == around[i].x && to.y == around[i].y)
			return (++i);
	}
	return (0);
}

/**
 * \fn void send_broadcast(t_zappy *z, t_player *sender, t_player *to, const char *param)
 * \brief send the broadcast.
 *
 * \param t_zappy *z, t_player *sender, t_player *to, const char *param
 * \return none.
 */

void 			send_broadcast(t_zappy *z, t_player *sender, t_player *to, const char *param)
{
	t_coord 	here;
	t_coord 	there;
	t_coord 	c;
	t_position 	p;
	int 		nb;
	char 		*msg;

	here.x = sender->x;
	here.y = sender->y;
	there.x = to->x;
	there.y = to->y;
	p.x = to->x;
	p.y = to->y;
	c = get_closest_case(z->height, z->width, here, there);
	if (sender->x == to->x && sender->y == to->y)
		nb = 0;
	else
		nb = get_direction(p, c, to->dir);
	msg = malloc(strlen(param) + 13);
	memset(msg, 0, strlen(param) + 13);
	sprintf(msg, "message %d,%s\n", nb, param);
	z->send.push_back(&z->send, new_buffer(msg, strlen(msg), to->fd));
	free(msg);
}
