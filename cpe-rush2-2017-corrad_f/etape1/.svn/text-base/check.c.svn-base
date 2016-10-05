/*
** check.c for sudoku in /home/daguen_s//rush/cpe-rush2-2017-corrad_f
**
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
**
** Started on  Sun Apr 21 10:53:14 2013 simon daguenet
** Last update Sun Apr 21 12:01:57 2013 simon daguenet
*/

#include "sudoku.h"

char	**realloc_tab(char **tab, char *str)
{
  int	i;
  char	**ret;

  i = 0;
  if (tab != NULL)
    while (tab[i])
      i++;
  ret = xmalloc(sizeof (char *) * (i + 2));
  i = 0;
  if (tab == NULL)
    {
      ret[0] = str;
      ret[1] = NULL;
      return (ret);
    }
  while (tab[i])
    {
      ret[i] = tab[i];
      i++;
    }
  ret[i] = str;
  ret[i + 1] = NULL;
  free(tab);
  return (ret);
}

int	check_base(char s, char *base)
{
  int	i;

  i = 0;
  while (base[i])
    {
      if (base[i] == s)
	return (1);
      i++;
    }
  if (s != ' ')
    {
      write(2, &s, 1);
      my_puterror(" :is not defined in the base");
    }
  return (0);
}

int	check_map(char **su, char *base)
{
  int	i;
  int	len;
  int	ctr;

  len = strlen(base);
  i = 0;
  while (su[i])
    {
      ctr = 0;
      if (su[i++][0] != '|')
	my_puterror("Map error1");
      if (su[i] == NULL)
	my_puterror("Map error2");
      while (su[i][0] != '|')
	{
	  ctr++;
	  i++;
	  if (su[i] == NULL)
	    my_puterror("Map error3");
	}
      if (ctr != len)
	my_puterror("Map error4");
      i++;
    }
  return (0);
}
