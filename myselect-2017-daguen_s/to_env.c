/*
** to_env.c for my_select in /home/daguen_s//charlotte/rendu
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Jan 19 23:10:34 2013 simon daguenet
** Last update Sat Jan 19 23:12:09 2013 simon daguenet
*/

#include "my_select.h"

char	*my_strdup_old(char *src)
{
  int	i;
  int	j;
  char	*chaine;

  i = 0;
  i = my_strlen(src) - 4;
  chaine = malloc(i + 1);
  if (chaine == NULL)
    return (NULL);
  j = 5;
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

char	*get_term(char **my_env, char *command)
{
  char	*str;
  int	i;

  str = NULL;
  i = 0;
  while (my_env[i])
    {
      if  (my_strncmp(my_env[i], command, 5) == 0)
        {
          str = my_strdup_old(my_env[i]);
          i++;
        }
      else
        i++;
    }
  return (str);
}
