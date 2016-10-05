/**
 * \file log.c
 * \brief log
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * log.
 *
 */

#include "log.h"

void            put_date(const int fd)
{
  time_t        now;
  char          *date;

  now = time(NULL);
  date = ctime(&now);
  write(fd, date, strlen(date));
}                              

/**
 * \fn int construct_log(t_log *this, const char *file_name)
 * \brief create log
 *
 * \param t_log *this, const char *file_name
 * \return int 0 if success et -1 failed.
 */

int 	construct_log(t_log *this, const char *file_error, const char *log)
{
	this->write_error = write_log_error;
	this->write_log = write_log;
	this->close = destruct_log;
	this->fd_error = open(file_error, O_WRONLY | O_APPEND);
	this->fd_log = open(log, O_WRONLY | O_APPEND);
	if (this->fd_error == -1)
	{
		if ((this->fd_error = open(file_error, O_WRONLY | O_APPEND | O_CREAT, 0644)) == -1)
		{
			printf("cannot open %s\n", file_error);
			return (-1);
		}
	}
	if (this->fd_log == -1)
	{
		if ((this->fd_log = open(log, O_WRONLY | O_APPEND | O_CREAT, 0644)) == -1)
			{
				printf("cannot open %s\n", log);
				return (-1);}
	}
	return (0);
}

/**
 * \fn int write_log(t_log *this, const char *msg)
 * \brief write on log
 *
 * \param t_log *this, const char *msg
 * \return int 0 if success et -1 failed.
 */

int 	write_log_error(t_log *this, const char *msg)
{
	if (write(this->fd_error, msg, strlen(msg)) == -1)
		return (-1);
	put_date(this->fd_error);
	write(this->fd_error, "\n", 1);
	return (0);
}

int 	write_log(t_log *this, const char *msg)
{
	if (write(this->fd_log, msg, strlen(msg)) == -1)
		return (-1);
	put_date(this->fd_log);
	return (0);
}
/**
 * \fn void destruct_log(t_log *this)
 * \brief close log
 *
 * \param t_log *this
 * \return none.
 */

void	destruct_log(t_log *this)
{
	close(this->fd_error);
	close(this->fd_log);
}
