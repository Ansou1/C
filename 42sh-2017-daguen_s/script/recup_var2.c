/*
** recup_var.c for infectsh in /home/corrad_f//projet/infect/script
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sun Apr  7 12:32:20 2013 florian corradin
** Last update Mon May  6 19:05:15 2013 florian corradin
*/

#include "42.h"
#include "script.h"

char	*check_var_script(char *com, int pos, t_var *list)
{
  int	i;
  char	*ret;
  char	*del;
  char	*rep;

  ret = NULL;
  i = pos;
  while (com[i] != '\0')
    {
      if (is_c(com, i, '$') == 1)
	{
	  if ((del = get_del_var_script(&com[i], 1)) == NULL)
	    return (NULL);
	  if ((rep = recup_var_script(&del[1], list)) == NULL)
	    return (com);
	  ret = replace_in_str(com, del, rep, i);
	  return (check_var_script(ret, i, list));
	}
      i++;
    }
  if (ret != NULL)
    return (ret);
  else
    return (com);
}

char	*check_var_script_op(char *com, int pos, t_var *list)
{
  int	i;
  char	*ret;
  char	*del;
  char	*rep;

  ret = NULL;
  i = pos;
  while (com[i] != '\0')
    {
      if (!is_operator(com[i]) && !is_digit(com[i]) && com[i] != '=')
	{
	  if ((del = get_del_var_script(&com[i], 0)) == NULL)
	    return (NULL);
	  if ((rep = recup_var_script(del, list)) == NULL)
	    return (com);
	  ret = replace_in_str(com, del, rep, i);
	  return (check_var_script(ret, i, list));
	}
      i++;
    }
  if (ret != NULL)
    return (ret);
  else
    return (com);
}
