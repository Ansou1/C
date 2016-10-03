/*
** buitins.c for 42sh in /home/corrad_f//projet/infect
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Thu Apr 11 18:45:07 2013 florian corradin
** Last update Sat May 18 16:50:17 2013 florian corradin
*/

#include "42.h"

int	is_buitins(char **com)
{
  if (com == NULL)
    return (0);
  if (com[0] == NULL)
    return (0);
  if (my_str_comp("echo", com[0]))
    return (1);
  else if (my_str_comp("setenv", com[0]))
    return (1);
  else if (my_str_comp("unsetenv", com[0]))
    return (1);
  else if (my_str_comp("cd", com[0]))
    return (1);
  else if (my_str_comp("env", com[0]))
    return (1);
  else if (my_str_comp("m", com[0]))
    return (1);
  else if (my_str_comp("alias", com[0]))
    return (1);
  return (0);
}

int	man(char **str)
{
  if (str == NULL || str[0] == NULL)
    return (FAIL);
  if (my_str_comp(str[0], "m"))
    {
      infectsh(my_strdup("cat man_infect | less"));
      return (SUCCESS);
    }
  return (FAIL);
}

void	my_bultins(char **com)
{
  if (is_cd(com))
    my_cd(com, 0);
  if (man(com) != SUCCESS)
    my_env_fct(com, 0);
}

int	ex_bultins(char **com)
{
  if (my_strncmp("echo", com[0], 4))
    {
      my_echo(&com[1]);
      return (1);
    }
  return (0);
}
