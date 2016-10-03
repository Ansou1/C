/*
** raytracer.h for raytracer in /home/cheval_y//raytracer/includes
** 
** Made by franck chevallier
** Login   <cheval_y@epitech.net>
** 
** Started on  Tue Apr  9 14:25:15 2013 franck chevallier
** Last update Sun Jun  9 16:05:52 2013 jonathan racaud
*/

#ifndef RAYTRACER_H_
#define RAYTRACER_H_


#define	_XOPEN_SOURCE 500
#define	_ISOC99_SOURCE
#define	_POSIX_C_SOURCE 200112l

#include <mlx.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include <pthread.h>
#include "xml.h"
#include "video.h"

#define WINDOW_X (mlx->width)
#define WINDOW_Y (mlx->height)
#define RAD(x) ((x * (3.14159265358979323846)) / 180)
#define SPHERE (1)
#define PLANE (2)
#define CONE (3)
#define CYLINDER (4)
#define	CUBE	(5)
#define EYE_TYPE (6)
#define LIGHT_TYPE (7)
#define	UNKNOWN_TYPE	(8)
#define OBJECT ((t_object*)(mlx->list))
#define DEF_TYPE OBJECT->def_object
#define EYE (mlx->eye)
#define LIGHT (mlx->light)
#define SELECT ((t_object*)(mlx->select_object))
#define RED(x) ((x) / 0x10000 % 0x100)
#define GREEN(x) ((x) / 0x100 % 0x100)
#define BLUE(x) ((x) % 0x100)
#define	AVG_COLOR(x) ((BLUE(x) + GREEN(x) + RED(x)) / 3)
#define	RED_BMP(x, y) (unsigned char)(mlx->image->data[(y * mlx->image->sizeline) + x * (mlx->image->bpp / 8)])
#define	GREEN_BMP(x, y) (unsigned char)(mlx->image->data[(y * mlx->image->sizeline) + x * (mlx->image->bpp / 8) + 1])
#define	BLUE_BMP(x, y) (unsigned char)(mlx->image->data[(y * mlx->image->sizeline) + x * (mlx->image->bpp / 8) + 2])
#define	GET_COLOR_BMP(x, y) (RED_BMP(x, y) * 0x10000 + GREEN_BMP(x, y) * 0x100 + BLUE_BMP(x, y))
#define	SIZE_READ	1000

typedef	struct	s_bmp_header
{
  short	signature;
  int	file_size;
  int	zero;
}		t_bmp_header;

typedef struct	s_bmp_info
{
  int	head_size;
  int	img_width;
  int	img_height;
  short	plane;
  int	bpp;
  int	compression;
  int	img_size;
  int	res_x_pxm;
  int	res_y_pxm;
  int	palette;
  int	vip_color;
}		t_bmp_info;

typedef	struct		s_image
{
  void			*img_ptr;
  char			*name;
  char			*data;
  int			bpp;
  int			sizeline;
  int			endian;
  struct s_image	*next;
  struct s_image	*prev;
}			t_image;

typedef struct		s_coordinates
{
  double		x;
  double		y;
  double		z;
}			t_coord;

typedef struct		s_discriminant
{
  double		a;
  double		b;
  double		c;
  double		delta;
}			t_discriminant;

typedef struct		s_result
{
  double		k;
  double		k1;
  double		k2;
  t_coord		intersection;
  t_coord		normal;
}			t_result;

typedef struct		s_eye
{
  int			r_x;
  int			r_y;
  int			r_z;
  t_coord		eye_pos;
  t_coord		v_eye;
}			t_eye;

typedef struct		s_light
{
  t_coord		pos_light;
  int			color;
  double		amb;
  struct s_light	*next;
}			t_light;

typedef struct		s_mlx
{
  t_xml			*xml;
  double		k;
  int			nb_lights;
  t_light		*light;
  t_image		*image;
  void			*list;
  t_eye			*eye;
  void			*mlx_ptr;
  void			*win_ptr;
  int			width;
  int			height;
  int			anti_aliasing;
  int			win_created;
  int			xml_error;
  int			blur;
  int			nb_threads;
  int			filter;
  t_video		video;
}			t_mlx;

typedef struct	s_data
{
  t_mlx		*rt;
  unsigned int	x;
  unsigned int	xmax;
  unsigned int	y;
}		t_data;

typedef int		(*t_solve)(t_mlx *mlx, t_coord v_eye, t_coord eye_pos);

typedef struct	s_tab_xml_elem
{
  char		*name_elem;
  int		(*ptr_add_elem)(t_mlx *rt, char **wordtab);
}		t_tab_xml_elem;

typedef struct		s_object
{
  double		reflexion;
  double		brightness;
  t_solve		intersection;
  t_result		*result;
  int			def_object;
  int			damier;
  int			x;
  int			y;
  int			z;
  int			r_x;
  int			r_y;
  int			r_z;
  int			radius;
  int			color;
  t_coord		bump;
  int			width_limit;
  int			length_limit;
  double		spec_int;
  double		material;
  struct s_object	*next;
}			t_object;

typedef struct	s_spec
{
  t_coord	light;
  t_coord	normal;
}		t_spec;

/* XML */
void	add_in_list(t_object *add, t_object **list);
void	add_in_list_light(t_light *add, t_light **list);
int	fill_xml(char *file, t_mlx *rt);
void	init_rt(t_mlx *rt);
int	check_conf(t_mlx *rt);
int	conf_file(t_mlx *rt, char *file);
void	change_elem_cube(t_object *obj, int type_modif, int new_val);
int	change_size_cube(t_object *obj, char **tab);
int	add_position_cube(t_object *obj, char **tab);
int	add_color_cube(t_object *obj, char **tab);
int	add_empty_cube(t_mlx *mlx);
int	add_ambiente(t_mlx *rt, char **tab);
int	add_angle_obj(t_object *obj, char **tab);
int	add_angle_eye(t_eye *eye, char **tab);
int	add_angle(t_mlx *rt, char **tab);
int	add_anti_aliasing(t_mlx *rt, char **tab);
int	add_video(t_mlx *rt, char **tab);
int	add_spec(t_mlx *rt, char **tab);
int	add_blur(t_mlx *rt, char **tab);
int	add_bright_obj(t_object *obj, char **tab);
int	add_bright(t_mlx *rt, char **tab);
int	add_bump_obj(t_object *obj, char **tab);
int	add_bump(t_mlx *rt, char **tab);
int	is_obj_state(t_mlx *rt);
int	add_elem(char *line, t_mlx *rt);
int	find_in_color_tab(char *val);
int	get_color(char *val);
int	add_color_obj(t_object *obj, char **tab);
int	add_color_light(t_light *light, char **tab);
int	add_color(t_mlx *rt, char **tab);
int	get_type_filter(char *val);
int	add_filter(t_mlx *rt, char **tab);
int	add_limit_obj(t_object *obj, char **tab);
int	add_limit(t_mlx *rt, char **tab);
int	add_position_obj(t_object *obj, char **tab);
int	add_position_light(t_light *light, char **tab);
int	add_position_eye(t_eye *eye, char **tab);
int	add_position(t_mlx *rt, char **tab);
int	add_radius_obj(t_object *obj, char **tab);
int	add_radius(t_mlx *rt, char **tab);
int	add_reflexion_obj(t_object *obj, char **tab);
int	add_reflexion(t_mlx *rt, char **tab);
int	add_rot_obj(t_object *obj, char **tab);
int	add_rot_eye(t_eye *eye, char **tab);
int	add_rot(t_mlx *rt, char **tab);
int	add_threads(t_mlx *rt, char **tab);
int	add_window(t_mlx *rt, char **tab);
char	*my_strcpy(char *dest, char *src);
char	*my_strcat(char *dest, char *src);
int	my_buf(char *buffer, char *buffer_s, int ret);
char	*my_realloc(char *buffer, int size);
char	*get_next_line(const int fd);
int	my_check_space_tab(char *str, int i);
char	*my_epur_str(char *str);
void	add_in_pile(t_pile **pile, char *data);
int	pop_in_pile(t_pile **pile);
int	reg_match(char *str, char *reg);
int	type_line_xml(char *line);
int	get_type_node(char *name);
void	add_empty_obj(t_mlx *rt, int type);
void	add_obj(t_mlx *rt, int type);
int	add_node(char *line, t_mlx *rt);
int	close_node(char *line, t_mlx *rt);
void	add_empty_light(t_mlx *rt);
void	fill_intersec_ptr(t_object *obj);

/* Multi-Threads */
void	multi_thread(t_mlx *val);
t_mlx	*copy_struct_all(t_mlx *val, t_mlx *new);
void    *my_malloc(size_t taille);

/*Limit.c*/
void	limit_x(t_mlx *mlx, double k1, double k2);
void	limit_y(t_mlx *mlx, double k1, double k2);
int	limit_z(t_mlx *mlx, double k1, double k2);

/* Sources */
int		good_color(int *color, int r, t_mlx *mlx);
int		add_anti_aliasing(t_mlx *rt, char **tab);
void		calc_light_vector(t_coord *light, t_coord pos_light, t_object *select_object);
int		calc(double x, double y, t_mlx *mlx);
int		light(int type, t_object *select_object, t_mlx *mlx);
int		shadow(t_mlx *mlx, t_coord *light, t_object *select_object);
void		translate_vector(t_coord *normal, t_object *select_object);
int		normalize_vector(t_coord *normal);
int		change_color(int color, double cos_a, t_object *select_object, t_mlx *mlx);
int		filtre(int color, t_mlx *mlx);

/* Intersection */
int		def_normal(t_coord  *normal, t_coord intersection, int type, int radius);
int		calc_k(t_discriminant disc, double *k1, double *k2);
t_result	*fill_result(t_mlx *mlx, double k1, double k2);
int		inter_sphere(t_mlx *mlx, t_coord v_eye, t_coord eye_pos);
int		inter_cylinder(t_mlx *mlx, t_coord v_eye, t_coord eye_pos);
int		inter_plan(t_mlx *mlx, t_coord v_eye, t_coord eye_pos);
int		inter_cone(t_mlx *mlx, t_coord v_eye, t_coord eye_pos);
int		rotate(double r_x, double r_y, double r_z, t_coord *vector);
void		translate(t_mlx *mlx, t_coord *tmp_eye_pos, t_coord eye_pos);

/* Lib_function */
void	my_putchar(char c);
void	my_putstr(char *str);
int	my_strlen(char *str);
void	manage_error(char *str);
int	my_getnbr(char *str);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strndup(char *str, int size);
void	my_puterr(char *str);
char	*my_strdup(char *src);
int	my_strcmp(char *s1, char *s2);
int	is_alpha_num(char c);
char	to_lower(char c);
int	my_strcmp_case(char *s1, char *s2);
int	my_strncmp_case(char *s1, char *s2, int n);
int	is_space(char c);
int	count_words(char *line);
char	**str_to_wordtab(char *line);
int	get_rand(int min, int max);

/* Mlx_function */
int	manage_key(int keycode, t_mlx *mlx);
int	manage_expose(t_mlx *mlx);
int	my_pixel_put_to_image(t_mlx *mlx, int x, int y, int color);

/* NEW */
int	find_intersection(t_mlx *mlx, t_coord vector, t_coord from);
int	check_option(char **av);
int	check_conf(t_mlx *rt);
int	fill_image(t_mlx *, int , int , int);
int	create_bmp_file(t_mlx *mlx);
void	my_print_error(char *str);
char	*my_get_file_name(char *str);
int	do_rt(char **av);

/* color_functions.c */
int	add_color2(int color, int color2);
int	calc_right_color(int *color, int cnt);
int	little_point(int color, double cos);
int	speculaire(t_mlx *mlx, t_object *select_object, int color, t_spec spec);

/* vector_tools.c */
int	get_checker(t_coord intersection, int color, double cos_a, t_object *select_object, t_mlx *mlx);
double	get_scalaire(t_coord *v1, t_coord *v2);
void    unitarise(t_coord *v);
int	check_cos(t_mlx *mlx, int *new_color, double cos_a, t_object *select_object);

/* BMP and Video */
void	write_padding(int data_wrote, char *data);
int	create_video(t_mlx *mlx);
void	set_eye_video(t_mlx *mlx);

#endif
