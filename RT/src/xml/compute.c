#include"obj.h"

static t_fptr g_parse[] =
  {
    {"cube", add_cube},
    {"plan", add_plan},
    {"cylinder", add_cylinder},
    {"sphere", add_sphere},
    {"cone", add_cone},
    {"light", add_light},
    {"camera", change_cam},
    {"model", add_model},
    {"torus", add_torus},
    {0, 0}
  };

void		interpret_dtree(t_rt *this, t_node *tree)
{
  t_node	*tmp;
  int		i;

  this->objs = 0;
  this->lights = 0;
  tmp = tree;
  while (tmp != 0)
    {
      i = 0;
      while (g_parse[i].name != 0)
	{
	  if (my_strcmp(tmp->name, g_parse[i].name) == 0)
	    g_parse[i].ptr(this, tmp->fils);
	  i++;
	}
      tmp = tmp->next;
    }
}

static int	get_basenum(char c)
{
  char		*basemin;
  char		*basemaj;
  int		i;

  basemin = "0123456789abcdef";
  basemaj = "0123456789ABCDEF";
  i = 0;
  while (i < 16)
    {
      if (c == basemin[i] || c == basemaj[i])
	return (i);
      i++;
    }
  return (0);
}

t_color		get_color_val(t_node *node)
{
  t_color	res;
  int		i;

  if (node == 0)
    return (0);
  i = 0;
  res = 0;
  if (node->value[0] == '0' && node->value[1] == 'x')
    i += 2;
  while (node->value[i] && i < PARSE_MAX_SIZE)
    {
      res *= 16;
      res += get_basenum(node->value[i]);
      i++;
    }
  return (res);
}

double		get_value(t_node *node)
{
  int		t[2];
  double	val;

  if (!(val = 0) && node == 0)
    return (0);
  t[1] = 1;
  t[0] = 0;
  if (node->value[t[0]] == '-')
    t[0]++;
  while (node->value[t[0]]
	 && node->value[t[0]] != '.' && t[0] < PARSE_MAX_SIZE)
    {
      val *= 10;
      val += get_basenum(node->value[t[0]++]);
    }
  if (node->value[t[0]] == '.' && t[0] < PARSE_MAX_SIZE)
    t[0]++;
  while (node->value[t[0]] && t[0] < PARSE_MAX_SIZE)
    {
      t[1] *= 10;
      val += (double)get_basenum(node->value[t[0]++]) / (double)t[1];
    }
  if (node->value[0] == '-')
    return (-val);
  return (val);
}

t_node		*get_node(t_node *tree, char *name)
{
  t_node	*tmp;

  tmp = tree;
  while (tmp != 0)
    {
      if (my_strcmp(name, tmp->name) == 0)
	return (tmp);
      tmp = tmp->next;
    }
  return (0);
}
