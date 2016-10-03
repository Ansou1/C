/*
** all_strdup.c for mysh in /home/daguen_s//secminishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar  9 12:01:17 2013 simon daguenet
** Last update Sat Mar  9 12:03:48 2013 simon daguenet
*/

#include "mysh.h"

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

char	*my_strdup_user(char *src)
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

char	*my_strdup_old(char *src)
{
  int	i;
  int	j;
  char	*chaine;

  i = 0;
  i = my_strlen(src) - 7;
  chaine = malloc(i + 1);
  if (chaine == NULL)
    return (NULL);
  j = 7;
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
