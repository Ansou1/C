/*
** elem.c for elem in /home/efilon/raytracer-2017-simon_o/xml/xml
** 
** Made by sebastien antonico
** Login   <efilon@heisenberg>
** 
** Started on  Wed May  8 14:17:45 2013 sebastien antonico
** Last update Sun Jun  9 15:09:20 2013 jonathan racaud
*/

#include <stdio.h>
#include "raytracer.h"

t_tab_xml_elem	g_tab_elem[] =
  {
    {"Position", &add_position},
    {"Rotation", &add_rot},
    {"Couleur", &add_color},
    {"Rayon", &add_radius},
    {"Brillance", &add_bright},
    {"Bump", &add_bump},
    {"Limite", &add_limit},
    {"Specularitee", &add_spec},
    {"Antialiasing", &add_anti_aliasing},
    {"Fenetre", &add_window},
    {"Flou", &add_blur},
    {"Threads", &add_threads},
    {"Filtre", &add_filter},
    {"Video", &add_video},
    {0, NULL}
  };

int	is_obj_state(t_mlx *rt)
{
  if ((rt->xml)->state == STATE_SPHERE ||
      (rt->xml)->state == STATE_PLAN ||
      (rt->xml)->state == STATE_CYLINDRE ||
      (rt->xml)->state == STATE_CONE)
    return (1);
  return (0);
}

int	add_elem(char *line, t_mlx *rt)
{
  char	**wt;
  char	*name;
  int	i;

  i = 0;
  wt = str_to_wordtab(line);
  if (wt[0] == NULL)
    return (0);
  if ((name = malloc(my_strlen(wt[0]))) == NULL)
    my_puterr("Erreur malloc\n");
  sprintf(name, "%s", wt[0] + 1);
  while (g_tab_elem[i].name_elem)
    {
      if (!my_strcmp_case(name, g_tab_elem[i].name_elem))
	g_tab_elem[i].ptr_add_elem(rt, &(wt[1]));
      i++;
    }
  free(name);
  free(wt);
  return (1);
}
