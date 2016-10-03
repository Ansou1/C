/*
** manage_error1.c for corewar in /home/daguen_s//Prog_Elem/corewar-2017-antoni_s/asm
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar 16 14:15:19 2013 simon daguenet
** Last update Sat Mar 16 17:50:14 2013 simon daguenet
*/

#include "asm.h"

int	check_aff_arg(char *arg, int line)
{
  int	i;

  i = 0;
  i = is_reg(arg);
  if (i == 0)
    my_put_error("Error bad argument in aff", arg, line, 1);
  return (0);
}

int	check_lfork_arg(char *arg, int line)
{
  int	i;

  i = 0;
  i = is_dir(arg);
  if (i == 0)
    my_put_error("Error bad argument in lfork", arg, line, 1);
  return (0);
}

int	check_lldi_arg(char *arg, int line)
{
  int	i;
  int	i1;
  int	i2;
  int	pos;

  my_null(&i, &i1, &i2);
  if ((i = is_dir(arg)) == 0 && (i1 = is_ind(arg)) == 0
      && (i2 = is_reg(arg)) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  i = my_max3(i, i1, i2);
  if (arg[i] == '\0')
    my_put_error("Error too few argument", arg, line, 1);
  pos = i + 1;
  my_null(&i, &i1, &i2);
  if ((i = is_reg(&arg[pos])) == 0 && (i1 = is_dir(&arg[pos])) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  pos = my_max(i, i1);
  my_null(&i, &i1, &i2);
  if (arg[pos] == '\0')
    my_put_error("Error too few argument", arg, line, 1);
  if ((i = is_reg(&arg[pos + 1])) == 0)
    my_put_error("Error bad argument", arg, line, 1);
  return (0);
}
