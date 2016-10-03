/*
** xml.c for xml in /home/efilon/Projets/Projects/Cproject/xml
** 
** Made by sebastien antonico
** Login   <efilon@heisenberg>
** 
** Started on  Sat May  4 15:29:27 2013 sebastien antonico
** Last update Sun Jun  9 15:07:30 2013 jonathan racaud
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "raytracer.h"

t_tab_xml_dep	g_tab_xml[] =
  {
    {"RT", STATE_NONE, UNKNOWN_TYPE},
    {"Scene", STATE_RT, UNKNOWN_TYPE},
    {"Objets", STATE_SCENE, UNKNOWN_TYPE},
    {"Sphere", STATE_OBJS, SPHERE},
    {"Plan", STATE_OBJS, PLANE},
    {"Cylindre", STATE_OBJS, CYLINDER},
    {"Cone", STATE_OBJS, CONE},
    {"Cube", STATE_OBJS, CUBE},
    {"Lumieres", STATE_SCENE, UNKNOWN_TYPE},
    {"Lumiere", STATE_LIGHTS, LIGHT_TYPE},
    {"Oeil", STATE_SCENE, EYE_TYPE},
    {"Configuration", STATE_RT, UNKNOWN_TYPE},
    {0, STATE_NONE, UNKNOWN_TYPE}
  };

int	get_type_node(char *name)
{
  int	i;

  i = 0;
  while (g_tab_xml[i].xml_cmp)
    {
      if (!my_strcmp_case(g_tab_xml[i].xml_cmp, name))
	return (i);
      i++;
    }
  return (-1);
}

void		add_empty_obj(t_mlx *rt, int type)
{
  t_object	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    my_puterr("Erreur malloc\n");
  memset(new, 0, sizeof(*new));
  new->color = 0xFFFFFF;
  new->def_object = g_tab_xml[type].xml_type;
  new->damier = -1;
  new->width_limit = -1;
  new->length_limit = -1;
  new->material = 700.0;
  new->spec_int = 3.0;
  if ((new->result = malloc(sizeof(t_result))) == NULL)
    my_puterr("Erreur malloc\n");
  memset(new->result, 0, sizeof(t_result));
  new->next = NULL;
  add_in_list(new, ((t_object**)&(rt->list)));
  fill_intersec_ptr((rt->list));
}

void		add_obj(t_mlx *rt, int type)
{
  int		type_obj;

  type_obj = g_tab_xml[type].xml_type;
  if (type_obj == SPHERE || type_obj == PLANE || type_obj == CONE ||
      type_obj == CYLINDER)
    add_empty_obj(rt, type);
  else if (type_obj == CUBE)
    add_empty_cube(rt);
}

int	add_node(char *line, t_mlx *rt)
{
  char	*name;
  int	type;

  if ((name = malloc(my_strlen(line) - 1)) == NULL)
    fprintf(stderr, "Erreur malloc.\n");
  snprintf(name, my_strlen(line) - 2 + 1, "%s", line + 1);
  if ((type = get_type_node(name)) == -1 ||
      g_tab_xml[type].xml_dep != (rt->xml)->state)
    return (0);
  if (g_tab_xml[type].xml_dep == STATE_OBJS)
    add_obj(rt, type);
  else if (g_tab_xml[type].xml_dep == STATE_LIGHTS)
    add_empty_light(rt);
  add_in_pile(&((rt->xml)->stack), name);
  (rt->xml)->state = type;
  free(name);
  return (1);
}

int	close_node(char *line, t_mlx *rt)
{
  char	*name;

  if ((rt->xml)->stack == NULL)
    return (0);
  if ((name = malloc(my_strlen(line) - 2)) == NULL)
    my_puterr("Erreur malloc\n");
  snprintf(name, my_strlen(line) - 3 + 1, "%s", line + 2);
  if (!my_strcmp(name, ((rt->xml)->stack)->str))
    {
      (rt->xml)->state = g_tab_xml[(rt->xml)->state].xml_dep;
      pop_in_pile(&((rt->xml)->stack));
      free(name);
      return (1);
    }
  else
    free(name);
  return (0);
}
