/*
** parser.c for corware in /home/corrad_f//projet/champion/commande
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Wed Jan 23 15:04:56 2013 florian corradin
** Last update Sat Mar 30 16:44:04 2013 simon daguenet
*/

#include "asm.h"

char	*get_octet_value(char *bin)
{
  int	i;
  char	*ret;
  int	len;

  len = my_strlen(bin);
  ret = xmalloc(9);
  i = 0;
  while (i < 8)
    ret[i++] = '0';
  ret[8] = '\0';
  i = 7;
  while (len >= 0 && i >= 0)
    {
      ret[i] = bin[len - 1];
      i--;
      len--;
    }
  i = 0;
  return (ret);
}

char	*get_good_name(char *name)
{
  int	i;
  char	*ret;

  i = 0;
  while (name[i] != '.' && name[i] != '\0')
    i++;
  if (name[i] == '\0')
    {
      my_putstr("invalide file name");
      exit(0);
    }
  name[i + 1] = '\0';
  ret = my_strcats(name, "cor");
  return (ret);
}

void		my_asm(char *name, int size, char ***file)
{
  char		**bin;
  t_list	*list;
  int		i;
  t_list	*stock;
  header_t	head;

  i = 0;
  head = get_header(file, bin);
  file = my_clean_file(file);
  size = my_len_bigtab(file);
  bin = init_bin(size);
  list = my_params_in_list(size);
  stock = list;
  while (i < size)
    {
      bin = wich_inst(bin, &list, i, file);
      i++;
      list = list->next;
    }
  bin = get_asm_bin(stock, size, bin, file);
  get_val_prog_size(&head, bin);
  name = get_good_name(name);
  make_bin_head(head, name);
  make_bin(bin, name);
}

int		main(int ac, char **av)
{
  char		***file;
  char		*name;
  int		i;
  int		size;

  i = 1;
  while (i < ac)
    {
      name = my_strdup(av[i]);
      size = get_line(name);
      manag_eror(size, name);
      file = get_file(name);
      my_asm(name, size, file);
      free(name);
      i++;
    }
  return (0);
}
