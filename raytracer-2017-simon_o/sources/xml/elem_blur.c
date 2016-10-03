/*
** elem_blur.c for elem_blur in /home/efilon/raytracer-2017-simon_o/rt/sources
** 
** Made by efilon
** Login   <efilon@Heisenbergs-RV>
** 
** Started on  Thu Jun  6 10:55:28 2013 efilon
** Last update Fri Jun  7 01:51:31 2013 efilon
*/

#include <unistd.h>
#include "raytracer.h"

int	add_blur(t_mlx *rt, char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (!my_strncmp_case(tab[i], "flou=", 5))
	{
	  if (!my_strncmp_case(tab[i] + 6, "actif\"", 6))
	    rt->blur = 1;
	  else if (!my_strncmp_case(tab[i] + 6, "inactif\"", 8))
	    rt->blur = 0;
	}
      i++;
    }
  return (1);
}
