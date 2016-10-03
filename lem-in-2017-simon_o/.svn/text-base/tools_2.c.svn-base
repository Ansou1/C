/*
** tools_2.c for lemin in /home/daguen_s//my_lemin
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Apr  1 20:59:07 2013 simon daguenet
** Last update Sun Apr 28 15:53:38 2013 simon daguenet
*/

#include "lemin.h"

char	*my_strcat_lem(char *s1, char *s2)
{
  char	*ret;
  int	i;

  i = 0;
  if (s2 == NULL)
    my_puterror("\033[1;31m Error empty line after start or end\n \033[0;m");
  ret = xmalloc(my_strlen(s1) + my_strlen(s2) + 2);
  while (*s1)
    ret[i++] = *s1++;
  ret[i++] = ' ';
  while (*s2)
    ret[i++] = *s2++;
  ret[i] = '\0';
  return (ret);
}

int	my_atoi(char *str)
{
  int	ret;
  char	neg;
  char	c;

  ret = 0;
  neg = (*str == '-') ? -1 : 1;
  if (neg == -1)
    *str++;
  while ((c = *str++) && c >= '0' && c <= '9')
    ret = ret * 10 + (c - '0');
  return (ret * neg);
}

char	*my_epurstr(char *str)
{
  int	i;
  char	*ret;
  int	a;

  a = 0;
  ret = xmalloc(my_strlen(str) + 2);
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
  xfree(str);
  return (ret);
}
