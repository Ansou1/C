/*
** prompt.c for infect in /home/corrad_f//projet/infect
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Wed Apr 24 21:27:15 2013 florian corradin
** Last update Wed May  8 14:33:05 2013 florian corradin
*/

#include "42.h"

int	put_effect2(char *p, int i)
{
  if (my_strncmp("%spa", &p[i], 4))
    return (aff_img("ascii_art/star_w_space", 3));
  else if (my_strncmp("%r", &p[i], 2))
    {
      my_putstr("\n");
      return (1);
    }
  else if (my_strncmp("%t", &p[i], 2))
    {
      aff_time();
      return (1);
    }
  return (0);
}

int	put_effect(char *p, int i)
{
  if (my_strncmp("%blue", &p[i], 5))
    return (effect_prompt(BLUE, 4));
  else if (my_strncmp("%red", &p[i], 4))
    return (effect_prompt(RED, 3));
  else if (my_strncmp("%cian", &p[i], 5))
    return (effect_prompt(CIAN, 4));
  else if (my_strncmp("%pink", &p[i], 5))
    return (effect_prompt(PINK, 4));
  else if (my_strncmp("%white", &p[i], 6))
    return (effect_prompt(WHITE, 5));
  else if (my_strncmp("%yellow", &p[i], 7))
    return (effect_prompt(YELLOW, 6));
  else if (my_strncmp("%green", &p[i], 6))
    return (effect_prompt(GREEN, 5));
  else if (my_strncmp("%s", &p[i], 2))
    return (effect_prompt(SOU, 1));
  else if (my_strncmp("%&", &p[i], 2))
    return (effect_prompt(STOP, 1));
  else if (my_strncmp("%g", &p[i], 2))
    return (effect_prompt(GRAS, 1));
  else if (my_strncmp("%c", &p[i], 2))
    return (effect_prompt(CLIGNO, 1));
  else if (my_strncmp("%vo", &p[i], 3))
    return (effect_prompt(VO, 2));
  return (put_effect2(p, i));
}

void	put_aff(char *p)
{
  int	i;

  i = 0;
  while (p[i])
    {
      if (my_strncmp("%com", &p[i], 4))
	{
	  my_put_nbr(g_com_ctr);
	  i += 3;
	}
      else if (is_c(p, i, '%'))
	i += put_effect(p, i);
      else
	my_putchar(p[i]);
      i++;
    }
  my_putstr(STOP);
}

char	put_prompt()
{
  char	*aff;

  if ((aff = my_getenv("PS1")) == NULL)
    {
      my_putstr("$>");
      return (0);
    }
  aff = check_var(aff, 0);
  put_aff(aff);
  return (0);
}
