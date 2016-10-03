/*
** add.c for add in /home/efilon/Projects/Cproject/Corewar
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Sat Mar 30 13:08:43 2013 sebastien antonico
** Last update Sun Mar 31 00:24:17 2013 sebastien antonico
*/

#include <unistd.h>
#include <stdlib.h>
#include "op.h"
#include "corewar.h"
#include "libmy/my.h"

void	read_add(t_cw *cw, t_proc *p)
{
  if (is_valid_nb(tab_to_int(READ_ON_VM(2), 1), 1, REG_NUMBER) - 1 &&
      is_valid_nb(tab_to_int(READ_ON_VM(3), 1), 1, REG_NUMBER) - 1 &&
      is_valid_nb(tab_to_int(READ_ON_VM(4), 1), 1, REG_NUMBER) - 1)
    {
      p->tmp_num_reg = tab_to_int(READ_ON_VM(4), 1) - 1;
      p->tmp_val = tab_to_int(p->regs[tab_to_int(READ_ON_VM(2), 1) - 1],
			      REG_SIZE) +
	tab_to_int(p->regs[tab_to_int(READ_ON_VM(3), 1) - 1], REG_SIZE);
    }
}

void	exec_add(t_cw *cw, t_proc *p)
{
  cw = cw;
  if (!is_valid_nb(p->tmp_num_reg, 1, REG_NUMBER - 1))
    p->tmp_num_reg = 0;
  write_int(p->regs[p->tmp_num_reg], REG_SIZE, p->tmp_val);
  if (p->tmp_val == 0)
    p->carry = 1;
  else
    p->carry = 0;
}
