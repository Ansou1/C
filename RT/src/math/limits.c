#include "maths.h"

static t_bool	sphere_limit(t_object *this,
			  t_coords *s,
			  t_coords *v,
			  double k)
{
  t_coords	tmp;
  t_bool	result;
  double	total;

  tmp.x = s->x + v->x * k - this->l_pos->x;
  tmp.y = s->y + v->y * k - this->l_pos->y;
  tmp.z = s->z + v->z * k - this->l_pos->z;
  tmp.x = POW2(tmp.x);
  tmp.y = POW2(tmp.y);
  tmp.z = POW2(tmp.z);
  total = tmp.x + tmp.y + tmp.z;
  result = FALSE;
  if (total >= POW2(this->l_value))
    result = TRUE;
  if (this->l_type < 0)
    result = !result;
  return (result);
}

static t_bool	cube_limit(t_object *this,
			t_coords *s,
			t_coords *v,
			double k)
{
  t_coords	tmp;
  t_bool	result;

  tmp.x = s->x + v->x * k - this->l_pos->x;
  tmp.y = s->y + v->y * k - this->l_pos->y;
  tmp.z = s->z + v->z * k - this->l_pos->z;
  my_inv_rotate(&tmp, this->l_rot);
  result = FALSE;
  if (ABS(tmp.x) > this->l_value)
    result = TRUE;
  if (ABS(tmp.y) > this->l_value)
    result = TRUE;
  if (ABS(tmp.z) > this->l_value)
    result = TRUE;
  if (this->l_type < 0)
    result = !result;
  return (result);
}

t_bool	is_limited(t_object_list *curr,
		 t_coords *s,
		 t_coords *v,
		 double k)
{
  t_object	*this;

  this = curr->obj;
  if (this->l_type == 0)
    return (FALSE);
  if (ABS(this->l_type) == LIM_SPHERE)
    return (sphere_limit(this, s, v, k));
  if (ABS(this->l_type) == LIM_CUBE)
    return (cube_limit(this, s, v, k));
  return (FALSE);
}
