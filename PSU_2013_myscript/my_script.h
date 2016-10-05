/*
** my_script.h for  in /home/daguen_s/rendu/PSU_2013_myscript
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Fri Feb 28 16:59:51 2014 daguen_s
** Last update Sat Mar  1 13:28:53 2014 daguen_s
*/

#ifndef _MY_SCRIPT_H_
# define _MY_SCRIPT_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <term.h>
#include <termios.h>
#include <string.h>
#include <utmp.h>
#include <time.h>
#include <errno.h>

# define FLAGS		O_WRONLY | O_CREAT | O_NONBLOCK
# define BUFF_SIZE	4096
# define DEBUT		"Script started on %a %d %b %Y %H:%M:%S %p %Z\n"
# define FIN		"\nScript done on %a %d %b %Y %H:%M:%S %p %Z\n"
# define USAGE		"Usage: script [-a] [-c COMMAND] [-q] [file]\n"
# define ERROR_OPENING	"ERROR in opening in open_options.\n"

typedef struct		s_opt
{
  int			a;
  int			c;
  int			q;
  char			*command;
  char			*output;
  int			my_fd;
  int			fd_master;
  struct termios	term;
  struct winsize	win;
}			t_opt;

t_opt			*opt;

	/* my_script.c */
int			my_openpty(int *aslave, t_opt *opt);
pid_t			my_forkpty(t_opt *opt);
int			the_son(t_opt *opt);
int			the_father(t_opt *opt, pid_t pid);

	/* parser.c */
void			*xmalloc(size_t size);
void			init_option(t_opt *opt);
int			get_option(int ac, char **av, t_opt *opt, int *i);
void			open_options(t_opt *opt);
int			get_params(int ac, char **av, t_opt *opt);

	/* term_and_win.c */
void			sigwinch(int signal);
void			set_termios(struct termios *term, struct winsize *win);
void			set_back_termios(t_opt *opt);

	/* tty_function.c */
int			my_posix_openpt(int flags);
char			*my_ptsname(int fd_master);
int			my_grantpt(int fd_master);
int			my_unlockpt(int fd_master);
int			my_login_tty(int fd);

	/* writting.c */
int			writting_data(t_opt *opt, fd_set *fd_in);
int			write_time(t_opt *opt, int order);

	/* xfunction.c */
int			xopen(char *pathname, int flags);
int			xclose(int fd);
int			xdup2(int fd_old, int fd_new);
int			xread(int fd, char *str, size_t size);
int			xwrite(int fd, char *str, size_t size);

#endif /* _MY_SCRIPT_H_ */
