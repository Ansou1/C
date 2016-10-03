/*
** check_error_sec.c for corewar in /home/daguen_s//Prog_Elem/corewar-2017-antoni_s/asm
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar 16 14:51:38 2013 simon daguenet
** Last update Sat Mar 16 14:52:24 2013 simon daguenet
*/

#include "asm.h"

int	check_sti_arg(char *arg, int line)
{
  int	i;
  int	i1;
  int	i2;
  int	pos;

  my_null(&i, &i1, &i2);
  if ((i = is_reg(arg)) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  if (arg[i] == '\0')
    my_put_error("Error too few argument", arg, line, 1);
  pos = i;
  my_null(&i, &i1, &i2);
  if ((i = is_reg(&arg[pos])) == 0 &&
      (i1 = is_dir(&arg[pos])) == 0 && (i2 = is_ind(&arg[pos])) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  pos = pos + my_max3(i, i1, i2);
  my_null(&i, &i1, &i2);
  if (arg[pos - 1] == '\0')
    my_put_error("Error too few argument", arg, line, 1);
  if ((i = is_reg(&arg[pos])) == 0 && (i1 = is_dir(&arg[pos])) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  return (0);
}

int	check_and_arg(char *arg, int line)
{
  int	i;
  int	i1;
  int	i2;
  int	pos;

  my_null(&i, &i1, &i2);
  if ((i = is_reg(arg)) == 0 &&
      (i1 = is_dir(arg)) == 0 && (i2 = is_ind(arg)) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  pos = my_max3(i, i1, i2);
  my_null(&i, &i1, &i2);
  if (arg[pos - 1] == '\0')
    my_put_error("Error too few argument", arg, line, 1);
  i = i1 = i2 = 0;
  if ((i = is_reg(&arg[pos])) == 0 &&
      (i1 = is_dir(&arg[pos])) == 0 && (i2 = is_ind(&arg[pos])) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  pos = pos + my_max3(i, i1, i2);
  my_null(&i, &i1, &i2);
  if (arg[pos - 1] == '\0')
    my_put_error("Error too few argument", arg, line, 1);
  if ((i = is_reg(&arg[pos])) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  return (0);
}

int	check_or_arg(char *arg, int line)
{
  int	i;
  int	i1;
  int	i2;
  int	pos;

  my_null(&i, &i1, &i2);
  if ((i = is_reg(arg)) == 0 &&
      (i1 = is_dir(arg)) == 0 && (i2 = is_ind(arg)) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  pos = my_max3(i, i1, i2);
  my_null(&i, &i1, &i2);
  if (arg[pos - 1] == '\0')
    my_put_error("Error too few argument", arg, line, 1);
  if ((i = is_reg(&arg[pos])) == 0 &&
      (i1 = is_dir(&arg[pos])) == 0 && (i2 = is_ind(&arg[pos])) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  pos = pos + my_max3(i, i1, i2);
  my_null(&i, &i1, &i2);
  if (arg[pos - 1] == '\0')
    my_put_error("Error too few argument", arg, line, 1);
  if ((i = is_reg(&arg[pos])) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  return (0);
}

int	check_xor_arg(char *arg, int line)
{
  int	i;
  int	i1;
  int	i2;
  int	pos;

  my_null(&i, &i1, &i2);
  if ((i = is_reg(arg)) == 0 &&
      (i1 = is_dir(arg)) == 0 && (i2 = is_ind(arg)) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  pos = my_max3(i, i1, i2);
  my_null(&i, &i1, &i2);
  if (arg[pos - 1] == '\0')
    my_put_error("Error too few argument", arg, line, 1);
  if ((i = is_reg(&arg[pos])) == 0 &&
      (i1 = is_dir(&arg[pos])) == 0 && (i2 = is_ind(&arg[pos])) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  pos = pos + my_max3(i, i1, i2);
  my_null(&i, &i1, &i2);
  if (arg[pos - 1] == '\0')
    my_put_error("Error too few argument", arg, line, 1);
  if ((i = is_reg(&arg[pos])) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  return (0);
}

int	check_st_arg(char *arg, int line)
{
  int	i;
  int	i1;
  int	pos;

  i = 0;
  i1 = 0;
  if ((i = is_reg(arg)) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  if (arg[i] == '\0')
    my_put_error("Error too few argument", arg, line, 1);
  pos = i;
  i = 0;
  i1 = 0;
  if ((i = is_ind(&arg[pos])) == 0 && (i1 = is_reg(&arg[pos])) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  return (0);
}
