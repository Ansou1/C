/*
** echo.c for infect in /home/corrad_f//projet/infect/script
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Mon Apr 22 21:39:57 2013 florian corradin
** Last update Sun May 26 14:13:09 2013 antoine simon
*/

#include "42.h"

void	put_opt(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\\')
	{
	  if (str[i + 1] == '0')
	    my_putchar((char)my_strtoll(&str[i + 2], "01234567"));
	  i++;
	  while (is_digit(str[i]))
	    i++;
	  i--;
	}
      else
	my_putchar(str[i]);
      i++;
    }
}

void	echo_e(char **com, char mod)
{
  int	i;

  i = 0;
  while (com[i])
    {
      if (!is_option(com[i]))
	put_opt(com[i]);
      i++;
    }
  if (mod == 1)
    my_putchar('\n');
}

char	option(char **com)
{
  int	i;
  int	ret;

  i = 0;
  ret = 0;
  while (com[i])
    {
      if (com[i][0] == '-')
	{
	  if (com[i][1] != '\0')
	    {
	      if (com[i][1] == 'e' || com[i][2] == 'e')
		ret += 1;
	      if (com[i][1] == 'n' || com[i][2] == 'n')
		ret += 10;
	    }
	}
      i++;
    }
  return (ret);
}

void	echo1(char **com, char mod)
{
  int	i;
  int	a;

  a = 0;
  i = a;
  while (com[i])
    {
      while (is_option(com[i]))
	i++;
      if (a > 0 && com[i] != NULL)
	my_putchar(' ');
      if (com[i] != NULL)
	{
	  my_putstr(com[i]);
	  a++;
	  i++;
	}
    }
  if (mod == 1)
    my_putchar('\n');
}

void	my_echo(char **com)
{
  char	ret;

  if ((ret = option(com)) == 0)
    echo1(com, 1);
  else
    {
      if (ret % 2 == 1)
	echo_e(com, (ret >= 10 ? 0 : 1));
      else if (ret >= 10)
	echo1(com, 0);
    }
}
