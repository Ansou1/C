/*
** my_strstr.c for libmy in /home/elegbe_m//programmation/fichiers_source_piscine/refonte/libmy
** 
** Made by martial elegbede
** Login   <elegbe_m@epitech.net>
** 
** Started on  Wed Oct 17 11:14:19 2012 martial elegbede
** Last update Wed Oct 17 11:29:55 2012 martial elegbede
*/

#include <stdlib.h>

char	*my_strstr(char *str, char *to_find)
{
  int i;
  int j;

  i = 0;
  while (str[i] != 0)
    {
      j = 0;
      while (str[i + j] == to_find[j])
	{
	  j = j + 1;
	  if (to_find[j] == 0)
	    return (str + i);
	}
      i = i + 1;
    }
  if (str[i] == 0)
    return (NULL);
}
