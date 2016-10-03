/*
** manage_error.c for corewar in /home/daguen_s//result
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Tue Feb 12 11:53:56 2013 simon daguenet
** Last update Sat Mar 16 17:51:53 2013 simon daguenet
*/

#include "asm.h"

int	check_ldi_arg(char *arg, int line)
{
  int	i;
  int	i1;
  int	i2;
  int	pos;

  my_null(&i, &i1, &i2);
  if ((i = is_dir2(arg)) == 0 &&
      (i1 = is_ind(arg)) == 0 && (i2 = is_reg(arg)) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  pos = my_max3(i, i1, i2);
  my_null(&i, &i1, &i2);
  if (arg[pos - 1] == '\0')
    my_put_error("Error too few argument", arg, line, 1);
  if ((i = is_dir2(&arg[pos])) == 0 &&
      (i1 = is_ind(&arg[pos])) == 0 && (i2 = is_reg(&arg[pos])) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  pos = pos + my_max3(i, i1, i2);
  my_null(&i, &i1, &i2);
  if (arg[pos - 1] == '\0')
    my_put_error("Error too few argument", arg, line, 1);
  if ((i = is_reg(&arg[pos])) == 0)
    my_put_error("Error argument 3 is not a registre", arg, line, 1);
  return (0);
}

int	check_lld_arg(char *arg, int line)
{
  int	i;
  int	i1;

  i = 0;
  i1 = 0;
  if ((i = is_dir(arg)) == 0 && (i1 = is_ind(arg)) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  i = my_max(i, i1);
  i1 = 0;
  if (arg[i] == '\0')
    my_put_error("Error too few argument", arg, line, 1);
  if ((i = is_reg(&arg[i + 1])) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  return (0);
}

int	check_fork_arg(char *arg, int line)
{
  int	i;

  i = is_dir(arg);
  if (i == 0)
    my_put_error("Error bad argument in fork", arg, line, 1);
  return (0);
}
