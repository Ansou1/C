/*
** check_opt_hist.c for 42sh in /home/daguen_s//42sh-2017-daguen_s
**
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
**
** Started on  Thu May 23 09:53:23 2013 simon daguenet
** Last update Thu May 23 10:06:05 2013 simon daguenet
*/

#include "42.h"

void	init_check_base(int *var, char *base)
{
  var[0] = -1;
  var[1] = 0;
  var[2] = 0;
  var[3] = 0;
  var[4] = 0;
  base[0] = 'c';
  base[1] = 'h';
  base[2] = 'r';
  base[3] = '\0';
}

int	check_base_loop(int *var, char *b, char *opt)
{
  while (opt[++var[0]] != '\0')
    {
      if (!(opt[var[0]] == b[0] || opt[var[0]] == b[1] || opt[var[0]] == b[2]))
	{
	  my_putstr("Usage: history [-chr] [# number of events].\n");
	  return (-1);
	}
      if (opt[var[0]] == b[0] && var[2] == 0)
	{
	  var[1] = var[1] + 4;
	  var[2] = 1;
	}
      if (opt[var[0]] == b[1] && var[3] == 0)
	{
	  var[1] = var[1] + 2;
	  var[3] = 1;
	}
      if (opt[var[0]] == b[2] && var[4] == 0)
	{
	  var[1] = var[1] + 1;
	  var[4] = 1;
	}
    }
  return (var[1]);
}

int	check_base(char *opt)
{
  char	b[4];
  int	var[5];

  init_check_base(var, b);
  var[1] = check_base_loop(var, b, opt);
  return (var[1]);
}

int	get_options(char *str)
{
  int	nbr;

  nbr = 0;
  if ((nbr = check_base(str)) == -1)
    return (-1);
  return (nbr);
}
