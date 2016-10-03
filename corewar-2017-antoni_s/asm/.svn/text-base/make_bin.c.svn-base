/*
** make_bin.c for corewar in /home/daguen_s//Prog_Elem/corewar-2017-antoni_s/asm
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar 16 15:03:20 2013 simon daguenet
** Last update Sat Mar 30 00:06:15 2013 simon daguenet
*/

#include "asm.h"

char		**get_asm_bin(t_list *stock, int size, char **bin, char ***file)
{
  int		i;
  t_list	*list;

  i = 0;
  list = stock;
  while (i < size)
    {
      if (list->x1 == -1)
	bin = wich_inst_off(bin, &list, i, file);
      list = list->next;
      i++;
    }
  i = 0;
  while (bin[i] != NULL)
    {
      my_putstr(bin[i++]);
      my_putstr("\n");
    }
  return (bin);
}

void	make_bin_line(int fd, char *str, int size)
{
  int	i;
  char	*bin;
  char	rec[3];
  int	a;
  int	base;

  rec[2] = '\0';
  i = 0;
  while (str[i] != '\0' && i < size)
    {
      rec[0] = str[i];
      rec[1] = str[i + 1];
      base = my_getnbr_base(rec, "0123456789abcdef");
      write(fd, &base, 1);
      i = i + 2;
    }
}

void	make_bin_head(header_t head, char *name)
{
  int	fd;

  if ((fd = open(name, O_RDWR | O_CREAT | O_TRUNC,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    {
      my_putstr("ERROR with open\n");
      exit (EXIT_FAILURE);
    }
  make_bin_line(fd, head.prog_name, PROG_NAME_LENGTH);
  make_bin_line(fd, head.comment, COMMENT_LENGTH);
  xclose(fd);
}

void	make_bin(char **bin, char *name)
{
  int	fd;
  int	i;

  i = 0;
  fd = open(name, O_WRONLY | O_APPEND);
  if (fd == -1)
    {
      my_putstr("open error\n");
      exit(0);
    }
  while (bin[i] != NULL)
    {
      make_bin_line(fd, bin[i], 500000);
      i++;
    }
  if (close(fd) == -1)
    {
      my_putstr("cannot close\n");
      exit(0);
    }
}
