/*
** str_to_wordtab.c for PiRaNhA in /home/cheval_y//rtv1
** 
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
** 
** Started on  Wed Mar 13 18:54:00 2013 franck chevallier
** Last update Thu Apr 11 15:54:34 2013 franck chevallier
*/

#include "raytracer.h"

char	*epur_str(char *str)
{
  int	a;
  int	b;

  a = 0;
  b = 0;
  while (str[a] == ' ' || str[a] == '\t')
    a++;
  while (str[a])
    {
      if (str[a] != ' ' || str[a] != '\t')
	{
	  str[b] = str[a];
	  a++;
	  b++;
	  if (str[a] == ' ' || str [a] == '\t')
	    {
	      str[b] = ' ';
	      b++;
	      while (str[a] == ' ' || str[a] == '\t')
		a++;
	    }
	}
    }
  str[b] = '\0';
  return (str);
}

int	nb_cmd(char *str)
{
  int	cnt;
  int	word;

  cnt = 0;
  word = 0;
  while (str[cnt])
    {
      if (str[cnt] == ' ')
	word = word + 1;
      cnt++;
    }
  return (word + 1);
}

int	num_char(char *str)
{
  int	cnt;

  cnt = 0;
  while (str[cnt] != ' ' && str[cnt] != '\0')
    cnt++;
  return (cnt);
}

char	**str_to_wordtab(char *str)
{
  char	**tab;
  int	cnt;
  int	i;
  int	len;

  epur_str(str);
  len = my_strlen(str);
  cnt = 0;
  i = 0;
  tab = malloc(sizeof(*tab) * (nb_cmd(str) + 1));
  if (tab == NULL)
    return (NULL);
  while (cnt < len)
    {
      if (str[cnt] != ' ')
	{
	  tab[i] = my_strndup(&str[cnt], num_char(&(str[cnt])));
	  cnt += num_char(&(str[cnt]));
	  i++;
	}
      cnt++;
    }
  tab[i] = NULL;
  return (tab);
}
