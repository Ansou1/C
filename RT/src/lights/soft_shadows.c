#include"utils.h"
#include"maths.h"

static void	tmp_mod_light(t_light_list *curr,
			 t_coords *base,
			 t_coords *decal,
			 int max)
{
  int		off;
  int		semi;
  t_coords	*cdecal;

  off = curr->soft_val;
  semi = off / 2;
  cdecal = &(curr->rndm[(int)decal->y * max + (int)decal->x]);
  curr->pos->x = base->x + cdecal->x + (rand() % off - semi) / 2;
  curr->pos->y = base->y + cdecal->y + (rand() % off - semi) / 2;
  curr->pos->z = base->z + cdecal->z + (rand() % off - semi) / 2;
}

static double	ratio_mid(double datas[], int max)
{
  double	total;
  int		x;
  int		y;

  total = 0;
  x = 0;
  while (x < max)
    {
      y = 0;
      while (y < max)
	{
	  total += datas[y * max + x];
	  ++y;
	}
      ++x;
    }
  total /= (double)(max * max);
  if (total >= 1.0)
    return (1.0);
  if (total <= 0.0)
    return (0.0);
  return (total);
}

double		soft_listing(t_rt *this,
		   t_light_list *curr,
		   t_coords *it)
{
  double	datas[256];
  t_coords	saved;
  t_coords	i;

  if (this->cam->light_sampling == 1
      || curr->type != LIGHT_NOR
      || curr->soft_val <= 1)
    return (list_transparency(this, curr, it, 1.0f));
  copy_coords(&saved, curr->pos);
  i.x = 0;
  while (i.x < this->cam->light_sampling)
    {
      i.y = 0;
      while (i.y < this->cam->light_sampling)
	{
	  tmp_mod_light(curr, &saved, &i, this->cam->light_sampling);
	  datas[(int)i.y * this->cam->light_sampling + (int)i.x] =
	    list_transparency(this, curr, it, 1.0f);
	  i.y++;
	}
      i.x++;
    }
  copy_coords(curr->pos, &saved);
  return (ratio_mid(datas, this->cam->light_sampling));
}
