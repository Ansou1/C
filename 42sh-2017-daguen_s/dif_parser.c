/*
** dif_parser.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sat Mar 30 21:44:43 2013 florian corradin
** Last update Fri May 24 14:19:48 2013 simon daguenet
*/

#include "42.h"

int	is_cd(char **com)
{
  if (com == NULL)
    return (0);
  if (com[0] == NULL)
    return (FAIL);
  if (my_str_comp("cd", com[0]) == 1)
    return (1);
  else
    return (0);
}

int	is_env(t_com *list)
{
  int	len;

  if (list->commande == NULL)
    return (0);
  if (list->commande[0] == NULL)
    return (0);
  len = my_tablen(list->commande);
  if (my_strncmp("env", list->commande[0], 3) == 1 && len == 1)
    return (0);
  else if (my_strncmp("setenv", list->commande[0], 3) == 1 && len == 1)
    return (0);
  else if (is_buitins(list->commande) == 1)
    return (1);
  else
    return (0);
}

int	my_exec_line(t_com *list)
{
  g_statu = 0;
  if (is_cd(list->commande) == 1)
    my_cd(list->commande, 1);
  if (is_env(list) == 1)
    g_statu = my_env_fct(list->commande, 1);
  bultins_history(list);
  my_exec_commande(list);
  return (SUCCESS);
}

int	my_parser_comm(char *com)
{
  char	*line;
  char	*line_epur;
  int	i;
  int	ctr;
  t_com	*list;

  i = 0;
  ctr = 0;
  if ((line = clear_commande_line(com)) == NULL)
    return (FAIL);
  if ((line_epur = my_epurstr_inib(line)) == NULL)
    return (FAIL);
  while (com[i++] != '\0')
    if (is_redir(com, i - 1) != 0)
      ctr++;
  if ((list = recup_list(ctr + 1)) == NULL)
    return (FAIL);
  if ((list = my_put_in_list(line_epur, list)) == NULL)
    return (FAIL);
  if (my_exec_line(list) == FAIL)
    return (FAIL);
  my_free_list(list);
  free(line_epur);
  return (SUCCESS);
}
