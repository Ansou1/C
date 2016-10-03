/*
** my_getnbr.c for my_getnbr in /tmp/pouetpouet/corewar-2017-antoni_s/corewar/libmy
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Sun Mar 31 18:54:36 2013 sebastien antonico
** Last update Sun Mar 31 18:56:45 2013 sebastien antonico
*/

#include <unistd.h>

int	is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int	my_getnbr(char *str)
{
  int	i;
  int	nb;

  if (str == NULL)
    return (0);
  nb = 0;
  i = (str[0] == '-') ? 1 : 0;
  while (str[i] && is_num(str[i]))
    {
      nb = (nb * 10) + (str[i] - 48);
      i++;
    }
  return ((str[0] == '-') ? nb * -1 : nb);
}
