/*
** multi_thread_cpy_fcts.c for raytracer in /home/racaud_j/Documents/Work/svn/raytracer-2017-simon_o/rt
**
** Made by jonathan racaud
** Login   <racaud_j@epitech.net>
**
** Started on  Fri Jun  7 21:50:44 2013 jonathan racaud
** Last update Sun Jun  9 13:28:09 2013 jonathan racaud
*/

#include "raytracer.h"

void	continue_copy_list_obj(t_object *tmp, t_object *cpy)
{
  cpy->def_object = tmp->def_object;
  cpy->damier = tmp->damier;
  cpy->intersection = tmp->intersection;
  cpy->bump.x = tmp->bump.x;
  cpy->bump.y = tmp->bump.y;
  cpy->bump.z = tmp->bump.z;
  cpy->width_limit = tmp->width_limit;
  cpy->length_limit = tmp->length_limit;
  cpy->x = tmp->x;
  cpy->y = tmp->y;
  cpy->z = tmp->z;
  cpy->r_x = tmp->r_x;
  cpy->r_y = tmp->r_y;
  cpy->r_z = tmp->r_z;
  cpy->radius = tmp->radius;
  cpy->color = tmp->color;
  cpy->material = tmp->material;
  cpy->spec_int = tmp->spec_int;
}

void		copy_list_obj(t_mlx *new, t_mlx *val)
{
  t_object	*tmp;
  t_object	*cpy;

  tmp = val->list;
  while (tmp)
    {
      cpy = my_malloc(sizeof(t_object));
      cpy->result = my_malloc(sizeof(t_result));
      cpy->result->k = tmp->result->k;
      cpy->result->k1 = tmp->result->k1;
      cpy->result->k2 = tmp->result->k2;
      cpy->result->intersection.x = tmp->result->intersection.x;
      cpy->result->intersection.y = tmp->result->intersection.y;
      cpy->result->intersection.z = tmp->result->intersection.z;
      cpy->result->normal.x = tmp->result->normal.x;
      cpy->result->normal.y = tmp->result->normal.y;
      cpy->result->normal.z = tmp->result->normal.z;
      cpy->brightness = tmp->brightness;
      cpy->intersection = tmp->intersection;
      continue_copy_list_obj(tmp, cpy);
      cpy->next = new->list;
      new->list = cpy;
      tmp = tmp->next;
    }
}

void	copy_list_light(t_mlx *new, t_mlx *val)
{
  t_light	*tmp;
  t_light	*cpy;

  tmp = val->light;
  while (tmp)
    {
      cpy = my_malloc(sizeof(t_light));
      cpy->pos_light = tmp->pos_light;
      cpy->color = tmp->color;
      cpy->next = new->light;
      new->light = cpy;
      tmp = tmp->next;
    }
}

void	copy_eye(t_mlx *val, t_mlx *new)
{
  new->eye->r_x = val->eye->r_x;
  new->eye->r_y = val->eye->r_y;
  new->eye->r_z = val->eye->r_z;
  new->eye->eye_pos.x = val->eye->eye_pos.x;
  new->eye->eye_pos.y = val->eye->eye_pos.y;
  new->eye->eye_pos.z = val->eye->eye_pos.z;
  new->eye->v_eye.x = val->eye->v_eye.x;
  new->eye->v_eye.y = val->eye->v_eye.y;
  new->eye->v_eye.z = val->eye->v_eye.z;
}

t_mlx		*copy_struct_all(t_mlx *val, t_mlx *new)
{
  new = my_malloc(sizeof(t_mlx));
  new->eye = my_malloc(sizeof(t_eye));
  new->width = val->width;
  new->height = val->height;
  new->anti_aliasing = val->anti_aliasing;
  new->win_created = val->win_created;
  new->xml_error = val->xml_error;
  new->blur = val->blur;
  new->nb_threads = val->nb_threads;
  new->filter = val->filter;
  new->image = val->image;
  new->win_ptr = val->win_ptr;
  new->mlx_ptr = val->mlx_ptr;
  new->list = 0;
  new->light = 0;
  new->nb_lights = val->nb_lights;
  new->k = val->k;
  copy_eye(val, new);
  copy_list_obj(new, val);
  copy_list_light(new, val);
  return (new);
}
