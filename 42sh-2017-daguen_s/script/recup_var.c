/*
** recup_var.c for infectsh in /home/corrad_f//projet/infect/script
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sun Apr  7 12:32:20 2013 florian corradin
** Last update Thu May 23 15:02:53 2013 simon daguenet
*/

#include "42.h"
#include "script.h"

char	*get_name_var_script(char *name, t_var *list)
{
  char	*ret;
  int	i;

  i = 0;
  if ((ret = malloc(my_strlen(name) + 1)) == NULL)
    fprintf(stderr, "COULD NOT ALLOC\n");
  if (ret == NULL)
    return (NULL);
  if (name[0] == '{')
    {
      i = my_strlen(name) - 1;
      if (name[i] != '}')
	{
	  fprintf(stderr, "Missing } \n");
	  g_stop_script = -1;
	  return (NULL);
	}
      name[i] = '\0';
      ret = my_strdup(&name[1]);
      name[i] = '}';
    }
  else
    return (name);
  ret = check_var_script(ret, 0, list);
  return (ret);
}

char	*recup_var_script_tab(char *name, t_var *list)
{
  int	i;
  int	ind;

  i = my_strlen(list->name);
  i++;
  ind = my_atoi(&name[i]);
  i = 0;
  while (list->tab[i] && i != ind)
    i++;
  if (i == ind && list->tab[i] != NULL)
    return (my_strdup(list->tab[i]));
  else
    return (my_strdup("\0"));
}

char	*recup_var_script(char *name, t_var *list)
{
  char	*ret;

  if ((name = get_name_var_script(name, list)) == NULL)
    return (NULL);
  while (list != NULL)
    {
      if (list->type == V_TAB &&
	  my_strncmp(list->name, name, my_strlen(list->name)) == 1)
	return (recup_var_script_tab(name, list));
      if (my_str_comp(name, list->name) == 1)
	{
	  if (list->type == V_TAB)
	    return (my_strdup(list->tab[0]));
	  return (my_strdup(list->val));
	}
      list = list->next;
    }
  if ((ret = my_getenv(name)) != NULL)
    return (ret);
  ret = xmalloc(1);
  ret[0] = '\0';
  return (ret);
}

char	*get_del_var_script2(char *str, char *ret, int i)
{
  int	bloc;

  bloc = 1;
  ret[i++] = '{';
  while (str[i] && bloc != 0)
    {
      if (str[i] == '{')
	bloc++;
      if (str[i] == '}')
	bloc--;
      ret[i] = str[i];
      i++;
    }
  ret[i] = '\0';
  if (bloc != 0)
    {
      fprintf(stderr, "unmatched }\n");
      g_stop_script = -1;
    }
  return (ret);
}

char	*get_del_var_script(char *s, int op)
{
  char	*ret;
  int	i;

  i = 1;
  while (s[i] != '\0' &&
	 (is_digit(s[i]) != 0 || is_alpha(s[i]) != 0 || is_varchar(s[i]) != 0))
    i++;
  ret = malloc(i + 1);
  if (ret == NULL)
    return (NULL);
  i = op;
  if (op == 1)
    ret[0] = '$';
  if (s[i] == '{')
    return (get_del_var_script2(s, ret, i));
  while (s[i] != '\0' &&
	 (is_digit(s[i]) != 0 || is_alpha(s[i]) != 0 || is_varchar(s[i]) != 0))
    {
      ret[i] = s[i];
      i++;
    }
  ret[i] = '\0';
  return (ret);
}
