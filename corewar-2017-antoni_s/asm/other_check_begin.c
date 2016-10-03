/*
** other_check_begin.c for corewar in /home/daguen_s//Prog_Elem/corewar-2017-antoni_s/asm
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar 16 15:00:05 2013 simon daguenet
** Last update Sat Mar 16 16:09:55 2013 simon daguenet
*/

#include "asm.h"

int	my_null(int *i, int *i1, int *i2)
{
  *i = 0;
  *i1 = 0;
  *i2 = 0;
}

int	error_open(int fd, char *file)
{
  if (fd == -1)
    {
      my_putstr("cannot open the file\n");
      my_putstr(file);
      return (0);
    }
  return (1);
}

int	check_arguments(char *file, int line)
{
  int	i;
  int	i2;
  char	*mnemo;

  i = 0;
  mnemo = get_mnemo(file);
  i2 = check_mnemo_len(mnemo);
  if (file[i2] != ' ' && file[i2] != '\0' && file[i2] != '\t')
    my_put_error("Error unknow mnemonique", file, line, 1);
  if (file[i2] == '\0')
    my_put_error("Error too few arguments in instructuion", file, line, 1);
  file[i2] = '\0';
  which_check(mnemo, &file[i2 + 1], line);
  free(mnemo);
  return (1);
}

int	check_assemb(char *file, int line)
{
  int	i;

  i = 0;
  if (file[0] == '\0' || file[0] == '#')
    return (1);
  check_lbl(file, line);
  while (check_mnemo(&file[i]) == 0 && file[i] != '\0' && file[i] != '#')
    i++;
  if (file[i] == '\0' || file[i] == '#')
    my_put_error("error unknow instruction", file, line, 1);
  else
    check_arguments(&file[i], line);
}

int	my_check_the_file(char **file)
{
  int	i;
  int	check;

  check = 0;
  i = 0;
  while (is_header(file[i]) == 1)
    {
      check = check_header(file[i], i);
      if (check == -1)
	return (0);
      ++i;
      if (file[i] == NULL)
	return (0);
    }
  if (file[i] == NULL)
    my_put_exit("Error no instrcution\n");
  while (file[i] != NULL)
    {
      check = check_assemb(file[i++], i);
      if (check == -1)
  	return (0);
    }
  return (1);
}
