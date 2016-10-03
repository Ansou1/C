/*
** the_rand.c for 42sh in /home/daguen_s/
**
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
**
** Started on  Fri May  3 09:59:21 2013 simon daguenet
** Last update Mon May  6 14:47:10 2013 florian corradin
*/

#include "42.h"

int	get_rand()
{
  srandom(time(NULL) * getpid());
  return (random() % 32767);
}
