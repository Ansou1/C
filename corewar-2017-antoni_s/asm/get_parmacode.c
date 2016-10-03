/*
** get_parmacode.c for corewar in /home/corrad_f//projet/champion/commande
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Sun Jan 27 16:18:59 2013 florian corradin
** Last update Fri Mar 29 14:18:26 2013 simon daguenet
*/

#include "asm.h"

char	*get_bin_char(char *bin, int a, int cas)
{
  if (cas == 1)
    {
      bin[a] = '0';
      bin[a + 1] = '1';
    }
  if (cas == 2)
    {
      bin[a] = '1';
      bin[a + 1] = '0';
    }
  if (cas == 3)
    {
      bin[a] = '1';
      bin[a + 1] = '1';
    }
  return (bin);
}

char	*get_octet_codage2(char *line, char *bin, int a, int i)
{
  int	i1;

  i1 = 0;
  while (line[i] != '\0')
    {
      if ((i1 = is_reg(&line[i])) != 0)
        {
	  get_bin_char(bin, a, 1);
          a += 2;
        }
      else if ((i1 = is_dir2(&line[i])) != 0)
        {
      	  get_bin_char(bin, a, 2);
          a += 2;
        }
      else if ((i1 = is_ind(&line[i])) != 0)
        {
	  get_bin_char(bin, a, 3);
          a += 2;
        }
      if (i1 == 0)
      	i++;
      i = i + i1;
    }
  return (convert_base(bin, "01", "0123456789abcdef"));
}

char	*get_octet_codage(char *line)
{
  char	*ret;
  char	*bin;
  int	i;
  int	a;

  if (line == NULL)
    {
      my_putstr("cannot access to line\n");
      exit(0);
    }
  a = 0;
  i = 0;
  bin = malloc(9);
  check_malloc(bin);
  bin[8] = '\0';
  while (a < 8)
    {
      bin[a] = '0';
      a++;
    }
  a = 0;
  ret = malloc(3);
  check_malloc(ret);
  ret[2] = '\0';
  return (get_octet_codage2(line, bin, a, i));
}
