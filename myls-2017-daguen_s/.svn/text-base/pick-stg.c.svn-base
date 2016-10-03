/*
** pick-stg.c for ls in /home/daguen_s//ls/my_ls
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Fri Nov 30 16:54:42 2012 simon daguenet
** Last update Fri Nov 30 21:13:29 2012 simon daguenet
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

int	count_nbr_name(char *path)
{
  DIR	*dirp;
  struct dirent	*entry;
  int	i;
  int	nbr;

  nbr = 0;
  if ((dirp = opendir(path)) == NULL)
    {
      my_printf("ERROR : opendir problem \n");
      exit (EXIT_FAILURE);
    }
  while ((entry = readdir(dirp)) != NULL)
    nbr++;
  if ((i = closedir(dirp)) == -1)
    {
      my_printf("ERROR : closedir problem \n");
      exit (EXIT_FAILURE);
    }
  return (nbr);
}

char	**pick_up_name(char *path, char **tab)
{
  DIR	*dirp;
  struct dirent	*entry;
  int	i;

  i = 0;
  if ((dirp = opendir(path)) == NULL)
    {
      my_printf("ERROR : opendir problem \n");
      exit (EXIT_FAILURE);
    }
  while ((entry = readdir(dirp)) != NULL)
    {
      if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
	{
	  tab[i] = my_strdup(entry->d_name);
	  i++;
	}
    }
  tab[i] = NULL;
  if ((i = closedir(dirp)) == -1)
    {
      my_printf("ERROR : closedir problem \n");
      exit (EXIT_FAILURE);
    }
  return (tab);
}

void	sort_in_tab(char **tab, int taille)
{
  char	*tmp;
  int	i;
  int	j;

  i = 0;
  while (i < taille)
    {
      j = 0;
      while (j < taille)
	{
	  if (strcmp(tab[i], tab[j]) < 0)
	    {
	      tmp = tab[i];
	      tab[i] = tab[j];
	      tab[j] = tmp;
	    }
	  j++;
	}
      i++;
    }
}

void	sort_in_tab_reverse(char **tab, int taille)
{
  char	*tmp;
  int	i;
  int	j;

  i = 0;
  while (i < taille)
    {
      j = 0;
      while (j < taille)
	{
	  if (strcmp(tab[i], tab[j]) > 0)
	    {
	      tmp = tab[i];
	      tab[i] = tab[j];
	      tab[j] = tmp;
	    }
	  j++;
	}
      i++;
    }
}

void	freetab(char **tab, int line)
{
  int	i;

  i = 0;
  while (i < line)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}
