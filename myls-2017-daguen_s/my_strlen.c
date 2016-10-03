/*
** my_strlen.c for my_strlen in /home/daguen_s//save_lib
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Wed Oct 10 09:32:56 2012 simon daguenet
** Last update Tue Nov 27 13:41:18 2012 simon daguenet
*/
#include "my_ls.h"

int	my_strlen(char * str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
      i++;
  return (i);
}
