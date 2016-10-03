/*
** commande.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Mon Mar 11 13:57:48 2013 florian corradin
** Last update Sat May 25 15:35:03 2013 florian corradin
*/

#include "42.h"

void	my_wait2(void)
{
  int	status;

  wait3(&status, 0, NULL);
  if (!WIFEXITED(status) || status != 0)
    {
      if (status == SIGSEGV)
	{
	  fprintf(stderr, "Segmentation fault (core dumped).\n");
	  put_file(SEG, RED);
	}
      if (status == SIGKILL && g_statu != -1)
	{
	  fprintf(stderr, "Killed (core dumped).\n");
	  put_file(KILL, RED);
	}
    }
}

void	my_wait(void)
{
  int	status;

  wait3(&status, 0, NULL);
  g_old_com = status % 10;
  if (!WIFEXITED(status) || status != 0)
    {
      g_statu = -1;
      g_old_com = (status == 9 ? 1 : g_old_com);
      if (status == SIGSEGV)
	{
	  fprintf(stderr, "Segmentation fault (core dumped).\n");
	  put_file(SEG, RED);
	}
    }
}

void	exec_commande_in_son(t_com *list)
{
  int	cas;

  if (list->redir == 0)
    my_exec(list->commande);
  else if (is_multi_redir(list) == 1)
    multiredir(list);
  else if (is_multipipe(list) == 1)
    multipipe(list);
  else if ((cas = is_multipipe_right(list)) != 0)
    multipipe_right(list, cas);
  else if ((cas = is_multipipe_left(list)) != 0)
    multipipe_left(list, cas, NULL);
  else if ((cas = is_multipipe_left_file(list)) != 0)
    multipipe_left_file(list, cas);
  else if ((cas = is_redir_simple(list)) != 0)
    redir_simple(list, cas);
  else
    {
      if (get_nbr_of_redir(list))
	my_put_error("Ambiguous output redirect.\n");
      else
	my_put_error("Ambiguous intput redirect.\n");
      kill(getpid(), SIGKILL);
    }
}

int	go_script(char **com)
{
  if (com == NULL || com[0] == NULL)
    return (0);
  if (my_strncmp("./", com[0], 2))
    {
      if (is_scripting(&com[0][2]) == 1)
	my_script(com);
      else
	return (0);
    }
  else if (is_scripting(com[0]))
    my_script(com);
  else
    return (0);
  return (1);
}

void		my_exec_commande(t_com *list)
{
  pid_t		pid;

  g_msg_error = NULL;
  list = clean_command(list);
  if (go_script(list->commande) == 0)
    {
      if (list != NULL)
	if (list->commande != NULL)
	  if (my_str_comp(list->commande[0], "alias"))
	    g_alias = alias_bult(list->commande);
      pid = xfork(1);
      if (pid == 0)
	exec_commande_in_son(list);
      else
      	my_wait();
      if (g_msg_error != NULL)
	{
	  fprintf(stderr, "%s\n", g_msg_error);
	  free(g_msg_error);
	}
    }
  g_com_ctr++;
}
