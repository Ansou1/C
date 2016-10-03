/*
** my_fonction2.c for mysh in /home/daguen_s//my_minishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Dec 23 12:18:29 2012 simon daguenet
** Last update Sun Dec 23 12:45:41 2012 simon daguenet
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

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (i < n)
    {
      if (s1[i] != s2[i])
        return (1);
      i++;
    }
  return (0);
}

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;
  char	*tmp;

  tmp = malloc(sizeof(char *) * (my_strlen(dest) + my_strlen(src)+ 1));
  if (dest == NULL)
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

char	*my_strdup(char *src)
{
  int	i;
  int	j;
  char	*chaine;

  i = 0;
  i = my_strlen(src);
  chaine = malloc(i + 1);
  if (chaine == NULL)
    return (NULL);
  j = 0;
  while (src[j] != '\0')
    {
      chaine[j] = src[j];
      j = j + 1;
    }
  chaine[j] = '\0';
  return (chaine);
}

char	*my_strdup_oldpwd(char *src)
{
  int	i;
  int	j;
  char	*chaine;

  i = 0;
  i = my_strlen(src) - 3;
  chaine = malloc(i + 1);
  if (chaine == NULL)
    return (NULL);
  j = 4;
  i = 0;
  while (src[j] != '\0')
    {
      chaine[i] = src[j];
      j = j + 1;
      i = i + 1;
    }
  chaine[i] = '\0';
  return (chaine);
}
