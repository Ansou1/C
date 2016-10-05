/**
 * \file loop.c
 * \brief loop of select.
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * loop.
 *
 */

#include "zappy.h"

/**
 * \fn void loop(t_zappy *z)
 * \brief loop of select
 *
 * \param t_zappy *z
 * \return none.
 */

void 				loop(t_zappy *z)
{
	fd_set 			fd_read;
	fd_set			fd_write;
	int 			fd_max;
	t_list_iterator *it;
	int 			fd;
	struct timeval 	tv;
	int 			ret;

	tv.tv_sec = 0;
	tv.tv_usec = 100;
	for (;;)
	{
		usleep(1000);
		fd_max = 0;
		FD_ZERO(&fd_read);
		FD_ZERO(&fd_write);
		for (it = z->fd.begin(&z->fd);it != NULL; it = it->next)
		{
			fd = ((t_fd *)(it->data))->fd;
			FD_SET(fd, &fd_read);
			FD_SET(fd, &fd_write);
			if (fd > fd_max)
				fd_max = fd;
		}
		if ((ret = select(fd_max + 1, &fd_read, &fd_write, NULL, &tv)) == -1)
			perror("select");
		tv.tv_sec = 0;
		tv.tv_usec = 100;
		it = z->fd.begin(&z->fd);
		while (it != NULL)
		{
			fd = ((t_fd *)(it->data))->fd;
			if (FD_ISSET(fd, &fd_read))
				it = (*((t_fd *)(it->data))->fct)(z, it);
			if (!z->send.empty(&z->send))
			{
				if (FD_ISSET(fd, &fd_write))
					send_response(z, it);
			}
			if (it)
				it = it->next;
		}
		handling(z);
	}
}
