/*
** rush.c for rush in /home/daguen_s//Rush
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Dec  1 09:17:06 2012 simon daguenet
** Last update Sat Dec  1 15:02:30 2012 simon torradou
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

char    *my_strdup(char *src);
char    *my_strcat1(char *dest, char *src);

char	**get_tab(char **tab, char *argv)
{
  int	fd = open(argv, O_RDONLY);
  char	*s = NULL;
  char	*c = NULL;
  int	i = 0;
  int	valeur;
 
  if (fd != -1)
    s = get_next_line(fd);
  valeur = my_getnbr(s);
  tab = malloc(sizeof(*tab) * (valeur + 1));
  if (fd != -1)
    {
      i = 0;
      while (c = get_next_line(fd))
	{
	  tab[i] = my_strdup(c);
	  i++;
	}
      tab[i] = NULL;
    }
  return (tab);
}
void	put_tab(char **str)
{
  int	i;
  
  i = 0;
  while (str[i])
    {
      my_putstr(str[i]);
      my_putchar(10);
      i++;
    }
}

int	tab_len(char **str)
{
  int	i;

  i = 0;
  while (str[i] != NULL)
    i++;
  return (i);
}
void	ftab(char **tab, char **tab2)
{
  int	i,j;
  int	max = 0;
  int	min = 0;
  char	*chaine;
  char	**ret;

  max = tab_len(tab);
  min = tab_len(tab2);
  ret = malloc(max * sizeof(ret)+1);
  j = 0;
  i = 0;
  while (i < max)
    {
      while (j < min)
  	{
  	  ret[i] = my_strcat1(tab[j], "_");
  	  ret[i] = my_strcat1(ret[i], tab2[j]);
  	  j++;
  	  i++;
  	}
      ret[i] = my_strcat1(tab[i],"\0");
      i++;
    }  
  ret[i] = NULL;
  put_tab(ret);
}

void	ftab2(char **tab, char **tab2)
{
  int	i,j;
  int	max = 0;
  int	min = 0;
  char	*chaine;
  char	**ret;

  i = 0;
  j = 0;
  max = tab_len(tab);
  min = tab_len(tab2);
  ret = malloc(max * sizeof(ret)+1);
  while (i < max)
    {
      while (j < min)
  	{
  	  ret[i] = my_strcat1(tab2[j], "_");
  	  ret[i] = my_strcat1(ret[i], tab[j]);
	  j++;
  	  i++;
  	}
      ret[i] = my_strcat1(tab[i],"\0");
      i++;
    }
  ret[i] = NULL;
  put_tab(ret);
}

int	main(int argc, char **argv)
{
  char	**tab;
  char	**tab2;
  int	i,j;
  int	max = 0;
  int	min = 0;
  char	*chaine;

  tab = get_tab(tab, argv[1]);
  tab2 = get_tab(tab2, argv[2]);
  if (tab_len(tab) > tab_len(tab2))
    {
      ftab(tab,tab2);
    }
  else
    {
      ftab2(tab2,tab);
    }
  return (0);
}
