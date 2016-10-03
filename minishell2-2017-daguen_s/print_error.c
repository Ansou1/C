/*
** print_error.c for mysh2 in /home/daguen_s//secminishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar  9 12:34:59 2013 simon daguenet
** Last update Sun Mar 10 19:26:09 2013 simon daguenet
*/

#include "mysh.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;
  char	*tmp;

  if (dest == NULL || src == NULL)
    return (NULL);
  tmp = malloc(my_strlen(dest) + my_strlen(src) + 1);
  if (tmp == NULL)
    return (NULL);
  i = 0;
  while (dest[i] != '\0')
    {
      tmp[i] = dest[i];
      i = i + 1;
    }
  j = 0;
  while (src[j] != '\0')
    {
      tmp[i] = src[j];
      i = i + 1;
      j = j + 1;
    }
  tmp[i] = '\0';
  return (tmp);
}

void	my_put_error(char *str)
{
  my_putstr(str);
  exit(EXIT_FAILURE);
}

void	error_with_function(int i)
{
  if (i == 1)
    {
      write(2, "error on pipe\n", my_strlen("error on pipe\n"));
      exit (EXIT_FAILURE);
    }
  else if (i == 2)
    {
      write(2, "error on fork\n", my_strlen("error on fork\n"));
      exit (EXIT_FAILURE);
    }
  else if (i == 3)
    {
      write(2, "error on dup2\n", my_strlen("error on dup2\n"));
      exit (EXIT_FAILURE);
    }
  else if (i == 4)
    {
      write(2, "error on close\n", my_strlen("error on close\n"));
      exit (EXIT_FAILURE);
    }
}
