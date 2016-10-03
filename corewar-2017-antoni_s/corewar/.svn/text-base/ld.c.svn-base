/*
** ld.c for ld in /home/efilon/Projects/Cproject/Corewar
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Sat Mar 30 13:06:09 2013 sebastien antonico
** Last update Sun Mar 31 00:48:43 2013 sebastien antonico
*/

#include <unistd.h>
#include <stdlib.h>
#include "op.h"
#include "corewar.h"
#include "libmy/my.h"

void	read_ld(t_cw *cw, t_proc *p)
{
  if (C_OCT1 == 2)
    p->tmp_num_reg = tab_to_int(READ_ON_VM(2 + DIR_SIZE), 1) - 1;
  else if (C_OCT1 == 3)
    p->tmp_num_reg = tab_to_int(READ_ON_VM(2 + IND_SIZE), 1) - 1;
  if (C_OCT1 == 2 && is_valid_nb(p->tmp_num_reg, 1, REG_NUMBER - 1))
    p->tmp_val = tab_to_int(READ_ON_VM(2), DIR_SIZE);
  if (C_OCT1 == 3 && is_valid_nb(p->tmp_num_reg, 1, REG_NUMBER - 1))
    p->tmp_val = tab_to_int(cw->vm +((p->pc - cw->vm +
				      (tab_to_int(READ_ON_VM(2), IND_SIZE) %
				       IDX_MOD)) % MEM_SIZE), IND_SIZE);
}

void	exec_ld(t_cw *cw, t_proc *p)
{
  cw = cw;
  write_int(p->regs[p->tmp_num_reg], REG_SIZE, p->tmp_val);
  p->carry = 0;
}
