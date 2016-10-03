/*
** elem_spec.c for elem_spec in /home/efilon/WORKSPACERT/raytracer-2017-simon_o/rt
** 
** Made by efilon
** Login   <efilon@Heisenbergs-RV>
** 
** Started on  Sat Jun  8 23:11:53 2013 efilon
** Last update Sun Jun  9 14:57:03 2013 efilon
*/

#include <unistd.h>
#include "raytracer.h"

int		add_spec_cube(t_mlx *mlx, char **tab)
{
  t_object	*tmp;
  int		i;
  int		j;

  i = 0;
  tmp = OBJECT;
  while (tmp != NULL && i < 6)
    {
      j = 0;
      while (tab[j] != NULL)
	{
	  if (!my_strncmp_case(tab[j], "matiere=", 8))
	    tmp->material = atof(tab[j] + 9);
	  else if (!my_strncmp_case(tab[j], "intensitee=", 11))
	    tmp->spec_int = atof(tab[j] + 12);
	  j++;
	}
      i++;
      tmp = tmp->next;
    }
  return (1);
}

int	add_spec(t_mlx *rt, char **tab)
{
  int	i;

  i = 0;
  if (rt->xml->state == STATE_CUBE)
    return (add_spec_cube(rt, tab));
  while (tab[i] != NULL)
    {
      if (!my_strncmp_case(tab[i], "matiere=", 8))
        ((t_object*)(rt->list))->material = atof(tab[i] + 9);
      else if (!my_strncmp_case(tab[i], "intensitee=", 11))
        ((t_object*)(rt->list))->spec_int = atof(tab[i] + 12);
      i++;
    }
  rt->nb_threads = MAX(0, MIN(15, rt->nb_threads));
  return (1);
}
