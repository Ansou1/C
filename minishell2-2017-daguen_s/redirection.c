/*
** redirection.c for mysh2 in /home/daguen_s//secminishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar  9 12:22:58 2013 simon daguenet
** Last update Sat Mar  9 13:05:32 2013 simon daguenet
*/

#include "mysh.h"

int	get_redirection(char *str)
{
  if (my_strstr(str, ">>") != 0)
    return (0);
  else if (my_strstr(str, ">") != 0)
    return (1);
  else if (my_strstr(str, "<<") != 0)
    return (2);
  else if (my_strstr(str, "<") != 0)
    return (3);
  return (4);
}

void	redi_out(char **env, char **tab_re, int v_redi)
{
  int	fd;

  if (v_redi == 1)
    {
      if ((fd = open(tab_re[1], O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU)) != -1)
        {
          my_dup(fd, 1);
          close(fd);
          processus_son(env, str_to_wordtab(tab_re[0], " "));
        }
      else
        my_putstr("Error with open!\n");
    }
  else if (v_redi == 0)
    {
      if ((fd = open(tab_re[1], O_WRONLY | O_CREAT | O_APPEND, S_IRWXU)) != -1)
        {
          my_dup(fd, 1);
          close(fd);
          processus_son(env, str_to_wordtab(tab_re[0], " "));
        }
      else
        my_putstr("Error with open!\n");
    }
}

t_list		*dbl_redi_left(char **tab_redi)
{
  t_list	*list;
  char		*buff;
  int		ret;

  list = NULL;
  while (42)
    {
      buff = xmalloc(sizeof(*buff) * BUFF);
      my_putstr("? ");
      ret = read(0, buff, BUFF);
      (ret == -1) ? my_put_error("Error with read\n") : 0;
      (ret == 0) ? my_putstr("\n") : 0;
      buff[ret - 1] = '\0';
      if (my_strcmp(buff, tab_redi[1]) == 0)
        {
          xfree(buff);
          my_rev_list(&list);
          return (list);
        }
      list = my_put_in_list(&list, buff);
      xfree(buff);
    }
}

void		redi_in(char **env, char **tab_redi, int v_redi)
{
  int		fd;
  t_list	*list;
  char		**tmp;

  if (v_redi == 3)
    {
      if ((fd = open(tab_redi[1], O_RDONLY)) != -1)
        {
          my_dup(fd, 0);
          close(fd);
          processus_son(env, str_to_wordtab(tab_redi[0], " "));
        }
      else
        my_putstr("Error with open!\n");
    }
  else if (v_redi == 2)
    {
      list = dbl_redi_left(tab_redi);
      tmp = str_to_wordtab(tab_redi[0], " ");
      if (tmp[1] != NULL)
        processus_son(env, tmp);
      aff_list(&list);
      free_list(list);
    }
}

void	gestion_redirection(char **env, char *cmd, int v_redi)
{
  char	**tab_redi;
  char	**redi;
  int	pid;

  redi = init_redi(redi);
  tab_redi = clean_tab(str_to_wordtab(cmd, redi[v_redi]));
  if ((pid = fork()) == -1)
    my_putstr("Error: fork failure !\n");
  else if (pid == 0)
    {
      if (tab_redi[0] != NULL)
        {
          if (v_redi == 0 || v_redi == 1)
            redi_out(env, tab_redi, v_redi);
          else
            redi_in(env, tab_redi, v_redi);
        }
    }
  else
    processus_father(pid);
}
