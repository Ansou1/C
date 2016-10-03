/*
** separator.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Mon Feb 25 20:43:08 2013 florian corradin
** Last update Sun May 26 14:01:52 2013 antoine simon
*/

#include "42.h"

int	get_number_of_in_str(char *str)
{
  int	i;
  int	ctr;

  ctr = 0;
  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    {
      if (str[i] == ';' || (str[i] == '|' && str[i + 1] == '|'))
	ctr++;
      else if (str[i] == '&' && str[i + 1] == '&')
	ctr++;
      i++;
    }
  return (ctr);
}

int	is_separator(char *str)
{
  if (str[0] == '\0')
    return (0);
  else if (str[0] == '|' && str[1] == '|')
    return (SEPARATOR_OR);
  else if (str[0] == '&' && str[1] == '&')
    return (SEPARATOR_AND);
  else if (str[0] == ';')
    return (SEMI_COLUMN);
  else
    return (0);
}

char	*my_strcopy_to_separator(char *str, int *position)
{
  int	i;
  char	*ret;

  i = 0;
  while (str[i] != '\0' && is_separator(&str[i]) == 0)
    i++;
  ret = malloc(i + 1);
  check_malloc(ret);
  ret[i] = '\0';
  i = 0;
  while (str[i] != '\0' && is_separator(&str[i]) == 0)
    {
      ret[i] = str[i];
      i++;
    }
  ret[i] = '\0';
  if (is_separator(&str[i]) == SEMI_COLUMN)
    *position = *position + i + 1;
  else if (is_separator(&str[i]) == SEPARATOR_AND || is_separator(&str[i])
	   == SEPARATOR_OR)
    *position = *position + i + 2;
  else
    *position = *position + i;
  return (ret);
}

char	*get_num_sep(char *com, char *sep, int ctr)
{
  int	i;
  int	point;
  int	i1;

  i1 = 0;
  i = 0;
  sep = malloc(ctr + 1);
  check_malloc(sep);
  while (com[i] != '\0')
    {
      if ((point = is_separator(&com[i])) != 0)
	sep[i1++] = point;
      i++;
    }
  sep[ctr] = '\0';
  return (sep);
}

char	**my_get_separator(char *com, char **sep)
{
  int	i;
  int	ctr;
  char	**ret;
  char	*epur;

  ctr = get_number_of_in_str(com);
  *sep = get_num_sep(com, *sep, ctr);
  i = 0;
  ret = malloc(sizeof (char **) * (ctr + 2));
  check_malloc(ret);
  ret[ctr + 1] = NULL;
  ctr = 0;
  while (com[i] != '\0')
    {
      epur = my_strcopy_to_separator(&com[i], &i);
      ret[ctr] = my_epurstr(epur);
      free(epur);
      ctr++;
    }
  ret[ctr] = NULL;
  return (ret);
}
