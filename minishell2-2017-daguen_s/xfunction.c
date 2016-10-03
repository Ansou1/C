/*
** xfunction.c for mysh in /home/daguen_s//secminishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar  9 11:56:32 2013 simon daguenet
** Last update Sat Mar  9 11:58:33 2013 simon daguenet
*/

#include "mysh.h"

void	xfree(void *ptr)
{
  if (ptr == NULL)
    my_putstr("The pointer is NULL.\n");
  else
    free(ptr);
}

void	*xmalloc(size_t taille)
{
  void	*ptr;

  if (taille == 0)
    return (NULL);
  ptr = malloc(taille);
  if (ptr == NULL)
    my_put_error("Error in Xmalloc\n");
  return (ptr);
}

int	xfork()
{
  int	pid;

  if ((pid = fork()) == -1)
    error_with_function(2);
  return (pid);
}

void	xpipe(int pipefd[2])
{
  int	error;

  if ((error = pipe(pipefd)) == -1)
    error_with_function(1);
}

void	xclose(int fd)
{
  int	error;

  if ((error = close(fd)) == -1)
    error_with_function(4);
}
