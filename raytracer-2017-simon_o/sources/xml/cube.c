/*
** cube.c for cube in /tmp/RT/raytracer-2017-simon_o/rt
** 
** Made by efilon
** Login   <efilon@Heisenbergs-RV>
** 
** Started on  Sat Jun  8 13:17:26 2013 efilon
** Last update Sun Jun  9 15:10:44 2013 jonathan racaud
*/

#include "raytracer.h"
#include "xml.h"

t_composed_obj	g_cube[6] =
  {
    {0, 0, -CUBESIZE, 0, 0, 0},
    {0, 0, CUBESIZE, 0, 0, 0},
    {0, CUBESIZE, 0, -90, 0, 0},
    {0, -CUBESIZE, 0, 90, 0, 0},
    {-CUBESIZE, 0, 0, 0, -90, 0},
    {CUBESIZE, 0, 0, 0, 90, 0},
  };

void		change_elem_cube(t_object *obj, int type_modif, int new_val)
{
  t_object	*tmp;
  int		i;

  i = 0;
  tmp = obj;
  while (tmp != NULL && i < 6)
    {
      if (type_modif == 1)
	tmp->x = CUBE_X;
      else if (type_modif == 2)
	tmp->y = CUBE_Y;
      else if (type_modif == 3)
	tmp->z = CUBE_Z;
      else if (type_modif == 4)
	tmp->color = new_val;
      else if (type_modif == 5)
	tmp->damier = new_val;
      else if (type_modif == 6)
	{
	  tmp->width_limit = new_val * 2;
	  tmp->length_limit = new_val * 2;
	}
      i++;
      tmp = tmp->next;
    }
}

int	change_size_cube(t_object *obj, char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (!my_strncmp_case(tab[i], "rayon=", 6) && atoi(tab[i] + 7) > 0)
	{
	  change_elem_cube(obj, 6, atoi(tab[i] + 7));
	  change_elem_cube(obj, 1, obj->x);
	  change_elem_cube(obj, 2, obj->y);
	  change_elem_cube(obj, 3, obj->next->next->z);
	}
      i++;
    }
  return (1);
}

int	add_position_cube(t_object *obj, char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (!my_strncmp_case(tab[i], "x=", 2))
	change_elem_cube(obj, 1, atoi(tab[i] + 3));
      else if (!my_strncmp_case(tab[i], "y=", 2))
	change_elem_cube(obj, 2, atoi(tab[i] + 3));
      else if (!my_strncmp_case(tab[i], "z=", 2))
	change_elem_cube(obj, 3, atoi(tab[i] + 3));
      i++;
    }
  return (1);
}

int	add_color_cube(t_object *obj, char **tab)
{
  int	i;
  char	*end;

  i = 0;
  end = NULL;
  while (tab[i] != NULL)
    {
      if (!my_strncmp_case(tab[i], "couleur=", 8))
	change_elem_cube(obj, 4, get_color(tab[i] + 9));
      else if (!my_strncmp_case(tab[i], "damier=", 7))
	change_elem_cube(obj, 5, get_color(tab[i] + 8));
      i++;
    }
  end = end;
  return (1);
}

int	add_empty_cube(t_mlx *mlx)
{
  int	i;

  i = 0;
  while (i < 6)
    {
      add_empty_obj(mlx, 4);
      OBJECT->width_limit = CUBESIZE * 2;
      OBJECT->length_limit = CUBESIZE * 2;
      OBJECT->x = g_cube[i].x;
      OBJECT->y = g_cube[i].y;
      OBJECT->z = g_cube[i].z;
      OBJECT->r_x = g_cube[i].r_x;
      OBJECT->r_y = g_cube[i].r_y;
      OBJECT->r_z = g_cube[i].r_z;
      i++;
    }
  return (1);
}
