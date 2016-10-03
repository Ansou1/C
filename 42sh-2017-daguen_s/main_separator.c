/*
** main_separator.c for 42 in /home/corrad_f//projet/infect
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Wed May  8 14:28:03 2013 florian corradin
** Last update Sat May 25 14:14:56 2013 florian corradin
*/

#include "42.h"

char	*check_sep_com(char **separator, int i)
{
  if (my_strlen(separator[i]) == 0)
    {
      fprintf(stderr, "Invalid null command\n");
      my_free_tab(separator);
      return (NULL);
    }
  if ((separator[i] = dell_tab(separator[i])) == NULL)
    return (NULL);
  return (separator[i]);
}

int	check_is_good_cmd(const char *cmd)
{
  int	i;

  i = strlen(cmd);
  i -= 2;
  if (i > 1)
    {
      if ((cmd[i] == '|' || cmd[i] == '&') && cmd[i + 1] == cmd[i])
	return (1);
      if (cmd[i + 1] == '|')
	return (1);
    }
  if (strstr(cmd, "; |") != 0 || strstr(cmd, "| ;") != 0 ||
      strstr(cmd, "|;") != 0 || strstr(cmd, ";|") != 0 ||
      strstr(cmd, "& |") != 0 || strstr(cmd, "| &") != 0 ||
      strstr(cmd, "|&") != 0 || strstr(cmd, "&|") != 0 ||
      strstr(cmd, "&&>") != 0 || strstr(cmd, "||>") != 0 ||
      strstr(cmd, "&& >") != 0 || strstr(cmd, "|| >") != 0 ||
      strstr(cmd, "| |") != 0 || strstr(cmd, "|||") != 0 ||
      strstr(cmd, "&& &&") != 0 || strstr(cmd, "&&&") != 0)
    return (1);
  return (0);
}

int	check_valide_command(const char *cmd)
{
  if (check_is_good_cmd(cmd))
    {
      fprintf(stderr, "Invalid null command.\n");
      return (1);
    }
  return (0);
}

/* statu = 0 c'est bon, -1 echec */
int	my_shell(char *com)
{
  char	**separator;
  char	*sep;
  int	i;
  int	ctr;

  if (init_shell(&ctr, &i, com))
    return (SUCCESS);
  if ((separator = my_get_separator(com, &sep)) == NULL)
    return (FAIL);
  while (separator[i] != NULL)
    {
      if ((separator[i] = check_sep_com(separator, i)) == NULL)
	return (SUCCESS);
      if (my_parser_comm(separator[i]) == FAIL)
	return (FAIL);
      if (sep[ctr] == SEPARATOR_OR && g_statu == 0)
	i++;
      else if (sep[ctr] == SEPARATOR_AND && g_statu == -1)
	i++;
      ctr++;
      i++;
    }
  free(sep);
  my_free_tab(separator);
  return (SUCCESS);
}
