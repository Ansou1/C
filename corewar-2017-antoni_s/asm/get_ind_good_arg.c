/*
** get_ind_good_arg.c for corewar in /home/daguen_s//Prog_Elem/corewar-2017-antoni_s/asm
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar 16 13:45:35 2013 simon daguenet
** Last update Sat Mar 16 15:30:50 2013 simon daguenet
*/

#include "asm.h"

char	*get_ind_init2(t_list **list, int *ctr, int *ctr_arg, char *line)
{
  int	i;

  i = is_ind(line);
  *ctr_arg = *ctr_arg + i;
  *ctr = *ctr + 4;
  if (is_number(line) != 0)
    {
      return (recup_nbr2(line));
    }
  if ((*list)->x1 == 0)
    (*list)->x1 = -1;
  return ("0000");
}

char	*get_ind_init4(t_list **list, int *ctr, int *ctr_arg, char *line)
{
  int	i;

  i = is_ind(line);
  *ctr_arg = *ctr_arg + i;
  *ctr = *ctr + 8;
  if (is_number(line) != 0)
    {
      return (recup_nbr4(line));
    }
  if ((*list)->x1 == 0)
    (*list)->x1 = -1;
  return ("00000000");
}

char	*get_arg_3_2(char *arg, int *ctr, int *ctr_arg)
{
  int	val;

  if ((val = is_reg(arg)) != 0)
    {
      *ctr = *ctr + 2;
      *ctr_arg = *ctr_arg + val;
      return (get_reg(arg));
    }
  else if ((val = is_dir(arg)) != 0)
    {
      *ctr = *ctr + 4;
      *ctr_arg = *ctr_arg + val;
      return (recup_nbr2(&arg[1]));
    }
}

char	*get_arg_3_4(char *arg, int *ctr, int *ctr_arg)
{
  int	val;

  if ((val = is_reg(arg)) != 0)
    {
      *ctr = *ctr + 2;
      *ctr_arg = *ctr_arg + val;
      return (get_reg(arg));
    }
  else if ((val = is_dir(arg)) != 0)
    {
      *ctr = *ctr + 8;
      *ctr_arg = *ctr_arg + val;
      return (recup_nbr4(&arg[1]));
    }
}
