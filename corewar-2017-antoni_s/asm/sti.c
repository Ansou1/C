/*
** sti.c for corewar in /home/corrad_f//projet/champion/commande
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Wed Jan 23 11:25:55 2013 florian corradin
** Last update Thu Mar 21 13:48:06 2013 florian corradin
*/

#include "asm.h"

/* col = ligne du bin */
char	**sti(char **bin, t_list **list, int col, char ***file)
{
  int	ctr;
  int	ctr_arg;
  int	i;
  int	arg;

  ctr_arg = 0;
  arg = get_where_are_the_arg(file[col][0]);
  ctr = 6;
  bin[col][0] = '0';
  bin[col][1] = 'b';
  bin[col] = my_copy_str_to(bin[col], get_octet_codage(file[col][arg]), 2);
  bin[col] = my_copy_str_to(bin[col], get_reg(file[col][arg]), 4);
  ctr_arg = is_reg(file[col][arg]);
  if (is_ind(&file[col][arg][ctr_arg]) != 0)
    bin[col] = my_copy_str_to(bin[col], get_ind_init2
			(list, &ctr, &ctr_arg, &file[col][arg][ctr_arg]), 6);
  else
    bin[col] = my_copy_str_to(bin[col], get_arg_3_2
			(&file[col][arg][ctr_arg], &ctr, &ctr_arg), 6);
  bin[col] = my_copy_str_to(bin[col], get_arg_3_2
			(&file[col][arg][ctr_arg], &ctr, &ctr_arg), ctr);
  bin[col][ctr] = '\0';
  return (bin);
}

char	**ld(char **bin, t_list **list, int col, char ***file)
{
  int	ctr;
  int	ctr_arg;
  int	i;
  int	arg;

  ctr_arg = 0;
  arg = get_where_are_the_arg(file[col][0]);
  ctr = 4;
  bin[col][0] = '0';
  bin[col][1] = '2';
  bin[col] = my_copy_str_to(bin[col], get_octet_codage(file[col][arg]), 2);
  if (is_ind(&file[col][arg][ctr_arg]) != 0)
    bin[col] = my_copy_str_to(bin[col], get_ind_init4
			(list, &ctr, &ctr_arg, &file[col][arg][ctr_arg]), 4);
  else
    bin[col] = my_copy_str_to(bin[col], get_arg_3_4
			(&file[col][arg][ctr_arg], &ctr, &ctr_arg), 4);
  bin[col] = my_copy_str_to(bin[col], get_reg(&file[col][arg][ctr_arg]), ctr);
  bin[col][ctr + 2] = '\0';
  return (bin);
}

char	**off_ld(char **bin, t_list **list, int col, char ***file)
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

char	**off_sti(char **bin, t_list **list, int col, char ***file)
{
  int	arg;
  int	ctr_arg;
  int	val;

  arg = get_where_are_the_arg(file[col][0]);
  ctr_arg = 0;
  ctr_arg = is_reg(file[col][arg]);
  if ((val = is_ind(&file[col][arg][ctr_arg])) != 0)
    {
      bin[col] = my_copy_str_to(bin[col], get_the_off2
			  (&file[col][arg][ctr_arg], bin, file, col), 6);
      ctr_arg = ctr_arg + val;
    }
  else
    ctr_arg = ctr_arg + get_the_next_arg(&file[col][arg][ctr_arg]);
  if ((val = is_ind(&file[col][arg][ctr_arg])) != 0)
    bin[col] = my_copy_str_to(bin[col], get_the_off2
			(&file[col][arg][ctr_arg], bin, file, col), 10);
  return (bin);
}

