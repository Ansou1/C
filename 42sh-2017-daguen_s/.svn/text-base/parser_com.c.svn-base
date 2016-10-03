/*
** parser_com.c for 42sh$ in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Tue Feb 26 09:04:18 2013 florian corradin
** Last update Sun May 26 14:05:55 2013 antoine simon
*/

#include "42.h"

int	init_shell(int *ctr, int *i, char *com)
{
  *i = 0;
  *ctr = 0;
  g_statu = 0;
  if (check_valide_command(com))
    return (1);
  if (strstr(com, "!") != 0)
    {
      fprintf(stderr, "%s: Event not found.\n", com);
      return (1);
    }
  return (0);
}

t_com	*list_fill_and_inhib(t_com *list, t_string str, char *com, int ind)
{
  list->commande = str_to_tab_inib(str.exec);
  list->commande = get_back_quote_tab(list->commande);
  list->commande = de_inhib_tab(list->commande);
  list->redir = is_redir(com, ind);
  list->file = str.file;
  return (list);
}

int		get_list_maill(char *com, int *i, t_com *list)
{
  t_string	str;
  int		ind;

  str.exec = NULL;
  str.file = NULL;
  ind = 0;
  str = get_com_params(com, str);
  str.exec = my_epurstr_inib(str.exec);
  if ((str.exec = get_alias_loop(g_alias, str.exec)) == NULL)
    return (SUCCESS);
  while (com[ind] != '\0' && is_redir(com, ind) == 0)
    ind++;
  list = list_fill_and_inhib(list, str, com, ind);
  if (com[ind] != '\0')
    ind++;
  if (list->redir != 0 && list->redir != PIPE)
    {
      if (com[ind] == '<' || com[ind] == '>')
	ind++;
      while (com[ind] != '\0' && is_redir(com, ind) == 0)
	ind++;
    }
  *i = *i + ind;
  free(str.exec);
  return (SUCCESS);
}

t_com	*my_put_in_list(char *com, t_com *list)
{
  t_com	*stock;
  int	i;

  i = 0;
  stock = list;
  while (list != NULL)
    {
      if (get_list_maill(&com[i], &i, list) == FAIL)
	return (NULL);
      list = list->next;
    }
  list = stock;
  return (list);
}
