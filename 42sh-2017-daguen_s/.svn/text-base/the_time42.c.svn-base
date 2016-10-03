/*
** the_time42.c for 42sh in /home/daguen_s/
**
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
**
** Started on  Fri May  3 09:30:31 2013 simon daguenet
** Last update Sun May 26 14:00:11 2013 antoine simon
*/

#include "42.h"

/* dans info */
time_t		get_time()
{
  time_t	timestamp;

  timestamp = time(NULL);
  return (timestamp);
}

int		get_seconds()
{
  time_t	timestamp2;
  double	diff = 0.f;

  timestamp2 = time(NULL);
  diff = difftime(timestamp2, info.time);
  return ((int)diff);
}

void		aff_time()
{
  struct tm	*t;
  time_t	ti;
  char		*str;

  str = malloc(20);
  ti = time(NULL);
  t = localtime(&ti);
  sprintf(str, "%.2d:%.2d:%.2d", t->tm_hour, t->tm_min, t->tm_sec);
  my_putstr(str);
  free(str);
}

int		get_tm_s()
{
  struct tm	*t;
  time_t	ti;

  ti = time(NULL);
  t = localtime(&ti);
  return (t->tm_sec);
}
