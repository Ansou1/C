#ifndef MATHS_H_
# define MATHS_H_

# include "obj.h"

# define RED(x)		(double)(((x) >> 16) % 256)
# define GRE(x)		(double)(((x) >> 8) % 256)
# define BLU(x)		(double)((x) % 256)

# define POW2(x)	((x) * (x))
# define ABS(x)		((x < 0) ? -(x) : (x))
# define MAX(x, y)	((x > y) ? (x) : (y))
# define MIN(x, y)	((x < y) ? (x) : (y))

# define DEG_TO_RAD	0.0174532
# define RAD_TO_DEG	57.2957
# define DEPR_RANGE	20
# define IMG_WIDTH	500
# define IMG_HEIGHT	313
# define BLURR_MAX	100

# define RPI		3.14159265358979323846

# define LIM_SPHERE	1
# define LIM_CUBE	2

typedef struct s_equation
{
  double	a;
  double	b;
  double	c;
  double	d;
  double	e;
  double	q;
  double	delta;
  double	s;
  double	p;
}		t_equation;

typedef struct	s_complex
{
  double	re;
  double	img;
}		t_complex;

typedef struct	s_quartet
{
  t_complex	a0;
  t_complex	b0;
  double	s;
  double	p;
  double	q;
  double	r;
  double	x0;
  t_equation	qeq;
}		t_quartet;

t_bool			is_limited(t_object_list *, t_coords *, t_coords *, double);
double			simple_poly_resolve(double, double, double, t_coords *);
double			get_dist(t_coords *, t_coords *);
double			get_scal(t_coords *, t_coords *);
double			get_normal_ratio(t_light_list *, t_intersect *);
double			mod_txt_light(t_intersect *, double);
double			set_bounds(double, double, double);
double			soft_listing(t_rt *, t_light_list *, t_coords *);
double			list_transparency(t_rt *, t_light_list *, t_coords *, double);
double			my_tan(double);
double			my_cos(double);
double			my_sin(double);
t_intersect		*free_intersect(t_intersect *);
t_intersect		*list_inters(t_rt *, t_coords *, t_coords *);
double			sphere_inter(t_object_list *, t_coords *, t_coords *);
double			cone_inter(t_object_list *, t_coords *, t_coords *);
double			cube_inter(t_object_list *, t_coords *, t_coords *);
double			plan_inter(t_object_list *, t_coords *, t_coords *);
double			cylinder_inter(t_object_list *, t_coords *, t_coords *);
double			model_inter(t_object_list *, t_coords *, t_coords *);
double			torus_inter(t_object_list *, t_coords *, t_coords *);
t_coords		*get_normal(t_intersect *);
t_coords		*sphere_normal(t_light_list *, t_intersect *);
t_coords		*cone_normal(t_light_list *, t_intersect *);
t_coords		*cube_normal(t_light_list *, t_intersect *);
t_coords		*plan_normal(t_light_list *, t_intersect *);
t_coords		*cylinder_normal(t_light_list *, t_intersect *);
t_coords		*model_normal(t_light_list *, t_intersect *);
t_coords		*torus_normal(t_light_list *, t_intersect *);
void			copy_coords(t_coords *, t_coords *);
void			unitarise(t_coords *);
void			my_rotate(t_coords *, t_coords *);
void			my_inv_rotate(t_coords *, t_coords *);
void			my_translate(t_coords *, t_coords *, t_coords *);
void			get_new_rep(t_coords *, t_coords *, t_coords *, t_coords *);
void			set_ref_vect(t_coords *, t_intersect *, t_coords *);
t_color			postfx_neg(t_rt *, t_color, int, int);
t_color			postfx_grey(t_rt *, t_color, int, int);
t_color			postfx_blurr(t_rt *, t_color, int, int);
t_color			postfx_hcont(t_rt *, t_color, int, int);
t_color			postfx_crazy(t_rt *, t_color, int, int);
t_color			postfx_chuck(t_rt *, t_color, int, int);
t_color			postfx_postr(t_rt *, t_color, int, int);
t_color			postfx_decomp(t_rt *, t_color, int, int);
double			prod_scal(t_coords *, t_coords *);
void			get_vector(t_coords *, t_coords *, t_coords *);
void			get_normal_to_triangle(t_coords *, t_coords *, t_coords *);
double			resolve_quart(t_equation *);
double			quadratique(t_equation *, t_complex *, t_complex *);
double			quartique(t_equation *, t_complex z[3]);
double			cubique(t_equation *, t_complex *, t_complex *, t_complex *);

#endif/* !MATHS_H_ */
