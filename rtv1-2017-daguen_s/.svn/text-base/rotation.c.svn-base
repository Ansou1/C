/*
** rotation.c for rtv1 in /home/daguen_s//prepa_rtv1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Mar 17 16:01:36 2013 simon daguenet
** Last update Sun Mar 17 16:02:56 2013 simon daguenet
*/

#include "rtv1.h"

t_point_3d	rotate_x(t_point_3d coord, double rot)
{
  t_point_3d	tmp;

  tmp.x = coord.x;
  tmp.y = coord.y * cos(rot) - coord.z * sin(rot);
  tmp.z = coord.y * sin(rot) + coord.z * cos(rot);
  return (tmp);
}

t_point_3d	rotate_y(t_point_3d coord, double rot)
{
  t_point_3d	tmp;

  tmp.x = coord.x * cos(rot) + coord.z * sin(rot);
  tmp.y = coord.y;
  tmp.z = -coord.x * sin(rot) + coord.z * cos(rot);
  return (tmp);
}

t_point_3d	rotate_z(t_point_3d coord, double rot)
{
  t_point_3d	tmp;

  tmp.x = coord.x * cos(rot) - coord.y * sin(rot);
  tmp.y = coord.x * sin(rot) + coord.y * cos(rot);
  tmp.z = coord.z;
  return (tmp);
}

t_point_3d	rotate(t_point_3d eyes, t_point_3d rot)
{
  eyes = rotate_x(eyes, rot.x);
  eyes = rotate_y(eyes, rot.y);
  eyes = rotate_z(eyes, rot.z);
  return (eyes);
}

t_point_3d	rotate_inv(t_point_3d eyes, t_obj rot)
{
  eyes = rotate_x(eyes, -rot.r_x);
  eyes = rotate_y(eyes, -rot.r_y);
  eyes = rotate_z(eyes, -rot.r_z);
  return (eyes);
}
