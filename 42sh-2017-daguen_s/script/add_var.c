/*
** add_var.c for infectsh in /home/corrad_f//projet/infect/script
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sun Apr  7 10:58:04 2013 florian corradin
** Last update Wed Apr 24 17:37:41 2013 florian corradin
*/

#include "42.h"

char	*get_str_sep(char *str, char sep)
{
  int	i;
  char	*ret;

  i = 0;
  while (str[i] != '\0' && is_c(str, i, sep) == 0)
    i++;
  ret = xmalloc(i + 1);
  i = 0;
  while (str[i] != '\0' && is_c(str, i, sep) == 0)
    {
      ret[i] = str[i];
      i++;
    }
  ret[i] = '\0';
  return (ret);
}
