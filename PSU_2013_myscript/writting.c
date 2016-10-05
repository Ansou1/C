/*
** writting.c for  in /home/daguen_s/rendu/PSU_2013_myscript
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Fri Feb 28 17:13:34 2014 daguen_s
** Last update Sat Mar  1 16:27:41 2014 daguen_s
*/

#include "my_script.h"

int			writting_data(t_opt *opt, fd_set *fd_in)
{
  int			i;
  char			buffer[BUFF_SIZE];

  if (FD_ISSET(0, fd_in))
    {
      if ((i = xread(0, buffer, BUFF_SIZE)) >= 0)
	xwrite(opt->fd_master, buffer, i);
      else
	return (-1);
    }
  if (FD_ISSET(opt->fd_master, fd_in))
    {
      if ((i = read(opt->fd_master, buffer, BUFF_SIZE)) >= 0)
	{
	  xwrite(1, buffer, i);
	  xwrite(opt->my_fd, buffer, i);
	}
      else
	return (-1);
    }
  return (0);
}

int			write_time(t_opt *opt, int order)
{
  time_t		date;
  struct tm		*info;
  char			msg[80];
  int			i;

  if (opt->q == 0 && order == 1)
    printf("Script started, file is %s\n", opt->output);
  if (opt->q == 0 && order == 0)
    printf("Script done, file is %s\n", opt->output);
  if (time(&date) == -1)
    return (-1);
  info = xmalloc(sizeof(struct tm));
  if ((info = localtime(&date)) == NULL)
    return (-1);
  i = strftime(msg, sizeof(msg), (order == 1) ? (DEBUT) : (FIN), info);
  if (opt->q != 1 || order == 1)
    xwrite(opt->my_fd, msg, i);
  return (0);
}
