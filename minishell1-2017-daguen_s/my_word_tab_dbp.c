/*
** my_fonction5.c for mysh in /home/daguen_s//my_minishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Dec 23 12:25:54 2012 simon daguenet
** Last update Sun Dec 23 12:40:32 2012 simon daguenet
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

int	count_w(char *str)
{
  int	i;
  int	n;

  i = 5;
  n = 1;
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] == ':' && str[i + 1] != '\0')
        n = n + 1;
      i = i + 1;
    }
  return (n);
}

int	count_char(char *str)
{
  int	c;

  c = 0;
  while ((str[c] != ':') && (str[c] != '\0') && (str[c] != '\n'))
    c = c + 1;
  c = c + 1;
  return (c);
}

char	**wordtab_dbp(char *str)
{
  char	**tab;
  int	var[3];

  init_var(var);
  tab = malloc(sizeof(*tab) * ((count_w(str) + 1)));
  while (str[var[2]] != '\n' && str[var[2]] != '\0')
    {
      if (str[var[2]] == ':' || str[var[2]] == '\n')
        {
          while (str[var[2]] == ':')
            var[2] = var[2] + 1;
          var[0] = var[0] + 1;
          var[1] = 0;
        }
      tab[var[0]] = malloc(sizeof(**tab) * ((count_char(str + var[2]) + 1)));
      while ((str[var[2]] != ':')  && (str[var[2]] != '\n')
             && (str[var[2]] != '\0'))
        tab[var[0]][var[1]++] = str[var[2]++];
      tab[var[0]][var[1]] = '/';
      tab[var[0]][var[1] + 1] = '\0';
    }
  tab[var[0] + 1] = 0;
  return (tab);
}
