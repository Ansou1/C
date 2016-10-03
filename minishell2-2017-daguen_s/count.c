/*
** count.c for mysh2 in /home/daguen_s//secminishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar  9 12:18:48 2013 simon daguenet
** Last update Sat Mar  9 12:20:21 2013 simon daguenet
*/

#include "mysh.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

int	my_strlen_dbl(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
