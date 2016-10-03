/*
** header.c for corewar in /home/daguen_s//result
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Feb 11 10:01:34 2013 simon daguenet
** Last update Fri Mar 29 14:50:48 2013 simon daguenet
*/

#include "asm.h"

char	*my_strcpy_bin(char *dest, char *src, int taille)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[taille] = src[i];
      taille++;
      i = i + 1;
    }
  return (dest);
}

void	get_com_and_name(char **com, char **name, char ***file)
{
  int	i;
  char	*str;

  i = 0;
  while (file[i] != NULL)
    {
      if (file[i][0] != NULL)
	{
	  if (my_strncmp(".comment", file[i][0], 8) == 1)
	    {
	      str = cut_cut(&file[i][1]);
	      *com = my_get_comment(str);
	    }
	  else if (my_strncmp(".name", file[i][0], 5) == 1)
	    {
	      str = cut_cut(&file[i][1]);
	      *name = my_get_comment(str);
	    }
	}
      i++;
    }
}

void	init_val(header_t *val)
{
  int	i;

  i = 0;
  while (i < (PROG_NAME_LENGTH))
    val->prog_name[i++] = '0';
  i = 0;
  while (i < (COMMENT_LENGTH))
    val->comment[i++] = '0';
}

/* !!!!!comment et name sont a 0x0 si le commentaire est vide !!!!!!!!!*/
header_t	get_header(char ***file, char **bin)
{
  header_t	val;
  int		i;
  char		*comment;
  char		*name;

  get_com_and_name(&comment, &name, file);
  i = 0;
  init_val(&val);
  if (name != NULL)
    get_header_name(&val, name);
  if (comment != NULL)
    get_header_comment(&val, comment);
  return (val);
}
