/*
** x_function.c for rush in /home/daguen_s//rush/save_valgrind
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Mar  3 10:40:15 2013 simon daguenet
** Last update Sun Mar  3 15:28:42 2013 simon daguenet
*/

#include "rush.h"

void	xfree(void *ptr)
{
  if (ptr == NULL)
    my_print_error("The pointer is NULL.\n");
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
    my_print_error("Error in Xmalloc\n");
  return (ptr);
}

void	xclose(int fd)
{
  int	error;

  if ((error = close(fd)) == -1)
    my_print_error("ERROR: close\n");
}
