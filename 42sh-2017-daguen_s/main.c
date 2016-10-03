/*
** main.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Fri Feb 22 17:09:43 2013 florian corradin
** Last update Sun May 26 14:09:39 2013 antoine simon
*/

#include "42.h"

void		free_alias(void)
{
  t_alias	*tmp;

  tmp = g_alias;
  while (tmp)
    {
      tmp = g_alias->next;
      if (g_alias->alias != NULL)
	free(g_alias->alias);
      if (g_alias->com != NULL)
	free(g_alias->com);
      free(g_alias);
      g_alias = tmp;
    }
}

int	exit_shell(char *str)
{
  int	i;

  i = 0;
  free_alias();
  my_free_tab(info.env);
  my_free_tab(info.path);
  free_list_histo(info.hist);
  if (info.home != NULL)
    free(info.home);
  if (info.old_pwd != NULL)
    free(info.old_pwd);
  if (info.term != NULL)
    free(info.term);
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  if (str[i] == '\0')
    {
      put_file(STORM_TROOPER, WHITE);
      return (0);
    }
  i = my_atoi(&str[i]);
  put_file(STORM_TROOPER, WHITE);
  return (i);
}

char	*module_str(char *command_line)
{
  int	i;

  i = 0;
  if ((command_line = get_str_inhib(command_line)) == NULL)
    return (NULL);
  if ((command_line = my_epurstr_inib(command_line)) == NULL)
    return (NULL);
  while (command_line[i] != '\0' && command_line[i] != '$')
    i++;
  if (command_line[i] == '$')
    if ((command_line = check_var(command_line, 0)) == NULL)
      return (NULL);
  if (my_strncmp("setenv", command_line, 6) == 0 &&
      my_strncmp("unsetenv", command_line, 8) == 0)
    command_line = put_globin(command_line);
  return (command_line);
}

int	my_prompt (void)
{
  char	*command_line;

  g_com_ctr = 0;
  put_prompt();
  while ((command_line = get_cmd_all()))
    {
      info.hist = get_cmd_for_history(info.hist, command_line);
      if (check_inhibiteur(command_line) == SUCCESS)
	{
	  if ((command_line = module_str(command_line)) != NULL)
	    {
	      if (my_strncmp(command_line, "exit", 4) == 1)
		if (command_line[4] == ' ' || command_line[4] == '\0')
		  return (exit_shell(&command_line[4]));
	      if (my_shell(command_line) == FAIL)
		return (FAIL);
	    }
	}
      put_prompt();
      xfree(command_line);
      signal(SIGINT, sig_fpe);
    }
  return (exit_shell("0"));
}

int	main (int ac, char **av, char **env)
{
  signal(SIGINT, sig_fpe);
  check_option(ac, av);
  if (env[0] != NULL)
    {
      info.env = my_copy_tab(env);
      info.path = my_get_path(info.env);
    }
  else
    {
      put_file(DIABLE, RED);
      if ((info.env = malloc(sizeof (char **) * 1)) == NULL)
	return (EXIT_FAILURE);
      info.env[0] = NULL;
      info.path = my_get_path(info.env);
      if (info.path == NULL)
	return (1);
    }
  info.home = my_getenv("HOME");
  if (check_c(ac, av) == -1)
    return (0);
  init_alias(ac, av);
  return (my_prompt());
}
