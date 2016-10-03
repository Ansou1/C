/*
** xml.h for xml in /home/efilon/eretay/raytracer-2017-simon_o/rt
** 
** Made by efilon
** Login   <efilon@Heisenbergs-RV>
** 
** Started on  Fri Jun  7 01:57:54 2013 efilon
** Last update Sun Jun  9 15:12:48 2013 jonathan racaud
*/

#ifndef XML_H_
# define XML_H_

#define	REGEX_ELEM	"^<(([a-zA-Z0-9_-]+)(( )([a-zA-Z0-9_-]+)=(\")([a-zA-Z0-9_.-]+)(\"))*)((/>)$)"
#define	REGEX_OPEN_NODE	"^<([a-zA-Z0-9_-]+)>$"
#define	REGEX_CLOSE_NODE	"^(</)([a-zA-Z0-9_-]+)>$"
#define	REGEX_COMMENT	"^(<!--)([[:alnum:][:space:][:punct:]]+)(-->)$"
#define	REGEX_SPEC	"<\?xml [[:alnum:][:punct:]=[:blank:]]*\?>"

#define	TYPE_OPEN_NODE		1
#define	TYPE_CLOSING_NODE	2
#define	TYPE_ELEM		3
#define TYPE_COMMENT		4
#define TYPE_PROLOGUE		5

#define	STATE_NONE	-1
#define	STATE_RT	0
#define	STATE_SCENE	1
#define	STATE_OBJS	2
#define	STATE_SPHERE	3
#define	STATE_PLAN	4
#define	STATE_CYLINDRE	5
#define	STATE_CONE	6
#define	STATE_CUBE	7
#define	STATE_LIGHTS	8
#define	STATE_LIGHT	9
#define	STATE_CAM	10
#define	STATE_UNKNOWN	11

#define	FILTER_NONE	0
#define	FILTER_RED	1
#define	FILTER_BLUE	2
#define	FILTER_GREEN	3
#define	FILTER_BW	4
#define	FILTER_NEG	5
#define	FILTER_SEPIA	6

#define	MAX(x, y)	((x) > (y) ? (x) : (y))
#define	MIN(x, y)	((x) < (y) ? (x) : (y))

#define	CUBESIZE	50
#define	CUBE_X	(int)((double)(g_cube[5 - i].x) * ((double)(tmp->width_limit / 2) / (double)CUBESIZE)) + new_val
#define	CUBE_Y	(int)((double)(g_cube[5 - i].y) * ((double)(tmp->width_limit / 2) / (double)CUBESIZE)) + new_val
#define	CUBE_Z	(int)((double)(g_cube[5 - i].z) * ((double)(tmp->width_limit / 2) / (double)CUBESIZE)) + new_val

typedef struct	s_tab_xml_dep
{
  char		*xml_cmp;
  int		xml_dep;
  int		xml_type;
}		t_tab_xml_dep;

typedef struct	s_pile
{
  char		*str;
  struct s_pile	*next;
}		t_pile;

typedef struct		s_xml
{
  int			state;
  t_pile		*stack;
}			t_xml;

typedef struct		s_xml_tab_color
{
  char			*color_name;
  int			color_value;
}			t_xml_color_tab;

typedef struct		s_xml_tab_filters
{
  char			*filter_name;
  int			filter_value;
}			t_xml_tab_filters;

typedef struct		s_composed_obj
{
  int			x;
  int			y;
  int			z;
  int			r_x;
  int			r_y;
  int			r_z;
}			t_composed_obj;

#endif /* !XML_H_ */
