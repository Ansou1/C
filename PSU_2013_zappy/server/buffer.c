/**
 * \file buffer.c
 * \brief buffer.
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * buffer.
 *
 */

#include "zappy.h"

/**
 * \fn void *new_buffer(void *msg, const unsigned int lenght, const int fd)
 * \brief create a new buffer.
 *
 * \param void *msg, const unsigned int lenght, const int fd
 * \return void*.
 */

void 		*new_buffer(void *msg, const unsigned int lenght,
			const int fd)
{
	t_buffer 	*new;

	if ((new = malloc(sizeof(t_buffer))) == NULL)
		return (NULL);
	if ((new->msg = malloc(lenght)) != NULL)
		memcpy(new->msg, msg, lenght);
	new->size = lenght;
	new->fd = fd;
	return (new);
}

/**
 * \fn void free_buffer(void *data)
 * \brief free buffer.
 *
 * \param void *data
 * \return none.
 */

void 	free_buffer(void *data)
{
	t_buffer 	*new;

	new = (t_buffer *)data;
	free(new->msg);
	free(data);
}

/**
 * \fn int match_fd(void *data, void *value)
 * \brief check to know id two fd are the same.
 *
 * \param void *data, void *value
 * \return la valeur du match en int.
 */

int 	match_fd(void *data, void *value)
{
	if (data == NULL || value == NULL)
		return (FALSE);
	return (((t_buffer *)data)->fd == *((int *)value));
}

/**
 * \fn void put_buffer(void *data)
 * \brief insert in buffer.
 *
 * \param put_buffer(void *data
 * \return void.
 */

void 	put_buffer(void *data)
{
	t_buffer *b;

	b = (t_buffer *)data;
	write(1, "msg = ", 6);
	write(1, b->msg, b->size);
	printf(", lenght = %d, fd = %d\n", b->size, b->fd);
}
