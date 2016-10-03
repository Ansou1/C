/*
** str_func.c for script in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Tue Apr 30 10:39:52 2013 florian corradin
** Last update Tue Apr 30 15:27:59 2013 florian corradin
*/

#include "42.h"

char	*get_word(char *str)
{
  int	i;
  char	*ret;
  int	a;

  a = 0;
  while (str[a] == ' ' || str[a] == '\t')
    a++;
  i = a;
  while (str[i] && str[i] != ' ' && str[i] != '\t')
    i++;
  if ((ret = malloc(i + 1)) == NULL)
    return (NULL);
  i = a;
  a = 0;
  while (str[i] && str[i] != ' ' && str[i] != '\t')
    {
      ret[a++] = str[i++];
    }
  ret[i] = '\0';
  return (ret);
}
