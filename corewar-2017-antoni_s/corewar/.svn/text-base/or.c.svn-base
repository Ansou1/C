/*
** or.c for or in /home/efilon/Projects/Cproject/Corewar
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Sat Mar 30 13:09:51 2013 sebastien antonico
** Last update Sun Mar 31 00:40:34 2013 sebastien antonico
*/

#include <unistd.h>
#include <stdlib.h>
#include "op.h"
#include "corewar.h"
#include "libmy/my.h"

int	read_first_oct_or(t_cw *cw, t_proc *p)
{
  int	v1;

  if (C_OCT1 == 1)
    {
      v1 = tab_to_int(cw->vm + ((p->pc - cw->vm + 2) % MEM_SIZE), 1) - 1;
      if (!is_valid_nb(v1, 1, REG_NUMBER - 1))
	v1 = tab_to_int(p->regs[0], REG_SIZE);
      else
	v1 = tab_to_int(p->regs[v1], REG_SIZE);
    }
  else if (C_OCT1 == 2)
    v1 = tab_to_int(cw->vm + ((p->pc - cw->vm + 2) % MEM_SIZE), DIR_SIZE);
  else if (C_OCT1 == 3)
    v1 = tab_to_int(cw->vm + ((p->pc - cw->vm +
			       (tab_to_int(READ_ON_VM(2), IND_SIZE) %
				IDX_MOD)) % MEM_SIZE), IND_SIZE);
  return (v1);
}

int	read_second_oct_or(t_cw *cw, t_proc *p, int jumping)
{
  int	v2;

  if (C_OCT2 == 1)
    {
      v2 = tab_to_int(cw->vm + ((p->pc - cw->vm + 2 + jumping) %
				MEM_SIZE), 1) - 1;
      if (!is_valid_nb(v2, 1, REG_NUMBER - 1))
	v2 = tab_to_int(p->regs[0], REG_SIZE);
      else
	v2 = tab_to_int(p->regs[v2], REG_SIZE);
    }
  else if (C_OCT2 == 2)
    v2 = tab_to_int(cw->vm + ((p->pc - cw->vm + 2 + jumping) % MEM_SIZE),
		    DIR_SIZE);
  else if (C_OCT2 == 3)
    v2 = tab_to_int(cw->vm + ((p->pc - cw->vm +
			       (tab_to_int(READ_ON_VM(2 + jumping), IND_SIZE) %
				IDX_MOD)) % MEM_SIZE), IND_SIZE);
  return (v2);
}

void	read_or(t_cw *cw, t_proc *p)
{
  int	jumping;
  int	v1;
  int	v2;
  int	v3;

  jumping = 0;
  v1 = read_first_oct_or(cw, p);
  jumping += (C_OCT1 == 1) ? 1 : ((C_OCT1 == 2) ? DIR_SIZE : IND_SIZE);
  v2 = read_second_oct_or(cw, p, jumping);
  jumping += (C_OCT2 == 1) ? 1 : ((C_OCT2 == 2) ? DIR_SIZE : IND_SIZE);
  v3 = tab_to_int(cw->vm + ((p->pc - cw->vm + 2 + jumping) % MEM_SIZE), 1) - 1;
  if (is_valid_nb(v3, 1, REG_NUMBER - 1))
    p->tmp_num_reg = v3;
  else
    p->tmp_num_reg = 0;
  p->tmp_val = v1 | v2;
}
