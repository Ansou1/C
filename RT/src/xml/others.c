#include "utils.h"
#include "maths.h"

t_coords	*get_coords(t_node *node, char *name)
{
  t_node	*cor;
  t_coords	*new;

  new = w_malloc(sizeof(t_coords));
  cor = get_node(node, name);
  if (cor != 0)
    cor = cor->fils;
  new->x = get_value(get_node(cor, "x"));
  new->y = get_value(get_node(cor, "y"));
  new->z = get_value(get_node(cor, "z"));
  return (new);
}

void		add_light(t_rt *this, t_node *node)
{
  t_light_list	*tmp;

  tmp = this->lights;
  this->lights = w_malloc(sizeof(t_light_list));
  this->lights->color = get_color_val(get_node(node, "color"));
  this->lights->type = get_value(get_node(node, "type"));
  this->lights->watt = get_value(get_node(node, "watt"));
  this->lights->psize = get_value(get_node(node, "psize"));
  this->lights->pos = get_coords(node, "pos");
  this->lights->photons = get_value(get_node(node, "photons"));
  this->lights->soft_val = get_value(get_node(node, "soft_val"));
  this->lights->soft_val = set_bounds(this->lights->soft_val, 1, V_FAR);
  this->lights->rndm = NULL;
  this->lights->next = tmp;
}

static void	additional_cam(t_rt *this, t_node *node)
{
  this->cam->used_photon = get_value(get_node(node, "photons_used"));
  if (this->cam->used_photon == 0)
    this->cam->used_photon = COMPUTE_PHOTON;
  this->cam->diff_fact = get_value(get_node(node, "diff_factor"));
  if (this->cam->diff_fact == 0)
    this->cam->diff_fact = 1000;
  this->cam->diff_fact = set_bounds(this->cam->diff_fact, 1, 100000);
}

void		change_cam(t_rt*this, t_node *node)
{
  w_free((void **)&(this->cam->pos));
  w_free((void **)&(this->cam->angle));
  this->cam->pos = get_coords(node, "pos");
  this->cam->angle = get_coords(node, "rotation");
  this->cam->light_sampling = get_value(get_node(node, "light_sampling"));
  this->cam->ratio_pixel = get_value(get_node(node, "aa"));
  this->cam->depth_field = get_value(get_node(node, "depthfield"));
  this->cam->depth_deform = get_value(get_node(node, "depthdeform"));
  this->cam->fog_depth = get_value(get_node(node, "fogdepth"));
  this->cam->fog_style = get_value(get_node(node, "fogstyle"));
  this->cam->fog_color = get_color_val(get_node(node, "fogcolor"));
  if (get_node(node, "pfx") != 0)
    my_strcpy(this->pfx, get_node(node, "pfx")->value);
  this->pfx_val = get_value(get_node(node, "pfx-val"));
  this->cam->ratio_pixel = set_bounds(this->cam->ratio_pixel, 1, 16);
  this->cam->light_sampling = set_bounds(this->cam->light_sampling, 1, 16);
  this->cam->background = get_image(get_node(node, "background"));
  this->cam->nb_core = get_value(get_node(node, "cores"));
  if (this->cam->nb_core == 0)
    this->cam->nb_core = 3;
  this->cam->nb_core = set_bounds(this->cam->nb_core, 1, 10);
  this->cam->photon_mapped = get_value(get_node(node, "photon_mapped"));
  this->cam->photon_mapped = set_bounds(this->cam->photon_mapped, 0, 1);
  additional_cam(this, node);
}
