/*
** env.c for allum1 in /home/daguen_s//myalum1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Feb 10 19:09:07 2013 simon daguenet
** Last update Sun Feb 10 20:05:29 2013 simon daguenet
*/

#include "allum1.h"

char	*my_strdup_old(char *src)
{
  int	i;
  int	j;
  char	*chaine;

  i = 0;
  i = my_strlen(src) - 4;
  chaine = malloc(i + 1);
  if (chaine == NULL)
    return (NULL);
  j = 5;
  i = 0;
  while (src[j] != '\0')
    {
      chaine[i] = src[j];
      j = j + 1;
      i = i + 1;
    }
  chaine[i] = '\0';
  return (chaine);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (i < n)
    {
      if (s1[i] != s2[i])
        return (1);
      i++;
    }
  return (0);
}

char	*get_term(char **my_env, char *command)
{
  char	*str;
  int	i;

  str = NULL;
  i = 0;
  while (my_env[i])
    {
      if  (my_strncmp(my_env[i], command, 5) == 0)
        {
          str = my_strdup_old(my_env[i]);
          i++;
        }
      else
        i++;
    }
  return (str);
}

int	check_ac_av(int ac, char **av, char **env)
{
  char	*term;
  int	ret;

  av = av;
  if (env[0] == NULL)
    my_put_error(2);
  if (ac > 1)
    my_put_error(3);
  term = get_term(env, "TERM=");
  if (term == NULL)
    my_put_error_term(3);
  ret = tgetent(NULL, term);
  if (ret == -1 || ret == 0)
    my_put_error_term(1);
  free(term);
  my_clear_screen();
  my_putstr("\t\033[31m Welcome in my allum1 \033[37m\n");
  return (0);
}
