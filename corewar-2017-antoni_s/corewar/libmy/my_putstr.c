/*
** my_putstr.c for my_printf in /home/antoni_s//Cproject/Unix/Printf/commit
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.net>
** 
** Started on  Thu Nov 15 21:48:11 2012 sebastien antonico
** Last update Thu Mar 21 09:24:01 2013 sebastien antonico
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	my_putstr(char *str)
{
  if (str == NULL)
    return (my_putstr("(null)"));
  return (write(1, str, my_strlen(str)));
}
