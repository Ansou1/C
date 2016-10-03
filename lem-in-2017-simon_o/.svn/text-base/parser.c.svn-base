/*
** parser.c for lem_in in /home/corrad_f//projet/lem-in
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Mon Apr  1 14:31:16 2013 florian corradin
** Last update Sun Apr 28 18:36:47 2013 simon daguenet
*/

#include "lemin.h"

char	is_nbr_ant(char *str)
{
  while (*str)
    if (!is_digit(*str))
      return (0);
  return (1);
}

char	is_room(char *str)
{
  int	ctr;

  ctr = 0;
  while (*str && *str != '#')
    if (*str++ == ' ')
      ctr++;
  if (ctr == 2)
    return (1);
  return (0);
}

t_room		*get_info(char *str, int ant)
{
  int		type;
  static char	enter = 0;
  int		n_ant;

  n_ant = 0;
  if (my_strncmp("##start", str, 7) == 1)
    {
      enter += 10;
      type = START;
      n_ant = ant;
    }
  else if (my_strncmp("##end", str, 5) == 1)
    {
      enter++;
      type = END;
    }
  else
      type = ROOM;
  enter = ((enter > 11) ? my_puterror(FILE) : enter);
  if (my_strncmp("##start", str, 7) == 1 || my_strncmp("##end", str, 5) == 1)
  while (*str != ' ' && *str != '\0')
    *str++;
  if (*str == ' ')
    *str++;
  return (creat_maill(get_name(str), n_ant, type));
}

t_room		*creat_maill(char *name, int ant, int type)
{
  t_room	*ret;

  ret = xmalloc(sizeof (*ret));
  ret->name = name;
  ret->ant = ant;
  ret->type = type;
  ret->n1 = 0;
  ret->n2 = 0;
  ret->tab = xmalloc(sizeof (t_room *));
  ret->tab[0] = NULL;
  if (ret->type == END)
    ret->p = 0;
  else
    ret->p = -1;
  return (ret);
}

t_room		**parser_str(char **file, int size)
{
  t_room	**ret;
  int		i;
  char		*get;
  int		ctr;

  i = 1;
  ctr = 0;
  ret = xmalloc(sizeof (*ret) * (size + 1));
  while (file[i] != NULL)
    {
      if (my_strncmp("##end", file[i], 5) == 1 ||
	  my_strncmp("##start", file[i], 7) == 1)
	{
	  get = my_strcat_lem(file[i], file[i + 1]);
	  ret[ctr++] = get_info(get, my_atoi(file[0]));
	  i += 2;
	  free(get);
	}
      else if (is_room(file[i]))
	ret[ctr++] = get_info(file[i++], my_atoi(file[0]));
      else
      i++;
    }
  ret[ctr] = NULL;
  return (ret);
}
