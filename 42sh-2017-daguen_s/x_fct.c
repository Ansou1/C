/*
** xfunction.c for mysh in /home/daguen_s//secminishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar  9 11:56:32 2013 simon daguenet
** Last update Sun May 12 20:56:29 2013 florian corradin
*/

#include "42.h"

void	xfree(void *ptr)
{
  if (ptr)
    free(ptr);
}

void	*xmalloc2(size_t taille)
{
  void	*ptr;

  if (taille <= 0)
    return (NULL);
  ptr = malloc(taille);
  if (ptr == NULL)
    {
      fprintf(stderr, "Could not alloc\n");
      g_statu = -1;
      kill(getpid(), SIGKILL);
    }
  return (ptr);
}

void	*xmalloc(size_t taille)
{
  void	*ptr;

  if (taille <= 0)
    return (NULL);
  ptr = malloc(taille);
  if (ptr == NULL)
    fprintf(stderr, "Could not alloc\n");
  return (ptr);
}

int	xfork(int context)
{
  int	pid;

  if ((pid = fork()) == -1)
    {
      fprintf(stderr, "Fork problem\n");
      if (context == 0)
	return (FAIL);
      else
	{
	  g_statu = -1;
	  kill(getpid(), SIGKILL);
	}
    }
  return (pid);
}

int	xpipe(int pipefd[2], int context)
{
  int	error;

  if ((error = pipe(pipefd)) == -1)
    {
      fprintf(stderr, "Problem with pipe\n");
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
