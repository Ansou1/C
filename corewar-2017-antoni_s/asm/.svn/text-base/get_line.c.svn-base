/*
** get_line.c for corewar in /home/daguen_s//Prog_Elem/corewar-2017-antoni_s/asm
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar 16 13:39:00 2013 simon daguenet
** Last update Sat Mar 16 13:39:46 2013 simon daguenet
*/

#include "asm.h"

int	get_the_next_arg(char *arg)
{
  int	i;

  i = 0;
  while (arg[i] != ',' && arg[i]!= '\0')
    i++;
  return (i);
}

char	*get_lbl(char *line)
{
  char	*ret;
  int	i;

  i = 0;
  if (line[0] == '%')
    return (get_lbl(&line[1]));
  while (line[i] != ',' && line[i] != '\0')
    i++;
  ret = malloc(i + 1);
  check_malloc(ret);
  ret[i] = '\0';
  ret[i - 1] = ':';
  i = 0;
  while (ret[i] != ':')
    ret[i++] = '0';
  i = 0;
  while (ret[i] != ':' && ret[i] != '\0')
    {
      ret[i] = line[i + 1];
      i++;
    }
  return (ret);
}

int	get_the_lbl_line(char *ind, char ***file, char *bin)
{
  int	pos;
  int	a;

  a = 0;
  pos = 0;
  while (file[pos] != NULL && a == 0)
    {
      if (my_strncmp(ind, file[pos][0], my_strlen(ind)) == 1)
	{
	  a = 1;
	  pos--;
	}
      pos++;
    }
  if (file[pos] == NULL)
    {
      my_putstr("cannot find lbl :");
      my_putstr(ind);
      my_putchar('\n');
      exit(0);
    }
  return (pos);
}

int	offset_down2(int pos, int col, char **bin)
{
  int	x;
  int	y;
  int	ctr;

  ctr = 0;
  x = 4;
  y = col;
  while (pos < y)
    {
      while (bin[pos][x] != '\0')
	{
	  x++;
	  ctr++;
	}
      x = 0;
      pos++;
    }
  ctr = ctr + 2;
  ctr = ctr / 2;
  return (65535 - ctr);
}

long	offset_down4(int pos, int col, char **bin)
{
  int	x;
  int	y;
  int	ctr;
  long	ret;

  ctr = 0;
  x = 4;
  y = col;
  while (pos < y)
    {
      while (bin[pos][x] != '\0')
	{
	  x++;
	  ctr++;
	}
      x = 0;
      pos++;
    }
  ctr = ctr + 2;
  ctr = ctr / 2;
  ret = 4294967295 - ctr;
  return (ret);
}
