/*
** my_putstr_temps.c for my_putstrtemps in /home/daguen_s//ls/my_ls
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Wed Nov 28 19:05:49 2012 simon daguenet
** Last update Fri Nov 30 13:49:42 2012 simon daguenet
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
#include "my_ls.h"

char	*my_putstr_temps(char *str, struct stat sb)
{
  char	*new_str;
  int	cnt;
  int	n;

  str = ctime(&sb.st_mtime);
  if (str == NULL)
    exit (EXIT_FAILURE);
  new_str = malloc(20);
  cnt = 0;
  n = 4;
  while (str[n] && n < 16)
    {
      new_str[cnt++] = str[n++];
    }
  new_str[cnt] = '\0';
  return (new_str);
}
