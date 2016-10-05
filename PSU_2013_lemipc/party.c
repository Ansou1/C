/*
** party.c for  in /home/daguen_s/rendu/PSU_2013_lemipc
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Sat Mar 29 14:53:40 2014 daguen_s
** Last update Sat Mar 29 20:41:11 2014 daguen_s
*/

#include "lemipc.h"

void		end(t_lemipc *this)
{
  unsigned char	v;

  v = 0;
  while (get_number_of_players(this) > 0)
    {
      v = aff_map(this);
      printf("number of players = %d\n", get_number_of_players(this));
      usleep(100000);
    }
  if (shmctl(this->shm_id, IPC_RMID, NULL) == -1)
    errx(EXIT_FAILURE, "Error %s\n", strerror(errno));
  if (semctl(this->sem_id, 0, IPC_RMID, 0) == -1)
    errx(EXIT_FAILURE, "Error %s\n", strerror(errno));
  if (this->status & GRAPHIC_MODE)
    end_sdl(this);
  if (v == 0)
    printf("This is a DRAW!!!\n");
  else
    printf("The team %d WIN THE GAME!!!!\n", v);
}

int		touch_opponent(unsigned char value, unsigned char team)
{
  if (value != team && value != OUT && value != IN)
    return (TRUE);
  return (FALSE);
}

void		cond_to_die(t_lemipc *this, unsigned char ctr)
{
  if (ctr > 1)
    {
      this->map[this->position.x + this->position.y * MAP] = 0;
      this->status &= ~ALIVE;
    }
}

void		is_gonna_die(t_lemipc *this)
{
  t_around	a;
  unsigned char	ctr;
  unsigned char	v;

  ctr = 0;
  a = get_around(this->position.x, this->position.y);
  if ((v = get_value(this, &a.right)) != IN && v != TEAM && v != OUT)
    ++ctr;
  if ((v = get_value(this, &a.left)) != IN && v != TEAM && v != OUT)
    ++ctr;
  if ((v = get_value(this, &a.top)) != IN && v != TEAM && v != OUT)
    ++ctr;
  if ((v = get_value(this, &a.bottom)) != IN && v != TEAM && v != OUT)
    ++ctr;
  if ((v = get_value(this, &a.top_left)) != IN && v != TEAM && v != OUT)
    ++ctr;
  if ((v = get_value(this, &a.top_right)) != IN && v != TEAM && v != OUT)
    ++ctr;
  if ((v = get_value(this, &a.bottom_left)) != IN && v != TEAM && v != OUT)
    ++ctr;
  if ((v = get_value(this, &a.bottom_right)) != IN && v != TEAM && v != OUT)
    ++ctr;
  cond_to_die(this, ctr);
}

void		lets_go(t_lemipc *this)
{
  while (this->status & ALIVE)
    {
      usleep(100000);
      if (shmget(this->key, MAP * MAP + 1, RW) == -1)
        this->status &= ~ALIVE;
      else
	{
	  is_gonna_die(this);
	  if (this->status & ALIVE)
	    mmove(this);
	  if (this->status & SERVER)
	    aff_map(this);
	  if (get_number_of_team(this) < 2)
	    this->status &= ~ALIVE;
	}
    }
  this->map[this->position.x + this->position.y * MAP] = 0;
  if (this->status & SERVER)
    end(this);
}
