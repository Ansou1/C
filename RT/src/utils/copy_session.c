#include"utils.h"
#include"rt.h"

static void	copy_object(t_object *dest, t_object *src)
{
  dest->type = src->type;
  dest->val1 = src->val1;
  dest->val2 = src->val2;
  dest->model = src->model;
  dest->hitted = src->hitted;
  dest->color = src->color;
  dest->reflexion = src->reflexion;
  dest->tr = src->tr;
  dest->ind = src->ind;
  dest->bright = src->bright;
  dest->r = src->r;
  dest->pos = src->pos;
  dest->l_type = src->l_type;
  dest->l_value = src->l_value;
  dest->l_pos = src->l_pos;
  dest->l_rot = src->l_rot;
  dest->color_mod = src->color_mod;
  dest->norml_mod = src->norml_mod;
  dest->texture = src->texture;
  dest->bumpmap = src->bumpmap;
}

static void	copy_lights(t_rt *dest, t_rt *src)
{
  t_light_list	*copied;
  t_light_list	*tmp;

  tmp = src->lights;
  while (tmp)
    {
      copied = w_malloc(sizeof(t_light_list));
      copied->pos = w_malloc(sizeof(t_coords));
      copied->pos->x = tmp->pos->x;
      copied->pos->y = tmp->pos->y;
      copied->pos->z = tmp->pos->z;
      copied->type = tmp->type;
      copied->color = tmp->color;
      copied->psize = tmp->psize;
      copied->watt = tmp->watt;
      copied->soft_val = tmp->soft_val;
      copied->rndm = tmp->rndm;
      copied->photons = tmp->photons;
      copied->next = dest->lights;
      dest->lights = copied;
      tmp = tmp->next;
    }
}

static void	copy_objs(t_rt *dest, t_rt *src)
{
  t_object_list	*copied;
  t_object_list	*tmp;

  tmp = src->objs;
  while (tmp)
    {
      copied = w_malloc(sizeof(t_object_list));
      copied->obj = w_malloc(sizeof(t_object));
      copied->next = dest->objs;
      dest->objs = copied;
      copy_object(copied->obj, tmp->obj);
      tmp = tmp->next;
    }
}

t_rt	*copy_tmp_session(t_rt *this)
{
  t_rt	*new;

  new = w_malloc(sizeof(t_rt));
  new->win = this->win;
  new->cam = this->cam;
  new->objs = 0;
  new->lights = 0;
  new->temps.rdepth = 0;
  new->temps.tdepth = 0;
  new->temps.d_sample = this->temps.d_sample;
  new->temps.last_tr = 0;
  new->temps.cpos = 0;
  new->photons = this->photons;
  new->pfx_val = this->pfx_val;
  my_strcpy(new->pfx, this->pfx);
  copy_objs(new, this);
  copy_lights(new, this);
  return (new);
}

void		free_session_copy(t_rt *this)
{
  t_light_list	*tmp;
  t_light_list	*next;
  t_object_list	*tmp_o;
  t_object_list	*next_o;

  tmp = this->lights;
  tmp_o = this->objs;
  while (tmp)
    {
      next = tmp->next;
      free(tmp->pos);
      free(tmp);
      tmp = next;
    }
  while (tmp_o)
    {
      next_o = tmp_o->next;
      free(tmp_o->obj);
      free(tmp_o);
      tmp_o = next_o;
    }
  free(this);
}
