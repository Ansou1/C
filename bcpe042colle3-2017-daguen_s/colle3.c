/*
** colle3.c for colle3 in /home/daguen_s//Downloads
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Oct 27 08:54:40 2012 simon daguenet
** Last update Sun Oct 28 09:09:54 2012 simon daguenet
*/

#include <unistd.h>
#include "my.h"

void	display_res(int colle, int colonne, int ligne)
{
  if (colle == 0)
    {
      my_putstr("aucune");
    }
  if (colle == 6)
    {
      display_res(3, colonne, ligne);
      my_putstr(" || ");
      display_res(4, colonne, ligne);
      my_putstr(" || ");
      display_res(5, colonne, ligne);
    }
  if (colle > 0 && colle < 6)
    {
      my_putstr("[colle-1-");
      my_put_nbr(colle);
      my_putstr("] [");
      my_put_nbr(colonne);
      my_putstr("] [");
      my_put_nbr(ligne);
      my_putchar(']');
    }
}

void	what_is_this_glue(char *buff, int len)
{
  int	size_l;

  size_l = 0;
  while (buff[size_l] != '\n')
    {
      size_l = size_l + 1;
    }
  display_res(get_colle_id(buff, len, size_l), get_col(buff), get_line(buff));
}

int	main(int ac, char* av[])
{
  char	buff[4096 + 1];
  int	len;

  usleep(1000000);
  if ((len = read(0, buff, 4096)) > 0)
    {
      buff[len] = 0;
      what_is_this_glue(buff, len);
      my_putchar('\n');
    }
  return (0);
}
