/*
** xfunction.c for mysh in /home/daguen_s//secminishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar  9 11:56:32 2013 simon daguenet
** Last update Thu Mar 28 20:53:41 2013 simon daguenet
*/

#include "asm.h"

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
    {
      my_putstr("Error in Xmalloc\n");
      exit(0);
    }
  return (ptr);
}

void	xclose(int fd)
{
  int	error;

  if ((error = close(fd)) == -1)
    {
      my_putstr("Cannot close the filedescriptor\n");
      exit(EXIT_FAILURE);
    }
}
