/*
** get_info.c for get_info in /home/daguen_s//colle3/colle
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Oct 27 23:20:13 2012 simon daguenet
** Last update Sat Oct 27 23:36:59 2012 simon daguenet
*/

#include "my.h"

int	get_colle_id(char *buff, int len, int nb_l)
{
  if (buff[0] == 'o')
    {
      return (1);
    }
  if (buff[0] == '/' || buff[0] == '*')
    {
      return (2);
    }
  if (buff[0] == 'A' && buff[len / nb_l - 2] == 'A')
    {
      return (3);
    }
  if (buff[0] == 'A' && buff[len - 2] == 'C' && buff[len / nb_l - 2] != 'A')
    {
      return (4);
    }
  if (buff[0] == 'A' && buff[len - 2] == 'A')
    {
      return (5);
    }
  if (buff[0] == 'B')
    {
      return (6);
    }
  return (0);
}

int	get_line(char *buff)
{
  int   i;
  int   nb_l;

  i = 0;
  nb_l = 0;
  while (buff[i])
    {
      if (buff[i] == '\n')
        {
          nb_l = nb_l + 1;
	}
      i = i + 1;
    }
  return (nb_l);
}

int	get_col(char *buff)
{
  int   i;

  i = 0;
  while (buff[i] != '\n')
    {
      i = i + 1;
    }
  return (i);
}
