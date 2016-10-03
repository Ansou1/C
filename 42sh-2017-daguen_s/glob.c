/*
** glob.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Wed Mar 27 13:42:18 2013 florian corradin
** Last update Thu May 23 14:14:12 2013 simon daguenet
*/

#include "42.h"

char	*recup_glob(char **glob)
{
  char	*ret;
  char	*save;
  int	i;

  i = 1;
  if ((ret = my_strdup(glob[0])) == NULL)
    return (NULL);
  if (glob[i] != NULL)
    ret = my_strcat_free_strt(ret, " ");
  while (glob[i] != NULL)
    {
      if ((save = my_strdup(glob[i])) == NULL)
	return (NULL);
      if ((ret = my_strcat_free_all(ret, save)) == NULL)
	return (NULL);
      if (glob[i + 1] != NULL)
	ret = my_strcat_free_strt(ret, " ");
      i++;
    }
  my_free_tab(glob);
  return (ret);
}

char		*my_glob(char *globin)
{
  glob_t	globbuf;

  globbuf.gl_offs = 10;
  glob(globin, 0, NULL, &globbuf);
  if (globbuf.gl_pathv == NULL)
    {
      fprintf(stderr, "%s: No match\n", globin);
      return (NULL);
    }
  if (globbuf.gl_pathv[0] == NULL)
    {
      fprintf(stderr, "%s: No match\n", globin);
      return (NULL);
    }
  return (recup_glob(globbuf.gl_pathv));
}

char	*get_glob(char *str)
{
  int	i;
  char	*ret;

  i = 0;
  while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0' && str[i] != '\n')
    i++;
  if ((ret = malloc(i + 1)) == NULL)
    return (NULL);
  i = 0;
  while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0' && str[i] != '\n')
    {
      ret[i] = str[i];
      i++;
    }
  ret[i] = '\0';
  return (ret);
}

char	is_glob(char *str, int i)
{
  while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
    {
      if (is_c(str, i, '*') == 1 || is_c(str, i, '?') == 1)
	return (1);
      i++;
    }
  return (0);
}

char	*put_globin(char *com)
{
  int	i;
  char	*rep;
  char	*glob;
  int	a;

  i = 0;
  while (com[i] != '\0')
    {
      if (is_glob(com, i) == 1)
	{
	  rep = get_glob(&com[i]);
	  if (rep == NULL)
	    return (com);
	  glob = my_glob(rep);
	  if (glob == NULL)
	    return (NULL);
	  a = my_strlen(glob);
	  com = replace_in_str(com, rep, glob, i);
	  i = i + a - 1;
	}
      i++;
    }
  return (com);
}
