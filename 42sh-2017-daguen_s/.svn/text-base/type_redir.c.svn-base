/*
** type_redir.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Wed Mar 13 14:11:52 2013 florian corradin
** Last update Mon Apr 29 13:19:33 2013 florian corradin
*/

#include "42.h"

int	is_multipipe_right(t_com *list)
{
  int	pipe2;

  pipe2 = 0;
  while (list != NULL)
    {
      if (list->redir == PIPE)
	pipe2++;
      else if ((list->redir == RIGHT || list->redir == D_RIGHT) && pipe2 == 0)
	return (0);
      else if (list->redir == LEFT || list->redir == D_LEFT)
	return (0);
      else if (list->redir == RIGHT && pipe2 > 0)
	return (1);
      else if (list->redir == D_RIGHT && pipe2 > 0)
	return (2);
      list = list->next;
    }
  return (0);
}

int	is_multipipe_left(t_com *list)
{
  int	cas;
  int	is_pipe;

  is_pipe = 0;
  if (list == NULL)
    return (0);
  if (list->redir != D_LEFT && list->redir != LEFT)
    return (0);
  cas = list->redir;
  list = list->next;
  if (list == NULL)
    return (0);
  while (list->redir == PIPE && list->next != NULL)
    {
      if (list->redir != PIPE)
	return (0);
      is_pipe++;
      list = list->next;
    }
  if ((list->redir == PIPE || list->redir == 0) && is_pipe != 0)
    return (cas);
  return (0);
}

int	is_multipipe_left_file(t_com *list)
{
  int	cas;

  if (list == NULL)
    return (0);
  if (list->redir != D_LEFT && list->redir != LEFT)
    return (0);
  cas = list->redir;
  list = list->next;
  if (list == NULL)
    return (0);
  while (list->next != NULL && list->redir == PIPE)
    list = list->next;
  if (list->redir != RIGHT && list->redir != D_RIGHT)
    return (0);
  return (cas);
}

int	is_multi_redir(t_com *list)
{
  if (list->redir != LEFT && list->redir != D_LEFT)
    return (0);
  list = list->next;
  if (list == NULL)
    return (0);
  if (list->redir != RIGHT && list->redir != D_RIGHT)
    return (0);
  return (1);
}

int	is_redir_simple(t_com *list)
{
  if (list->redir != 0 && list->next->redir == 0)
    return (list->redir);
  else
    return (0);
}
