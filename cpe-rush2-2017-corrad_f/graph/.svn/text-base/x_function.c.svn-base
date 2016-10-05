/*
** x_function.c for rush in /home/daguen_s//rush/save_valgrind
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Mar  3 10:40:15 2013 simon daguenet
** Last update Sun Apr 21 12:03:13 2013 simon daguenet
*/

#include "sudoku.h"

void	*xmalloc(size_t taille)
{
  void	*ptr;

  if (taille == 0)
    return (NULL);
  ptr = malloc(taille);
  if (ptr == NULL)
    my_puterror("Error in Xmalloc");
  return (ptr);
}

void	my_freetab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}
