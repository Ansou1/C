/*
** my_fonction4.c for mysh in /home/daguen_s//my_minishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Dec 23 12:23:45 2012 simon daguenet
** Last update Sun Dec 23 12:41:46 2012 simon daguenet
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

int	count_word(char *str)
{
  int	i;
  int	n;

  i = 0;
  n = 1;
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] == ' ' && str[i + 1] != '\0')
        n = n + 1;
      i = i + 1;
    }
  return (n);
}

int	countchar(char *str)
{
  int	c;

  c = 0;
  while ((str[c] != ' ') && (str[c] != '\0') && (str[c] != '\n'))
    c = c + 1;
  c = c + 1;
  return (c);
}

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  int	i;
  int	b;
  int	a;

  b = 0;
  i = 0;
  a = 0;
  tab = malloc(sizeof(*tab) * ((count_word(str) + 1)));
  while (str[i] != '\n' && str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\n')
        {
          while (str[i] == ' ')
            i = i + 1;
          a = a + 1;
          b = 0;
        }
      tab[a] = malloc(sizeof(**tab) * ((countchar(str + i) + 1)));
      while ((str[i] != ' ')  && (str[i] != '\n') && (str[i] != '\0'))
        tab[a][b++] = str[i++];
      tab[a][b] = '\0';
    }
  tab[a + 1] = 0;
  return (tab);
}
