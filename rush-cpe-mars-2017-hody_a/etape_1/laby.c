/*
** laby.c for rush in /home/hody_a//BSQ
** 
** Made by alexy hody
** Login   <hody_a@epitech.net>
** 
** Started on  Fri Dec  7 15:56:00 2012 alexy hody
** Last update Sun Mar  3 15:27:37 2013 simon daguenet
*/

#include "rush.h"

void	found_one(t_laby *s)
{
  s->x = 0;
  while (s->algo[s->x])
    {
      s->i = 0;
      while ((s->algo[s->x][s->i]))
	{
	  if (s->algo[s->x][s->i] == 1)
	    {
	      s->one_coordy = s->x - 1;
	      s->one_coordx = s->i;
	    }
      	  s->i++;
	}
      s->x++;
    }
}

void	found_two(t_laby *s)
{
  s->x = 0;
  while (s->algo[s->x])
    {
      s->i = 0;
      while ((s->algo[s->x][s->i]))
	{
	  if (s->algo[s->x][s->i] == -2)
	    {
	      s->two_coordy = s->x;
	      s->two_coordx = s->i;
	    }
      	  s->i++;
	}
      s->x++;
    }
}

void	init_laby(t_laby *s)
{
     s->a = 0;
     s->b = 0;
     s->y = 0;
     s->x = 0;
     s->i = 0;
     s->cnt = 0;
     s->one_coordx = 0;
     s->one_coordy = 0;
     s->two_coordx = 0;
     s->two_coordy = 0;
     s->found = 0;
}

void	display_path(t_laby *s)
{
  int	i;
  int	x;

  printf("%dx%d\n", s->size_x, s->size_y - 1);
  i = 1;
  while (s->end[i])
    {
      x = 0;
      while (s->end[i][x])
	{
	  if (s->end[i][x] == -3)
	    printf("*");
	  else if (s->end[i][x] == -4)
	    printf(" ");
	  else if (s->end[i][x] == -5)
	    printf("o");
	  else if (s->end[i][x] == -2)
	    printf("2");
	  else if (s->end[i][x] == 1)
	    printf("1");
	  x++;
  	}
      i++;
      puts("");
    }
}

void	aff_tab(t_laby *s)
{
  init_laby(s);
  end(s);
  found_one(s);
  found_two(s);
  algo_laby(s);
  display_path(s);
  printf("\n=> RESULTAT EN %i COUPS !\n", s->bestpath - 2);
}
