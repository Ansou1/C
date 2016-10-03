/*
** strcmp.c for lib in /home/corrad_f/
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sun Dec  9 10:14:14 2012 florian corradin
** Last update Thu May 23 14:19:44 2013 simon daguenet
*/

#include <stdlib.h>

int	str_op(const char *s1, const char *s2)
{
  int	ret;

  while ((ret = *(unsigned char *) s1 - *(unsigned char *) s2++) == 0
	 && *s1++);
  if (*s1 == 0 || *s2 == 0)
    return ret;
  return (0);
}

int				my_strcmp(const char *p1, const char *p2)
{
  register const unsigned char	*s1;
  register const unsigned char	*s2;
  register unsigned char	c1;
  register unsigned char	c2;

  s1 = (const unsigned char *)p1;
  s2 = (const unsigned char *)p2;
  c1 = (unsigned char)*s1++;
  c2 = (unsigned char)*s2++;
  while (c1 == c2)
    {
      c1 = (unsigned char)*s1++;
      c2 = (unsigned char)*s2++;
      if (c1 == '\0')
	return (c1 - c2);
    }
  return (c1 - c2);
}

int	my_strncmp(char *str1, char *str2, int n)
{
  int	i;

  i = 0;
  while (str1[i] != '\0' && str2[i] != '\0' && i < n)
    {
      if (str1[i] != str2[i])
	return (0);
      i++;
    }
  if (i == n)
    return (1);
  else
    return (0);
}

int	my_str_comp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (0);
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (0);
      i++;
    }
  if (s1[i] != s2[i])
    return (0);
  return (1);
}
