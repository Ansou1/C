/*
** print_error.c for my_select in /home/daguen_s//charlotte/rendu
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Jan 19 22:40:29 2013 simon daguenet
** Last update Sat Jan 19 23:32:04 2013 simon daguenet
*/

#include "my_select.h"

void	my_put_error(int i)
{
  if (i == 1)
    {
      my_putstr("problem with tgetent\n");
      exit (EXIT_FAILURE);
    }
  else if (i == 2)
    {
      my_putstr("problem with tcgetattr\n");
      exit (EXIT_FAILURE);
    }
  else if (i == 3)
    {
      my_putstr("problem with tcsetattr\n");
      exit (EXIT_FAILURE);
    }
  else if (i == 4)
    {
      my_putstr("problem with malloc\n");
      exit (EXIT_FAILURE);
    }
  else if (i == 5)
    {
      my_putstr("problem with term\n");
      exit (EXIT_FAILURE);
    }
}

void	my_put_error_2(int i)
{
  if (i == 1)
    {
      my_putstr("problem with tgetstr\n");
      exit (EXIT_FAILURE);
    }
  else if (i == 2)
    {
      my_putstr("problem with tgoto\n");
      exit (EXIT_FAILURE);
    }
}
