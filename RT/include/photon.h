#ifndef PHOTON_H_
# define PHOTON_H_

# define INCAXIS(x)		((x + 1 == 3) ? (x = 0) : (x += 1))
# define RATIO(x)		(((x) > 1) ? (1) : (((x) < 0) ? (0) : (x)))

# define PHOTON_RATIO		1000

enum	e_search
  {
    NNEAREST,
    DNEAREST
  };

typedef struct s_photon		t_photon;
typedef enum   e_search		t_search;
typedef struct s_photon_list	t_photon_list;
typedef struct s_near_photon	t_near_photon;
typedef struct s_photon_map	t_photon_map;
typedef struct s_photon_info	t_photon_info;
typedef struct s_kdtree		t_kdtree;

struct s_photon
{
  t_coords	*pos;
  t_coords	*vec;
  double	power;
  t_color	color;
};

struct s_photon_list
{
  t_photon	*cur;
  double	dist;
  t_photon_list	*next;
  t_photon_list	*prev;
};

struct s_near_photon
{
  t_photon_list	*begin;
  t_photon_list	*last;
  double	last_dist;
  int		max_len;
  int		len;
};

struct s_kdtree
{
  t_photon	*photon;
  int		axis;
  t_kdtree	*right;
  t_kdtree	*left;
};

struct s_photon_map
{
  t_photon	**map;
  int		map_size;
  int		cur;
  t_kdtree	*tree;
};

struct s_photon_info
{
  double	power;
  t_color	color;
  t_coords	*pt;
  t_coords	*vec;
};

t_photon_map	*launch_photons(t_light_list *light, t_rt *this);
void		fill_photon_map(t_photon_map *map, t_light_list *light, t_rt *this);
void		launch_from_light(t_light_list *light, t_photon_map *map, t_rt *this);
t_kdtree	*create_kdtree(t_photon **map, int axis, int begin, int end);
void		qsort_photons(t_photon **tab, int axis, int begin, int end);
t_near_photon	*get_nearest_photons(int n, t_photon_map *photon_map, t_coords *pt);
t_near_photon	*get_photons_dist(double dist, t_photon_map *photon_map, t_coords *pt);

#endif/* !PHOTON_H_ */
