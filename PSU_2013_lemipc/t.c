/*
** t.c for  in /home/corrad_f/rendu/PSU_2013_lemipc
**
** Made by corrad_f
** Login   <corrad_f@epitech.net>
**
** Started on  Mon Mar 24 11:21:50 2014 corrad_f
** Last update Sat Mar 29 15:18:50 2014 daguen_s
*/

#include "lemipc.h"

unsigned char		get_value(t_lemipc *this, t_point *p)
{
  unsigned int		pos;

  pos = p->x + p->y * MAP;
  if (p->x >= MAP || p->y >= MAP)
    return (OUT);
  if (pos >= (unsigned int)(MAP * MAP))
    return (OUT);
  return (this->map[pos]);
}

unsigned char		case_is_free(t_lemipc *this, t_point *p)
{
  if (get_value(this, p) == 0)
    return (TRUE);
  return (FALSE);
}

//pose le jouer dans la map si la case est libre et retourne 1 sinon retourne 0
int			put_in_map(t_lemipc *this, unsigned int i)
{
  struct  sembuf	sops;
  int			ret;

  ret = 0;
  sops.sem_num = 0;
  sops.sem_op = -1;
  sops.sem_flg = 0;
  semop(this->sem_id, &sops, 1);
  if (this->map[i] == IN)
    {
      this->map[i] = this->team_player;
      this->position.x = i % MAP;
      this->position.y = i / MAP;
      ret = 1;
    }
  sops.sem_num = 0;
  sops.sem_op = 1;
  sops.sem_flg = 0;
  semop(this->sem_id, &sops, 1);
  return (ret);
}

//place un joueur à une position random dans la map
//retourne -1 si la focntion échoue
int			pop_at_random(t_lemipc *this)
{
  unsigned int		i;
  unsigned int		max;
  char			ok;

  ok = 0;
  max = MAP * MAP;
  srand(time(NULL) * getpid());
  i = rand() % (MAP * MAP);
  while (i < max)
    {
      if (put_in_map(this, i) == 1)
	return (1);
      if (i == max && ok == 0)
	{
	  ok = 1;
	  i  = 0;
	}
      ++i;
    }
  fprintf(stderr, "WARNING too much player\n");
  this->status &= ~ALIVE;
  return (-1);
}

unsigned char		aff_map(t_lemipc *this)
{
  unsigned int		i;
  unsigned int		a;
  unsigned char		v;

  if (this->status & GRAPHIC_MODE)
    return (display_map(this));
  system("clear");
  i = 0;
  while (i < (unsigned int)(MAP * MAP))
    {
      a = 0;
      while (a < MAP)
	{
	  if (this->map[a + i] != IN)
	    v = this->map[a + i];
	  printf("%d", this->map[a++ + i]);
	}
      printf("\n");
      i += MAP;
    }
  printf("Number of team %d\n", get_number_of_team(this));
  return (v);
}
