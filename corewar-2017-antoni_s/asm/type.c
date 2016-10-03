/*
** type.c for corewar in /home/corrad_f//projet/champion/commande
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Thu Jan 24 12:59:53 2013 florian corradin
** Last update Sat Mar 16 18:12:12 2013 simon daguenet
*/

#include "asm.h"

//afficher message derreur et quitter dans le return de if (i > 3)
int	is_reg(char *str)
{
  int	i;

  i = 1;
  if (str[0] != 'r')
    return (0);
  while (str[i] != '\0' && str[i] != ',' && str[i] != ' ' && str[i] != '\t')
    {
      if ((i == 1) && (str[i] < '1' || str[i] > '9'))
        return (0);
      if ((i == 2) && (str[i] < '0' || str[i] > '6'))
        return (0);
      i++;
    }
  if (i > 3)
    return (0);
  if (str[i] != '\0')
    i++;
  return (i);
}

int	is_dir2(char *str)
{
  int	i;

  i = 1;
  if (str[0] != '%')
    return (0);
  while (str[i] != '\0' && str[i] != ',' && str[i] != ' ' && str[i] != '\t')
    {
      i++;
    }
  if (str[i] != '\0')
    i++;
  return (i);
}

int	is_dir(char *str)
{
  int	i;

  i = 1;
  if (str[0] != '%')
    return (0);
  while (str[i] != '\0' && str[i] != ',' && str[i] != ' ' && str[i] != '\t')
    {
      if ((str[i] < '0' || str[i] > '9') && (str[i] != '-' && i == 0))
        return (0);
      i++;
    }
  if (str[i] != '\0')
    i++;
  return (i);
}

int	is_ind(char *str)
{
  int	i;
  int	st;

  i = 1;
  if ((st = is_number(str)) != 0)
    return (st);
  if (str[0] != ':' && str[0] != '%')
    return (0);
  if (str[0] != ':' && str[1] != ':')
    return (0);
  if (str[0] == '%')
    i++;
  while (str[i] != '\0' && str[i] != ',' && str[i] != ' ' && str[i] != '\t')
    {
      if ((str[i] < '0' || str[i] > '9') &&
	(str[i] != '_') && (str[i] < 'a' || str[i] > 'z'))
        return (0);
      i++;
    }
  if (str[i] != '\0')
    i++;
  return (i);
}
