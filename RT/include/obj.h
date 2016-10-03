#ifndef OBJ_H_
# define OBJ_H_

# include "rt.h"

# define TYPE_NUM	7

# define TYPE_SPHERE	0
# define TYPE_CONE	1
# define TYPE_PLAN	2
# define TYPE_CYLINDER	3
# define TYPE_CUBE	4
# define TYPE_MODEL	5
# define TYPE_TORUS	6

# define LIGHT_NOR	0
# define LIGHT_DIR	1
# define LIGHT_AMB	2

typedef struct s_intersect	t_intersect;
typedef struct s_fptr		t_fptr;
typedef struct s_ffx		t_ffx;
typedef struct s_ftxt		t_ftxt;

struct s_intersect
{
  t_object	*obj;
  t_color	color;
  double	dist;
  t_tri_list	*cur_tri;
  t_coords	v;
  t_coords	*pos;
};

struct	s_fptr
{
  char	*name;
  void	(*ptr)();
};

struct	s_ffx
{
  char		*name;
  t_color	(*ptr)();
};

struct	s_ftxt
{
  t_obj_type	type;
  t_color	(*ptr)();
};

t_bool			is_same_coord(t_coords *, t_coords *);
t_bool			is_positive(double, t_coords *);
t_color			adapt_light_color(t_color, t_color, double);
t_color			calc_fog(t_rt *, t_intersect *, t_color);
t_color			calc_light(t_rt *, t_intersect *);
t_color			calc_phong(t_rt *, t_intersect *, t_coords *, t_color);
t_color			calc_ref(t_rt *, t_coords *, t_intersect *, t_color);
t_color			calc_transparency(t_rt *, t_coords *, t_intersect *, t_color);
t_color			calc_reflex(t_rt *, t_coords *, t_intersect *);
t_color			gcalc_color(t_rt *, t_intersect *, t_coords *, t_color);
t_color			form_color(int, int, int);
t_color			ratioed_color(t_color, t_color, double);
t_color			txtcolor_plan(t_object *, t_coords *, t_img *);
t_color			txtcolor_cube(t_object *, t_coords *, t_img *);
t_color			txtcolor_sphere(t_object *, t_coords *, t_img *);
double			_modulo(double, int);
t_coords		*get_coords(t_node *, char *);
t_color			get_color_val(t_node *);
t_node			*get_node(t_node *, char *);
double			get_value(t_node *);
void			interpret_dtree(t_rt *, t_node *);
t_color			get_illumination(t_intersect *, t_rt *, t_color);

#endif/* !OBJ_H_ */
