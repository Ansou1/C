/**
 * \file read.c
 * \brief use of read
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * read.
 *
 */

#include "zappy.h"

/**
 * \fn t_buffer *receive_buffer(char *buf, int ret, const int fd)
 * \brief reception in buffer.
 *
 * \param char *buf, int ret, const int fd
 * \return t_buffer *
 */

t_buffer *receive_buffer(char *buf, int ret, const int fd)
{
	t_buffer *r;
	char *str;
	char *tmp;
	char bufs[LEN_READ + 1];
	int lenght;

	lenght = ret;
	str = concat_str(NULL, buf);
	while (ret == LEN_READ && buf[ret - 1] != '\n')
	{
		ret = read(fd, bufs, LEN_READ);
		bufs[ret] = 0;
		tmp = str;
		str = concat_str(str, bufs);
		lenght += ret;
		free(tmp);
	}
	r = new_buffer(str, lenght, fd);
	free(str);
	return (r);
}

/**
 * \fn t_list_iterator *read_server(t_zappy *z, t_list_iterator *it)
 * \brief read data server.
 *
 * \param t_zappy *z, t_list_iterator *it
 * \return t_list_iterator*
 */

t_list_iterator *read_server(t_zappy *z, t_list_iterator *it)
{
	int 				cs;
  	struct sockaddr_in	client_sin;
  	socklen_t 			client_sin_len;

  	client_sin_len = sizeof(client_sin);
  	cs = accept(((t_fd *)(it->data))->fd, (struct sockaddr *)&client_sin, &client_sin_len);
  	z->fd.push_back(&z->fd, new_fd(cs, read_client));
  	z->send.push_front(&z->send, new_buffer("BIENVENU\n", 9, cs));
  	printf("%s\n", "connection accepted");
  	return (it);
}

/**
 * \fn t_list_iterator *read_client(t_zappy *z, t_list_iterator *it)
 * \brief read data client.
 *
 * \param t_zappy *z, t_list_iterator *it
 * \return t_list_iterator*
 */

t_list_iterator *read_client(t_zappy *z, t_list_iterator *it)
{
	char 		buf[LEN_READ + 1];
	int 		ret;
	t_player 	*p;

	ret = read(((t_fd *)(it->data))->fd, buf, LEN_READ);
	if (ret == -1)
		z->log.write_error(&z->log, "Error: read failed");
	else if (ret == 0)
	{
		p = z->player.get(&z->player, match_player_fd,
		 &(((t_fd *)(it->data))->fd));
		if (p != NULL)
		{
			p->fd = -1;
			close(((t_fd *)(it->data))->fd);
			printf("%s\n", "client deconnected");
		}
		z->fd.erase(&z->fd, it);
		return (NULL);
	}
	else
	{
		buf[ret] = 0;
		z->buffer.push_front(&z->buffer,
		receive_buffer(buf, ret, ((t_fd *)(it->data))->fd));
	}
	return (it);
}

/**
 * \fn void send_response(t_zappy *z, t_list_iterator *fd)
 * \brief send response.
 *
 * \param t_zappy *z, t_list_iterator *fd
 * \return none.
 */

void 	send_response(t_zappy *z, t_list_iterator *fd)
{
	t_list_iterator *buffer;
	t_buffer 		*b;

	if (fd == NULL)
		return ;
	buffer = z->send.find(&z->send, z->send.begin(&z->send), match_fd,
	 &((t_fd *)fd->data)->fd);
	if (buffer == NULL)
		return ;
	b = (t_buffer *)buffer->data;
	if (b->msg)
		write(b->fd, b->msg, b->size);
	z->send.erase(&z->send, buffer);
}
