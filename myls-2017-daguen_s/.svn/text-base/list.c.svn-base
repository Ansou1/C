/*
** list.c for ls in /home/daguen_s//ls/my_ls
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Wed Nov 28 10:59:32 2012 simon daguenet
** Last update Sat Dec  1 21:54:02 2012 simon daguenet
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

void	del_red(char *options, int *j, char *str)
{
  int	i;
  char	base;

  i = 0;
  while (str[i] != '\0')
    {
      base = str[i];
      if (my_strstr(options, &base) == 0)
        {
          options[*j] = str[i];
          (*j)++;
        }
      i++;
    }
}

int	check_options(char *options, int nbr, char **tab)
{
  char	*result;
  char	*result1;

  if ((result = strstr(options, "r")) != 0)
    sort_in_tab_reverse(tab, nbr);
  if (((result = strstr(options, "l")) == 0) &&
      ((result1 = strstr(options, "t")) == 0))
    display_without_options(tab);
  if (((result = strstr(options, "l")) != 0) &&
      ((result1 = strstr(options, "t")) == 0))
    display_opt(tab, nbr);
}

void	display_opt(char **tab, int nbr)
{
  struct stat	sb;
  int	i;

  i = 0;
  while (i < nbr)
    {
      if (stat(tab[i], &sb) == -1)
	{
	  my_printf("ERROR : stat problem \n");
	  exit (EXIT_FAILURE);
	}
      display_rights(sb);
      display_data(sb);
      my_printf("%s\n" , tab[i]);
      i++;
    }
  freetab(tab, nbr);
}

void	display_with_option(char *path, char *options)
{
  int	nbr;
  char	**tab;

  nbr = count_nbr_name(path);
  tab = malloc(sizeof(*tab) * (nbr));
  if (tab == NULL)
    exit (EXIT_FAILURE);
  tab = pick_up_name(path, tab);
  sort_in_tab(tab, (nbr - 2));
  if (options[0] == '\0')
    display_without_options(tab);
  else
      check_options(options, (nbr - 2), tab);
}

void	display_list(char *options, char **args)
{
  int	i;
  char	*result;

  i = 0;
  while (args[i] != '\0')
    {
      if ((result = my_strstr(options, "d")) != 0)
	display_with_option_d(args[i], options);
      else
	display_with_option(args[i], options);
      i++;
    }
}
