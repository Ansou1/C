/*
** clean_pars_line.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Tue Feb 26 08:49:18 2013 florian corradin
** Last update Wed Apr 10 09:23:46 2013 florian corradin
*/

#include "42.h"

char	*dell_tab(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\t')
	str[i] = ' ';
      i++;
    }
  return (str);
}

int	is_redir(char *str, int pos)
{
  if (str[0] == '\0')
    return (0);
  else if (is_c(str, pos, '|'))
    return (1);
  else if (is_c(str, pos, '<') == 1 && str[pos + 1] == '<')
    return (2);
  else if (is_c(str, pos, '>') == 1 && str[pos + 1] == '>')
    return (3);
  else if (is_c(str, pos, '<'))
    return (4);
  else if (is_c(str, pos, '>'))
    return (5);
  else
    return (0);
}

char	*my_strcopy_redir(char *ret, char *sym, int *ctr, int *i)
{
  int	ind;

  ind = 0;
  while (sym[ind] != '\0')
    {
      ret[*ctr] = sym[ind];
      *i = *i + 1;
      *ctr = *ctr + 1;
      ind++;
    }
  *i = *i - 1;
  return (ret);
}

char	*get_redir_in_str(char *ret, char *com, int *ctr, int *i)
{
  int	redir;
  char	sym[3];

  sym[0] = '\0';
  sym[1] = '\0';
  sym[2] = '\0';
  redir = is_redir(com, 0);
  if (redir == 1)
    sym[0] = '|';
  else if (redir == 2)
    {
      sym[0] = '<';
      sym[1] = '<';
    }
  else if (redir == 3)
    {
      sym[0] = '>';
      sym[1] = '>';
    }
  else if (redir == 4)
    sym[0] = '<';
  else if (redir == 5)
    sym[0] = '>';
  ret = my_strcopy_redir(ret, sym, ctr, i);
  return (ret);
}

char	*clear_commande_line(char *com)
{
  char	*ret;
  int	i;
  int	a;

  a = 0;
  i = 0;
  ret = malloc(my_strlen(com) * 3 + 2);
  check_malloc(com);
  while (com[i] != '\0')
    {
      while (is_redir(com, i) == 0 && com[i] != '\0')
	ret[a++] = com[i++];
      if (com[i] != '\0')
	{
	  if (i > 0 && a > 0)
	    if (com[i - 1] != ' ')
	      ret[a++] = ' ';
	  ret = get_redir_in_str(ret, &com[i], &a, &i);
	  if (com[i + 1] != ' ' && com[i + 1] != '\0')
	    ret[a++] = ' ';
	  i++;
	}
    }
  ret[a] = '\0';
  return (ret);
}
