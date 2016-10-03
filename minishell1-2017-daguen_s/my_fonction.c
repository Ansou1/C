/*
** my_fonction8.c for mysh in /home/daguen_s//my_minishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Dec 23 12:32:50 2012 simon daguenet
** Last update Sun Dec 23 12:36:34 2012 simon daguenet
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <unistd.h>
#include <dirent.h>
#include <signal.h>
#include "mysh.h"

char	*get_value_oldpwd(char **my_env, char *command)
{
  int	i;
  char	*tab;

  i = 0;
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
