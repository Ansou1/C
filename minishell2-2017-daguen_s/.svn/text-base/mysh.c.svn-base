/*
** mysh.c for mysh in /home/daguen_s//secminishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Fri Mar  1 19:53:30 2013 simon daguenet
** Last update Sun Mar 10 20:37:45 2013 simon daguenet
*/

#include "mysh.h"

char	*my_epurstr(char *str)
{
  int	i;
  char	*ret;
  int	a;

  a = 0;
  ret = xmalloc(my_strlen(str) + 2);
  ret[my_strlen(str)] = '\0';
  i = 0;
  while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
    i++;
  while (str[i] != '\0')
    {
      if ((str[i] == ' ' || str[i] == '\t') &&
          (str[i + 1] == ' ' || str[i + 1] == '\t'))
        i++;
      else
        ret[a++] = str[i++];
    }
  if (a > 0)
    if (ret[a - 1] == ' ' || ret[a - 1] == '\t')
      ret[a - 1] = '\0';
  ret[a] = '\0';
  xfree(str);
  return (ret);
}

void	guid_command_all(char **env, char *cmd)
{
  char	**all_cmd;
  char	**pipe_cmd;
  int	i;
  int	taille;

  all_cmd = NULL;
  all_cmd = str_to_wordtab(cmd, ";");
  i = 0;
  while (all_cmd[i])
    {
      all_cmd[i] = my_epurstr(all_cmd[i]);
      if (good_cmd(all_cmd[i]))
	{
	  if (my_strstr(all_cmd[i], "|") != 0)
	    {
	      pipe_cmd = clean_tab(str_to_wordtab(all_cmd[i], "|"));
	      taille = my_strlen_dbl(pipe_cmd);
	      gestion_cmd_pipe(env, pipe_cmd, taille);
	    }
	  else if (my_strcmp(all_cmd[i], "") != 0)
	    gestion_cmd_other(env, all_cmd[i]);
	}
      i++;
    }
}

void	my_prompt(char **env)
{
  int	ret;
  char	*cmd;

  while (42)
    {
      cmd = NULL;
      cmd = xmalloc((sizeof(char *)) * (BUFF + 1));
      my_putstr("$>");
      ret = read(0, cmd, BUFF);
      (ret == -1) ? my_put_error("Error with read\n") : 0;
      (ret == 0) ? my_putstr("\n") : 0;
      cmd[ret - 1] = '\0';
      cmd = my_epurstr(cmd);
      /* (ret >= BUFF) ?  my_put_error("buffer overflow, too many char\n") : 0; */
      if ((good_cmd(cmd)) == 1)
  	guid_command_all(env, cmd);
      xfree(cmd);
    }
}

int	main(int argc, char **argv, char **env)
{
  char	**my_env;

  argc = argc;
  argv = argv;
  if (env[0] == NULL)
    my_put_error("program without env, soo bad...!!!\n");
  my_env = malloc(sizeof(**env));
  if (my_env == NULL)
    my_put_error("Error with malloc my_env in main function\n");
  else
    {
      my_env = env;
      my_prompt(my_env);
    }
  return (0);
}
