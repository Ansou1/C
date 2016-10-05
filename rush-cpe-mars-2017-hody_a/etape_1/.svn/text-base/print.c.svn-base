/*
** print.c for rush in /home/daguen_s//rush/save_valgrind
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Mar  3 10:41:45 2013 simon daguenet
** Last update Sun Mar  3 10:57:29 2013 simon daguenet
*/

#include "rush.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

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

void	my_print_error(char *str)
{
  write(2, str, my_strlen(str));
  exit(EXIT_FAILURE);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    {
      i = i + 1;
    }
  return (s1[i] - s2[i]);
}
