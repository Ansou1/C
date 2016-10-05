/*
** team.c for  in /home/corrad_f/rendu/PSU_2013_lemipc
**
** Made by corrad_f
** Login   <corrad_f@epitech.net>
**
** Started on  Mon Mar 24 11:20:07 2014 corrad_f
** Last update Sat Mar 29 20:49:20 2014 daguen_s
*/

#include "lemipc.h"

t_point			move_anywhere(t_lemipc *this)
{
  int			rands;
  t_point		tab[8];
  t_around		a;
  unsigned char		v;
  int			ctr;
  t_point		ret;

  ctr = 0;
  rands = rand() % 8;
  ret = this->position;
  a = get_around(this->position.x, this->position.y);
  tab[0] = a.right;
  tab[1] = a.left;
  tab[2] = a.top;
  tab[3] = a.bottom;
  tab[5] = a.top_left;
  tab[4] = a.top_right;
  tab[6] = a.bottom_right;
  tab[7] = a.bottom_left;
  while ((v = get_value(this, &tab[rands %= 8])) != IN && ctr < 8)
    {
      ++rands;
      ++ctr;
    }
  return (ret = ((ctr < 8) ? tab[rands] : ret));
}

t_point			get_order_by_distance(t_lemipc *this, t_point pos)
{
  t_around		around;
  double		dist;

  around = get_around(this->position.x, this->position.y);
  dist = get_dist(this->position.x, this->position.y, pos.x, pos.y);
  if (get_value(this, &R) == IN && (get_dist(R.x, R.y, pos.x, pos.y) < dist))
    return (R);
  if (get_value(this, &L) == IN && (get_dist(L.x, L.y, pos.x, pos.y) < dist))
    return (L);
  if (get_value(this, &T) == IN && (get_dist(T.x, T.y, pos.x, pos.y) < dist))
    return (T);
  if (get_value(this, &B) == IN && (get_dist(B.x, B.y, pos.x, pos.y) < dist))
    return (B);
  if (get_value(this, &TL) == IN && (get_dist(TL.x, TL.y, pos.x, pos.y) < dist))
    return (TL);
  if (get_value(this, &TR) == IN && (get_dist(TR.x, TR.y, pos.x, pos.y) < dist))
    return (TR);
  if (get_value(this, &BL) == IN && (get_dist(BL.x, BL.y, pos.x, pos.y) < dist))
    return (BL);
  if (get_value(this, &BR) == IN && (get_dist(BR.x, BR.y, pos.x, pos.y) < dist))
    return (BR);
  return (move_anywhere(this));
}

void			mmove(t_lemipc *this)
{
  t_point		go_to;
  struct sembuf		sops;

  sops.sem_num = 0;
  sops.sem_op = -1;
  sops.sem_flg = 0;
  semop(this->sem_id, &sops, 1);
  go_to = get_closest_opponents(this);
  go_to = get_order_by_distance(this, go_to);
  this->map[this->position.x + this->position.y * MAP] = 0;
  this->position = go_to;
  this->map[this->position.x + this->position.y * MAP] = TEAM;
  sops.sem_num = 0;
  sops.sem_op = 1;
  sops.sem_flg = 0;
  semop(this->sem_id, &sops, 1);
}

int			loop(t_lemipc *this, t_around around)
{
  int			i;

  i = 0;
  while (i < (MAP * MAP))
    {
      around = get_around(i % MAP, i / MAP);
      if (get_value(this, &R) == IN && this->map[i] == TEAM)
        return (set_position(this, R));
      else if (get_value(this, &L) == IN && this->map[i] == TEAM)
        return (set_position(this, L));
      else if (get_value(this, &T) == IN && this->map[i] == TEAM)
        return (set_position(this, T));
      else if (get_value(this, &B) == IN && this->map[i] == TEAM)
        return (set_position(this, B));
      else if (get_value(this, &TL) == IN && this->map[i] == TEAM)
        return (set_position(this, TL));
      else if (get_value(this, &TR) == IN && this->map[i] == TEAM)
        return (set_position(this, TR));
      else if (get_value(this, &BL) == IN && this->map[i] == TEAM)
        return (set_position(this, BL));
      else if (get_value(this, &BR) == IN && this->map[i] == TEAM)
        return (set_position(this, BR));
      i++;
    }
  return (-1);
}

int			pop_near_friend(t_lemipc *this)
{
  struct sembuf		sops;
  t_around		near;
  int			error;

  sops.sem_num = 0;
  sops.sem_op = -1;
  sops.sem_flg = 0;
  semop(this->sem_id, &sops, 1);
  error = loop(this, near);
  sops.sem_num = 0;
  sops.sem_op = 1;
  sops.sem_flg = 0;
  semop(this->sem_id, &sops, 1);
  if (error == -1)
    return (pop_at_random(this));
  return (0);
}
