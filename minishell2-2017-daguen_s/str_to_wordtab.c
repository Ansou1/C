/*
** str_to_wordtab.c for mysh2 in /home/daguen_s//secminishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar  9 12:08:53 2013 simon daguenet
** Last update Sun Mar 10 20:38:37 2013 simon daguenet
*/

#include "mysh.h"

int	is_sep(char c, char *sep)
{
  int	i;

  i = -1;
  while (sep[++i])
    if (sep[i] == c)
      return (1);
  return (0);
}

int	my_count_word(char *str, char *sep)
{
  int	i;
  int	nbr;

  nbr = 0;
  i = -1;
  while (str[++i])
    if (!is_sep(str[i], sep))
      {
	while (!is_sep(str[i], sep) && str[i + 1])
	  i++;
	nbr++;
      }
  return (nbr);
}

char	**str_to_wordtab(char *str, char *sep)
{
  char	**tab;
  int	i;
  int	j;
  int	x;
  int	z;

  tab = xmalloc(sizeof(*tab) * (my_count_word(str, sep) + 1));
  j = -1;
  i = -1;
  while (str[++i])
    if (!is_sep(str[i], sep))
      {
	x = i;
	while (!is_sep(str[++i], sep) && str[i] != '\0');
	tab[++j] = xmalloc(sizeof(**tab) * (i - x + 1));
	z = -1;
	while (++z < i - x)
	  tab[j][z] = str[x + z];
	tab[j][z] = '\0';
	i -= (str[i] == '\0');
      }
  tab[++j] = NULL;
  return (tab);
}
