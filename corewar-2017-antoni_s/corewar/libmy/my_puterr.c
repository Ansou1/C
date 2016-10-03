/*
** my_puterr.c for my_puterr in /home/efilon/corewar-2017-antoni_s/corewar/libmy
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Wed Mar 13 13:58:37 2013 sebastien antonico
** Last update Tue Mar 19 10:08:23 2013 sebastien antonico
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void	my_puterr(char *err)
{
  write(2, err, my_strlen(err));
  exit(0);
}
