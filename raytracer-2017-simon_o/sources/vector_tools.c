/*
** vector_tools.c for raytracer in /home/racaud_j/Documents/Work/svn/raytracer-2017-simon_o/rt
**
** Made by jonathan racaud
** Login   <racaud_j@epitech.net>
**
** Started on  Sun Jun  9 12:32:43 2013 jonathan racaud
** Last update Sun Jun  9 12:42:00 2013 jonathan racaud
*/

#include "raytracer.h"

int		check_cos(t_mlx *mlx, int *new_color, double cos_a,
			  t_object *select_object)
{
  int		color;

  color = 0;
  if (cos_a >= 0.0)
    {
      if (select_object->damier != -1)
      	{
      	  color = change_color(select_object->color, cos_a, select_object,
			       mlx);
      	  color = get_checker(select_object->result->intersection,
			      color, cos_a, select_object, mlx);
      	  (*new_color) = add_color2((*new_color), color);
      	}
      else
	(*new_color) = add_color2((*new_color),
				  change_color(select_object->color,
					       cos_a, select_object, mlx));
    }
  else
    (*new_color) = add_color2((*new_color), 0);
  return (*new_color);
}

void		unitarise(t_coord *v)
{
  double	norm;

  norm = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
  if (norm == 0)
    return ;
  v->x /= norm;
  v->y /= norm;
  v->z /= norm;
}

double		get_scalaire(t_coord *v1, t_coord *v2)
{
  double	scalaire;

  unitarise(v1);
  unitarise(v2);
  scalaire = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
  return (scalaire);
}

int		get_checker(t_coord intersection, int color, double cos_a,
			    t_object *select_object, t_mlx *mlx)
{
  double	xfloor;
  double	yfloor;
  int		x;
  int		y;

  xfloor = intersection.x / 200.0;
  yfloor = intersection.y / 50.0;
  x = (int)floor(xfloor);
  y = (int)floor(yfloor);
  if (y % 2 == 0)
    {
      if (x % 2 == 0)
	return (color);
      else
	return (change_color(select_object->damier, cos_a, select_object, mlx));
    }
  else
    {
      if (x % 2 == 0)
	return (change_color(select_object->damier, cos_a, select_object, mlx));
      else
	return (color);
    }
  return (0);
}

