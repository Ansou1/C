/*
** elem_filter.c for elem_filter in /home/efilon/eretay/raytracer-2017-simon_o/rt/sources/xml
** 
** Made by efilon
** Login   <efilon@Heisenbergs-RV>
** 
** Started on  Fri Jun  7 02:15:39 2013 efilon
** Last update Sun Jun  9 15:08:22 2013 jonathan racaud
*/

#include <unistd.h>
#include "raytracer.h"

t_xml_tab_filters	g_filter_tab[] =
  {
    {"bleu\"", FILTER_BLUE},
    {"rouge\"", FILTER_RED},
    {"vert\"", FILTER_GREEN},
    {"noir_et_blanc\"", FILTER_BW},
    {"negatif\"", FILTER_NEG},
    {"sepia\"", FILTER_SEPIA},
    {"aucun\"", FILTER_NONE},
    {"bleu\"/>", FILTER_BLUE},
    {"rouge\"/>", FILTER_RED},
    {"vert\"/>", FILTER_GREEN},
    {"noir_et_blanc\"/>", FILTER_BW},
    {"negatif\"/>", FILTER_NEG},
    {"sepia\"/>", FILTER_SEPIA},
    {"aucun\"/>", FILTER_NONE},
    {NULL, FILTER_NONE}
  };

int	get_type_filter(char *val)
{
  int	i;

  i = 0;
  while (g_filter_tab[i].filter_name)
    {
      if (!my_strcmp_case(g_filter_tab[i].filter_name, val))
	return (i);
      i++;
    }
  return (-1);
}

int	add_filter(t_mlx *rt, char **tab)
{
  int	i;
  int	ret_filter;

  i = 0;
  while (tab[i] != NULL)
    {
      if (!my_strncmp_case(tab[i], "filtre=", 7))
	{
	  if ((ret_filter = get_type_filter(tab[i] + 8)) != -1)
	    rt->filter = g_filter_tab[ret_filter].filter_value;
	}
      i++;
    }
  return (1);
}
