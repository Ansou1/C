/*
** initialisation.c for rtv1 in /home/daguen_s//prepa_rtv1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Mar 17 16:00:11 2013 simon daguenet
** Last update Sun Mar 17 16:27:39 2013 simon daguenet
*/

#include "rtv1.h"

void	init_obj(t_element *param)
{
  param->sph.x = 100;
  param->sph.y = 150;
  param->sph.z = 200;
  param->sph.r = 200;
  param->sph.r_x = 0;
  param->sph.r_y = 0;
  param->sph.r_z = 0;
  param->cyl.x = -100;
  param->cyl.y = -150;
  param->cyl.z = 0;
  param->cyl.r = 50;
  param->cyl.r_x = 0;
  param->cyl.r_y = 0;
  param->cyl.r_z = 0;
  param->con.x = 50;
  param->con.y = 500;
  param->con.z = 0;
  param->con.r = RAD(75);
  param->con.r_x = 0;
  param->con.r_y = 0;
  param->con.r_z = 0;
}

void	init(t_element *param)
{
  param->eyes.x = -300;
  param->eyes.y = 0;
  param->eyes.z = 100;
  param->r_eyes.x = 0;
  param->r_eyes.y = 0;
  param->r_eyes.z = 0;
  param->lig.x = -400;
  param->lig.y = 0;
  param->lig.z = 20;
  param->plan.x = 0;
  param->plan.y = 0;
  param->plan.z = 0;
  param->plan.r_x = 0;
  param->plan.r_y = 0;
  param->plan.r_z = 0;
  init_obj(param);
}
