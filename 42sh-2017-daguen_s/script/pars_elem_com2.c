/*
** pars_elem_com2.c for script in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Mon May  6 18:58:17 2013 florian corradin
** Last update Thu May 23 15:00:32 2013 simon daguenet
*/

#include "42.h"
#include "script.h"

int	get_var_type(char *str)
{
  char	flot;
  int	i;

  flot = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (is_c(str, i, '(') == 1)
	return (V_TAB);
      if (is_c(str, i, '.') == 1)
	flot = 1;
      if (is_alpha(str[i]) == 1)
	return (V_STR);
      i++;
    }
  if (flot == 1)
    return (V_DOUBLE);
  return (V_INT);
}

t_script	*get_tab_var(char *name, char *file)
{
  t_script	*pars;
  int		i;
  int		a;
  char		*str;
  char		**tab;

  i = 0;
  a = 0;
  i = go_to_in_str(file, i, '=') + 2;
  str = xmalloc(my_strlen(&file[i]) + 1);
  while (file[i] != '\0' && file[i] != ')')
    str[a++] = file[i++];
  str[a] = '\0';
  tab = str_to_tab_inib(str);
  tab = de_inhib_tab(tab);
  pars = xmalloc(sizeof (*pars));
  pars->name = my_strdup(name);
  pars->inst = my_strdup(tab[0]);
  pars->type = ASIGN;
  pars->att = -1;
  pars->tab = tab;
  pars->add = g_add;
  free(str);
  return (pars);
}

/* fonction qui donne le type */
/* fonction qui transforme la chaine, */
/* fonction qui, rempli var */
/* contient un = */
t_script	*get_var(char *file)
{
  t_script	*pars;
  int		i;
  char		*str;
  char		*name;
  char		*value;

  i = 0;
  str = my_strdup(file);
  name = get_str_sep(str, '=');
  name = desinhiber(name);
  i = go_to_in_str(file, i, '=') + 1;
  if (is_c(file, i, '('))
    return (get_tab_var(name, file));
  value = my_strdup(&str[i]);
  free(str);
  pars = xmalloc(sizeof (*pars));
  pars->name = name;
  pars->inst = value;
  pars->type = ASIGN;
  pars->att = -1;
  pars->add = g_add;
  pars->tab = NULL;
  return (pars);
}

t_script	*get_com(char *file)
{
  t_script	*pars;

  pars = xmalloc(sizeof (*pars));
  pars->type = COM;
  pars->inst = my_strdup(file);
  pars->name = NULL;
  pars->att = -1;
  pars->add = g_add;
  pars->tab = NULL;
  return (pars);
}
