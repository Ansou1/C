/*
** find_intersection.c for raytracer in /home/racaud_j/Documents/Work/svn/raytracer-2017-simon_o/rt
**
** Made by jonathan racaud
** Login   <racaud_j@epitech.net>
**
** Started on  Sat Jun  8 14:32:11 2013 jonathan racaud
** Last update Sun Jun  9 13:40:58 2013 jonathan racaud
*/

#include "raytracer.h"

int		flou(t_mlx *mlx, t_object *select_object, int type)
{
  int		i;
  int		*new;
  t_coord	save;

  i = 0;
  if ((new = malloc(sizeof(int) * 100 * 2)) == NULL)
    return (-1);
  while (i < 100)
    {
      save.x = mlx->light->pos_light.x;
      save.y = mlx->light->pos_light.y;
      save.z = mlx->light->pos_light.z;
      mlx->light->pos_light.x += (get_rand(-300, 300));
      mlx->light->pos_light.y += (get_rand(-300, 300));
      mlx->light->pos_light.z += (get_rand(-300, 300));
      new[i] = light(type, select_object, mlx);
      i++;
      mlx->light->pos_light.x = save.x;
      mlx->light->pos_light.y = save.y;
      mlx->light->pos_light.z = save.z;
    }
  return (good_color(new, 10, mlx));
}

int		get_color_inter(t_object *select_object, t_mlx *mlx, int type)
{
  int		color;

  color = 0;
  if (select_object != NULL)
    {
      color = light(type, select_object, mlx);
      if (mlx->blur != 0)
      	color = flou(mlx, select_object, type);
      return (color);
    }
  else
    return (0x000000);
}

int		find_intersection(t_mlx *mlx, t_coord vector, t_coord from)
{
  t_object	*select_object;
  t_object	*tmp;
  int		type;
  int		color;

  type = 0;
  color = 0;
  tmp = mlx->list;
  mlx->k = 10;
  select_object = NULL;
  while (mlx->list != NULL)
    {
      if (OBJECT != NULL && OBJECT->intersection(mlx, vector, from) == 0 &&
       OBJECT->result->k1 < mlx->k && OBJECT->result->k1 > 0.f)
  	{
	  type = DEF_TYPE;
  	  select_object = OBJECT;
	  mlx->k = OBJECT->result->k1;
  	}
      mlx->list = OBJECT->next;
    }
  mlx->list = tmp;
  color = get_color_inter(select_object, mlx, type);
  return (color);
}

