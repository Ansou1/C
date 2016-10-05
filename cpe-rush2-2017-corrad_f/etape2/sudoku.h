/*
** sudoku.h for sudou in /home/corrad_f//projet/sudoku
**
** Made by florian corradin
** Login   <corrad_f@epitech.net>
**
** Started on  Sat Apr 20 20:34:27 2013 florian corradin
** Last update Sun Apr 21 11:25:09 2013 simon daguenet
*/

#ifndef SUDOKU
# define SUDOKU

# define  _SVID_SOURCE

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	g_len;

typedef struct	s_point
{
  int		x;
  int		y;
}		t_point;

	/* check.c */
char	**realloc_tab(char **tab, char *str);
int	check_base(char s, char *base);
int	check_map(char **su, char *base);

	/* get_map.c */
char	*get_clean_line(char *s, char *base);
char	*get_sudo_line(char *s, char *base);
char	**get_sudo(char *base);
int	send_map(char **su, char *base);

	/* get_next_line.c */
int	new_line(char *str);
char	*my_cpy(char *buff, char *out);
char	*my_realloc(char *str, int size);
char	*get_next_line(const int fd);

	/* print.c */
void	my_puttab(char **tab);
void	my_puterror(char *str);

	/* resolve.c */
int	is_cube(char **sol, int x, int y, int val);
char	get_next_value(char **sol, int x, int y);
int	next_case(char **sudo, int *x, int *y);
int	previous_case(char **sudo, int *x, int *y);
void	get_good_sudo(char **sudo, char *base);

void	check_imp(char **sudo, int x, int y, t_point p);

	/* resolve_fou.c */
char	**resolve(char **sudo, char **sol);
char	**get_g(char **sudo, char *base);

	/* resolve_sec.c */
void	aff(char **tab, char *base);
char	digit(char *digit, char d);
char	**my_tabdup(char **tab);
char	get_the_first(int *x, int *y, char **tab);
char	is_intouchable(char **sudo, int x, int y);

	/* resolve_thr.c */
int	is_col(char **sol, int x, int y, int val);
int	is_line(char **sol, int x, int y, int val);
int	is_in_rule(char **sol, int x, int y, int val);
void	next(int *x, int *y);
void	previous(int *x, int *y, int len);

	/* x_function.c */
void	*xmalloc(size_t taille);
void	my_freetab(char **tab);

#endif
