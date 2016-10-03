/*
** tools_clt.c for client_minitalk in /home/daguen_s//talk/client
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Mar 24 00:14:04 2013 simon daguenet
** Last update Sun Mar 24 01:08:45 2013 simon daguenet
*/

#include "client.h"

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

int	my_getnbr(char *str)
{
  int	nbr;

  if (*str == '-')
    return (-my_getnbr(str + 1));
  if (*str == '+')
    return (my_getnbr(str + 1));
  nbr = 0;
  while (*str >= '0' && *str <= '9')
    nbr = nbr * 10 + (*(str++) - '0');
  return (nbr);
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
