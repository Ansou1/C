/*
** get_value.c for mysh2 in /home/daguen_s//secminishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar  9 12:20:34 2013 simon daguenet
** Last update Sat Mar  9 13:03:23 2013 simon daguenet
*/

#include "mysh.h"

char	*get_pwd_for_oldpwd(char **my_env, char *command)
{
  int	i;
  char	*tab;

  tab = NULL;
  i = 0;
  while (my_env[i])
    {
      if (my_strncmp(my_env[i], command, 3) == 0)
        {
          tab = my_strdup_oldpwd(my_env[i]);
          i++;
        }
      else
        i++;
    }
  return (tab);
}

char	*get_value_user(char **my_env, char *command)
{
  int	i;
  char	*tab;

  tab = NULL;
  i = 0;
  while (my_env[i])
    {
      if (my_strncmp(my_env[i], command, 5) == 0)
        {
          tab = my_strdup_user(my_env[i]);
          i++;
        }
      else
        i++;
    }
  if (tab != NULL)
    tab = my_strcat(tab, "/");
  return (tab);
}

char	*get_value_oldpwd(char **my_env, char *command)
{
  int	i;
  char	*tab;

  i = 0;
  tab = NULL;
  while (my_env[i])
    {
      if (my_strncmp(my_env[i], command, 6) == 0)
        {
          tab = my_strdup_old(my_env[i]);
          i++;
        }
      else
        i++;
    }
  return (tab);
}

int	existing_directory(char *path)
{
  DIR	*dirp;
  int	i;

  if (path == NULL)
    return (1);
  if ((dirp = opendir(path)) == NULL)
    {
      my_printf("%s: No such file or directory.\n", path);
      return (1);
    }
  if ((i = closedir(dirp)) == -1)
    {
      my_printf("ERROR : closedir problem \n");
      exit (EXIT_FAILURE);
    }
  else
    return (0);
}
