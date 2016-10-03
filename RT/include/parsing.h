#ifndef PARSING_H_
# define PARSING_H_

# include "rt.h"

typedef struct s_obj		t_obj;
typedef struct s_normal		t_normal;
typedef struct s_point		t_point;

struct		s_normal
{
  t_uint	id;
  t_coords	n;
  char		**line;
  char		*str;
  t_normal	*next;
};

struct s_point
{
  t_uint	id;
  t_coords	p;
  char		**line;
  char		*str;
  t_point	*next;
};

struct s_obj
{
  char		*name;
  int		fd;
  t_uint	id_p;
  t_point	*point;
  t_uint	id_n;
  t_normal	*normal;
  t_tri_list	*triangle;
};

t_tri_list		*parsing_object(char *path);
t_tri_list		*fill_triangle_in_list(t_obj *this);
t_bool			get_point_token(t_obj *this, char **line, char *str);
t_bool			get_normal_token(t_obj *this, char **line, char *str);
t_bool			get_tri_list_token(t_obj *this, char **line, char *str);
t_uint			count_tabtab(char **tab);
t_bool			is_tab_number(char **line, t_obj *this);
t_bool			corrupt_file(char *str, t_obj *this);
double			my_get_double(const char *str);
int			is_num(const char c);
void			destroy_all(t_obj *this, t_tri_list *tri_list);

#endif/* !PARSING_H_ */
