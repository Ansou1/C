/*
** ex_history.c for 42sh in /home/daguen_s//42sh-2017-daguen_s
**
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
**
** Started on  Thu May 23 09:48:26 2013 simon daguenet
** Last update Fri May 31 19:08:46 2013 simon daguenet
*/

#include "42.h"

char	*rep_str(char *src, char *del, char *rep, int pos)
{
  int	i;
  int	j;
  int	k;
  char	*ret;

  i = 0;
  j = 0;
  k = 0;
  ret = malloc(my_strlen(src) + my_strlen(rep) + 1);
  if (ret == NULL)
    return (NULL);
  while (i < pos && src[i] != '\0')
    ret[j++] = src[i++];
  while (rep[k] != '\0')
    ret[j++] = rep[k++];
  k = 0;
  while (del[k++] != '\0' && src[i] != '\0')
    i++;
  while (src[i] != '\0')
    ret[j++] = src[i++];
  ret[j] = '\0';
  free(del);
  free(rep);
  free(src);
  return (ret);
}

char	*get_del(char *command)
{
  int	i;
  int	j;
  char	*str;

  i = 0;
  while (command[i] != '\0' && command[i] != ' ' && command[i] != '\t' &&
	 command[i] != '|' && command[i] != '&' && command[i] != ';' &&
	 command[i] != '<' && command[i] != '>')
    i++;
  str = malloc(i + 1);
  if (str == NULL)
    return (NULL);
  j = 0;
  while (j < i)
    {
      str[j] = command[j];
      j++;
    }
  str[j] = '\0';
  return (str);
}

char	*get_rep(char *command)
{
  if (command != NULL)
    command = replace_cmd_hist(command);
  return (command);
}

char	*ex_history(char *cmd)
{
  int	i;

  i = 0;
  if (cmd == NULL)
    return (NULL);
  while (cmd[i] != '\0')
    {
      if (strstr(cmd, "!!!") != NULL)
	return (cmd);
      if (cmd[i] == '!')
	{
	  cmd = rep_str(cmd, get_del(&cmd[i]), get_rep(get_del(&cmd[i])), i);
	  i = 0;
	}
      i++;
    }
  return (cmd);
}

void	bultins_history(t_com *list)
{
  if (list != NULL && list->commande != NULL && list->commande[0] != NULL)
    {
      if (strcmp(list->commande[0], "history") == 0)
	my_history(list->commande, info.hist);
    }
}
