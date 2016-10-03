/*
** prompt_effect.c for 42 in /home/corrad_f//projet/infect
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Wed May  8 14:30:53 2013 florian corradin
** Last update Wed May  8 14:32:57 2013 florian corradin
*/

#include "42.h"

int	aff_img(char *name, int nb)
{
  int	save;

  save = g_ascii;
  g_ascii = 1;
  put_file(name, WHITE);
  g_ascii = save;
  return (nb);
}

int	effect_prompt(char *str, int ret)
{
  my_putstr(str);
  return (ret);
}
