/*
** fonction_print.c for allum1 in /home/daguen_s//myalum1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Feb 10 18:47:31 2013 simon daguenet
** Last update Tue Feb 12 22:29:47 2013 simon daguenet
*/

#include "allum1.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

void	my_put_error(int i)
{
  if (i == 1)
    {
      my_putstr("\033[31mError with malloc\033[37m\n");
      exit (EXIT_FAILURE);
    }
  else if (i == 2)
    {
      my_putstr("\033[31mNo env, so bad...!!!\033[37m\n");
      exit (EXIT_FAILURE);
    }
  else if (i == 3)
    {
      my_putstr("\033[31mUsage: ./allum1\033[37m\n");
      exit (EXIT_FAILURE);
    }
  else if (i == 4)
    {
      my_putstr("\033[31mError with read\033[37m\n");
      exit (EXIT_FAILURE);
    }
}

void	my_put_error_term(int i)
{
  if (i == 1)
    {
      my_putstr("\033[31mError with tgetent\033[37m\n");
      exit (EXIT_FAILURE);
    }
  else if (i == 2)
    {
      my_putstr("\033[31mError with tegetstr\033[37m\n");
      exit (EXIT_FAILURE);
    }
  else if (i == 3)
    {
      my_putstr("\033[31mNo term\033[37m\n");
      exit (EXIT_FAILURE);
    }
}
