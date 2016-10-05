/*
** get_map.c for rush in /home/daguen_s//rush/save_valgrind
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Mar  3 10:43:45 2013 simon daguenet
** Last update Sun Mar  3 15:23:30 2013 simon daguenet
*/

#include "rush.h"

int	get_line(char *av)
{
  int	fd;
  char	*s;
  int	i;

  fd  = open(av, O_RDONLY);
  i = 0;
  s = NULL;
  if (fd != -1)
    {
      while ((s = get_next_line(fd)))
        {
          i++;
          xfree(s);
        }
    }
  else
    my_print_error("cannot read\n");
  xclose(fd);
  return (i);
}

void	get_first_line(char *s, int *height, int *width, int i)
{
  int	j;
  char	*str;

  str = strcpy(xmalloc(my_strlen(s) + 1), s);
  if (!(str[0] >= '0' && str[0] <= '9'))
    my_print_error("MAP ERROR\n");
  i = 0;
  while (str[i] != '\0')
    {
      if (!((str[i] >= '0' && str[i] <= '9') || str[i] == 'x'))
	my_print_error("MAP ERROR\n");
      i++;
    }
  i = 0;
  while (str[i++])
    {
      if (str[i] == 'x')
	{
	  str[i] = '\0';
	  j = i;
	}
    }
  *width = atoi(str);
  if (&str[j + 1] != NULL)
    *height= atoi(&str[j + 1]);
}

void	check_map(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '1')
	;
      else if (str[i] == '2')
	;
      else if (str[i] == '*')
	;
      else if (str[i] == ' ')
	;
      else
	my_print_error("MAP ERROR\n");
      i++;
    }
}

int		check_door(char *str)
{
  static int	cmd_1 = 0;
  static int	cmd_2 = 0;
  int		nb;
  int		i;

  i = 0;
  nb = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '1' && cmd_1 == 0)
        {
	  cmd_1 = 1;
	  nb = nb + 1;
	}
      else if (str[i] == '2' && cmd_2 == 0)
        {
	  cmd_2 = 1;
	  nb = nb + 2;
	}
      i++;
    }
  return (nb);
}
