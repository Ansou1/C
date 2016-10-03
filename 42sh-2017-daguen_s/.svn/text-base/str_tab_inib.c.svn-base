/*
** str_tab_inib.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Tue Mar 26 11:50:26 2013 florian corradin
** Last update Sat Mar 30 19:39:03 2013 florian corradin
*/

#include "42.h"

int	is_c(char *str, int pos, char c)
{
  int	i;

  i = 1;
  if (str[pos] != c)
    return (0);
  if (pos == 0)
    return (1);
  while ((pos - i) != 0 && str[pos - i] == 92)
    i++;
  if ((pos - i) == 0 && str[0] == 92)
    i++;
  return (i & 1);
}

char	*get_word_inib_suite(int *pos, int ctr, char *str)
{
  char	*word;
  int	i;
  int	ctr2;

  ctr2 = 0;
  i = 0;
  if ((word = malloc(ctr + 1)) == NULL)
    return (NULL);
  i = *pos;
  while (ctr2 < ctr)
    word[ctr2++] = str[i++];
  word[ctr] = '\0';
  *pos = *pos + ctr;
  if (str[*pos] != '\0')
    *pos = *pos + 1;
  return (word);
}

char	*get_word_inib(char *str, int *pos)
{
  int	mag;
  int	cont;
  int	ctr;
  int	i;

  ctr = 0;
  cont = 0;
  i = *pos;
  mag = 0;
  while (str[i] != '\0' && cont == 0)
    {
      if (is_c(str, i, 96) == 1 && mag == 0)
	mag = 1;
      else if (is_c(str, i, 96) == 1 && mag == 1)
	mag = 0;
      i++;
      ctr++;
      if (is_s(str, i) == 1 && mag == 0)
	cont = 1;
    }
  return (get_word_inib_suite(pos, ctr, str));
}

char	**str_to_tab_inib(char *str)
{
  char	**ret;
  int	pos;
  char	*word;

  pos = 0;
  ret = malloc(sizeof (char **));
  if (ret == NULL)
    return (NULL);
  ret[0] = NULL;
  while (str[pos] != '\0')
    {
      if ((word = get_word_inib(str, &pos)) == NULL)
	return (NULL);
      if ((word = my_epurstr_inib(word)) == NULL)
	return (NULL);
      if (word[0] != '\0')
	ret = my_tabcat(ret, word);
    }
  return (ret);
}
