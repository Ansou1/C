/*
** cl_fr.c for mysh2 in /home/daguen_s//secminishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar  9 12:31:39 2013 simon daguenet
** Last update Sat Mar  9 13:03:02 2013 simon daguenet
*/

#include "mysh.h"

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      xfree(tab[i]);
      i++;
    }
  xfree(tab);
}

char	**init_redi(char **redi)
{
  redi = xmalloc(sizeof(*redi) * 5);
  redi[0] = ">>";
  redi[1] = ">";
  redi[2] = "<<";
  redi[3] = "<";
  redi[4] = NULL;
  return (redi);
}

char	**clean_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != '\0')
    {
      tab[i] = my_epurstr(tab[i]);
      i++;
    }
  return (tab);
}

int	good_cmd(char *cmd)
{
  if (my_strlen(cmd) == 0)
    return (0);
  if (my_strstr(cmd, "||") != 0 || my_strstr(cmd, "| |") != 0
      || my_strstr(cmd, ";|") != 0 || my_strstr(cmd, "|;") != 0
      || my_strstr(cmd, "; |") != 0 || my_strstr(cmd, "| ;") != 0
      || my_strstr(cmd, ";>") != 0 || my_strstr(cmd, "|>") != 0
      || my_strstr(cmd, "; >") != 0 || my_strstr(cmd, "| >") != 0
      || my_strstr(cmd, ">;") != 0 || my_strstr(cmd, ">|") != 0
      || my_strstr(cmd, "> ;") != 0 || my_strstr(cmd, "> |") != 0
      || my_strstr(cmd, ";<") != 0 || my_strstr(cmd, "|<") != 0
      || my_strstr(cmd, "; <") != 0 || my_strstr(cmd, "| <") != 0
      || my_strstr(cmd, "<;") != 0 || my_strstr(cmd, "<|") != 0
      || my_strstr(cmd, "< ;") != 0 || my_strstr(cmd, "< |") != 0
      || my_strstr(cmd, "; ;") != 0 || cmd[0] == '|'
      || cmd[my_strlen(cmd) - 1] == '|' || cmd[my_strlen(cmd) - 1] == '>'
      || cmd[my_strlen(cmd) - 1] == '<' || cmd[0] == '<' || cmd[0] == '>')
    {
      my_putstr("Invalid null command.\n");
      return (0);
    }
  return (1);
}
