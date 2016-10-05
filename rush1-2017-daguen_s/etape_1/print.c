/*
** print.c for print in /home/daguen_s//rush/ex_1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Dec  2 16:45:03 2012 simon daguenet
** Last update Sun Dec  2 16:56:37 2012 simon daguenet
*/
#include "get_next_line.h"

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
