/*
** commande.c for mini in /home/corrad_f//projet/minishell1
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Thu Dec 13 13:31:12 2012 florian corradin
** Last update Wed Apr 10 09:17:15 2013 florian corradin
*/

#include "42.h"

char	*my_copy_path(char *ret, char *path)
{
  int	i;
  int	a;

  i = 5;
  a = 0;
  while (path[i] != '\0')
    {
      if (path[i] == ':')
	{
	  ret[a] = '/';
	  ret[a + 1] = ' ';
	  a += 2;
	  i++;
	}
      else
	{
	  ret[a] = path[i];
	  a++;
	  i++;
	}
    }
  ret[a] = '/';
  ret[a + 1] = '\0';
  return (ret);
}

int	have_nbr_of_path(char *path)
{
  int	i;
  int	ctr;

  ctr = 0;
  i = 0;
  while (path[i] != '\0')
    {
      if (path[i] == ':')
	ctr++;
      i++;
    }
  return (ctr + 1);
}

char	*get_good_path(char *path)
{
  char	*ret;
  int	nb_path;

  nb_path = have_nbr_of_path(path);
  ret = malloc(my_strlen(path) - 5 + 1 + nb_path);
  check_malloc(ret);
  ret = my_copy_path(ret, path);
  return (ret);
}

char	*get_void_path()
{
  char	*ret;
  char	*ret2;
  int	i;
  int	i2;

  i = 0;
  i2 = 0;
  ret = my_fill_path();
  ret2 = xmalloc(my_strlen(ret) * 2);
  while (ret[i] != '\0')
    {
      if (ret[i] == ':')
	{
	  ret2[i2++] = '/';
	  ret2[i2++] = ' ';
	  i++;
	}
      else
	ret2[i2++] = ret[i++];
    }
  ret2[i2] = '\0';
  free(ret);
  return (ret2);
}

char	**my_get_path(char **env)
{
  int	i;
  char	*path;
  char	**ret;

  path = NULL;
  i = 0;
  while (env[i] != NULL)
    {
      if (my_strncmp("PATH=", env[i], 5) == 1)
	{
	  path = get_good_path(env[i]);
	}
      i++;
    }
  if (path == NULL)
    path = get_void_path();
  ret = my_str_to_wordtab(path);
  free(path);
  return (ret);
}
