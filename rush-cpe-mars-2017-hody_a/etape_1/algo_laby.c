/*
** algo_laby.c for rush in /home/hody_a//rush
** 
** Made by alexy hody
** Login   <hody_a@epitech.net>
** 
** Started on  Sat Mar  2 10:40:15 2013 alexy hody
** Last update Sun Mar  3 14:36:52 2013 simon daguenet
*/

#include "rush.h"

void	check_algo(t_laby *s)
{
  s->y = 0;
  while (s->algo[s->y])
    {
      s->x = 0;
      while (s->algo[s->y][s->x])
	{
	  if (s->algo[s->y][s->x] == s->cnt)
	    algo_start(s->y, s->x, s);
	  s->x++;
	}
      s->y++;
    }
}

void	algo_start(int y, int x, t_laby *s)
{
  algo_one(s->cnt, x, y, s);
  algo_two(s->cnt, x, y, s);
  algo_three(s->cnt, x, y, s);
  algo_for(s->cnt, x, y, s);
}

void	algo_laby(t_laby *s)
{
  s->cnt = 1;
  s->bestpath = 2000000;
  while (s->cnt < 10000)
    {
      check_algo(s);
      s->cnt++;
    }
  if (s->bestpath != 2000000)
    end_tab(s);
  else
    my_print_error("MAP ERROR\n");
}
