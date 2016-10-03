/*
** x_fct2.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Tue Mar 12 19:04:00 2013 florian corradin
** Last update Mon Apr  1 11:23:39 2013 florian corradin
*/

#include "42.h"

int	xdup2(int oldfd, int newfd, int context)
{
  if (dup2(oldfd, newfd) == -1)
    {
      fprintf(stderr, "Pipe error\n");
      if (context == 0)
	return (FAIL);
      else
	{
	  kill(getpid(), SIGKILL);
	  g_statu = -1;
	}
    }
  return (SUCCESS);
}

int	xclose(int fd, int context)
{
  int	error;

  if ((error = close(fd)) == -1)
    {
      fprintf(stderr, "Cannot close the filedescriptor\n");
      if (context == 0)
	return (FAIL);
      else
	{
	  g_statu = -1;
	  kill(getpid(), SIGKILL);
	}
    }
  return (SUCCESS);
}
