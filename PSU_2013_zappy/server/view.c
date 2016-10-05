#include "zappy.h"

/**
 * \fn t_coord *view_line(t_coord c, e_direction d, t_coord *p, unsigned int n)
 * \brief get the ressource on a line of the pyramide vision
 *
 * \param t_coord c, e_direction d, t_coord *p, unsigned int n
 * \return t_coord
 */

t_coord 		*view_line(t_coord c, e_direction d, t_coord *p,
 unsigned int n)
{
	int 		indx;
	int 		len;
	int 		i;
	t_coord 	tmp;
	e_direction dd;

	i = 0;
	dd = rot_right(d);
	tmp = c;
	len = 1 + 2 * (n - 1);
	indx = n * n - len;
	while (i < len)
	{
		p[i + indx] = tmp;
		tmp = go_to(tmp, dd);
		++i;
	}
	return (p);
}

/**
 * \fn t_coord *view_all(t_coord c, e_direction d, int level)
 * \brief get the pyramid vision
 *
 * \param t_coord c, e_direction d, int level
 * \return t_coord
 */

t_coord 			*view_all(t_coord c, e_direction d, int level)
{
	unsigned int 	max;
	int 			i;
	t_coord 		*view;

	i = 1;
	max = level * level;
	if ((view = malloc(max * sizeof(t_position))) == NULL)
		return (NULL);
	while (i <= level)
	{
		view_line(c, d, view, i);
		c = go_to(c, d);
		c = go_to(c, rot_left(d));
		++i;
	}
	return (view);
}

static char	*get_string_from_view(t_zappy *z, const t_coord *view,
 const int max)
{
	char 	*tmp;
	char 	*str;
	int 	i;

	i = -1;
	str = strdup("{");
	while (++i < max)
	{
		if (i != 0)
			str = realloc_str(str, ",");
		if ((tmp = get_stuff_on_case(z, view[i])) != NULL)
		{
			str = realloc_str(str, tmp);
			free(tmp);
		}
	}
	str = realloc_str(str, "}\n");
	return (str);
}

/**
 * \fn void voir(t_zappy *z, t_player *p, __attribute__((unused))char *param)
 * \brief action player voir
 *
 * \param t_zappy *z, t_player *p, __attribute__((unused))char *param
 * \return none.
 */
//colone 1 + 2 * (level - 1)
void 				voir(t_zappy *z, t_player *p,
					 __attribute__((unused))char *param)
{
	t_coord 		*view;
	t_coord 		c;
	char 			*str;

	c.x = p->x;
	c.y = p->y;
	if ((view = view_all(c, p->dir, p->level)) == NULL)
		return ;
	if ((str = get_string_from_view(z, view, p->level * p->level)) == NULL)
		return ;		
	z->send.push_back(&z->send, new_buffer(str, strlen(str), p->fd));
	free(view);
	free(str);
	log_player(&z->log, p, "regarde la case");
}
