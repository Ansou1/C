/*
** zjmp.c for zjmp in /home/efilon/Projects/Cproject/Corewar
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Sat Mar 30 13:10:16 2013 sebastien antonico
** Last update Sun Mar 31 00:41:49 2013 sebastien antonico
*/

#include <unistd.h>
#include <stdlib.h>
#include "op.h"
#include "corewar.h"
#include "libmy/my.h"

void	read_zjmp(t_cw *cw, t_proc *p)
{
  p->tmp_val = tab_to_int(cw->vm + ((p->pc - cw->vm + 1) % MEM_SIZE), IND_SIZE);
}

void	exec_zjmp(t_cw *cw, t_proc *p)
{
  p->pc = cw->vm + ((p->pc - cw->vm + (p->tmp_val % IDX_MOD)) % MEM_SIZE);
  p->carry = 0;
}
