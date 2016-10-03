/*
** my_strncmp.c for my_strncmp in /home/cheval_y//testjour6
** 
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
** 
** Started on  Tue Oct  9 15:03:49 2012 franck chevallier
** Last update Thu Apr 11 15:54:35 2013 franck chevallier
*/

#include "raytracer.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	result;
  int	a;

  a = 0;
  result = 0;
  while (s2[a] == s1[a] && a < (n - 1))
    {
      a = a + 1;
      if (s2[a] == '\0' && s1[a] == '\0')
        {
          return (0);
        }
    }
  result = s1[a] - s2[a];
  return (result);
}
