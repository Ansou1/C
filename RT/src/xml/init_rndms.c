#include "utils.h"
#include "maths.h"

static void	init_lights(t_rt *this)
{
  t_light_list	*tmp;
  int		max;
  int		i;
  int		off;
  int		semi;

  tmp = this->lights;
  max = this->cam->light_sampling;
  while (tmp)
    {
      off = tmp->soft_val;
      semi = off / 2;
      tmp->rndm = w_malloc(sizeof(t_coords) * max * max);
      i = 0;
      while (i < max * max)
	{
	  tmp->rndm[i].x = rand() % off - semi;
	  tmp->rndm[i].y = rand() % off - semi;
	  tmp->rndm[i].z = rand() % off - semi;
	  ++i;
	}
      tmp = tmp->next;
    }
}

void		init_rndms(t_rt *this)
{
  int		aa;
  int		i;
  int		def;

  init_lights(this);
  my_cos(42);
  my_sin(42);
  def = this->cam->depth_deform;
  if (def <= 0)
    return ;
  aa = this->cam->ratio_pixel;
  if (this->temps.d_sample == NULL)
    {
      this->temps.d_sample = w_malloc(sizeof(t_coords) * aa * aa);
      i = 0;
      while (i < aa * aa)
	{
	  this->temps.d_sample[i].x = rand() % (def * 2) - def;
	  this->temps.d_sample[i].y = rand() % (def * 2) - def;
	  ++i;
	}
    }
}
