/*
** live.c for live in /home/efilon/Projects/Cproject/Corewar
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Sat Mar 30 12:59:46 2013 sebastien antonico
** Last update Sun Mar 31 00:48:35 2013 sebastien antonico
*/

#include <unistd.h>
#include <stdlib.h>
#include "op.h"
#include "corewar.h"
#include "libmy/my.h"

void	read_live(t_cw *cw, t_proc *p)
{
  p->tmp_val = tab_to_int(cw->vm + ((p->pc - cw->vm + 1) % MEM_SIZE), 4);
}

void	exec_live(t_cw *cw, t_proc *p)
{
  cw = cw;
  p->bool_live = TRUE;
  p->carry = 0;
}
