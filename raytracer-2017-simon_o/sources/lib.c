/*
** lib.c for lib in /home/efilon/Projets/Projects/Cproject/xml
** 
** Made by sebastien antonico
** Login   <efilon@heisenberg>
** 
** Started on  Sat May  4 15:06:01 2013 sebastien antonico
** Last update Sat Jun  8 16:19:33 2013 antoine simon
*/

#include <unistd.h>
#include <stdlib.h>
#include "raytracer.h"

int	my_strcmp_case(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i])
    {
      if (to_lower(s1[i]) - to_lower(s2[i]) != 0)
	return (to_lower(s1[i]) - to_lower(s2[i]));
      i++;
    }
  return (to_lower(s1[i]) - to_lower(s2[i]));
}

int	my_strncmp_case(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] && i < n)
    {
      if (to_lower(s1[i]) - to_lower(s2[i]) != 0)
	return (to_lower(s1[i]) - to_lower(s2[i]));
      i++;
    }
  return (0);
}

int	is_space(char c)
{
  if (c == ' ' || c == '\t')
    return (1);
  return (0);
}

int	count_words(char *line)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (line[i])
    {
      while (line[i] && is_space(line[i]))
	i++;
      if (line[i] && !is_space(line[i]))
	nb++;
      while (line[i] && !is_space(line[i]))
	i++;
    }
  return (nb);
}

char	**str_to_wordtab(char *line)
{
  char	**str;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((str = malloc(sizeof(char*) * (count_words(line) + 1))) == NULL)
    my_puterr("Erreur malloc.\n");
  while (line[i])
    {
      while (line[i] && is_space(line[i]))
	line[i++] = 0;
      if (line[i] && !is_space(line[i]))
	str[j++] = &(line[i]);
      while (line[i] && !is_space(line[i]))
	i++;
    }
  str[j] = NULL;
  return (str);
}
