/*
** live.c for corewar in /home/corrad_f//projet/champion/commande
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Wed Jan 23 18:46:00 2013 florian corradin
** Last update Sat Mar 16 16:30:32 2013 simon daguenet
*/

#include "asm.h"

char	**live(char **bin, t_list **list, int col, char ***file)
{
  int	ctr;
  int	i;
  int	arg;
  int	ctr_arg;

  arg = get_where_are_the_arg(file[col][0]);
  ctr = 2;
  i = 0;
  bin[col][0] = '0';
  bin[col][1] = '1';
  if (is_ind(&file[col][arg][0]))
    bin[col] = my_copy_str_to(bin[col], get_ind_init4
			(list, &ctr, &ctr_arg, &file[col][arg][0]), ctr);
  else
    bin[col] = my_copy_str_to(bin[col], recup_nbr4(&file[col][arg][1]), ctr);
  bin[col][10] = '\0';
  return (bin);
}

char	**off_live(char **bin, t_list **list, int col, char ***file)
{
  int	arg;
  int	ctr_arg;
  int	val;

  arg = get_where_are_the_arg(file[col][0]);
  ctr_arg = 0;
  if ((val = is_ind(&file[col][arg][ctr_arg])) != 0)
    {
      bin[col] = my_copy_str_to(bin[col], get_the_off4
			  (&file[col][arg][ctr_arg], bin, file, col), 2);
      ctr_arg = ctr_arg + val;
    }
  return (bin);
}
