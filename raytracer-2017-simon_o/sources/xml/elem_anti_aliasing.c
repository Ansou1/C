/*
** elem_aaliasing.c for elem_aaliasing in /home/efilon/raytracer-2017-simon_o
** 
** Made by efilon
** Login   <efilon@Heisenbergs-RV>
** 
** Started on  Thu May 16 16:08:16 2013 efilon
** Last update Fri Jun  7 01:45:47 2013 efilon
*/

#include <unistd.h>
#include "raytracer.h"

int	add_anti_aliasing(t_mlx *rt, char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (!my_strncmp_case(tab[i], "antialiasing=", 13))
	rt->anti_aliasing = atoi(tab[i] + 14);
      i++;
    }
  return (1);
}
