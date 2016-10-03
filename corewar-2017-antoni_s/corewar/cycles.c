/*
** cycles.c for cycles in /home/efilon/Projects/Cproject/Corewar
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Sat Mar 30 22:08:00 2013 sebastien antonico
** Last update Sun Mar 31 16:59:44 2013 sebastien antonico
*/

#include <unistd.h>
#include "corewar.h"
#include "op.h"

int	get_nb_cycle(t_proc *p)
{
  if (p->pc[0] <= 0 || p->pc[0] > 0x10)
    return (0);
  return (op_tab[p->pc[0] - 1].nbr_cycles);
}

int	read_proc(t_cw *cw, t_proc *p)
{
  p->type_instr = p->pc[0];
  if (p->pc[0] > 0 && p->pc[0] <= 0x10)
    cw->ptr_read[p->pc[0] - 1](cw, p);
  (p->nbr_cycle)--;
  return (1);
}

int	calc_jumping(t_cw *cw, t_proc *p)
{
  int	jumping;

  cw = cw;
  jumping = 1;
  if (p->pc[0] - 1 >= 0 && p->pc[0] - 1 < 16)
    if (op_tab[p->pc[0] - 1].nbr_args > 1)
      jumping++;
  if (p->type_instr == 0x0a || p->type_instr == 0x0b)
    jumping += (IND_SIZE * 2) + 1;
  else if (p->type_instr == 0x0c)
    jumping += IND_SIZE;
  else
    {
      jumping += (p->c_oct.type1 == 1) ? 1 :
	((p->c_oct.type1 == 2) ? DIR_SIZE : ((p->c_oct.type1 == 3) ?
					     IND_SIZE : 0));
      jumping += (p->c_oct.type2 == 1) ? 1 :
	((p->c_oct.type2 == 2) ? DIR_SIZE : ((p->c_oct.type2 == 3) ?
					     IND_SIZE : 0));
      jumping += (p->c_oct.type3 == 1) ? 1 :
	((p->c_oct.type3 == 2) ? DIR_SIZE : ((p->c_oct.type3 == 3) ?
					     IND_SIZE : 0));
    }
  return (jumping);
}

int	exec_proc(t_cw *cw, t_proc *p)
{
  int	jumping;

  if (p->type_instr > 0 && p->type_instr <= 0x10)
    cw->ptr_exec[p->type_instr - 1](cw, p);
  jumping = calc_jumping(cw, p);
  p->pc = cw->vm + ((p->pc - cw->vm + jumping) % MEM_SIZE);
  p->type_instr = 0;
  p->tmp_num_reg = 0;
  p->tmp_val = 0;
  p->nbr_cycle = get_nb_cycle(p);
  return (1);
}

void		do_cycle(t_cw *cw)
{
  t_proc	*p;

  p = cw->list_proc;
  while (p != NULL)
    {
      fill_coding_oct(p);
      if (is_valid_nb((int)(p->pc[0]), 1, 16) && is_valid_opcode(p))
	{
	  if (p->nbr_cycle == op_tab[p->pc[0] - 1].nbr_cycles)
	    read_proc(cw, p);
	  else if (p->nbr_cycle == 0)
	    exec_proc(cw, p);
	  else
	    (p->nbr_cycle)--;
	}
      else
	{
	  if (p->pc == cw->vm + MEM_SIZE)
	    p->pc = &(cw->vm[0]);
	  else
	    (p->pc)++;
	}
      p = p->next;
    }
}
