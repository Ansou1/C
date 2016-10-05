/*
** rush.h for rush in /home/daguen_s//rush
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Fri Mar  1 23:45:18 2013 simon daguenet
** Last update Sun Mar  3 14:52:14 2013 simon daguenet
*/

#ifndef RUSH_H_
# define RUSH_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_laby
{
  int	**tab;
  int	**algo;
  int	**end;
  int	a;
  int	b;
  int	y;
  int	x;
  int	i;
  int	size_x;
  int	size_y;
  int	cnt;
  int	one_coordx;
  int	one_coordy;
  int	two_coordx;
  int	two_coordy;
  int	found;
  int	bestpath;
  int	nb;
  int	new_pathy;
  int	new_pathx;
}		t_laby;

/* algo_number.c */
void	algo_one(int cnt, int x, int y, t_laby *s);
void	algo_two(int cnt, int x, int y, t_laby *s);
void	algo_three(int cnt, int x, int y, t_laby *s);
void	algo_for(int cnt, int x, int y, t_laby *s);

/* algo_laby.c */
void	check_algo(t_laby *s);
void	algo_start(int y, int x, t_laby *s);
void	algo_laby(t_laby *s);

/* end_number.c */
int	end_one(int x, int y, t_laby *s);
int	end_two(int x, int y, t_laby *s);
int	end_three(int x, int y, t_laby *s);
int	end_for(int x, int y, t_laby *s);

/* end.c */
void	end_tab(t_laby *s);
int	end(t_laby *s);
void	get_end(t_laby *s);

/* get_next_line.c */
int	new_line(char *str);
char	*my_cpy(char *buff, char *out);
char	*my_realloc(char *str, int size);
char	*get_next_line(const int fd);

/* get_map.c */
int	get_line(char *av);
void	get_first_line(char *s, int *height, int *width, int);
void	check_map(char *str);
int	check_door(char *str);

/* grimly.c */
int	**get_map(char *av, t_laby *s);
char	**map_in_tab(char **map, int fd, int taille, int *width);
int	**put_in_map(char **tab, int taille, int width, int);

/* print.c */
void	my_putchar(char c);
void	my_putstr(char *str);
int	my_strlen(char *str);
void	my_print_error(char *str);
int	my_strcmp(char *s1, char *s2);

/* x_function.c */
void	xfree(void *ptr);
void	*xmalloc(size_t taille);
void	xclose(int fd);

/* laby.c */
void	found_one(t_laby *s);
void	found_two(t_laby *s);
void	init_laby(t_laby *s);
void	display_path(t_laby* s);
void	aff_tab(t_laby *s);

#endif
