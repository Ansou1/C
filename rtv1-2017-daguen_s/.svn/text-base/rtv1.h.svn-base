/*
** rtv1.h for rtv1 in /home/daguen_s//prepa_rtv1
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Sun Mar 17 15:41:49 2013 simon daguenet
** Last update Sun Mar 17 16:29:11 2013 simon daguenet
*/

#ifndef RTV1_H_
# define RTV1_H_

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <mlx.h>
#include <math.h>
#include <X11/X.h>

# define PI		(3.1415926)
# define RAD(x)		((x * PI) / 180)
# define WIDTH		(800)
# define HEIGHT		(800)
# define WHITE		(0xFFFFFF)
# define RED		(0xFF0000)
# define BLUE		(0x0000FF)
# define GREEN		(0x00FF00)
# define BLACK		(0x000000)
# define YELLOW		(0xFFFF00)
# define CON(x)		(pow(tan(x), 2))

typedef struct	s_img
{
  void		*image;
  char		*data;
  int		bpp;
  int		sizeline;
  int		endian;
}		t_img;

typedef struct	s_obj
{
  double	x;
  double	y;
  double	z;
  double	r;
  double	r_x;
  double	r_y;
  double	r_z;
}		t_obj;

typedef struct	s_point
{
  double	x;
  double	y;
  double	z;
}		t_point_3d;

typedef struct	s_resultat
{
  double	a;
  double	b;
  double	min;
  t_point_3d	n;
  t_point_3d	sec;
  double	delta;
}		t_result;

typedef struct	s_element
{
  void		*mlx_ptr;
  void		*win_ptr;
  t_img		img;
  t_point_3d	eyes;
  t_point_3d	r_eyes;
  t_point_3d	lig;
  t_obj		sph;
  t_obj		cyl;
  t_obj		con;
  t_obj		plan;
}		t_element;

int		mlx_put_pixel_to_img(t_img img, int x, int y, int color);
int		gere_key(int keycode, t_element *param);
int		gere_expose(t_element *param);
t_result	equation_second(double a, double b, double c);
t_point_3d	rotate_x(t_point_3d coord, double rot);
t_point_3d	rotate_y(t_point_3d coord, double rot);
t_point_3d	rotate_z(t_point_3d coord, double rot);
t_point_3d	rotate(t_point_3d eyes, t_point_3d rot);
t_point_3d	rotate_inv(t_point_3d eyes, t_obj rot);
t_result	cylindre(t_point_3d save, t_point_3d vect, t_element *p);
t_result	calc_cylindre(t_element *param, int x, int y);
t_result	calc_plan(t_element *param, int x, int y);
t_result	cone(t_point_3d save, t_point_3d vect, t_element *p);
t_result	calc_cone(t_element *param, int x, int y);
t_result	sphere(t_point_3d save, t_point_3d vect, t_element *p);
t_result	calc_sphere(t_element *param, int x, int y);
void		init_obj(t_element *param);
void		init(t_element *param);
double		pro_scal(t_point_3d ret, t_point_3d v, int color);
int		light(int color, t_result ret, t_point_3d lig);
double		get_min_in_two(double a, double b);
int		get_k_min(double a, double b, double c, double d);
int		calc_all(t_element *param, int x, int y);
int		draw(t_element *param);

#endif
