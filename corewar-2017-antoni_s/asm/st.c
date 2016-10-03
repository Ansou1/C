/*
** st.c for corewar in /home/daguen_s//result
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Jan 28 10:12:48 2013 simon daguenet
** Last update Sat Mar 30 16:44:02 2013 simon daguenet
*/

#include "asm.h"

char	**st(char **bin, t_list **list, int col, char ***file)
{
  int	ctr;
  int	ctr_arg;
  int	i;
  int	arg;

  ctr_arg = 0;
  arg = get_where_are_the_arg(file[col][0]);
  ctr = 6;
  bin[col][0] = '0';
  bin[col][1] = '3';
  bin[col] = my_copy_str_to(bin[col], get_octet_codage(file[col][arg]), 2);
  bin[col] = my_copy_str_to(bin[col], get_reg(file[col][arg]), 4);
  ctr_arg = is_reg(file[col][arg]);
  if (is_ind(&file[col][arg][ctr_arg]) != 0)
    bin[col] = my_copy_str_to(bin[col], get_ind_init2
			(list, &ctr, &ctr_arg, &file[col][arg][ctr_arg]), 6);
  else
    bin[col] = my_copy_str_to(bin[col], get_arg_3_2
			(&file[col][arg][ctr_arg], &ctr, &ctr_arg), 6);
  bin[col][ctr] = '\0';
  return (bin);
}
