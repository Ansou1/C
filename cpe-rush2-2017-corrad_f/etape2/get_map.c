/*
** get_map.c for sudoku in /home/corrad_f//projet/sudoku
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Sat Apr 20 20:19:28 2013 florian corradin
** Last update Sun Apr 21 22:25:42 2013 simon daguenet
*/

#include "sudoku.h"

char	*get_clean_line(char *s, char *base)
{
  int	i;
  char	*ret;
  int	a;

  a = 0;
  i = 0;
  ret = xmalloc(strlen(s) / 2 + 1);
  while (s[i])
    {
      if (s[i] != ' ')
	my_puterror("Missing space");
      i++;
      ret[a++] = s[i++];
      check_base(ret[a - 1], base);
    }
  ret[a] = '\0';
  if (strlen(ret) != strlen(base))
    my_puterror("Map error");
  return (ret);
}

char	*get_sudo_line(char *s, char *base)
{
  int	i;

  i = 0;
  if (s[0] != '|')
    my_puterror("Map error");
  if (s[1] == '-')
    return (strdup(s));
  i = strlen(s);
  s[i - 1] = '\0';
  return (get_clean_line(&s[1], base));
}

char	**get_sudo(char *base)
{
  char	*s;
  char	**su;

  su = NULL;
  while ((s = get_next_line(0)) != NULL)
    {
      su = realloc_tab(su, get_sudo_line(s, base));
      free(s);
    }
  return (su);
}

int	send_map(char **su, char *base)
{
  int	i;
  char	*tmp;
  int	len;

  len = strlen(base);
  i = 1;
  while (su[i])
    {
      tmp = su[i + len];
      su[i + len] = NULL;
      get_good_sudo(&su[i], base);
      su[i + len] = tmp;
      if (su[i + len + 1] == NULL)
	return (0);
      i = i + len + 2;
      printf("#### BOCAL ROXX ####\n");
    }
  return (0);
}

int	main(int ac, char **av)
{
  char	**sudo;
  char	*base;

  if (ac == 2)
    base = av[1];
  else
    base = "123456789";
  sudo = get_sudo(base);
  if (sudo == NULL || sudo[0] == NULL)
    my_puterror("Map error");
  check_map(sudo, base);
  send_map(sudo, base);
  my_freetab(sudo);
  return (0);
}
