/*
** print.c for sudoku in /home/daguen_s//rush/cpe-rush2-2017-corrad_f
**
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
**
** Started on  Sun Apr 21 10:52:07 2013 simon daguenet
** Last update Sun Apr 21 10:52:33 2013 simon daguenet
*/

#include "sudoku.h"

void	my_puttab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      printf("%s\n", tab[i]);
      i++;
    }
}

void	my_puterror(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    write(2, &str[i++], 1);
  write(2, "\n", 1);
  exit(0);
}
