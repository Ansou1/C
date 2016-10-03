/*
** check_file_header.c for corewar in /home/daguen_s//Prog_Elem/corewar-2017-antoni_s/asm
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar 16 14:58:13 2013 simon daguenet
** Last update Thu Mar 28 20:52:25 2013 simon daguenet
*/

#include "asm.h"

int	check_header(char *file, int line)
{
  if (file[0] == '\0')
    return (1);
  if (file[0] != '#' && file[0] != '.')
    my_put_error("WARNING : unknow directive", file, line, 0);
  if (my_strncmp(".name", file, 5) == 0)
    if (my_strncmp(".comment", file, 8) == 0 && file[0] != '#')
      my_put_error("WARNING : unknow directive", file, line, 0);
  return (1);
}

int	check_lbl(char *l_file, int line)
{
  int	i;
  int	check;
  char	*save;

  check = 0;
  i = 0;
  if (l_file[0] == '\0')
    return (0);
  while (l_file[i] != '\0' && l_file[i] != ':'
	&& l_file[i] != '\t' && l_file[i] != ' ')
    i++;
  if (check_mnemo(&l_file[0]) == 1 && l_file[i] != ':')
    return (1);
  if (l_file[i] == '\0')
    my_put_error("Error unknow instruction", l_file, line, 1);
  save = my_strdup(l_file);
  save[i + 1] = '\0';
  if (is_label(save) == 0)
    {
      my_put_error("Error incorect label", save, line, 1);
      free(save);
    }
  free(save);
  return (1);
}

int	which_check2(char *mnemo, char *arg, int line)
{
  if (my_strncmp("or", mnemo, 2) == 1)
    check_or_arg(arg, line);
  else if (my_strncmp("xor", mnemo, 3) == 1)
    check_xor_arg(arg, line);
  else if (my_strncmp("zjmp", mnemo, 4) == 1)
    check_zjmp_arg(arg, line);
  else if (my_strncmp("fork", mnemo, 4) == 1)
    check_fork_arg(arg, line);
  else if (my_strncmp("lld", mnemo, 3) == 1)
    check_lld_arg(arg, line);
  else if (my_strncmp("ld", mnemo, 2) == 1)
    check_ld_arg(arg, line);
  else if (my_strncmp("lldi", mnemo, 4) == 1)
    check_lldi_arg(arg, line);
  else if (my_strncmp("lfork", mnemo, 5) == 1)
    check_lfork_arg(arg, line);
  else if (my_strncmp("aff", mnemo, 3) == 1)
    check_aff_arg(arg, line);
}

int	which_check(char *mnemo, char *arg, int line)
{
  if (my_strncmp("live", mnemo, 4) == 1)
    check_live_arg(arg, line);
  else if (my_strncmp("ldi", mnemo, 3) == 1)
    check_ldi_arg(arg, line);
  else if (my_strncmp("sti", mnemo, 3) == 1)
    check_sti_arg(arg, line);
  else if (my_strncmp("st", mnemo, 2) == 1)
    check_st_arg(arg, line);
  else if (my_strncmp("add", mnemo, 3) == 1)
    check_add_arg(arg, line);
  else if (my_strncmp("sub", mnemo, 3) == 1)
    check_sub_arg(arg, line);
  else if (my_strncmp("and", mnemo, 3) == 1)
    check_and_arg(arg, line);
  else
    which_check2(mnemo, arg, line);
}
