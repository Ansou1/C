/*
** st.c for st in /home/efilon/Projects/Cproject/Corewar
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Sat Mar 30 13:08:00 2013 sebastien antonico
** Last update Sun Mar 31 00:48:52 2013 sebastien antonico
*/

#include <unistd.h>
#include <stdlib.h>
#include "op.h"
#include "corewar.h"
#include "libmy/my.h"

void	read_st(t_cw *cw, t_proc *p)
{
  p->tmp_num_reg = tab_to_int(READ_ON_VM(2), 1) - 1;
  if (!is_valid_nb(p->tmp_num_reg, 1, REG_NUMBER - 1))
    p->tmp_num_reg = 0;
  p->tmp_val = tab_to_int(p->regs[p->tmp_num_reg], REG_SIZE);
  if (C_OCT2 == 1)
    {
      p->tmp_num_reg = tab_to_int(cw->vm + ((p->pc - cw->vm + 3) %
					    MEM_SIZE), 1) - 1;
      if (!is_valid_nb(p->tmp_num_reg, 1, REG_NUMBER - 1))
	p->tmp_num_reg = 0;
    }
  else if (C_OCT2 == 3)
    {
      p->tmp_pc = cw->vm + ((p->pc - cw->vm +
			     (tab_to_int(READ_ON_VM(3), IND_SIZE) % IDX_MOD)) %
			    MEM_SIZE);
    }
}

void	exec_st(t_cw *cw, t_proc *p)
{
  cw = cw;
  if (C_OCT2 == 1)
    {
      write_int(p->regs[p->tmp_val], REG_SIZE,
		tab_to_int(p->regs[p->tmp_num_reg], REG_SIZE));
    }
  else if (C_OCT2 == 3)
    {
      write_int(p->tmp_pc, REG_SIZE, p->tmp_val);
    }
  p->carry = 0;
}
