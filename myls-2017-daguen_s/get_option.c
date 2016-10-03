/*
** get_option.c for option in /home/daguen_s//ls/my_ls
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Tue Nov 27 09:31:43 2012 simon daguenet
** Last update Fri Nov 30 23:05:04 2012 simon daguenet
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdarg.h>
#include "my_ls.h"

char	*check_base(char *options)
{
  char	base[6];
  int	i;

  base[0] = 'l';
  base[1] = 'R';
  base[2] = 'd';
  base[3] = 'r';
  base[4] = 't';
  base[5] = '\0';
  if (options == NULL)
    return (NULL);
  i = 0;
  while (options[i] != '\0')
    {
      if (!(options[i] == base[0] || options[i] == base[1]
	    || options[i] == base[2] || options[i] == base[3] ||
	    options[i] == base[4] ||options[i] == base[5]))
	{
	  my_printf("ls: invalid option -- %c\n", options[i]);
	  exit(EXIT_FAILURE);
	}
      i++;
    }
  return (options);
}

char	*del_x_options(char *options)
{
  int	i;
  int	j;
  char	first_option;

  if (options == NULL)
    return (NULL);
  i = 0;
  first_option = options[0];
  while (i < my_strlen(options))
    {
      while (options[i + 1] == first_option)
	{
	  j = i;
	  while (options[j + 1] != '\0')
	    {
	      options[j] = options[j + 1];
	      j++;
	    }
	  options[j] = '\0';
	}
      i++;
      first_option = options[i];
    }
  options = check_base(options);
  return (options);
}

char	*get_options(int ac, char **av)
{
  int	tab[2];
  char	*options;

  init_var(tab);
  if (ac == 1)
    {
      options = malloc(2 * sizeof(char));
      if (options == NULL)
        return (NULL);
      options[0] = '\0';
    }
  else
    {
      options = malloc((4) * sizeof(char));
      if (options == NULL)
	return (NULL);
      options[3] == '\0';
      while (tab[0] < ac)
	{
	  if (av[tab[0]][0] == '-')
	    del_red(options, &tab[1], &av[tab[0]][1]);
	  tab[0]++;
	}
    }
  return (options);
}

char	**get_args(int ac, char **av)
{
  int	i;
  int	j;
  char	**arguments;

  i = 1;
  j = 0;
  arguments = malloc(ac * sizeof(char *));
  if (arguments == NULL)
    return (NULL);
  while (i < ac)
    {
      if (av[i][0] != '-')
	{
	  arguments[j] = my_strdup(av[i]);
	  j++;
	}
      i++;
    }
  if (j == 0)
    {
      arguments[0] = my_strdup("./");
      j++;
    }
  arguments[j] = '\0';
  return (arguments);
}

void	get_options_and_args(int ac, char **av, char **options, char ***args)
{
  *options = del_x_options(get_options(ac, av));
  *args = get_args(ac, av);
}
