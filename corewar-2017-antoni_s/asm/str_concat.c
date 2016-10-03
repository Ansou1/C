/*
** str_concat.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Fri Feb 22 20:32:45 2013 florian corradin
** Last update Fri Mar 29 14:37:41 2013 simon daguenet
*/

#include "asm.h"

char	*my_strcats(char *strt, char *end)
{
  char	*ret;
  int	i;
  int	a;

  a = 0;
  i = 0;
  ret = malloc(my_strlen(end) + my_strlen(strt) + 1);
  check_malloc(ret);
  while (strt[i] != '\0')
    {
      ret[i] = strt[i];
      i++;
    }
  while (end[a])
    {
      ret[i] = end[a];
      a++;
      i++;
    }
  ret[i] = '\0';
  return (ret);
}

char	*my_strcat_free_strt(char *strt, char *end)
{
  char	*ret;
  int	i;
  int	a;

  a = 0;
  i = 0;
  ret = malloc(my_strlen(end) + my_strlen(strt) + 1);
  check_malloc(ret);
  while (strt[i] != '\0')
    {
      ret[i] = strt[i];
      i++;
    }
  while (end[a])
    {
      ret[i] = end[a];
      a++;
      i++;
    }
  ret[i] = '\0';
  free(strt);
  return (ret);
}

char	*my_strcat_free_end(char *strt, char *end)
{
  char	*ret;
  int	i;
  int	a;

  a = 0;
  i = 0;
  ret = malloc(my_strlen(end) + my_strlen(strt) + 1);
  check_malloc(ret);
  while (strt[i] != '\0')
    {
      ret[i] = strt[i];
      i++;
    }
  while (end[a])
    {
      ret[i] = end[a];
      a++;
      i++;
    }
  ret[i] = '\0';
  free(end);
  return (ret);
}

char	*my_strcat_free_all(char *strt, char *end)
{
  char	*ret;
  int	i;
  int	a;

  a = 0;
  i = 0;
  ret = malloc(my_strlen(end) + my_strlen(strt) + 1);
  check_malloc(ret);
  while (strt[i] != '\0')
    {
      ret[i] = strt[i];
      i++;
    }
  while (end[a])
    {
      ret[i] = end[a];
      a++;
      i++;
    }
  ret[i] = '\0';
  free(end);
  free(strt);
  return (ret);
}
