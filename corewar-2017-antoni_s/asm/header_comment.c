/*
** header_comment.c for corewar in /home/daguen_s//Prog_Elem/corewar-2017-antoni_s/asm
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sat Mar 16 13:49:51 2013 simon daguenet
** Last update Sat Mar 16 17:39:12 2013 simon daguenet
*/

#include "asm.h"

char	*my_strcpy_comment(char *dest, char *src, int taille)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[taille] = src[i];
      taille++;
      i = i + 1;
    }
  while (taille < COMMENT_LENGTH)
    dest[taille++] = '0';
  dest[COMMENT_LENGTH] = '\0';
  return (dest);
}

void	get_val_prog_size(header_t *val, char **bin)
{
  int	j;
  char	*str;
  int	taille;

  taille = get_size_bin(bin) / 2;
  str = my_nbr_str(taille);
  str = convert_base(str, "0123456789", "0123456789abcdef");
  j = 24 - my_strlen(str);
  my_strcpy_bin(val->comment, str , j);
}

void	get_header_comment(header_t *val, char *comment)
{
  int	i;
  int	j;
  char	*str;

  i = 0;
  j = 24;
  while ((comment[i] != '\0') && (j < COMMENT_LENGTH))
    {
      str = my_nbr_str((int)comment[i]);
      str = convert_base(str, "0123456789", "0123456789abcdef");
      my_strcpy_comment(val->comment, str , j);
      i++;
      j = j + 2;
    }
}

int	get_size_bin(char **bin)
{
  int	ctr;
  int	i;
  int	y;

  i = 0;
  y = 0;
  ctr = 0;
  while (bin[i] != NULL)
    {
      while (bin[i][y] != '\0')
	{
	  y++;
	  ctr++;
	}
      y = 0;
      i++;
    }
  return (ctr);
}

char	*my_get_comment(char *comment)
{
  int	i;
  char	*ret;
  int	len;

  if (comment == NULL)
    return (NULL);
  len = my_strlen(comment);
  if (len < 3)
    return (NULL);
  i = 1;
  ret = malloc(len);
  check_malloc(ret);
  ret[len - 1] = '\0';
  if (len == 0)
    return (NULL);
  while (comment[i] != '\0' && comment[i] != 34)
    {
      ret[i - 1] = comment[i];
      i++;
    }
  ret[i] = '\0';
  return (ret);
}
