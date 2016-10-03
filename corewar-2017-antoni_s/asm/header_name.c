/*
** header_name.c for corewar in /home/daguen_s//Prog_Elem/corewar-2017-antoni_s/asm
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar 16 13:52:15 2013 simon daguenet
** Last update Fri Mar 29 14:23:51 2013 simon daguenet
*/

#include "asm.h"

char	*my_strcpy_exec_magic(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[PROG_NAME_LENGTH + 1] = '\0';
  return (dest);
}

char	*my_strcpy_name(char *dest, char *src, int taille)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[taille] = src[i];
      taille++;
      i = i + 1;
    }
  while (taille < PROG_NAME_LENGTH)
    dest[taille++] = '0';
  dest[PROG_NAME_LENGTH] = '\0';
  return (dest);
}

void	get_header_name(header_t *val, char *name)
{
  int	i;
  int	j;
  char	*str;

  i = 0;
  j = 8;
  my_strcpy_exec_magic(val->prog_name, "00ea83f3");
  while ((name[i] != '\0') && (j < PROG_NAME_LENGTH))
    {
      str = my_nbr_str((int)name[i]);
      str = convert_base(str, "0123456789", "0123456789abcdef");
      my_strcpy_name(val->prog_name, str , j);
      i++;
      j = j + 2;
    }
}

int	get_len_tab(char **name)
{
  int	i;
  int	y;
  int	len;

  i = 0;
  len = 0;
  y = 0;
  while (name[i] != NULL)
    {
      y = 0;
      while (name[i][y] != '\0')
	{
	  len++;
	  y++;
	}
      i++;
    }
  return (len);
}

char	*cut_cut(char **name)
{
  int	i;
  int	j;
  char	*ret;
  int	a;
  int	len;

  a = 0;
  len = get_len_tab(name);
  ret = malloc(len + 1);
  check_malloc(ret);
  j = 0;
  i = 0;
  while (name[j] != '\0')
    {
      i = 0;
      while (name[j][i] != '\0')
	ret[a++] = name[j][i++];
      j++;
      if (name[j] != NULL)
	ret[a++] = ' ';
      else
	ret[a] = '\0';
    }
  return (ret);
}
