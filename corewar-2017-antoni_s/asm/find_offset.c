/*
** find_offset.c for corewar in /home/corrad_f//projet/champion/commande
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Mon Jan 28 10:01:45 2013 florian corradin
** Last update Sat Mar 16 17:19:10 2013 simon daguenet
*/

#include "asm.h"

int	offset_up(int pos, int col, char **bin)
{
  int	x;
  int	y;
  int	ctr;

  ctr = 0;
  x = 4;
  y = col;
  while (y < pos)
    {
      while (bin[y][x] != '\0')
	{
	  x++;
	  ctr++;
	}
      x = 0;
      y++;
    }
  ctr = ctr + 4;
  ctr = ctr / 2;
  return (ctr);
}

int	get_offset_value2(int pos, char **bin, int col)
{
  int	x;
  int	y;
  int	ctr;

  ctr = 0;
  x = 4;
  y = col;
  if (pos > col)
    {
      return (offset_up(pos, col, bin));
    }
  else if (pos == col)
    return (0);
  else
    {
      return (offset_down2(pos, col, bin));
    }
}

int	get_offset_value4(int pos, char **bin, int col)
{
  int	x;
  int	y;
  int	ctr;

  ctr = 0;
  x = 4;
  y = col;
  if (pos > col)
    {
      return (offset_up(pos, col, bin));
    }
  else if (pos == col)
    return (0);
  else
    {
      return (offset_down4(pos, col, bin));
    }
}

/* renvoie l'offset a remplacer dans le bin a la place des 0 */
/* avec line la ligne arg et off le numero de l'offset */
char	*get_the_off2(char *line, char **bin, char ***file, int col)
{
  char	*ind;
  int	pos;
  int	line_to_go;
  int	offset;

  ind = get_lbl(line);
  pos = get_the_lbl_line(ind, file, bin[col]);
  offset = get_offset_value2(pos, bin, col);
  return (recup_nbr2(my_nbr_str(offset)));
}

/* renvoie l'offset a remplacer dans le bin a la place des 0 */
/* avec line la ligne arg et off le numero de l'offset */
char		*get_the_off4(char *line, char **bin, char ***file, int col)
{
  char		*ind;
  int		pos;
  int		line_to_go;
  unsigned int	offset;

  ind = get_lbl(line);
  pos = get_the_lbl_line(ind, file, bin[col]);
  offset = get_offset_value4(pos, bin, col);
  return (recup_nbr4l(my_nbr_strl(offset)));
}
