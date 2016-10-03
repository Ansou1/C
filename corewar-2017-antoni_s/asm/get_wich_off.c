/*
** get_wich_off.c for corewar in /home/daguen_s//Prog_Elem/corewar-2017-antoni_s/asm
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar 16 15:05:03 2013 simon daguenet
** Last update Fri Mar 29 23:43:01 2013 simon daguenet
*/

#include "asm.h"

char	**wich_inst2(char **bin, t_list **list, int col, char ***file)
{
  int	arg;

  arg = get_where_are_the_arg(file[col][0]) - 1;
  if (my_strncmp(op_tab[2].M, file[col][arg], my_strlen(op_tab[2].M)))
    return (st(bin, list, col, file));
  else if (my_strncmp(op_tab[11].M, file[col][arg], my_strlen(op_tab[1].M)))
    return (fork_fun(bin, list, col, file));
  else if (my_strncmp(op_tab[13].M, file[col][arg], my_strlen(op_tab[3].M)))
    return (lldi(bin, list, col, file));
  else if (my_strncmp(op_tab[12].M, file[col][arg], my_strlen(op_tab[2].M)))
    return (lld(bin, list, col, file));
  else if (my_strncmp(op_tab[14].M, file[col][arg], my_strlen(op_tab[4].M)))
    return (lfork(bin, list, col, file));
  else if (my_strncmp(op_tab[15].M, file[col][arg], my_strlen(op_tab[5].M)))
    return (aff(bin, list, col, file));
  else
    return (bin);
}

char	**wich_inst(char **bin, t_list **list, int col, char ***file)
{
  int	arg;

  arg = get_where_are_the_arg(file[col][0]) - 1;
  if (my_strncmp(op_tab[0].M, file[col][arg], my_strlen(op_tab[0].M)))
    return (live(bin, list, col, file));
  else if (my_strncmp(op_tab[9].M, file[col][arg], my_strlen(op_tab[9].M)))
    return (ldi(bin, list, col, file));
  else if (my_strncmp(op_tab[1].M, file[col][arg], my_strlen(op_tab[1].M)))
    return (ld(bin, list, col, file));
  else if (my_strncmp(op_tab[10].M, file[col][arg], my_strlen(op_tab[0].M)))
    return (sti(bin, list, col, file));
  else if (my_strncmp(op_tab[3].M, file[col][arg], my_strlen(op_tab[3].M)))
    return (add(bin, list, col, file));
  else if (my_strncmp(op_tab[4].M, file[col][arg], my_strlen(op_tab[4].M)))
    return (sub(bin, list, col, file));
  else if (my_strncmp(op_tab[5].M, file[col][arg], my_strlen(op_tab[5].M)))
    return (and(bin, list, col, file));
  else if (my_strncmp(op_tab[6].M, file[col][arg], my_strlen(op_tab[6].M)))
    return (or(bin, list, col, file));
  else if (my_strncmp(op_tab[7].M, file[col][arg], my_strlen(op_tab[7].M)))
    return (xor(bin, list, col, file));
  else if (my_strncmp(op_tab[8].M, file[col][arg], my_strlen(op_tab[8].M)))
    return (zjmp(bin, list, col, file));
  else
    return (wich_inst2(bin, list, col, file));
}

char	**wich_inst_off2(char **bin, t_list **list, int col, char ***file)
{
  int	arg;

  arg = get_where_are_the_arg(file[col][0]) - 1;
  if (my_strncmp(op_tab[1].M, file[col][arg], my_strlen(op_tab[1].M)))
    return (off_ld(bin, list, col, file));
  else if (my_strncmp(op_tab[10].M, file[col][arg], my_strlen(op_tab[0].M)))
    return (off_sti(bin, list, col, file));
  else if (my_strncmp(op_tab[11].M, file[col][arg], my_strlen(op_tab[1].M)))
    return (off_fork(bin, list, col, file));
  else if (my_strncmp(op_tab[13].M, file[col][arg], my_strlen(op_tab[3].M)))
    return (off_lldi(bin, list, col, file));
  else if (my_strncmp(op_tab[12].M, file[col][arg], my_strlen(op_tab[2].M)))
    return (off_lld(bin, list, col, file));
  else if (my_strncmp(op_tab[14].M, file[col][arg], my_strlen(op_tab[4].M)))
    return (off_lfork(bin, list, col, file));
  else
    return (bin);
}

char	**wich_inst_off(char **bin, t_list **list, int col, char ***file)
{
  int	arg;

  arg = get_where_are_the_arg(file[col][0]) - 1;
  if (my_strncmp(op_tab[0].M, file[col][arg], my_strlen(op_tab[0].M)))
    return (off_live(bin, list, col, file));
  else if (my_strncmp(op_tab[9].M, file[col][arg], my_strlen(op_tab[9].M)))
    return (off_ldi(bin, list, col, file));
  else if (my_strncmp(op_tab[5].M, file[col][arg], my_strlen(op_tab[5].M)))
    return (off_and(bin, list, col, file));
  else if (my_strncmp(op_tab[6].M, file[col][arg], my_strlen(op_tab[6].M)))
    return (off_or(bin, list, col, file));
  else if (my_strncmp(op_tab[7].M, file[col][arg], my_strlen(op_tab[7].M)))
    return (off_xor(bin, list, col, file));
  else if (my_strncmp(op_tab[8].M, file[col][arg], my_strlen(op_tab[8].M)))
    return (off_zjmp(bin, list, col, file));
  else
    return (wich_inst_off2(bin, list, col, file));
}
