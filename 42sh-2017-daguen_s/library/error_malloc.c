/*
** error_malloc.c for 42sh in /home/corrad_f//projet/42sh/library
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Fri Feb 22 18:03:37 2013 florian corradin
** Last update Fri Feb 22 19:46:53 2013 florian corradin
*/

#include "42.h"

void	check_malloc(void *ptr)
{
  if (ptr == NULL)
    {
      my_putstr("could not alloc\n");
      exit(0);
    }
}
