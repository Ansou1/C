/*
** ckeck_error_cmd.c for corewar in /home/daguen_s//Prog_Elem/corewar-2017-antoni_s/asm
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar 16 14:38:54 2013 simon daguenet
** Last update Fri Mar 29 14:38:55 2013 simon daguenet
*/

#include "asm.h"

int	check_live_arg(char *arg, int line)
{
  int	i;

  i = is_dir(arg);
  if (i == 0)
    my_put_error("Error bad argument in live", arg, line, 1);
  return (0);
}

int	check_ld_arg(char *arg, int line)
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
  if ((i = is_reg(&arg[i])) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  return (0);
}

int	check_add_arg(char *arg, int line)
{
  int	i;
  int	pos;

  i = 0;
  if ((i = is_reg(arg)) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  if (arg[i] == '\0')
    my_put_error("Error too few argument", arg, line, 1);
  pos = i;
  if ((i = is_reg(&arg[pos])) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  if (arg[pos + i] == '\0')
    my_put_error("Error too few argument", arg, line, 1);
  pos = pos + i;
  if ((i = is_reg(&arg[pos])) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  return (0);
}

int	check_zjmp_arg(char *arg, int line)
{
  int	i;
  int	pos;

  i = 0;
  if ((i = is_dir(arg)) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  return (0);
}

int	check_sub_arg(char *arg, int line)
{
  int	i;
  int	pos;

  i = 0;
  if ((i = is_reg(arg)) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  if (arg[i] == '\0')
    my_put_error("Error too few argument", arg, line, 1);
  pos = i;
  if ((i = is_reg(&arg[pos])) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  if (arg[pos + i] == '\0')
    my_put_error("Error too few argument", arg, line, 1);
  pos = pos + i;
  if ((i = is_reg(&arg[pos])) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  return (0);
}
