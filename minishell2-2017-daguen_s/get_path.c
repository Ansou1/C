/*
** get_path.c for mysh in /home/daguen_s//secminishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar  9 12:06:31 2013 simon daguenet
** Last update Sat Mar  9 12:08:17 2013 simon daguenet
*/

#include "mysh.h"

void	init_var(int *var)
{
  var[0] = 0;
  var[1] = 0;
  var[2] = 5;
}

char	*get_path(char **env)
{
  int	i;
  char	*tab;

  tab = NULL;
  i = 0;
  while (env[i])
    {
      if (my_strncmp(env[i], "PATH=", 5) == 0)
        {
          tab = my_strdup_user(env[i]);
          i++;
        }
      else
        i++;
    }
  return (tab);
}

int	count_w(char *str)
{
  int	i;
  int	n;

  i = 5;
  n = 1;
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] == ':' && str[i + 1] != '\0')
        n = n + 1;
      i = i + 1;
    }
  return (n);
}

int	count_char(char *str)
{
  int	c;

  c = 0;
  while ((str[c] != ':') && (str[c] != '\0') && (str[c] != '\n'))
    c = c + 1;
  c = c + 1;
  return (c);
}

char	**wordtab_dbp(char *str)
{
  char	**tab;
  int	var[3];

  if (str == NULL)
    return (NULL);
  init_var(var);
  tab = xmalloc(sizeof(*tab) * ((count_w(str) + 1)));
  while (str[var[2]] != '\n' && str[var[2]] != '\0')
    {
      if (str[var[2]] == ':' || str[var[2]] == '\n')
        {
          while (str[var[2]] == ':')
            var[2] = var[2] + 1;
          var[0] = var[0] + 1;
          var[1] = 0;
        }
      tab[var[0]] = xmalloc(sizeof(**tab) * ((count_char(str + var[2]) + 1)));
      while ((str[var[2]] != ':')  && (str[var[2]] != '\n')
             && (str[var[2]] != '\0'))
        tab[var[0]][var[1]++] = str[var[2]++];
      tab[var[0]][var[1]] = '/';
      tab[var[0]][var[1] + 1] = '\0';
    }
  tab[var[0] + 1] = 0;
  return (tab);
}
