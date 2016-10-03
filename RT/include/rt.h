#ifndef RT_H_
# define RT_H_

# include <stdlib.h>

# define WIN_WIDTH		1920
# define WIN_HEIGHT		1080

# define DEF_TXT_SIZE		360
# define PARSE_MAX_SIZE		256
# define V_FAR			1000000
# define COMPUTE_PHOTON		100

# define FALSE			0
# define TRUE			!FALSE

typedef int			t_color;
typedef double			t_coord;
typedef unsigned int		t_uint;
typedef unsigned char		t_bool;

typedef struct s_node		t_node;
typedef struct s_coords		t_coords;
typedef struct s_triangle	t_triangle;
typedef struct s_rectangle	t_rectangle;
typedef struct s_color_val	t_color_val;

typedef unsigned int		t_obj_type;
typedef struct s_object		t_object;
typedef struct s_cam		t_cam;
typedef struct s_img		t_img;
typedef struct s_temp		t_temp;
typedef struct s_light_list	t_light_list;
typedef struct s_object_list	t_object_list;
typedef struct s_tri_list	t_tri_list;

typedef struct s_mlx_win	t_mlx_win;
typedef struct s_rt		t_rt;

# include "photon.h"

struct s_color_val
{
  double	r;
  double	g;
  double	b;
};

struct s_coords
{
  t_coord	x;
  t_coord	y;
  t_coord	z;
};

struct s_triangle
{
  t_uint	id_p[3];
  t_uint	id_n;
  t_coords	p1;
  t_coords	p2;
  t_coords	p3;
  t_coords	n;
};

struct s_tri_list
{
  t_triangle	*val;
  t_tri_list	*next;
  char		**line;
  char		*str;
};

struct s_rectangle
{
  t_uint	x;
  t_uint	y;
  t_uint	width;
  t_uint	height;
};

struct s_img
{
  double	amp;
  t_uint	rep;
  t_uint	xsize;
  t_uint	ysize;
  int		**val;
};

struct s_mlx_win
{
  void		*xclient;
  void		*cwindow;
  void		*m_image;
  char		*m_img_addr;
  int		pixelsize;
  int		linesize;
  int		endianess;
};

struct s_cam
{
  double	photon_mapped;
  t_coords	*pos;
  t_coords	*angle;
  int		fog_depth;
  int		fog_style;
  t_color	fog_color;
  int		depth_field;
  int		depth_deform;
  int		ratio_pixel;
  int		effects_active;
  int		nb_core;
  int		diff_fact;
  int		used_photon;
  int		light_sampling;
  t_img		*background;
};

struct s_object
{
  t_obj_type	type;
  double	val1;
  double	val2;
  t_tri_list	*model;
  t_tri_list	*hitted;
  t_color	color;
  double	reflexion;
  double	tr;
  double	ind;
  double	bright;
  t_coords	*r;
  t_coords	*pos;
  int		l_type;
  double	l_value;
  t_coords	*l_pos;
  t_coords	*l_rot;
  int		color_mod;
  int		norml_mod;
  t_img		*texture;
  t_img		*bumpmap;
};

struct s_object_list
{
  t_object	*obj;
  t_object_list	*next;
};

struct s_light_list
{
  t_uint	type;
  t_uint	photons;
  t_color	color;
  double	psize;
  double	watt;
  t_coords	*pos;
  int		soft_val;
  t_coords	*rndm;
  t_light_list	*next;
};

struct s_temp
{
  t_uint	rdepth;
  t_uint	tdepth;
  t_uint	cpos;
  t_coords	*d_sample;
  t_object	*last_tr;
};

struct s_rt
{
  t_mlx_win	*win;
  t_cam		*cam;
  t_object_list	*objs;
  t_light_list	*lights;
  t_photon_map	*photons;
  t_temp	temps;
  double	pfx_val;
  char		pfx[PARSE_MAX_SIZE + 1];
  int		multi_thread;
};

struct s_node
{
  char		name[PARSE_MAX_SIZE + 1];
  char		value[PARSE_MAX_SIZE + 1];
  t_node	*fils;
  t_node	*next;
};

t_rt		*create_session(int, char **);
void		parse_xml(t_rt *, char *);
void		free_dtree(t_node *);
void		render_session(t_rt *, char *);
void		view_loop(t_rt *, char *);
void		refresh_render(t_mlx_win *);
void		depth_field(t_rt *, t_coords *, t_coords *);
t_color		get_mid(t_rt *, t_color *, int);
t_color		calc_color(t_rt *, int, int);
t_color		get_txt_color(t_object *, t_coords *, int);
t_color		get_background(t_rt *, int, int, int);
t_color		app_fx(t_rt *, t_color, int, int);
t_color		get_pixel_color(t_mlx_win *, int, int);
t_object	*create_obj(t_rt *, t_node *);
t_img		*get_image(t_node *);
void		add_cube(t_rt *, t_node *);
void		add_plan(t_rt *, t_node *);
void		add_cone(t_rt *, t_node *);
void		add_cylinder(t_rt *, t_node *);
void		add_sphere(t_rt *, t_node *);
void		add_light(t_rt *, t_node *);
void		add_model(t_rt *, t_node *);
void		add_torus(t_rt *, t_node *);
void		change_cam(t_rt *, t_node *);
int		**load_image(char *, int, int);
int		try_load(double *, char *, int);
int		my_strcmp(char *, char *);
char		*my_strcpy(char *, char *);
void		print_pixel(t_mlx_win *, int, int, t_color);
void		generate_modifiers(t_rt *, t_object *);
void		gen_perlin(t_color, t_color, t_img *, int);
void		init_rndms(t_rt *);
void		apply_postfx(t_rt *);
t_tri_list	*parsing_object(char *);
void		save_image(t_rt *this, char *name_file);
t_bool		fill_header_bitmap(int fd);
int		x_write(int fd, const void *buf, int count);

#endif/* !RT_H_ */
