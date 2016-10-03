/*
** lemin.c for lemin in /home/daguen_s//my_lemin
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Apr  1 14:43:54 2013 simon daguenet
** Last update Sun Apr 28 22:55:27 2013 simon daguenet
*/

#include "lemin.h"

void	check_file(char **file, int size)
{
  int	i;

  i = 0;
  while (file[i])
    {
      if (i < (size -1))
	{
	  if (file[i][0] == '#' && file[i + 1][0] == '#')
	    my_puterror("\033[1;31mInvalid file.\033[0;m\n");
	}
      i++;
    }
}

char	*my_strstr_tube(char *str, char *to_find)
{
  int	i;
  int	j;

  i = 0;
  while (i < my_strlen(str))
    {
      j = 0;
      while (str[i + j] == to_find[j] && j < my_strlen(to_find))
	j++;
      if (j == my_strlen(to_find))
	return (&str[i]);
      i++;
    }
  return (0);
}

void	check_tube(char **file, int size)
{
  int	i;
  int	tube;

  i = 0;
  tube = 0;
  while (file[i])
    {
      if (my_strstr_tube(file[i], " ") == NULL)
	if (my_strstr_tube(file[i], "-") != NULL)
	  tube++;
      i++;
    }
  if (tube == 0)
    my_puterror("\033[1;31mInvalid file.\033[0;m\n");
}

int		main()
{
  t_room	**tab;
  char		**file;
  int		size;
  int		i;

  i = 0;
  file = get_file_lemin();
  size = get_nbr_room(file);
  check_file(file, size);
  check_tube(file, size);
  tab = parser_str(file, size);
  tab = get_the_link(tab, file);
  tab = water_fill(tab);
  dell_one_direction_way(tab);
  del_crossing_way(tab);
  dell_one_direction_way(tab);
  while (tab[i]->type != START)
    i++;
  moov_ant(tab[i]);
  my_free_tab(file);
  return (EXIT_SUCCESS);
}
