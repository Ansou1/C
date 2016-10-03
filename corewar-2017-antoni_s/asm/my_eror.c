/*
** my_eror.c for corware in /home/corrad_f//projet/champion/commande/lib
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Wed Jan 23 16:18:10 2013 florian corradin
** Last update Sat Mar 16 18:37:48 2013 simon daguenet
*/

#include "asm.h"

void	check_malloc(void *ptr)
{
  if (ptr == NULL)
    {
      my_putstr("Can't perform malloc\n");
      exit(0);
    }
}
