/*
** fct_pars.c for corewar in /home/corrad_f//projet/champion/commande
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sat Jan 26 16:02:03 2013 florian corradin
** Last update Fri Mar 29 14:08:35 2013 simon daguenet
*/

#include "asm.h"

char	*mal_tab()
{
  char	*ret;
  int	i;

  i = 0;
  ret = malloc(SIZE_MAX + 1);
  ret[SIZE_MAX] = '\0';
  check_malloc(ret);
  while (i < SIZE_MAX)
    {
      ret[i] = '0';
      i++;
    }
  return (ret);
}

/* size: nombre de ligne du binaire */
char	**init_bin(int size)
{
  int	i;
  char	**ret;

  ret = malloc(sizeof (char *) * (size + 1));
  check_malloc(ret);
  ret[size] = NULL;
  i = 0;
  while (i < size)
    {
      ret[i] = mal_tab();
      i++;
    }
  return (ret);
}

int		my_put_in_list(t_list **list)
{
  t_list	*elem;

  elem = malloc(sizeof(*elem));
  check_malloc(elem);
  elem->x1 = 0;
  elem->next = *list;
  *list = elem;
  return (0);
}

/* size: nb de ligne du binaire */
t_list		*my_params_in_list(int size)
{
  t_list	*list;
  int		i;

  i = 0;
  list = NULL;
  while (i < size)
    {
      my_put_in_list(&list);
      i = i + 1;
    }
  return (list);
}
