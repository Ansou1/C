/*
** option_echo.c for 42 in /home/corrad_f//projet/infect
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Wed May  8 14:26:26 2013 florian corradin
** Last update Wed May  8 14:27:04 2013 florian corradin
*/

#include "42.h"

char	is_option(char *com)
{
  if (com == NULL)
    return (0);
  if (com[0] == '-')
    {
      if (com[1] != '\0')
	{
	  if (com[1] == 'e' || com[2] == 'e')
	    return (1);
	  if (com[1] == 'n' || com[2] == 'n')
	    return (1);
	}
      return (0);
    }
  return (0);
}
