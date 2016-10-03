/*
** x_func.c for lemin in /home/daguen_s//my_lemin
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Apr  1 15:17:03 2013 simon daguenet
** Last update Tue Apr  2 10:41:16 2013 simon daguenet
*/

#include "lemin.h"

int	my_puterror(char *str)
{
  write(2, str, my_strlen(str));
  exit(EXIT_FAILURE);
  return (0);
}

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

void	my_free_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab != NULL)
    while (tab[i] != NULL)
      {
	xfree(tab[i]);
	i++;
      }
  if (tab != NULL)
    xfree(tab);
}
