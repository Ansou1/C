/*
** my_fonction3.c for mysh in /home/daguen_s//my_minishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Dec 23 12:21:33 2012 simon daguenet
** Last update Sun Dec 23 12:43:57 2012 simon daguenet
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <unistd.h>
#include <dirent.h>
#include <signal.h>
#include "mysh.h"

char	*my_strdup_user(char *src)
{
  int	i;
  int	j;
  char	*chaine;

  i = 0;
  i = my_strlen(src) - 4;
  chaine = malloc(i + 1);
  if (chaine == NULL)
    return (NULL);
  j = 5;
  i = 0;
  while (src[j] != '\0')
    {
      chaine[i] = src[j];
      j = j + 1;
      i = i + 1;
    }
  chaine[i] = '\0';
  return (chaine);
}

char	*my_strdup_old(char *src)
{
  int	i;
  int	j;
  char	*chaine;

  i = 0;
  i = my_strlen(src) - 7;
  chaine = malloc(i + 1);
  if (chaine == NULL)
    return (NULL);
  j = 7;
  i = 0;
  while (src[j] != '\0')
    {
      chaine[i] = src[j];
      j = j + 1;
      i = i + 1;
    }
  chaine[i] = '\0';
  return (chaine);
}

int	my_d_strlen(char **str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_print_char(va_list ap, char format)
{
  if (format == 'c')
    my_putchar(va_arg(ap, int));
  else if (format == 's')
    my_putstr(va_arg(ap, char *));
  else if (format == 'd')
    my_putnbr_base2(va_arg(ap, int), "0123456789");
}

void	my_printf(char *format, ...)
{
  va_list	ap;
  int	i;

  va_start(ap, format);
  i = 0;
  while (format[i] != '\0')
    {
      if (format[i] == '%')
        {
          i++;
          if (format[i] == 'c' || format[i] == 's' || format[i] == 'd')
            my_print_char(ap, format[i]);
        }
      else
        my_putchar(format[i]);
      i++;
    }
  va_end(ap);
}
