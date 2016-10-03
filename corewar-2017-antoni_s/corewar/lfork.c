/*
** lfork.c for lfork in /home/efilon/Projects/Cproject/Corewar
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Sat Mar 30 13:11:47 2013 sebastien antonico
** Last update Sun Mar 31 00:39:38 2013 sebastien antonico
*/

#include <unistd.h>
#include <stdlib.h>
#include "op.h"
#include "corewar.h"
#include "libmy/my.h"

void	read_lfork(t_cw *cw, t_proc *p)
{
  p->tmp_pc = cw->vm +
    ((tab_to_int(cw->vm + ((p->pc - cw->vm + 1) % MEM_SIZE), IND_SIZE)) %
     MEM_SIZE);
}

void	exec_lfork(t_cw *cw, t_proc *p)
{
  add_proc(cw->list_proc, p->num_player, p->tmp_pc, p);
  p->carry = 1;
}
