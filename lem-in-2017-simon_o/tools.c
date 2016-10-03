/*
** tools.c for lemin in /home/daguen_s//my_lemin
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Apr  1 16:08:49 2013 simon daguenet
** Last update Mon Apr  1 20:50:22 2013 simon daguenet
*/

#include "lemin.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

char	*my_strdup(char *src)
{
  int	i;
  int	j;
  char	*chaine;

  i = 0;
  i = my_strlen(src);
  chaine = xmalloc(i + 1);
  j = 0;
  while (src[j] != '\0')
    {
      chaine[j] = src[j];
      j = j + 1;
    }
  chaine[j] = '\0';
  return (chaine);
}

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;

  if (my_strlen(str) > my_strlen(to_find))
    return (0);
  i = 0;
  while (i < my_strlen(str))
    {
      j = 0;
      while (str[i + j] == to_find[j] && j < my_strlen(to_find))
	j++;
      if (j == my_strlen(to_find))
	return (&str[i]);
      i++;
    }
  return (0);
}

int	my_strcmp(char *str1, char *str2)
{
  int	i;
  int	ctr;

  ctr = 0;
  i = 0;
  while (str2[i] != '\0')
    {
      while (str1[ctr] == str2[i] && str2[i] != '\0' && str1[ctr] != '\0')
	{
	  i++;
	  ctr++;
	}
      if (ctr == my_strlen(str1))
	return (1);
      else
	ctr = 0;
      i++;
    }
  return (0);
}

int	my_strncmp(char *str1, char *str2, int n)
{
  int	i;

  i = 0;
  while (str1[i] != '\0' && str2[i] != '\0' && i < n)
    {
      if (str1[i] != str2[i])
	return (0);
      i++;
    }
  if (i == n)
    return (1);
  else
    return (0);
}

