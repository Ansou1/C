/*
** shadow.c for raytracer in /home/cheval_y//raytracer
**
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
**
** Started on  Thu Apr 18 01:16:00 2013 franck chevallier
** Last update Sat Jun  8 13:24:00 2013 antoine simon
*/

#include "raytracer.h"

int		shadow(t_mlx *mlx, t_coord *light, t_object *select_object)
{
  t_object	*tmp;
  t_coord	intersection;

  tmp = mlx->list;
  intersection = select_object->result->intersection;
  while (mlx->list != NULL)
    {
      if (OBJECT != select_object)
	{
	  if (OBJECT->intersection(mlx, (*light), intersection) == 0
	      &&OBJECT->result->k1 > 0.0 &&  OBJECT->result->k1 < 1.0)
	    {
	      mlx->list = tmp;
	      select_object->result->intersection = intersection;
	      return (0);
	    }
	}
      mlx->list = OBJECT->next;
    }
  mlx->list = tmp;
  return (1);
}
