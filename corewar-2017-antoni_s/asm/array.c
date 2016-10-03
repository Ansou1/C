/*
** array.c for mini in /home/corrad_f//projet/minishell1
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Tue Dec 11 20:53:49 2012 florian corradin
** Last update Fri Mar 29 13:51:56 2013 simon daguenet
*/

#include "asm.h"

char	*my_stradd(char *strt, char *end)
{
  char	*ret;
  int	i;
  int	a;

  a = 0;
  i = 0;
  ret = malloc(my_strlen(end) + my_strlen(strt) + 1);
  check_malloc(ret);
  while (strt[i] != '\0')
    {
      ret[i] = strt[i];
      i++;
    }
  while (end[a])
    {
      ret[i] = end[a];
      a++;
      i++;
    }
  ret[i] = '\0';
  return (ret);
}

char	*my_get_word(char *buf, int *pos)
{
  int	i;
  char	*stock;
  int	a;

  a = 0;
  i = 0;
  while (buf[*pos + i] != ' ' &&
	buf[*pos + i] != '\0' && buf[*pos + i] != '\t')
    i++;
  stock = malloc(i + 1);
  check_malloc(stock);
  i = 0;
  while (buf[*pos + i] != ' ' && buf[*pos + i] != '\0'
	&& buf[*pos + i] != '\t')
    {
      stock[a] = buf[*pos + i];
      if (stock[a] == '\n')
	stock[a] = '\0';
      a++;
      i++;
    }
  *pos = *pos + i - 1;
  stock[a] = '\0';
  return (stock);
}

int	my_is_word(char *buf, int i)
{
  if (buf[i] == ' ' && (buf[i  + 1] != ' ' && buf[i + 1] != '\0'))
    return (1);
  else if (buf[i] == '\t' && (buf[i  + 1] != '\t' && buf[i + 1] != '\0'))
    return (1);
  else if (buf[0] != ' ' && i == 0)
    return (1);
  else if (buf[0] != '\t' && i == 0)
    return (1);
  else
    return (0);
}

int	my_count_word(char *buf)
{
  int	i;
  int	ctr;

  i = 0;
  ctr = 0;
  while (buf[i] != '\0')
    {
      if (my_is_word(buf, i))
	ctr++;
      i++;
    }
  return (ctr);
}

char	**my_str_to_wordtab(char *buf)
{
  char	**ret;
  int	i;
  int	ctr;
  int	a;

  i = 0;
  a = 0;
  ctr = my_count_word(buf);
  ret = malloc(sizeof (char *) * (ctr + 1));
  check_malloc(ret);
  ret[ctr] = NULL;
  while (buf[i] != '\0' && a < ctr)
    {
      if (buf[i] != ' ' && buf[i] != '\t')
	{
	  ret[a] = my_get_word(buf, &i);
	  a++;
	}
      i++;
    }
  return (ret);
}
