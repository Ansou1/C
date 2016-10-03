/*
** builtins.c for mysh2 in /home/daguen_s//secminishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar  9 12:16:59 2013 simon daguenet
** Last update Sat Mar  9 12:18:21 2013 simon daguenet
*/

#include "mysh.h"

void	my_builtin_env(char **my_env)
{
  int	i;

  i = 0;
  while (my_env[i] != 0)
    {
      my_putstr(my_env[i]);
      my_putchar('\n');
      i = i + 1;
    }
}

void	my_builtin_setenv(char **my_env, char **tab_co)
{
  int	i;
  int	j;
  char	*str;
  char	*tmp;

  i = my_strlen_dbl(tab_co);
  j = my_strlen_dbl(my_env);
  if (i == 1)
    my_builtin_env(my_env);
  else if (i != 3)
    (i < 3) ? my_putstr(MIN_I) : my_putstr(SUP_I);
  else
    {
      tmp = my_strcat(tab_co[1], "=");
      str = my_strcat(tmp, tab_co[2]);
      i = 0;
      while ((my_env[i] != NULL) &&
             (my_strncmp(my_env[i], tmp, my_strlen(tmp)) != 0) && (i = i + 1));
      my_env[i] = str;
      if (i == j)
        my_env[i + 1] = 0;
    }
}

void	put_my_oldpwd(char **my_env, char **env_for_cd)
{
  env_for_cd[0] = "setenv";
  env_for_cd[1] = "OLDPWD";
  env_for_cd[2] = get_pwd_for_oldpwd(my_env, "PWD");
  env_for_cd[3] = NULL;
  my_builtin_setenv(my_env, env_for_cd);
}

int	my_builtin_unsetenv(char **my_env, char **tab_co)
{
  int	i;

  i = my_strlen_dbl(tab_co);
  if (i == 1)
    {
      my_putstr("unsetenv: Too few arguments.\n");
      return (0);
    }
  tab_co[1] = my_strcat(tab_co[1], "=");
  i = 0;
  while ((my_env[i] != NULL)  &&
         (my_strncmp(my_env[i], tab_co[1], my_strlen(tab_co[1])) != 0))
    i = i + 1;
  while (my_env[i] != 0)
    {
      my_env[i] = my_env[i + 1];
      i++;
    }
  return (0);
}

void	my_builtin_cd(char **my_env, char **tab_co)
{
  int	i;
  char	*env_for_cd[4];
  char	*env_pwd[4];

  env_pwd[0] = "setenv";
  env_pwd[1] = "PWD";
  env_pwd[3] = NULL;
  i = my_strlen_dbl(tab_co);
  if (i > 2)
    my_putstr("cd: Too many arguments.\n");
  else
    {
      if (i == 1 || ((tab_co[1][0] == '~') && (my_strlen(tab_co[1]) == 1)))
        env_pwd[2] = my_strcat("/home/", get_value_user(my_env, "USER="));
      else if (tab_co[1][0] == '-' && my_strlen(tab_co[1]) == 1)
        env_pwd[2] = get_value_oldpwd(my_env, "OLDPWD");
      else if (tab_co[1][my_strlen(tab_co[1]) - 1] == '/')
        env_pwd[2] = tab_co[1];
      else if (tab_co[1][my_strlen(tab_co[1]) - 1] != '/')
        env_pwd[2] = my_strcat(tab_co[1], "/");
      put_my_oldpwd(my_env, env_for_cd);
      if (existing_directory(env_pwd[2]) == 0 && (chdir(env_pwd[2]) == 0))
        my_builtin_setenv(my_env, env_pwd);
    }
}
