/*
** check_live.c for check_live in /home/efilon/Projects/Cproject/Corewar
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Sat Mar 30 23:58:13 2013 sebastien antonico
** Last update Sun Mar 31 18:44:26 2013 sebastien antonico
*/

#include <unistd.h>
#include <stdlib.h>
#include "op.h"
#include "corewar.h"
#include "libmy/my.h"

int		check_procs_alive(t_cw *cw)
{
  t_proc	*p;
  int		i;

  i = 0;
  p = cw->list_proc;
  while (p != NULL)
    {
      if (p->bool_live == TRUE && p->num_player > 0 &&
	  p->num_player <= cw->nb_champs && cw->champs[p->num_player - 1].exist)
	cw->champs[p->num_player - 1].alive = TRUE;
      else
	rm_proc(&(cw->list_proc), i);
      p = p->next;
      i++;
    }
  return (1);
}

int		check_champs(t_cw *cw)
{
  int		i;

  i = 0;
  while (i < cw->nb_champs)
    {
      if (cw->champs[i].exist && cw->champs[i].alive == 0)
	{
	  my_putstr("Le champion ");
	  my_putnbr(i + 1, 0);
	  my_putstr(" (");
	  my_putstr(cw->champs[i].header.prog_name);
	  my_putstr(") est tombé au combat.\n");
	  cw->champs[i].alive = -1;
	}
      i++;
    }
  return (1);
}

int		nb_champs_alive(t_cw *cw)
{
  int		i;
  int		nb_champs_alive;

  i = 0;
  nb_champs_alive = 0;
  while (i < cw->nb_champs)
    {
      if (cw->champs[i].alive == TRUE && cw->champs[i].exist)
	nb_champs_alive++;
      i++;
    }
  return (nb_champs_alive);
}

int		check_win(t_cw *cw)
{
  int		i;

  i = 0;
  while (i < cw->nb_champs)
    {
      if (cw->champs[i].alive != -1)
	cw->champs[i].alive = 0;
      i++;
    }
  i = 0;
  check_procs_alive(cw);
  check_champs(cw);
  if (nb_champs_alive(cw) > 1)
    return (0);
  return (1);
}

void		reinit_live_proc(t_cw *cw)
{
  t_proc	*p;

  p = cw->list_proc;
  while (p != NULL)
    {
      p->bool_live = FALSE;
      p = p->next;
    }
}
