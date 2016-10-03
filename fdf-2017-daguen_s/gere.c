/*
** gere.c for fdf in /home/daguen_s//Ighaph/fdf
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Fri Dec  7 09:46:53 2012 simon daguenet
** Last update Fri Dec  7 18:09:58 2012 simon daguenet
*/

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include "my_fdf.h"

int	gere_key(int touche)
{
  if (touche == 65307)
    exit(0);
}

int	gere_expose(t_element *param)
{
  mlx_put_image_to_window(param->mlx_ptr,
			  param->win_ptr, param->img, 0, 0);
}

int	abs(int x)
{
  if (x < 0)
    return (-1 * x);
  else
    return (x);
}

void	free_tab(char ***tab, int line)
{
  int	i;
  int	j;

  j = 0;
  while (j < line)
    {
      i = 0;
      while (i < line)
	{
	  free(tab[j][i]);
	  i++;
	}
      j++;
    }
  free(tab);
}
