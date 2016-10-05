/**
 * \file connection.c
 * \brief connection
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * The connection.
 *
 */

#include "zappy.h"

/**
 * \fn void *new_fd(const int fd, read_fct fct)
 * \brief create a new fd client.
 *
 * \param const int fd, read_fct fct
 * \return void* of the new client
 */

void *new_fd(const int fd, read_fct fct)
{
	t_fd *new;

	if ((new = malloc(sizeof(t_fd))) == NULL)
		return (NULL);
	new->fd = fd;
	new->fct = fct;
  new->is_monitor = false;
  return (new);
}

/**
 * \fn int match_fd_fd(void *data, void *fd)
 * \brief test match between two fd
 *
 * \param void *data, void *fd
 * \return int of comparaison between two fd.
 */

int match_fd_fd(void *data, void *fd)
{
  return (((t_fd*)data)->fd == *(int *)fd);
}

/**
 * \fn void free_fd(void *data)
 * \brief free client.
 *
 * \param void *data
 * \return none.
 */

void  free_fd(void *data)
{
    if (data)
    {
      close(((t_fd *)(data))->fd);
      free(data);
    }
}

/**
 * \fn void init_server(t_zappy *z, const unsigned short port)
 * \brief create socket and initialistion on port
 *
 * \param t_zappy *z, const unsigned short port
 * \return none.
 */

void 					        init_server(t_zappy *z, const unsigned short port)
{
  int 					      s;
  struct protoent		  *protocole;
  struct sockaddr_in  sin;

  if ((protocole = getprotobyname("TCP")) == NULL)
    errx(EXIT_FAILURE, "Error cannot determine the protocole\n");
  if ((s = socket(AF_INET, SOCK_STREAM, protocole->p_proto)) == -1)
    errx(EXIT_FAILURE, "Error in socket : %s", strerror(errno));
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(s, (struct sockaddr *)&sin, sizeof(sin)) == -1)
    {
      close(s);
      errx(EXIT_FAILURE, "Error in bind : %s", strerror(errno));
    }
  if (listen(s, MAX_CLIENT) == -1)
    {
      close(s);
      errx(EXIT_FAILURE, "Error in listen : %s", strerror(errno));
    }
  z->socket = s;
  z->fd.push_front(&z->fd, new_fd(s, read_server));
}
