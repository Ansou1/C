/*
** atof.c for infectsh in /home/corrad_f//projet/infect
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Thu Apr  4 14:01:06 2013 florian corradin
** Last update Thu May 23 12:32:25 2013 florian corradin
*/

#include "42.h"
#include "script.h"

void	sig_fpe(int sig)
{
  if (g_trap.active == 1)
    exec_function(g_trap.s, g_trap.v, g_trap.i);
  else
    {
      sig = sig;
      my_putchar('\b');
      my_putchar('\b');
      my_putchar(128);
      my_putchar(128);
      my_putstr("\n");
      put_prompt();
    }
}

int	get_exp(int c, char *s, int e)
{
  int	sign;
  int	i;

  i = 0;
  sign = 1;
  if (c == 'e' || c == 'E')
    {
      c = *s++;
      if (c == '+')
	c = *s++;
      else if (c == '-')
	{
	  c = *s++;
	  sign = -1;
	}
      while (c >= '0' && c <= '9')
	{
	  i = i*10 + (c - '0');
	  c = *s++;
	}
      e += i * sign;
    }
  return (e);
}

double	get_double(int e, double a)
{
  while (e > 0)
    {
      a *= 10.0;
      e--;
    }
  while (e < 0)
    {
      a *= 0.1;
      e++;
    }
  return (a);
}

double		my_atof(char *s)
{
  double	a;
  int		e;
  int		c;

  a = 0.0;
  e = 0;
  if (s[0] == '-')
    return (-my_atof(&s[1]));
  while ((c = *s++) != '\0' && c >= '0' && c <= '9')
    {
      a = a * 10.0 + (c - '0');
    }
  if (c == '.')
    {
      while ((c = *s++) != '\0' && c >= '0' && c <= '9')
	{
	  a = a * 10.0 + (c - '0');
	  e = e - 1;
	}
    }
  e = get_exp(c, s, e);
  return (get_double(e, a));
}
