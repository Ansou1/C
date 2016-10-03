/*
** recup.c for corewar in /home/corrad_f//projet/champion/commande
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Fri Jan 25 17:31:35 2013 florian corradin
** Last update Sat Mar 16 15:09:38 2013 simon daguenet
*/

#include "asm.h"

char	*my_clean2(char *ret)
{
  int	i;
  char	*str;
  int	len;

  i = 0;
  str = malloc(5);
  check_malloc(str);
  str[4] = '\0';
  while (i < 4)
    {
      str[i] = '0';
      i++;
    }
  len = my_strlen(ret) - 1;
  i = 3;
  while (len >= 0)
    {
      str[i] = ret[len];
      i--;
      len--;
    }
  return (str);
}

char	*my_clean4(char *ret)
{
  int	i;
  char	*str;
  int	len;

  i = 0;
  str = malloc(9);
  check_malloc(str);
  str[8] = '\0';
  while (i < 8)
    {
      str[i] = '0';
      i++;
    }
  len = my_strlen(ret) - 1;
  i = 7;
  while (len >= 0)
    {
      str[i] = ret[len];
      i--;
      len--;
    }
  return (str);
}

void	my_memset(char c, char **str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      *str[i] = c;
      i++;
    }
}

char	*my_copy_str_to(char *dest, char *src, int pos)
{
  int	i;

  i = 0;
  if (src == NULL || dest == NULL)
    {
      my_putstr("Error in the assembleur\n");
      exit(0);
    }
  while (src[i] != '\0' && dest[pos + i] != '\0')
    {
      dest[pos + i] = src[i];
      i++;
    }
  return (dest);
}
