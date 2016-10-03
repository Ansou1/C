/*
** fork.c for corewar in /home/daguen_s//result
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Jan 28 16:28:29 2013 simon daguenet
** Last update Sat Mar 16 17:19:54 2013 simon daguenet
*/

#include "asm.h"

char	**fork_fun(char **bin, t_list **list, int col, char ***file)
{
  int	ctr;
  int	i;
  int	arg;
  int	ctr_arg;

  arg = get_where_are_the_arg(file[col][0]);
  ctr = 2;
  i = 0;
  bin[col][0] = '0';
  bin[col][1] = 'c';
  if (is_ind(&file[col][arg][0]))
    bin[col] = my_copy_str_to(bin[col], get_ind_init2
			(list, &ctr, &ctr_arg, &file[col][arg][0]), ctr);
  else
    bin[col] = my_copy_str_to(bin[col], recup_nbr2(&file[col][arg][1]), ctr);
  bin[col][6] = '\0';
  return (bin);
}

char	**off_fork(char **bin, t_list **list, int col, char ***file)
{
  int	arg;
  int	ctr_arg;
  int	val;

  arg = get_where_are_the_arg(file[col][0]);
  ctr_arg = 0;
  if ((val = is_ind(&file[col][arg][ctr_arg])) != 0)
    {
      bin[col] = my_copy_str_to(bin[col], get_the_off2
			(&file[col][arg][ctr_arg], bin, file, col), 2);
      ctr_arg = ctr_arg + val;
    }
  return (bin);
}
