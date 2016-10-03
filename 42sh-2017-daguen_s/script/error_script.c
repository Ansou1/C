/*
** error_script.c for script in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Sat May  4 21:04:26 2013 florian corradin
** Last update Sat May  4 21:28:59 2013 florian corradin
*/

#include "42.h"
#include "script.h"

void	my_put_error_script(char *str, int line)
{
  fprintf(stderr, "%s line: %d\n", str, line);
  g_stop_script = -1;
}
