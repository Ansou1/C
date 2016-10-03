/*
** my_putstr.c for my_putstr in /home/daguen_s//afs/rendu/piscine/Jour_04
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Thu Oct  4 11:47:19 2012 simon daguenet
** Last update Tue Nov 27 13:40:40 2012 simon daguenet
*/
#include "my_ls.h"

void	my_putstr(char	*str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}
