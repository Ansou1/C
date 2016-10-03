/*
** my_link.c for lemin in /home/daguen_s//my_lemin
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Tue Apr  2 14:54:31 2013 simon daguenet
** Last update Thu Apr 25 14:19:51 2013 simon daguenet
*/

#include "lemin.h"

int	my_str_comp(char *s1, char *s2)
{
  while (*s1 && *s2)
    {
      if (*s1 != *s2)
	return (0);
      *s1++;
      *s2++;
    }
  if (*s1 != *s2)
    return (0);
  return (1);
}

t_room		*my_add_link(t_room *mail, t_room *add)
{
  int		i;
  t_room	**rep;

  i = 0;
  while (mail->tab[i] != NULL)
    i++;
  rep = xmalloc(sizeof (*rep) * (i + 2));
  i = 0;
  while (mail->tab[i] != NULL)
    {
      rep[i] = mail->tab[i];
      i++;
    }
  rep[i] = add;
  rep[i + 1] = NULL;
  free(mail->tab);
  mail->tab = rep;
  return (mail);
}

t_room	**modif_tab(t_name name, t_room *a1, t_room *a2, t_room ** tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (my_str_comp(name.name1, tab[i]->name))
	tab[i] = my_add_link(tab[i], a2);
      else if (my_str_comp(name.name2, tab[i]->name))
	tab[i] = my_add_link(tab[i], a1);
      i++;
    }
  return (tab);
}
