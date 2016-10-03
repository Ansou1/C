/*
** corewar.c for corewar in /home/efilon/Projects/Cproject/Corewar
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Mon Mar 18 11:56:32 2013 sebastien antonico
** Last update Sun Mar 31 18:40:32 2013 sebastien antonico
*/

#include <stdlib.h>
#include <unistd.h>
#include "op.h"
#include "corewar.h"
#include "libmy/my.h"

void		exit_cw(t_cw *cw)
{
  int		i;

  i = 0;
  write(1, "\ncleaning and quitting...\n", 26);
  while (i < cw->nb_champs)
    {
      free(cw->champs[i].binary);
      i++;
    }
  i = 0;
  free(cw->vm);
  exit(42);
}

void	init_first_proc(t_cw *cw)
{
  int	i;

  i = 0;
  if ((cw->list_proc = malloc(sizeof(t_proc))) == NULL)
    my_puterr("Malloc error\n");
  while (i < REG_NUMBER)
    {
      my_memset((cw->list_proc)->regs[i], REG_SIZE);
      i++;
    }
  write_int((cw->list_proc)->regs[0], REG_SIZE, 1);
  i = 1;
  (cw->list_proc)->num_player = 1;
  (cw->list_proc)->carry = 0;
  (cw->list_proc)->pc = &(cw->vm[0]);
  (cw->list_proc)->next = NULL;
  (cw->list_proc)->bool_live = FALSE;
  (cw->list_proc)->tmp_val = 0;
  (cw->list_proc)->tmp_num_reg = 0;
  (cw->list_proc)->tmp_pc = (cw->list_proc)->pc;
  (cw->list_proc)->type_instr = 0;
  fill_coding_oct(cw->list_proc);
  (cw->list_proc)->nbr_cycle = get_nb_cycle(cw->list_proc);
}

void		place_champs(t_cw *cw)
{
  int		i;
  int		j;
  int		pc;

  i = 0;
  while (i < cw->nb_champs)
    {
      j = 0;
      pc = (MEM_SIZE / cw->nb_champs) * i;
      if (i == 0)
  	init_first_proc(cw);
      else
  	add_proc(cw->list_proc, i + 1, cw->vm + pc, NULL);
      while (j < cw->champs[i].header.prog_size)
  	{
  	  cw->vm[(pc + j) % MEM_SIZE] = cw->champs[i].binary[j];
  	  j++;
  	}
      get_proc(cw->list_proc, -1)->nbr_cycle =
	get_nb_cycle(get_proc(cw->list_proc, -1));
      i++;
    }
}

void	memdump(t_cw *cw)
{
  int	i;

  i = 0;
  write(1, "Memory dump : \n", 15);
  while (i < MEM_SIZE)
    {
      if (i % 32 == 0 && i != 0)
	write(1, "\n", 1);
      my_putnbrXX((int)cw->vm[i]);
      i++;
    }
  write(1, "\n", 1);
  exit_cw(cw);
}

int	corewar(t_cw *cw)
{
  if ((cw->vm = malloc(MEM_SIZE * sizeof(unsigned char))) == NULL)
    my_puterr("Malloc error");
  my_memset(cw->vm, MEM_SIZE);
  if (total_size(cw) > MEM_SIZE)
    {
      write(2, "Champions trop gros !\n", 21);
      free(cw->vm);
      return (-1);
    }
  if (!check_defines())
    {
      write(2, "Header invalide !\n", 18);
      free(cw->vm);
      return (-1);
    }
  fill_pfunc_read(cw);
  fill_pfunc_exec(cw);
  place_champs(cw);
  fight(cw);
  memdump(cw);
  return (1);
}
