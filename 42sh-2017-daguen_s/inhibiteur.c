/*
** inhibiteur.c for 42s in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sun Mar 24 18:41:44 2013 florian corradin
** Last update Sat Mar 30 19:18:41 2013 florian corradin
*/

#include "42.h"

int	is_this_type(char c, char *type)
{
  int	i;

  i = 0;
  while (type[i] != '\0')
    {
      if (c == type[i])
	return (1);
      i++;
    }
  return (0);
}

int	is_inib(char *com, int pos)
{
  if (is_c(com, pos, 34) == 1 || is_c(com, pos, 39) == 1)
    return (1);
  return (0);
}

int	inib_this_char(char com, int inib)
{
  if (inib == 34)
    {
      if (is_this_type(com, CHAR_INIB34) == 1)
	return (1);
    }
  else if (inib == 39)
    {
      if (is_this_type(com, CHAR_INIB39) == 1)
	return (1);
    }
  return (0);
}

void	init_get_str_inib(int *i2, int *inib, int *i)
{
  *i2 = 0;
  *inib = 0;
  *i = 0;
}

char	*get_str_inhib(char *com)
{
  char	*ret;
  int	i;
  int	inib;
  int	i2;

  init_get_str_inib(&i2, &inib, &i);
  ret = malloc(my_strlen(com) * 2 + 1);
  while (com[i] != '\0')
    {
      if (inib == 0 && is_inib(com, i) == 1)
	inib = com[i++];
      if (inib != 0 && is_inib(com, i) == 1 && inib == com[i])
	{
	  inib = 0;
	  i++;
	}
      if (inib_this_char(com[i], inib) == 1)
	ret[i2++] = 92;
      ret[i2++] = com[i];
      if (com[i] != '\0')
	i++;
    }
  ret[i2] = '\0';
  free(com);
  return (ret);
}
