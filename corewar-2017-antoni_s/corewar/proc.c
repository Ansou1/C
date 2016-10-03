/*
** proc.c for proc in /home/efilon/Projects/Cproject/Corewar
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Tue Mar 19 10:41:03 2013 sebastien antonico
** Last update Sat Mar 30 22:33:49 2013 sebastien antonico
*/

#include <stdlib.h>
#include <unistd.h>
#include "libmy/my.h"
#include "op.h"
#include "corewar.h"

t_proc	*get_proc(t_proc *first, int id)
{
  t_proc	*tmp;
  int		i;

  tmp = first;
  i = 0;
  while (tmp->next != NULL && (i < id || id == -1))
    {
      tmp = tmp->next;
      i++;
    }
  return (tmp);
}

void	init_regs(t_proc *p, t_proc *from, int num_player)
{
  int	i;

  i = 0;
  while (i < REG_NUMBER)
    {
      if (from != NULL)
	i += my_strcpy(from->regs[i], p->regs[i], REG_SIZE);
      else
	{
	  if (i == 0)
	    write_int(p->regs[i++], REG_SIZE, num_player);
	  else
	    write_int(p->regs[i++], REG_SIZE, 0);
	}
    }
}

void	add_proc(t_proc *procs, int num_player, unsigned char *pc, t_proc *from)
{
  t_proc	*p;

  if ((p = malloc(sizeof(t_proc))) == NULL)
    my_puterr("Malloc error\n");
  init_regs(p, from, num_player);
  p->tmp_val = (from == NULL) ? 0 : from->tmp_val;
  p->tmp_num_reg = (from == NULL) ? 0 : from->tmp_num_reg;
  p->tmp_pc = (from == NULL) ? 0 : from->tmp_pc;
  p->type_instr = (from == NULL) ? 0 : from->type_instr;
  p->num_player = num_player;
  p->pc = pc;
  p->next = NULL;
  p->bool_live = FALSE;
  p->carry = 0;
  fill_coding_oct(p);
  p->nbr_cycle = get_nb_cycle(p);
  get_proc(procs, -1)->next = p;
}

void	rm_proc(t_proc **procs, int id)
{
  t_proc	*tmp;
  int		i;

  tmp = *procs;
  i = 0;
  while (tmp->next != NULL && i < id)
    {
      tmp = tmp->next;
      i++;
    }
  if (id > 0)
    get_proc(*procs, id - 1)->next = tmp->next;
  else
    *procs = (*procs)->next;
  free(tmp);
}

int		size_procs(t_proc *procs)
{
  t_proc	*tmp;
  int		i;

  tmp = procs;
  i = 0;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}
