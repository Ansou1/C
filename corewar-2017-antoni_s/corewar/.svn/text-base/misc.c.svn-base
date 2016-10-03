/*
** misc.c for misc in /home/efilon/Projects/Cproject/Corewar
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Sat Mar 30 22:31:34 2013 sebastien antonico
** Last update Sun Mar 31 01:02:14 2013 sebastien antonico
*/

#include "op.h"
#include "corewar.h"

void	fill_coding_oct(t_proc *p)
{
  p->c_oct.type1 = ((p->pc + 1)[0] & 0xC0) >> 6;
  p->c_oct.type2 = ((p->pc + 1)[0] & 0x30) >> 4;
  p->c_oct.type3 = ((p->pc + 1)[0] & 0xC) >> 2;
}

int	total_size(t_cw *cw)
{
  int	i;
  int	size;

  i = 0;
  size = 0;
  while (i < cw->nb_champs)
    {
      size += cw->champs[i].header.prog_size;
      i++;
    }
  return (size);
}

void	fill_pfunc_read(t_cw *cw)
{
  cw->ptr_read[0] = &read_live;
  cw->ptr_read[1] = &read_ld;
  cw->ptr_read[2] = &read_st;
  cw->ptr_read[3] = &read_add;
  cw->ptr_read[4] = &read_sub;
  cw->ptr_read[5] = &read_and;
  cw->ptr_read[6] = &read_or;
  cw->ptr_read[7] = &read_xor;
  cw->ptr_read[8] = &read_zjmp;
  cw->ptr_read[9] = &read_ldi;
  cw->ptr_read[10] = &read_sti;
  cw->ptr_read[11] = &read_fork;
  cw->ptr_read[12] = &read_lld;
  cw->ptr_read[13] = &read_lldi;
  cw->ptr_read[14] = &read_lfork;
  cw->ptr_read[15] = &read_aff;
}

void	fill_pfunc_exec(t_cw *cw)
{
  cw->ptr_exec[0] = &exec_live;
  cw->ptr_exec[1] = &exec_ld;
  cw->ptr_exec[2] = &exec_st;
  cw->ptr_exec[3] = &exec_add;
  cw->ptr_exec[4] = &exec_sub;
  cw->ptr_exec[5] = &exec_and_or_xor;
  cw->ptr_exec[6] = &exec_and_or_xor;
  cw->ptr_exec[7] = &exec_and_or_xor;
  cw->ptr_exec[8] = &exec_zjmp;
  cw->ptr_exec[9] = &exec_ldi;
  cw->ptr_exec[10] = &exec_sti;
  cw->ptr_exec[11] = &exec_fork;
  cw->ptr_exec[12] = &exec_lld;
  cw->ptr_exec[13] = &exec_lldi;
  cw->ptr_exec[14] = &exec_lfork;
  cw->ptr_exec[15] = &exec_aff;
}

int	check_defines()
{
  if (MEM_SIZE < 1*1024 || MEM_SIZE > 16*1024 ||
      IDX_MOD < 32 || IDX_MOD > 4096 ||
      REG_NUMBER < 4 || REG_NUMBER > 64 ||
      IND_SIZE < 1 || IND_SIZE > 16 ||
      REG_SIZE < 1 || REG_SIZE > 16 ||
      DIR_SIZE < 1 || DIR_SIZE > 16 ||
      PROG_NAME_LENGTH < 1 || COMMENT_LENGTH < 1 ||
      CYCLE_TO_DIE < 10 || CYCLE_DELTA < 1 || NBR_LIVE < 1)
    return (0);
  return (1);
}
