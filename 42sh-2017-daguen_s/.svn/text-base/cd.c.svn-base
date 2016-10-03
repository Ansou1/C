/*
** cd.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sat Mar 30 12:19:44 2013 florian corradin
** Last update Thu May 23 17:52:39 2013 simon daguenet
*/

#include "42.h"

int	change_directory(char **com, int mod)
{
  char	*pwd;

  if ((pwd = my_get_pwd()) == NULL)
    return (FAIL);
  if (chdir(com[1]) == 0)
    {
      replace_old_pwd(pwd);
      return (replace_env());
    }
  else
    g_statu = -1;
  if (mod == 1)
    fprintf(stderr, "%s: %s\n", com[1], strerror(errno));
  return (SUCCESS);
}

int	my_cd(char **com, int mod)
{
  int	len;

  len = my_tablen(com);
  if (len > 2 && mod == 1)
    {
      fprintf(stderr, "cd : Too many arguments.\n");
      g_statu = -1;
      return (SUCCESS);
    }
  else if (len == 1)
    return (go_home(mod));
  else if (my_str_comp("-", com[1]) == 1)
    return (go_back(mod));
  else
    return (change_directory(com, mod));
}
