/*
** get_file.c for lemin in /home/daguen_s//my_lemin
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Apr  1 17:27:26 2013 simon daguenet
** Last update Sun Apr 28 19:58:22 2013 simon daguenet
*/

#include "lemin.h"

int	count_space(char *str)
{
  int	nbr;
  int	i;

  nbr = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
	nbr++;
      i++;
    }
  return (nbr);
}

char	**realloc_tab(char **tab, char *str)
{
  int	i;
  char	**ret;

  i = 0;
  if (tab != NULL)
    while (tab[i])
      i++;
  ret = xmalloc(sizeof (char *) * (i + 2));
  i = 0;
  if (tab == NULL)
    {
      ret[0] = str;
      ret[1] = NULL;
      return (ret);
    }
  while (tab[i])
    {
      ret[i] = tab[i];
      i++;
    }
  ret[i] = str;
  ret[i + 1] = NULL;
  return (ret);
}

char	**get_file_lemin()
{
  char	**file;
  char	*s;
  int	door;

  s = NULL;
  file = NULL;
  door = 0;
  while ((s = get_next_line(0)) != NULL)
    {
      if (s[0] != '#' || (my_strstr(s, "##start") != NULL)
	  || (my_strstr(s, "##end")) != NULL)
	{
	  s = my_epurstr(s);
	  door = check_door(s, door);
	  file = realloc_tab(file, s);
	  my_putstr(s);
	  my_putchar('\n');
	}
    }
  result_door(door);
  return (file);
}

int	get_nbr_room(char **file)
{
  int	size;
  int	i;

  size = 0;
  i = 0;
  if (my_atoi(file[0]) <= 0)
    {
      my_free_tab(file);
      my_puterror("\033[1;31mInvalid number of ants\033[0;m\n");
    }
  while (file[i])
    {
      if (count_space(file[i]) == 2)
	size++;
      i++;
    }
  if (size <= 0)
    my_puterror("\033[1;31mInvalid File\033[0;m\n");
  return (size);
}
