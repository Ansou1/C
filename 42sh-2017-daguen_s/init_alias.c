/*
** init_alias.c for  in /home/corrad_f//projet/infect
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Wed May  8 14:08:56 2013 florian corradin
** Last update Thu May 23 14:15:09 2013 simon daguenet
*/

#include "42.h"

void		my_put_alias()
{
  t_alias	*tmp;

  tmp = g_alias;
  while (tmp != NULL)
    {
      printf("%s\t%s\n", tmp->alias, tmp->com);
      tmp = tmp->next;
    }
}

void	init_alias(int ac, char **av)
{
  char	**com;

  g_alias = NULL;
  com = malloc(sizeof (char *) * 3);
  if (com != NULL)
    {
      com[0] = my_strdup("./.infectshrc.sh");
      com[1] = NULL;
      if (ac > 1)
	com[1] = my_strdup(av[1]);
      com[2] = NULL;
      my_script(com);
      my_free_tab(com);
    }
}
