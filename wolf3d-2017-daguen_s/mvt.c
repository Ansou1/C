/*
** mvt.c for wolf in /home/daguen_s//charlotte
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Jan 13 00:47:07 2013 simon daguenet
** Last update Sun Jan 13 00:57:23 2013 simon daguenet
*/

#include "my_wolf.h"

int	go_right(t_element *param)
{
  param->agl = param->agl + 0.05;
  draw_all(param);
}

int	go_left(t_element *param)
{
  param->agl = param->agl - 0.05;
  draw_all(param);
}

int	move_up(t_element *param, double new_pos)
{
  param->x = param->x + (new_pos * cos(param->agl));
  param->y = param->y + (new_pos * sin(param->agl));
  draw_all(param);
}

int	move_down(t_element *param, double new_pos)
{
  param->x = param->x + (new_pos * cos(param->agl));
  param->y = param->y + (new_pos * sin(param->agl));
  draw_all(param);
}
