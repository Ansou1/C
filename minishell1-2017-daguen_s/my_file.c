/*
** my_fonction6.c for mysh in /home/daguen_s//my_minishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Dec 23 12:26:51 2012 simon daguenet
** Last update Sun Dec 23 12:39:33 2012 simon daguenet
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <unistd.h>
#include <dirent.h>
#include <signal.h>
#include "mysh.h"

void	my_putnbr_base2(int nb, char *base)
{
  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
    }
  if (nb >= my_strlen(base))
    {
      my_putnbr_base2(nb / my_strlen(base), base);
    }
  my_putchar(base[nb % my_strlen(base)]);
}

void	init_var(int *var)
{
  var[0] = 0;
  var[1] = 0;
  var[2] = 5;
}

char	*get_path(char **env)
{
  int	i;
  char	*tab;

  i = 0;
  while (env[i])
    {
      if (my_strstr(env[i], "PATH=") && env[i][0] == 'P')
        {
          tab = my_strdup(env[i]);
          i++;
        }
      else
        i++;
    }
  return (tab);
}

void	get_sigint(int sig)
{
  my_putstr("\b");
  my_putstr("\b");
  my_putchar(128);
  my_putchar(128);
  my_putchar('\n');
  my_putstr("$>");
}
