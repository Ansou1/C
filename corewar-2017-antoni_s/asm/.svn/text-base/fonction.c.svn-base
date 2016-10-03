/*
** fonction.c for corewar in /home/corrad_f//projet/champion/commande/lib
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Wed Jan 23 16:39:20 2013 florian corradin
** Last update Sat Mar 16 18:36:33 2013 simon daguenet
*/

#include "asm.h"

char	*my_strdup(char *src)
{
  int	i;
  char	j;
  char	*chaine;

  i = 0;
  i = my_strlen(src);
  chaine = malloc(i + 1);
  if (chaine == NULL)
    return (NULL);
  j = 0;
  while (src[j] != '\0')
    {
      chaine[j] = src[j];
      j = j + 1;
    }
  chaine[j] = '\0';
  return (chaine);
}
