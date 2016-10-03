/*
** sti.c for sti in /home/efilon/Projects/Cproject/Corewar
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Sat Mar 30 13:10:46 2013 sebastien antonico
** Last update Sun Mar 31 17:00:49 2013 sebastien antonico
*/

#include <unistd.h>
#include <stdlib.h>
#include "op.h"
#include "corewar.h"
#include "libmy/my.h"

int	read_first_oct_sti(t_cw *cw, t_proc *p)
{
  int	v2;

  if (C_OCT2 == 1)
    {
      p->tmp_num_reg = tab_to_int(READ_ON_VM(3), 1) - 1;
      if (!is_valid_nb(p->tmp_num_reg, 1, REG_NUMBER - 1))
	p->tmp_num_reg = 0;
      v2 = tab_to_int(p->regs[p->tmp_num_reg], REG_SIZE);
    }
  else if (C_OCT2 == 2)
    v2 = tab_to_int(cw->vm + ((p->pc - cw->vm + 3) % MEM_SIZE), IND_SIZE);
  else if (C_OCT2 == 3)
    {
      v2 = tab_to_int(cw->vm + ((p->pc - cw->vm + 3) % MEM_SIZE), IND_SIZE);
      v2 = tab_to_int(cw->vm + ((p->pc - cw->vm + (v2 % IDX_MOD)) %
				MEM_SIZE), IND_SIZE);
    }
  return (v2);
}

void	read_sti(t_cw *cw, t_proc *p)
{
  int	jumping;
  int	v2;
  int	v3;

  p->tmp_num_reg = tab_to_int(READ_ON_VM(2), 1) - 1;
  if (!is_valid_nb(p->tmp_num_reg, 1, REG_NUMBER - 1))
    p->tmp_num_reg = 0;
  p->tmp_val = tab_to_int(p->regs[p->tmp_num_reg], REG_SIZE);
  v2 = read_first_oct_sti(cw, p);
  jumping = ((C_OCT2 == 1) ? 1 : IND_SIZE) + 3;
  if (C_OCT3 == 1)
    {
      p->tmp_num_reg = tab_to_int(READ_ON_VM(jumping), 1) - 1;
      if (!is_valid_nb(p->tmp_num_reg, 1, REG_NUMBER - 1))
	p->tmp_num_reg = 0;
      v3 = tab_to_int(p->regs[p->tmp_num_reg], REG_SIZE);
    }
  else if (C_OCT3 == 2)
    v3 = tab_to_int(cw->vm + ((p->pc - cw->vm + jumping) % MEM_SIZE), IND_SIZE);
  p->tmp_pc = cw->vm + (tab_to_int(cw->vm +
				   ((p->pc - cw->vm + (v2 + v3) % IDX_MOD) %
				    MEM_SIZE), IND_SIZE));
}

void	exec_sti(t_cw *cw, t_proc *p)
{
  cw = cw;
  write_int(p->tmp_pc, REG_SIZE, tab_to_int(p->regs[p->tmp_num_reg], REG_SIZE));
  p->carry = 0;
}
