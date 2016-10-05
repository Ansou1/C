/*
** algo_number.c for rush in /home/daguen_s//rush/save_valgrind
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Mar  3 10:35:26 2013 simon daguenet
** Last update Sun Mar  3 14:51:57 2013 simon daguenet
*/

#include "rush.h"

void	algo_one(int cnt, int x, int y, t_laby *s)
{
  if ((y - 1) >= 0)
    {
      if (s->algo[y - 1][x] == -4)
	s->algo[y - 1][x] = (cnt + 1);
      if (s->algo[y - 1][x] == -2)
	{
	  s->algo[y - 1][x] = (cnt + 1);
	  s->nb = (s->algo[y - 1][x]);
	  if (s->nb < s->bestpath)
	    {
	      s->bestpath = s->nb;
	      s->new_pathy = y - 1;
	      s->new_pathx = x;
	    }
	}
    }
}

void	algo_two(int cnt, int x, int y, t_laby *s)
{
  if (s->algo[y + 1])
    {
      if (s->algo[y + 1][x] == -4)
	s->algo[y + 1][x] = (cnt + 1);
      if (s->algo[y + 1][x] == -2)
	{
	  s->algo[y + 1][x] = (cnt + 1);
	  s->nb = (s->algo[y + 1][x]);
	  if (s->nb < s->bestpath)
	    {
	      s->bestpath = s->nb;
	      s->new_pathy = y + 1;
	      s->new_pathx = x;
	    }
	}
    }
}

void	algo_three(int cnt, int x, int y, t_laby *s)
{
  if ((x + 1) <= s->size_x)
    {
      if (s->algo[y][x + 1] == -4)
	s->algo[y][x + 1] = (cnt + 1);
      if (s->algo[y][x + 1] == -2)
	{
	  s->algo[y][x + 1] = (cnt + 1);
	  s->nb = s->algo[y][x + 1];
	  if (s->nb < s->bestpath)
	    {
	      s->bestpath = s->nb;
	      s->new_pathy = y;
	      s->new_pathx = x + 1;
	    }
	}
    }
}

void	algo_for(int cnt, int x, int y, t_laby *s)
{
  if ((x - 1) >= 0)
    {
      if (s->algo[y][x - 1] == -4)
	s->algo[y][x - 1] = (cnt + 1);
      if (s->algo[y][x - 1] == -2)
	{
	  s->algo[y][x - 1] = (cnt + 1);
	  s->nb = (s->algo[y][x - 1]);
	  if (s->nb < s->bestpath)
	    {
	      s->bestpath = s->nb;
	      s->new_pathy = y;
	      s->new_pathx = x - 1;
	    }
	}
    }
}
