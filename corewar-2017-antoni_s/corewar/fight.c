/*
** fight.c for fight in /home/efilon/Projects/Cproject/Corewar
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Wed Mar 20 13:06:29 2013 sebastien antonico
** Last update Sun Mar 31 19:04:55 2013 sebastien antonico
*/

#include <unistd.h>
#include <stdlib.h>
#include "op.h"
#include "corewar.h"
#include "libmy/my.h"

int	is_valid_nb(int nb, int min, int max)
{
  if (nb >= min && nb <= max)
    return (1);
  return (0);
}

int	is_valid_opcode(t_proc *p)
{
  if ((p->pc[0] == 0x02 && (C_OCT2 != 1 || C_OCT1 == 1)) ||
      (p->pc[0] == 0x03 && (C_OCT1 != 1 || C_OCT2 == 2)) ||
      (p->pc[0] == 0x04 && (C_OCT1 != 1 || C_OCT2 != 1 || C_OCT3 != 1)) ||
      (p->pc[0] == 0x05 && (C_OCT1 != 1 || C_OCT2 != 1 || C_OCT3 != 1)) ||
      (p->pc[0] == 0x06 && (C_OCT3 != 1)) ||
      (p->pc[0] == 0x07 && (C_OCT3 != 1)) ||
      (p->pc[0] == 0x08 && (C_OCT3 != 1)) ||
      (p->pc[0] == 0x0a && (C_OCT3 != 1 || C_OCT2 == 2)) ||
      (p->pc[0] == 0x0b && (C_OCT1 != 1 || C_OCT3 == 3)) ||
      (p->pc[0] == 0x0d && (C_OCT1 != 1)) ||
      (p->pc[0] == 0x0e && (C_OCT3 != 1)) ||
      (p->pc[0] == 0x10 && (C_OCT1 != 1)))
    return (0);
  return (1);
}

int		fight(t_cw *cw)
{
  int		cycles[4];

  cycles[CTODIE] = CYCLE_TO_DIE;
  cycles[TOTALC] = 0;
  while (cycles[CTODIE] > 0)
    {
      cycles[LIVEC] = NBR_LIVE;
      cycles[CYCL] = cycles[CTODIE];
      while (cycles[CYCL] >= 0)
	{
	  if (cycles[LIVEC] >= 0 && cycles[TOTALC] >= CYCLE_TO_DIE)
	    cycles[LIVEC] -= 1;
	  else if (cycles[TOTALC] >= CYCLE_TO_DIE && check_win(cw))
	    return (1);
	  else if (cycles[TOTALC] >= CYCLE_TO_DIE)
	    reinit_live_proc(cw);
	  do_cycle(cw);
	  cycles[TOTALC]++;
	  if (cycles[TOTALC] >= cw->dump && cw->dump != NO_DUMP)
	    return (1);
	  cycles[CYCL]--;
	}
      cycles[CTODIE] -= CYCLE_DELTA;
    }
  return (0);
}
