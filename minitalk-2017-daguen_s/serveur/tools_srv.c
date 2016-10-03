/*
** tools_srv.c for minitalk_srv in /home/daguen_s//talk/serveur
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Mar 24 00:39:04 2013 simon daguenet
** Last update Sun Mar 24 12:11:35 2013 simon daguenet
*/

#include "serveur.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_puterror(char *str)
{
  write(2, str, my_strlen(str));
  exit(EXIT_FAILURE);
}

char	*my_strcpy(char *str)
{
  int	i;
  char	*tmp;

  i = 0;
  tmp = malloc(my_strlen(str) + 1);
  if (tmp == NULL)
    my_puterror("Error malloc in strcpy.\n");
  while (str[i] != '\0')
    {
      tmp[i] = str[i];
      i++;
    }
  tmp[i] = '\0';
  return (tmp);
}
