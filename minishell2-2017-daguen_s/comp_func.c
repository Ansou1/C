/*
** comp_func.c for mysh in /home/daguen_s//secminishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar  9 11:59:19 2013 simon daguenet
** Last update Sat Mar  9 12:00:58 2013 simon daguenet
*/

#include "mysh.h"

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;

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
