/*
** elem_window.c for elem_window in /home/efilon/raytracer-2017-simon_o/sources/xml
** 
** Made by efilon
** Login   <efilon@Heisenbergs-RV>
** 
** Started on  Tue May 21 09:23:52 2013 efilon
** Last update Fri Jun  7 02:08:34 2013 efilon
*/

#include <unistd.h>
#include "raytracer.h"

int	add_window(t_mlx *rt, char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (!my_strncmp_case(tab[i], "largeur=", 8))
	rt->width = atoi(tab[i] + 9);
      else if (!my_strncmp_case(tab[i], "hauteur=", 8))
	rt->height = atoi(tab[i] + 9);
      i++;
    }
  return (1);
}
