/*
** my_wolf.h for  in /home/daguen_s//my_wolf
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Fri Dec 14 13:14:40 2012 simon daguenet
** Last update Sun Jan 13 19:17:36 2013 simon daguenet
*/

#ifndef		MY_WOLF_H_
# define	MY_WOLF_H_

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <mlx.h>
#include <math.h>
#include <X11/X.h>

# define	SKY	(0x77aecb)
# define	GREY	(0xA7A7A7)
# define	FLOOR	(0x5f883d)
# define	WALL	(0xFFAFFF)
# define	COLOR1	(0x41FF21)
# define	COLOR2	(0xD8D12A)
# define	COLOR3	(0x0540D9)
# define	COLOR4	(0x760A82)

# define	DEG	(180 / M_PI)
# define	RAD	(M_PI / 180)
# define	HEIGHT	(900)
# define	WIDTH	(900)

typedef struct	s_img
{
  void		*image;
  char		*data;
  int		bpp;
  int		sizeline;
  int		endian;
  double	primex;
  double	primey;
  double	kx;
  double	ky;
}		t_img;

typedef struct	s_element
{
  void		*mlx_ptr;
  void		*win_ptr;
  t_img		img;
  double	x;
  double	y;
  double	agl;
}		t_element;

typedef struct	s_coord
{
  double	x;
  double	y;
}		t_coord;

static int	map[115] =
  {
    1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,1,0,0,1,
    1,0,1,0,0,0,0,0,0,1,
    1,0,1,0,1,0,1,1,0,1,
    1,0,0,0,0,0,1,0,0,1,
    1,0,0,0,1,0,0,0,0,1,
    1,0,0,0,1,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1,
  };

int	mlx_put_pixel_to_img(t_img img, int x, int y, int color);
double	get_k_line(t_element *param, t_coord vect);
double	get_k_col(t_element *param, t_coord vect);
double	get_k(t_element *param, int col);
int	go_right(t_element *param);
int	go_left(t_element *param);
int	move_up(t_element *param, double new_pos);
int	move_down(t_element *param, double new_pos);
int	gere_key(int keycode, t_element *param);
int	gere_expose(t_element *param);
int	color(t_img img);
int	draw_wall(int taille, int row, t_img img);
int	draw(int taille, int row, t_img img);
int	draw_all(t_element *param);

#endif
