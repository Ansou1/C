/*
** get.c for  in /home/daguen_s/rendu/PSU_2013_lemipc
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Sat Mar 29 14:41:08 2014 daguen_s
** Last update Sat Mar 29 20:45:56 2014 daguen_s
*/

#include "lemipc.h"

key_t			get_key()
{
  char			buf[256];
  char			*ptr;
  key_t			key;

  memset(buf, 0, 256);
  if ((ptr = getcwd(buf, 256)) == NULL)
    errx(EXIT_FAILURE, "Error %s\n", strerror(errno));
  if ((key = ftok(buf, 0)) == -1)
    errx(EXIT_FAILURE, "Error %s\n", strerror(errno));
  return (key);
}

double			get_dist(int ax, int ay, int bx, int by)
{
  return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

t_point			get_closest_opponents(t_lemipc *this)
{
  unsigned int		i;
  double		tmp;
  double		distance;
  unsigned char		v;
  t_point		ret;

  i = 0;
  ret = this->position;
  distance = 999999999.0;
  while (i < (unsigned int)(MAP * MAP))
    {
      v = this->map[i];
      if (v != this->team_player && v != IN)
	{
	  tmp = get_dist(this->position.x, this->position.y, i % MAP, i / MAP);
	  if (tmp < distance)
	    {
	      distance = tmp;
	      ret.x = i % MAP;
	      ret.y = i / MAP;
	    }
	}
      i++;
    }
  return (ret);
}

t_point			get_closest_friends(t_lemipc *this)
{
  unsigned int		i;
  double		tmp;
  double		distance;
  t_point		ret;

  i = 0;
  ret = this->position;
  distance = 999999999.0;
  while (i < (unsigned int)(MAP * MAP))
    {
      if (this->map[i] == this->team_player &&
	  (this->position.x != (i % MAP) && (this->position.y != i / MAP)))
	{
	  tmp = get_dist(this->position.x, this->position.y,
			     i % MAP, i / MAP);
	  if (tmp < distance)
	    {
	      distance = tmp;
	      ret.x = i % MAP;
	      ret.y = i / MAP;
	    }
	}
      ++i;
    }
  return (ret);
}

unsigned int		get_number_of_players(t_lemipc *this)
{
  unsigned int		i;
  unsigned int		ctr;

  i = 0;
  ctr = 0;
  while (i < (unsigned int)(MAP * MAP))
    {
      if (this->map[i] != IN)
        ++ctr;
      ++i;
    }
  return (ctr);
}
