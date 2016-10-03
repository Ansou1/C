/*
** epur_str.c for string.h in /home/corrad_f//lib/string
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Fri Jan 18 18:27:18 2013 florian corradin
** Last update Sat Mar 16 18:42:24 2013 simon daguenet
*/

#include "asm.h"

char	*my_epurstr(char *str)
{
  int	i;
  char	*ret;
  int	a;

  a = 0;
  ret = malloc(my_strlen(str) + 1);
  check_malloc(ret);
  ret[my_strlen(str)] = '\0';
  i = 0;
  while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
    i++;
  while (str[i] != '\0')
    {
      if ((str[i] == ' ' || str[i] == '\t') &&
	  (str[i + 1] == ' ' || str[i + 1] == '\t'))
	i++;
      else
	ret[a++] = str[i++];
    }
  if (a > 0)
    if (ret[a - 1] == ' ' || ret[a - 1] == '\t')
      ret[a - 1] = '\0';
  ret[a] = '\0';
  return (ret);
}
