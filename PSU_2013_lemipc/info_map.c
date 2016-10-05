/*
** info_map.c for  in /home/daguen_s/rendu/PSU_2013_lemipc
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Sat Mar 29 14:49:57 2014 daguen_s
** Last update Sat Mar 29 20:49:17 2014 daguen_s
*/

#include "lemipc.h"

unsigned char	get_number_of_team(t_lemipc *this)
{
  unsigned int	i;
  unsigned char	team[10];

  i = 0;
  while (i < 9)
    {
      ++i;
      team[i] = 0;
    }
  i = 0;
  while (i < (unsigned int)(MAP * MAP))
    {
      team[this->map[i]] = 1;
      ++i;
    }
  i = 1;
  team[0] = 0;
  while (i < 9)
    {
      if (team[i])
	team[0] = team[0] + 1;
      ++i;
    }
  return (team[0]);
}

unsigned char	get_number_of_teamate(t_lemipc *this, unsigned char team)
{
  unsigned int	i;
  unsigned int	ctr;

  ctr = 0;
  i = 0;
  while (i < (unsigned int)(MAP * MAP))
    {
      if (this->map[i] == team)
	++ctr;
      ++i;
    }
  return (ctr);
}

t_around		get_around(int x, int y)
{
  t_around		around;

  L.x = x - 1;
  L.y = y;
  R.x = x + 1;
  R.y = y;
  T.x = x;
  T.y = y - 1;
  B.x = x;
  B.y = y + 1;
  TL.x = x - 1;
  TL.y = y - 1;
  TR.x = x + 1;
  TR.y = y - 1;
  BL.x = x - 1;
  BL.y = y + 1;
  BR.x = x + 1;
  BR.y = y + 1;
  return (around);
}

int			set_position(t_lemipc *this, t_point pos)
{
  this->map[(pos.y * MAP) + pos.x] = TEAM;
  this->position.x = pos.x;
  this->position.y = pos.y;
  return (0);
}
