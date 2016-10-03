/*
** elem_couleur.c for elem_couleur in /home/efilon/raytracer-2017-simon_o/xml/xml
** 
** Made by efilon
** Login   <efilon@Heisenbergs-RV>
** 
** Started on  Fri May 10 15:12:09 2013 efilon
** Last update Sun Jun  9 15:13:16 2013 jonathan racaud
*/

#include "raytracer.h"

t_xml_color_tab g_tab_color[] =
  {
    {"rouge\"", 0xFF0000},
    {"vert\"", 0xFF00},
    {"bleu\"", 0xFF},
    {"noir\"", 0x0},
    {"blanc\"", 0xFFFFFF},
    {"jaune\"", 0xFFFF00},
    {"cyan\"", 0xFFFF},
    {"rouge\"/>", 0xFF0000},
    {"vert\"/>", 0xFF00},
    {"bleu\"/>", 0xFF},
    {"noir\"/>", 0x0},
    {"blanc\"/>", 0xFFFFFF},
    {"jaune\"/>", 0xFFFF00},
    {"cyan\"/>", 0xFFFF},
    {NULL, 0}
  };

int	find_in_color_tab(char *val)
{
  int	i;

  i = 0;
  while (g_tab_color[i].color_name)
    {
      if (!my_strcmp_case(val, g_tab_color[i].color_name))
	return (i);
      i++;
    }
  return (-1);
}

int	get_color(char *val)
{
  char	*end;
  int	ret_color;

  end = NULL;
  if (!my_strncmp_case(val, "random\"", 7))
    return (get_rand(0, 0xFFFFFF));
  else if (!my_strncmp_case(val, "random\"/>", 9))
    return (get_rand(0, 0xFFFFFF));
  else if ((ret_color = find_in_color_tab(val)) != -1)
    return (g_tab_color[ret_color].color_value);
  else
    return (strtol(val, &end, 16));
  end = end;
  return (0);
}

int	add_color_obj(t_object *obj, char **tab)
{
  int	i;
  char	*end;

  i = 0;
  end = NULL;
  while (tab[i] != NULL)
    {
      if (!my_strncmp_case(tab[i], "couleur=", 8))
        obj->color = get_color(tab[i] + 9);
      else if (!my_strncmp_case(tab[i], "damier=", 7))
        obj->damier = get_color(tab[i] + 8);
      i++;
    }
  end = end;
  return (1);
}

int	add_color_light(t_light *light, char **tab)
{
  int	i;
  char	*end;

  i = 0;
  end = NULL;
  while (tab[i] != NULL)
    {
      if (!my_strncmp_case(tab[i], "couleur=", 8))
        light->color = get_color(tab[i] + 9);
      i++;
    }
  end = end;
  return (1);
}


int	add_color(t_mlx *rt, char **tab)
{
  if (is_obj_state(rt))
    return (add_color_obj((rt->list), tab));
  else if (rt->xml->state == STATE_CUBE)
    return (add_color_cube(rt->list, tab));
  else if ((rt->xml)->state == STATE_LIGHT)
    return (add_color_light(rt->light, tab));
  return (0);
}
