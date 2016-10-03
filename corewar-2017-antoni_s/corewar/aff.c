/*
** aff.c for aff in /home/efilon/Projects/Cproject/Corewar
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Sat Mar 30 13:11:58 2013 sebastien antonico
** Last update Sun Mar 31 00:24:52 2013 sebastien antonico
*/

#include <unistd.h>
#include <stdlib.h>
#include "op.h"
#include "corewar.h"
#include "libmy/my.h"

void	read_aff(t_cw *cw, t_proc *p)
{
  if (!is_valid_nb(p->tmp_num_reg = tab_to_int(READ_ON_VM(2), 1) - 1,
		   1, REG_NUMBER - 1))
    p->tmp_num_reg = 0;
  p->tmp_val = tab_to_int(p->regs[p->tmp_num_reg], REG_SIZE);
  p->tmp_val %= 256;
}

void	exec_aff(t_cw *cw, t_proc *p)
{
  cw = cw;
  write(1, &(p->tmp_val), 1);
}
