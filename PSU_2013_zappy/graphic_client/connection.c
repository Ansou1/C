/**
 * \file connection.c
 * \brief Every function need for the connection with the server.
 * \author fildie_a / lerman_v
 * \version 0.1
 * \date 10 mai 2014
 *
 * Function use for the connection.
 *
 */

#include "graphique.h"

/**
 * \fn void close_client_ctrl(int __attribute__((unused))signal).
 * \brief Function use in case of ctrl-c.
 *
 * \param int __attribute__((unused))signal.
 * \return none.
 */

void                    close_client_ctrl(int __attribute__((unused))signal)
{
  close(g_socket);
  errx(EXIT_FAILURE, "%s\n", "client_graphique disconected from ctrl-c.\n");
}

/**
 * \fn void init_connect(t_graph *this, int port, char *ip_machine).
 * \brief Function use to set the connection between graphique and server.
 *
 * \param t_graph *this, int port, char *ip_machine.
 * \return none.
 */

void			init_connect(t_graph *this, int port, char *ip_machine)
{
  struct protoent	*protocole;
  struct sockaddr_in	sin;
  int			s;

  if ((protocole = getprotobyname("TCP")) == NULL)
    errx(EXIT_FAILURE, "Error cannot determine the protocole\n");
  if ((s = socket(AF_INET, SOCK_STREAM, protocole->p_proto)) == -1)
    errx(EXIT_FAILURE, "Error in socket : %s", strerror(errno));
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = inet_addr(ip_machine);;
  if ((connect(s, (const struct sockaddr *)&sin, sizeof(sin))) == -1)
    {
      close(s);
      errx(EXIT_FAILURE, "%s\n", strerror(errno));
    }
  this->sock = s;
  g_socket = s;
}

/**
 * \fn .
 * \brief .
 *
 * \param .
 * \return .
 */

/*
void 			loop(t_zappy *z)
{
  fd_set 		fd_read;
  fd_set		fd_write;
  int 			fd_max;
  t_list_iterator	*it;
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
*/
