#include <math.h>

#include "maths.h"
#include "utils.h"
#include "rt.h"

static void	insert_before(t_near_photon *this,
			 t_photon_list *cur,
			 t_photon_list *new)
{
  if (cur)
    {
      new->next = cur;
      new->prev = cur->prev;
      if (cur->prev)
	cur->prev->next = new;
      else
	this->begin = new;
      cur->prev = new;
    }
  else
    {
      new->next = NULL;
      new->prev = this->last;
      if (this->last)
	this->last->next = new;
      else
	this->begin = new;
      this->last = new;
    }
}

static void	add_photon(t_near_photon *this,
		      t_photon *cur,
		      double dist,
		      t_search flag)
{
  t_photon_list	*new;
  t_photon_list	*tmp;

  new = w_malloc(sizeof(t_photon_list));
  new->cur = cur;
  new->dist = dist;
  tmp = this->begin;
  while (tmp && dist > tmp->dist)
    tmp = tmp->next;
  insert_before(this, tmp, new);
  ++this->len;
  if (flag == NNEAREST && this->len > this->max_len)
    {
      --this->len;
      tmp = this->last;
      this->last = this->last->prev;
      if (this->last)
	this->last->next = NULL;
      free(tmp);
    }
}

static void	find_nearest(t_kdtree *node,
			t_near_photon *near,
			t_coords *pt,
			t_search flag)
{
  double	axis_dist;
  double	dist;

  dist = sqrt(POW2(node->photon->pos->x - pt->x)
	      + POW2(node->photon->pos->y - pt->y)
	      + POW2(node->photon->pos->z - pt->z));
  if (dist < near->last_dist || near->len < near->max_len)
    {
      add_photon(near, node->photon, dist, flag);
      if (flag == NNEAREST)
	near->last_dist = near->last->dist;
    }
  axis_dist = ((double*)(node->photon->pos))[node->axis] -
    ((double*)(pt))[node->axis];
  if (node->left && (ABS(axis_dist) < near->last_dist || axis_dist > 0))
    find_nearest(node->left, near, pt, flag);
  if (node->right && (ABS(axis_dist) < near->last_dist || axis_dist < 0))
    find_nearest(node->right, near, pt, flag);
}

t_near_photon	*get_nearest_photons(int n,
				  t_photon_map *photon_map,
				  t_coords *pt)
{
  t_near_photon	*ret;

  ret = w_malloc(sizeof(t_near_photon));
  ret->last_dist = HUGE_VAL;
  ret->max_len = n;
  find_nearest(photon_map->tree, ret, pt, NNEAREST);
  return (ret);
}

t_near_photon	*get_photons_dist(double dist,
			       t_photon_map *photon_map,
			       t_coords *pt)
{
  t_near_photon	*ret;

  ret = w_malloc(sizeof(t_near_photon));
  ret->max_len = 0;
  ret->last_dist = dist;
  find_nearest(photon_map->tree, ret, pt, DNEAREST);
  return (ret);
}
