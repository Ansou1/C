/*
** and.c for corewar in /home/corrad_f//projet/champion/commande
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Mon Jan 28 14:40:45 2013 florian corradin
** Last update Sat Mar 16 17:03:40 2013 simon daguenet
*/

#include "asm.h"

char	**and(char **bin, t_list **list, int col, char ***file)
{
  int	ctr;
  int	ctr_arg;
  int	i;
  int	arg;

  ctr_arg = 0;
  arg = get_where_are_the_arg(file[col][0]);
  ctr = 4;
  bin[col][0] = '0';
  bin[col][1] = '6';
  bin[col] = my_copy_str_to(bin[col], get_octet_codage(file[col][arg]), 2);
  if (is_ind(&file[col][arg][ctr_arg]) != 0)
    bin[col] = my_copy_str_to(bin[col],
			get_ind_init4(list, &ctr, &ctr_arg, ARG), ctr);
  else
    bin[col] = my_copy_str_to(bin[col], get_arg_3_4(ARG, &ctr, &ctr_arg), ctr);
  if (is_ind(&file[col][arg][ctr_arg]) != 0)
    bin[col] = my_copy_str_to(bin[col],
			get_ind_init4(list, &ctr, &ctr_arg, ARG), ctr);
  else
    bin[col] = my_copy_str_to(bin[col], get_arg_3_4(ARG, &ctr, &ctr_arg), ctr);
  bin[col] = my_copy_str_to(bin[col], get_arg_3_4(ARG, &ctr, &ctr_arg), ctr);
  bin[col][ctr] = '\0';
  return (bin);
}

char	**off_and(char **bin, t_list **list, int col, char ***file)
{
  int	arg;
  int	ctr_arg;
  int	val;

  arg = get_where_are_the_arg(file[col][0]);
  ctr_arg = 0;
  if ((val = is_ind(&file[col][arg][ctr_arg])) != 0)
    {
      bin[col] = my_copy_str_to(bin[col], get_the_off4
			(&file[col][arg][ctr_arg], bin, file, col), 4);
      ctr_arg = ctr_arg + val;
    }
  else
    ctr_arg = ctr_arg + get_the_next_arg(&file[col][arg][ctr_arg]) + 1;
  if ((val = is_ind(&file[col][arg][ctr_arg])) != 0)
    bin[col] = my_copy_str_to(bin[col], get_the_off4
			(&file[col][arg][ctr_arg], bin, file, col), 12);
  return (bin);
}
