/*
** my_str_to_word_tab.c for string in /home/corrad_f//projet/minishell2/string
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Tue Feb 12 15:39:17 2013 florian corradin
** Last update Thu May 23 14:20:25 2013 simon daguenet
*/

#include "42.h"

char	*my_get_word(char *buf, int *pos)
{
  int	i;
  char	*stock;
  int	a;

  a = 0;
  i = 0;
  while (buf[*pos + i] != ' ' && buf[*pos + i] != '\0')
    i++;
  stock = malloc(i + 1);
  i = 0;
  while (buf[*pos + i] != ' ' && buf[*pos + i] != '\0')
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
  if (buf[i] == ' ' && (buf[i + 1] != ' ' && buf[i + 1] != '\0'))
    return (1);
  else if (buf[0] != ' ' && i == 0)
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
  ret = malloc(sizeof (char **) * (ctr + 2));
  check_malloc(ret);
  ret[ctr + 1] = NULL;
  while (buf[i] != '\0' && a < ctr)
    {
      if (buf[i] != ' ')
	{
	  ret[a] = my_get_word(buf, &i);
	  a++;
	}
      i++;
    }
  ret[a] = NULL;
  return (ret);
}
