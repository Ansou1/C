/*
** error.c for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Wed Mar 13 16:29:38 2013 florian corradin
** Last update Thu Apr 11 13:52:11 2013 florian corradin
*/

#include "42.h"

void	my_put_error2(char *str)
{
  int	i;

  i = 0;
  if (my_strncmp(str, "invalide NULL commande\n", 22) == 1)
    put_file(FLINGUEUR, RED);
  else if (my_strncmp(str, "Missing name for redirect\n", 25) == 1)
    put_file(OPEN, RED);
  else if (my_str_comp(str, "Ambiguous input redirect.\n") == 1)
    put_file(VADOR, WHITE);
  else if (my_str_comp(str, ": No such file or directory.\n") == 1)
    put_file(WOLF, PINK);
  while (str[i] != '\0')
    {
      write(2, &str[i], 1);
      i++;
    }
  g_statu = -1;
}

void	my_put_error(char *str)
{
  int	i;

  i = 0;
  if (my_strncmp(str, "invalide NULL commande\n", 22) == 1)
    put_file(FLINGUEUR, RED);
  else if (my_strncmp(str, "Missing name for redirect\n", 25) == 1)
    put_file(OPEN, RED);
  else if (my_str_comp(str, "Ambiguous input redirect.\n") == 1)
    put_file(VADOR, WHITE);
  else if (my_str_comp(str, ": No such file or directory.\n") == 1)
    put_file(WOLF, PINK);
  while (str[i] != '\0')
    {
      write(2, &str[i], 1);
      i++;
    }
  g_statu = -1;
  kill(getpid(), SIGKILL);
}

void	my_put_on_error(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      write(2, &str[i], 1);
      i++;
    }
}
