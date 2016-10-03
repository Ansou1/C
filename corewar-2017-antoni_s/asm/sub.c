/*
** sub.c for corewar in /home/daguen_s//result
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Jan 28 13:00:31 2013 simon daguenet
** Last update Mon Jan 28 13:06:17 2013 simon daguenet
*/

#include "asm.h"

char	**sub(char **bin, t_list **list, int col, char ***file)
{
  int	ctr;
  int	ctr_arg;
  int	i;
  int	arg;

  ctr_arg = 0;
  arg = get_where_are_the_arg(file[col][0]);
  ctr = 6;
  bin[col][0] = '0';
  bin[col][1] = '5';
  bin[col] = my_copy_str_to(bin[col], get_octet_codage(file[col][arg]), 2);
  bin[col] = my_copy_str_to(bin[col], get_reg(file[col][arg]), 4);
  ctr_arg += is_reg(file[col][arg]);
  bin[col] = my_copy_str_to(bin[col], get_reg(&file[col][arg][ctr_arg]), 6);
  ctr_arg += is_reg(&file[col][arg][ctr_arg]);
  bin[col] = my_copy_str_to(bin[col], get_reg(&file[col][arg][ctr_arg]), 8);
  ctr_arg += is_reg(&file[col][arg][ctr_arg]);
  bin[col][10] = '\0';
  return (bin);
}
