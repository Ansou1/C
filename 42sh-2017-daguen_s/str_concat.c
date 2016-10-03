/*
** str_concat.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Fri Feb 22 20:32:45 2013 florian corradin
** Last update Thu May 23 15:06:50 2013 simon daguenet
*/

#include "42.h"

char	*my_strcat(char *strt, char *end)
{
  char	*ret;
  int	i;
  int	a;

  a = 0;
  i = 0;
  if (strt == NULL || end == NULL)
    return (NULL);
  if ((ret = malloc(my_strlen(end) + my_strlen(strt) + 1)) == NULL)
    return (NULL);
  while (strt[i] != '\0')
    {
      ret[i] = strt[i];
      i++;
    }
  while (end[a] != '\0')
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
  if (strt == NULL || end == NULL)
    return (NULL);
  if ((ret = malloc(my_strlen(end) + my_strlen(strt) + 1)) == NULL)
    return (NULL);
  while (strt[i] != '\0')
    {
      ret[i] = strt[i];
      i++;
    }
  while (end[a] != '\0')
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
  if (strt == NULL || end == NULL)
    return (NULL);
  if ((ret = malloc(my_strlen(end) + my_strlen(strt) + 1)) == NULL)
    return (NULL);
  while (strt[i] != '\0')
    {
      ret[i] = strt[i];
      i++;
    }
  while (end[a] != '\0')
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
  if (strt == NULL || end == NULL)
    return (NULL);
  if ((ret = malloc(my_strlen(end) + my_strlen(strt) + 1)) == NULL)
    return (NULL);
  while (strt[i] != '\0')
    {
      ret[i] = strt[i];
      i++;
    }
  while (end[a] != '\0')
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
