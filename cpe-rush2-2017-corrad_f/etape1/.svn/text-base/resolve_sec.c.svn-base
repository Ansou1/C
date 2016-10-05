/*
** resolve_sec.c for sudoku in /home/daguen_s//rush/cpe-rush2-2017-corrad_f
**
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
**
** Started on  Sun Apr 21 10:57:18 2013 simon daguenet
** Last update Sun Apr 21 23:30:08 2013 simon daguenet
*/

#include "sudoku.h"

void	aff(char **tab, char *base)
{
  int	x;
  int	i;
  char	c;

  x = 0;
  printf("|------------------|\n");
  while (tab[x])
    {
      i = 0;
      printf("|");
      while (tab[x][i])
	{
	  c = tab[x][i] - 1;
	  printf(" %c", base[(int)c]);
	  i++;
	}
      printf("|");
      printf("\n");
      x++;
    }
  printf("|------------------|\n");
}

char	digit(char *digit, char d)
{
  int	i;

  i = 0;
  if (d == ' ')
    return ('0');
  while (digit[i])
    {
      if (digit[i] == d)
	return (i + 1);
      i++;
    }
  return (i);
}

char	**my_tabdup(char **tab)
{
  int	x;
  char	**ret;

  x = 0;
  while (tab[x])
    x++;
  ret = xmalloc(sizeof (char *) * (x + 2));
  x = 0;
  while (tab[x])
    {
      ret[x] = strdup(tab[x]);
      x++;
    }
  ret[x] = NULL;
  return (ret);
}

char	get_the_first(int *x, int *y, char **tab)
{
  *x = 0;
  *y = 0;
  while (tab[*y])
    {
      *x = 0;
      while (tab[*y][*x])
	{
	  if (tab[*y][*x] == '0')
	    return (0);
	  *x = *x + 1;
	}
      *y = *y + 1;
    }
  return (0);
}

char	is_intouchable(char **sudo, int x, int y)
{
  if (sudo[y][x] == '0')
    return (0);
  else
    return (1);
}

