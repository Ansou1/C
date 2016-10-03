/*
** aff.c for correwar in /home/daguen_s//result
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Jan 28 17:28:09 2013 simon daguenet
** Last update Sat Mar 16 16:59:42 2013 simon daguenet
*/

#include "asm.h"

char	**aff(char **bin, t_list **list, int col, char ***file)
{
  int	i;
  int	arg;

  arg = get_where_are_the_arg(file[col][0]);
  bin[col][0] = '1';
  bin[col][1] = '0';
  bin[col] = my_copy_str_to(bin[col], get_octet_codage(file[col][arg]), 2);
  bin[col] = my_copy_str_to(bin[col], get_reg(file[col][arg]), 4);
  bin[col][6] = '\0';
  return (bin);
}
