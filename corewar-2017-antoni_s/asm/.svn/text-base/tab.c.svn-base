/*
** tab.c for corewar in /home/daguen_s//Prog_Elem/corewar-2017-antoni_s/asm
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar 16 13:41:32 2013 simon daguenet
** Last update Sat Mar 16 13:42:15 2013 simon daguenet
*/

#include "asm.h"

int	my_len_bigtab(char ***tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

void	my_free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
}

void	my_free_bigtab(char ***tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_free_tab(tab[i]);
      i++;
    }
}
