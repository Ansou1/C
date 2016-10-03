/*
** my_putchar.c for my_putchar in /home/daguen_s//ls/my_ls
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Tue Nov 27 13:37:06 2012 simon daguenet
** Last update Tue Nov 27 13:41:05 2012 simon daguenet
*/

#include "my_ls.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
