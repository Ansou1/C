/*
** get_str.c for  in /home/corrad_f//projet/champion/commande
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sun Jan 27 16:04:03 2013 florian corradin
** Last update Fri Mar 29 14:20:07 2013 simon daguenet
*/

#include "asm.h"

int	is_number(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] != ',')
    {
      if ((str[i] < '0' || str[i] > '9') && str[0] != '-')
	return (0);
      i++;
    }
  return (i + 1);
}

int	get_where_are_the_arg(char *line)
{
  if (check_mnemo(line) == 1)
    return (1);
  else
    return (2);
}

/* renvoie la valeur hexa du registre */
char	*get_reg(char *arg)
{
  int	i;
  char	*nbr;
  char	*ret;

  nbr = malloc(3);
  check_malloc(nbr);
  nbr[2] = '\0';
  nbr[0] = arg[1];
  if (arg[2] <= '6' && arg[2] >= '0')
    nbr[1] = arg[2];
  else
    nbr[1] = '\0';
  ret = convert_base(nbr, "0123456789", "0123456789abcdef");
  if (my_strlen(ret) == 1)
    {
      nbr[0] = '0';
      nbr[1] = ret[0];
      free(ret);
      return (nbr);
    }
  free(nbr);
  return (ret);
}
