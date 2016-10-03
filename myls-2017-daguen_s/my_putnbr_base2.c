/*
** my_putnbr_base2.c for printf in /home/daguen_s/
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Fri Nov  9 10:06:11 2012 simon daguenet
** Last update Fri Nov 30 21:19:26 2012 simon daguenet
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdarg.h>
#include "my_ls.h"

long     my_putnbr_base2(long nb, char *base)
{
  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
    }
  if (nb >= my_strlen(base))
    {
      my_putnbr_base2(nb / my_strlen(base), base);
    }
  my_putchar(base[nb % my_strlen(base)]);
}
