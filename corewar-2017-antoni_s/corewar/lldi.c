/*
** lldi.c for lldi in /home/efilon/Projects/Cproject/Corewar
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Sat Mar 30 13:11:34 2013 sebastien antonico
** Last update Sun Mar 31 00:40:18 2013 sebastien antonico
*/

#include <unistd.h>
#include <stdlib.h>
#include "op.h"
#include "corewar.h"
#include "libmy/my.h"

int	read_first_oct_lldi(t_cw *cw, t_proc *p)
{
  int	v1;

  if (C_OCT1 == 1)
    {
      if (is_valid_nb(v1 = tab_to_int(READ_ON_VM(2), IND_SIZE) - 1,
				      1, REG_NUMBER - 1))
	v1 = tab_to_int(p->regs[v1], REG_SIZE);
      else
	v1 = tab_to_int(p->regs[0], REG_SIZE);
    }
  else if (C_OCT1 == 2)
    v1 = tab_to_int(cw->vm + ((p->pc - cw->vm + 2) % MEM_SIZE), IND_SIZE);
  else if (C_OCT1 == 3)
    v1 = tab_to_int(cw->vm + ((p->pc - cw->vm +
			       (tab_to_int(READ_ON_VM(2), IND_SIZE)))
			      % MEM_SIZE), IND_SIZE);
  v1 = tab_to_int(cw->vm + ((p->pc - cw->vm + v1) % MEM_SIZE), IND_SIZE);
  return (v1);
}

int	read_second_oct_lldi(t_cw *cw, t_proc *p, int jumping)
{
  int	v2;

  if (C_OCT2 == 1)
    {
      if (is_valid_nb(v2 = tab_to_int(READ_ON_VM(2 + jumping),
				      IND_SIZE) - 1, 1, REG_NUMBER - 1))
	v2 = tab_to_int(p->regs[v2], REG_SIZE);
      else
	v2 = tab_to_int(p->regs[0], REG_SIZE);
    }
  else if (C_OCT2 == 2)
    v2 = tab_to_int(READ_ON_VM(2 + jumping), IND_SIZE);
  else if (C_OCT2 == 3)
    v2 = tab_to_int(cw->vm + ((p->pc - cw->vm +
			       (tab_to_int(READ_ON_VM(2 + jumping),
					   IND_SIZE))) % MEM_SIZE), IND_SIZE);
  v2 = tab_to_int(cw->vm + ((p->pc - cw->vm + jumping + v2) % MEM_SIZE),
		  IND_SIZE);
  return (v2);
}

void	read_lldi(t_cw *cw, t_proc *p)
{
  int	jumping;
  int	v1;
  int	v2;
  int	v3;

  v1 = read_first_oct_lldi(cw, p);
  jumping = (C_OCT1 == 1) ? 1 : ((C_OCT1 == 2) ? DIR_SIZE : IND_SIZE);
  v2 = read_second_oct_lldi(cw, p, jumping);
  jumping += (C_OCT2 == 1) ? 1 : ((C_OCT2 == 2) ? DIR_SIZE : IND_SIZE);
  if (!is_valid_nb(v3 = tab_to_int(READ_ON_VM(2 + jumping), 1) - 1,
		   1, REG_NUMBER - 1))
    v3 = 0;
  p->tmp_num_reg = v3;
  p->tmp_val = tab_to_int(cw->vm + ((p->pc - cw->vm + ((v1 + v2))) %
				    MEM_SIZE), IND_SIZE);
}

void	exec_lldi(t_cw *cw, t_proc *p)
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
