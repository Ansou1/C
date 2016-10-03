/*
** fork.c for fork in /home/efilon/Projects/Cproject/Corewar
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Sat Mar 30 13:11:01 2013 sebastien antonico
** Last update Sun Mar 31 00:37:07 2013 sebastien antonico
*/

#include <unistd.h>
#include <stdlib.h>
#include "op.h"
#include "corewar.h"
#include "libmy/my.h"

void	read_fork(t_cw *cw, t_proc *p)
{
  p->tmp_pc = (p->pc + ((tab_to_int(cw->vm + ((p->pc - cw->vm + 1) % MEM_SIZE),
				    IND_SIZE) % IDX_MOD) % MEM_SIZE) %
	       MEM_SIZE);
}

void	exec_fork(t_cw *cw, t_proc *p)
{
  add_proc(cw->list_proc, p->num_player, p->tmp_pc, p);
  p->carry = 0;
}
