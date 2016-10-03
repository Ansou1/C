/*
** all_for_light.c for rtv1 in /home/daguen_s//prepa_rtv1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Mar 17 16:11:12 2013 simon daguenet
** Last update Sun Mar 17 16:11:45 2013 simon daguenet
*/

#include "rtv1.h"

double		pro_scal(t_point_3d ret, t_point_3d v, int color)
{
  double	cos;
  double	scal;
  double	n1;
  double	n2;

  scal = ret.x * v.x + ret.y * v.y + ret.z * v.z;
  n1 = v.x * v.x + v.y * v.y + v.z * v.z;
  n1 = sqrt(n1);
  n2 = ret.x * ret.x + ret.y * ret.y + ret.z * ret.z;
  n2 = sqrt(n2);
  cos = scal / (n1 * n2);
  return (cos);
}

int		light(int color, t_result ret, t_point_3d lig)
{
  t_point_3d	v;
  double	cos;
  unsigned char	*couleur;

  v.x = lig.x - ret.sec.x;
  v.y = lig.y - ret.sec.y;
  v.z = lig.z - ret.sec.z;
  cos = pro_scal(ret.n, v, color);
  couleur = (unsigned char *) & color;
  if (cos > 0)
    {
      couleur[0] = cos * couleur[0];
      couleur[1] = cos * couleur[1];
      couleur[2] = cos * couleur[2];
    }
  else
    color = 0;
  return (color);
}
