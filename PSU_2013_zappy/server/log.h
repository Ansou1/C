/**
 * \file log.h
 * \brief header de log.
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * header log.
 *
 */

#ifndef LOG_H
#define LOG_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

/**
 * \struct t_log
 * \brief struct log write and read
 */

typedef struct 	s_log
{
	int 		fd_error;
	int 		fd_log;
	int 		(*write_error)(struct s_log *this, const char *msg);
	int 		(*write_log)(struct s_log *this, const char *msg);
	void 		(*close)(struct s_log *this);
}				t_log;


int 	construct_log(t_log *this, const char *, const char *);
int 	write_log_error(t_log *this, const char *msg);
void	destruct_log(t_log *this);
int 	write_log(t_log *this, const char *msg);

#endif
