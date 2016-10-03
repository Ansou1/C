/*
** k_value.c for wolf in /home/daguen_s//charlotte
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Jan 13 00:45:48 2013 simon daguenet
** Last update Sun Jan 13 19:19:56 2013 simon daguenet
*/

#include "my_wolf.h"

double	get_k_line(t_element *param, t_coord vect)
{
  double	line;
  double	col;
  double	save;
  double	taille;

  line = 0;
  taille = 10000;
  while (line != 10)
    {
      save = line;
      if (vect.y < 0 && line != 0)
        save--;
      col = (((line - param->y) / vect.y) * vect.x) + param->x;
      if (((line - param->y) / vect.y) >= 0 && (col >= 0 && col <= 10 - 1))
        {
          if (map[((10 - 1) -(int)save) * 10 + (int)col] == 1)
            if (((line - param->y) / vect.y) < taille)
              taille = ((line - param->y) / vect.y);
        }
      line++;
    }
  return (taille);
}

double	get_k_col(t_element *param, t_coord vect)
{
  double	line;
  double	col;
  double	save;
  double	taille;

  col = 0;
  taille = 10000;
  while (col != 10)
    {
      save = col;
      if (vect.x < 0 && col != 0)
        save--;
      line = (((col - param->x) / vect.x) * vect.y) + param->y;
      if (((col - param->x) / vect.x) >= 0 && (line >= 0 && line <= 10 - 1))
        {
          if (map[((10 - 1) -(int)line) * 10 + (int)save] == 1)
            if (((col - param->x) / vect.x) < taille)
              taille = ((col - param->x) / vect.x);
        }
      col++;
    }
  return (taille);
}

double	get_k(t_element *param, int col)
{
  t_coord	pos;
  t_coord	vect;

  pos.x = 0.5;
  pos.y = (WIDTH / 2 - col);
  pos.y = pos.y / WIDTH;
  param->img.primex = pos.x * cos(param->agl) - pos.y * sin(param->agl);
  param->img.primey = pos.x * sin(param->agl) + pos.y * cos(param->agl);
  pos.x = param->img.primex + param->x;
  pos.y = param->img.primey + param->y;
  vect.x = pos.x - param->x;
  vect.y = pos.y - param->y;
  param->img.kx = get_k_line(param, vect);
  param->img.ky = get_k_col(param, vect);
  return ((param->img.kx >= param->img.ky) ? (param->img.ky) : (param->img.kx));
}
