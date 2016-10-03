/*
** elem_threads.c for elem_threads in /home/efilon/eretay/raytracer-2017-simon_o/rt/sources/xml
** 
** Made by efilon
** Login   <efilon@Heisenbergs-RV>
** 
** Started on  Fri Jun  7 02:13:44 2013 efilon
** Last update Sun Jun  9 01:21:42 2013 efilon
*/

#include <unistd.h>
#include "raytracer.h"

int	add_threads(t_mlx *rt, char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (!my_strncmp_case(tab[i], "threads=", 8))
	rt->nb_threads = atoi(tab[i] + 9);
      i++;
    }
  rt->nb_threads = MAX(0, MIN(15, rt->nb_threads));
  return (1);
}
