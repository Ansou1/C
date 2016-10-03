/*
** my_epur_str.c for Corewar in /home/Jonathan/Work/ProgElem/Corewar/ASM/src
** 
** Made by Jonathan Racaud
** Login   <Jonathan@epitech.net>
** 
** Started on  Wed Jan 30 17:40:25 2013 Jonathan Racaud
** Last update Mon May 13 13:28:51 2013 efilon
*/

#include <unistd.h>
#include <stdlib.h>
#include "raytracer.h"

int	my_check_space_tab(char *str, int i)
{
  while ((str[i] == ' ' || str[i] == '\t') &&
	 (str[i + 1] == ' ' || str[i + 1] == '\t'))
    i++;
  return (i);
}

char	*my_epur_str(char *str)
{
  int	cnt;
  int	i;
  char	*ep_ln;

  i = 0;
  cnt = 0;
  if (str[i] == ' ' || str[i] == '\t')
    i = my_check_space_tab(str, i) + 1;
  if ((ep_ln = malloc(sizeof(str) * my_strlen(str))) == NULL)
    {
      my_putstr("[ERROR]: malloc error in my_epur_str");
      return (NULL);
    }
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
	i = my_check_space_tab(str, i);
      if ((str[i] == ' ' || str[i] == '\t') && (str[i + 1] == '\0'))
	i += 1;
      if (str[i] == '\t' && str[i++] != '\t')
	ep_ln[cnt++] = ' ';
      ep_ln[cnt++] = str[i++];
    }
  ep_ln[cnt] = '\0';
  return (ep_ln);
}
