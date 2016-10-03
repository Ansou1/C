/*
** modif_str.c for str in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Sat Apr 13 19:06:15 2013 florian corradin
** Last update Fri May  3 19:17:38 2013 florian corradin
*/

#include "42.h"

char	*replace_by_in_str(char *str, char rep, char by)
{
  char	*ret;
  char	c;

  ret = str;
  while ((c = *str++))
    str[-1] = ((c == rep) ? by : c);
  return (ret);
}

char	*get_next_word(char *str)
{
  int	i;
  int	a;
  char	*ret;

  a = 0;
  i = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i] && str[i] != ' ' && str[i] != '\t')
    i++;
  if ((ret = malloc(i + 1)) == NULL)
    return (NULL);
  i = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i] && str[i] != ' ' && str[i] != '\t')
    {
      ret[a++] = str[i++];
    }
  ret[a] = '\0';
  return (ret);
}
