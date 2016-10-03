/*
** mysh.c for minishell in /home/daguen_s//my_minishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Dec 15 10:33:29 2012 simon daguenet
** Last update Sat Dec 29 21:24:24 2012 simon daguenet
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

void	guid_other_command(char **my_env, char **tab_co)
{
  pid_t	pid;

  if ((pid = fork()) == -1)
    {
      my_putstr("Error: fork problem\n");
      exit(EXIT_FAILURE);
    }
  if (pid == 0)
    processus_son(my_env, tab_co);
  else
    processus_father(pid);
}

void	guid_command(char **my_env, char *command)
{
  char	**tab_co;

  tab_co = my_str_to_wordtab(command);
  if (my_strcmp(command, "exit") == 0)
    exit (EXIT_SUCCESS);
  else if (my_strcmp(tab_co[0], "env") == 0)
    my_builtin_env(my_env);
  else if (my_strcmp(tab_co[0], "setenv") == 0)
    my_builtin_setenv(my_env, tab_co);
  else if (my_strcmp(tab_co[0], "unsetenv") == 0)
    my_builtin_unsetenv(my_env, tab_co);
  else if (my_strcmp(tab_co[0], "cd") == 0)
    my_builtin_cd(my_env, tab_co);
  else
    guid_other_command(my_env, tab_co);
}

char	*my_epurstr(char *str)
{
  char	*tab;
  int	i;
  int	j;

  i = 0;
  j = 0;
  tab = malloc(sizeof(char *) * (my_strlen(str) + 2));
  if (str[i] == ' ' || str[i] == '\t')
    while ((str[i] == ' ' || str[i] == '\t') && (i = i + 1));
  while (str[i])
    {
      if (str[i] == ' ' || str[i] == '\t')
        {
          while ((str[i] == ' ' || str[i] == '\t') && (i = i + 1));
          tab[j] = ' ';
          j++;
        }
      else
        tab[j++] = str[i++];
    }
  if (tab[j - 1] == ' ')
    tab[j - 1] = '\0';
  tab[j] = '\0';
  return (tab);
}

void	my_prompt(char **my_env)
{
  int	ret;
  char	buffer[BUFF + 1];
  char	*str;

  signal(SIGINT, get_sigint);
  while (42)
    {
      str = NULL;
      my_putstr("$>");
      ret = read(0, buffer, BUFF);
      if (ret == 0)
	{
	  my_putchar('\n');
	  exit(EXIT_SUCCESS);
	}
      buffer[ret - 1] = '\0';
      str = my_epurstr(buffer);
      if (ret >= BUFF)
	{	
	  my_putstr("Buffer overflow, too many char\n");
	  exit(EXIT_SUCCESS);
	}
      else if (my_strcmp(str, "") != 0)
	guid_command(my_env, str);
    }
}

int	main(int argc, char **argv, char **env)
{
  char	**my_env;

  my_env = malloc(sizeof(**env));
  if (my_env == NULL || env[0] == NULL)
    {
      my_putstr("program without env\n");
      exit(EXIT_FAILURE);
    }
  else
    {
      my_env = env;
      my_prompt(my_env);
    }
  return (0);
}
