/*
** main.c for printf in /home/antoni_s//Cproject/Unix/Printf/bonux
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.net>
** 
** Started on  Fri Nov 16 17:05:12 2012 sebastien antonico
** Last update Thu Mar 21 09:24:10 2013 sebastien antonico
*/

#include <stdarg.h>
#include "my.h"

int	parsing(char *str, int *id, va_list list)
{
  char	*list_flags;
  char	flag;

  list_flags = "-+ 0#";
  *id = *id + 1;
  flag = 0;
  if (my_find(str[*id], list_flags) != -1)
    {
      flag = str[*id];
      *(id) = *(id) + 1;
    }
  return (my_putthing(str[*id], list, flag));
}
