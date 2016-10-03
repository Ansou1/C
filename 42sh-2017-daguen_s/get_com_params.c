/*
** get_com_params.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sat Mar 16 18:18:01 2013 florian corradin
** Last update Wed Apr 10 11:18:32 2013 florian corradin
*/

#include "42.h"

int	get_str_com_cut(char *com, int i)
{
  i++;
  if (com[i] == '<' || com[i] == '>')
    i++;
  if (com[i] != '\0')
    i++;
  while (com[i] != '\0' && com[i] != ' ' && com[i] != '\t')
    i++;
  return (i);
}

char	*get_str_com(char *com)
{
  int	i;
  int	ctr;
  char	*ret;

  i = 0;
  ctr = 0;
  ret = xmalloc(my_strlen(com) + 1);
  while (com[i] != '\0' && is_redir(com, i) == 0)
    ret[ctr++] = com[i++];
  ret[ctr] = '\0';
  if (com[i] == '\0')
    return (ret);
  if (com[i] == '<' || com[i] == '>')
    i = get_str_com_cut(com, i);
  else
    return (ret);
  if (com[i] == '\0')
    return (ret);
  while (com[i] != '\0' && is_redir(com, i) == 0)
    ret[ctr++] = com[i++];
  ret[ctr] = '\0';
  return (ret);
}

char	*get_str_file(char *com)
{
  int	i;
  int	ctr;
  char	*ret;

  i = 0;
  ctr = 0;
  while (com[i] != '\0' && is_redir(com, i) == 0)
    i++;
  if (com[i] == '\0')
    return (NULL);
  if (com[i] != '<' && com[i] != '>')
    return (NULL);
  i++;
  if (com[i] == '<' || com[i] == '>')
    i++;
  if (com[i] == '\0')
    return (NULL);
  i++;
  ret = xmalloc(my_strlen(com) + 1);
  while (com[i] != '\0' && com[i] != ' ' && com[i] != '\t')
    {
      ret[ctr++] = com[i++];
    }
  ret[ctr] = '\0';
  return (ret);
}

t_string	get_com_params(char *com, t_string str)
{
  str.exec = get_str_com(com);
  str.file = get_str_file(com);
  return (str);
}
