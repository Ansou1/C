/*
** link.c for lemçin in /home/corrad_f//projet/lem-in
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Tue Apr  2 14:34:22 2013 florian corradin
** Last update Sun Apr 28 18:34:05 2013 simon daguenet
*/

#include "lemin.h"

char	is_link(char *str)
{
  while (*str)
    {
      if (*str++ == '-')
	return (1);
    }
  return (0);
}

t_room	**get_the_link(t_room **tab, char **file)
{
  int	i;

  i = 0;
  while (file[i] != NULL)
    {
      if (is_link(file[i]))
	tab = change_add(tab, file[i]);
      i++;
    }
  return (tab);
}

char	*get_name2(char *line)
{
  int	i;
  char	*ret;

  i = 0;
  while (line[i] != '-' && line[i] != '\0')
    i++;
  ret = xmalloc(i + 1);
  i = 0;
  while (line[i] != '\0' && line[i] != '-')
    {
      ret[i] = line[i];
      i++;
    }
  ret[i] = '\0';
  return (ret);
}

t_room		**change_add(t_room **tab, char *file)
{
  t_name	name;
  t_room	*add1;
  t_room	*add2;
  int		i;

  i = 0;
  name.name1 = get_name2(file);
  add1 = get_address(tab, name.name1);
  while (file[i] != '-' && file[i] != '\0')
    i++;
  if (file[i] == '-')
    i++;
  name.name2 = get_name2(&file[i]);
  add2 = get_address(tab, name.name2);
  tab = modif_tab(name, add1, add2, tab);
  return (tab);
}

t_room		*get_address(t_room **tab, char *name)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (my_str_comp(name, tab[i]->name))
	return (tab[i]);
      i++;
    }
  my_puterror("\033[1;31mInvalid name of room\033[0;m\n");
  return (NULL);
}
