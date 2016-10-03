/*
** main.c for main in /home/efilon/Projects/Cproject/Corewar
** 
** Made by sebastien antonico
** Login   <antoni_s@epitech.eu>
** 
** Started on  Sun Mar 17 20:03:44 2013 sebastien antonico
** Last update Sun Mar 31 19:04:09 2013 sebastien antonico
*/

#include <stdlib.h>
#include <unistd.h>
#include "libmy/my.h"
#include "corewar.h"
#include "op.h"

int	parse_arg(int ac, char **av, t_cw *cw)
{
  int	i;
  int	j;

  i = 1;
  j = 0;
  while (i < ac)
    {
      if (!my_strcmp(av[i], "-dump"))
	{
	  if (i + 1 < ac)
	    cw->dump = my_getnbr(av[i + 1]);
	  else
	    my_puterr(USAGE);
	  i += 2;
	}
      else
	{
	  cw->champs[j] = get_binary(av[i]);
	  cw->champs[j].exist = 1;
	  j++;
	  i++;
	}
    }
  return (j);
}

int	main(int ac, char **av)
{
  t_cw	cw;

  if (ac == 1)
    my_puterr(USAGE);
  cw.nb_champs = parse_arg(ac, av, &cw);
  if (cw.dump <= 0)
    cw.dump = NO_DUMP;
  corewar(&cw);
  return (1);
}

