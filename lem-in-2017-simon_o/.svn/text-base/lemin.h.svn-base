/*
** lemin.h for lemin in /home/daguen_s//my_lemin
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Apr  1 14:35:53 2013 simon daguenet
** Last update Sun Apr 28 22:24:35 2013 simon daguenet
*/

#ifndef LEMIN_H
#define LEMIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>

# define	SIZE_READ	(16)
# define	START		(1)
# define	END		(2)
# define	ROOM		(3)
# define	USELESS		(4)
# define	ERROR1		"\033[1;31mMissing start\033[0;m\n"
# define	ERROR2		"\033[1;31mMissing end\033[0;m\n"
# define	FILE		"\033[1;31mInvalide file\033[0;m\n"

typedef struct	s_room
{
  unsigned int	ant;
  char		*name;
  char		type;
  int		p;
  unsigned int	n1;
  unsigned int	n2;
  struct s_room	**tab;
}		t_room;

typedef struct	s_name
{
  char		*name1;
  char		*name2;
}		t_name;

char	**g_name;

	/* del_crossing_way.c */
t_room		**sort_tab(t_room **tab);
t_room		*next_room(t_room *way);

	/* del_crossing_way_sec.c */
t_room		**del_link(t_room **tab, t_room *link, t_room *room);
void		del_the_cross_bis(t_room *way, int *ctr, int *ctr2, int i);
void		del_the_cross(t_room *way);
void		del_the_useless_link(t_room *start, t_room **r);
void		del_crossing_way(t_room	**r);

	/* dell_useless_way.c */
void		delink_in_tab(t_room *room);
void		dell_one_direction_way(t_room **tab);

	/* door.c */
int		check_door(char *s, int door);
void		result_door(int door);

	/* get_file.c */
int		count_space(char *str);
char		**realloc_tab(char **tab, char *str);
char		**get_file_lemin();
int		get_nbr_room(char **file);

	/* get_next_line.c */
char		*my_strcpy(char *dest, char *src);
char		*my_strcat(char *dest, char *src);
int		my_buf(char *buffer, char *buffer_s, int ret);
char		*my_realloc(char *buffer, int size);
char		*get_next_line(const int fd);

	/* lemin.c */
void		check_file(char **file, int size);
int		main();

	/* link.c */
char		is_link(char *str);
t_room		**get_the_link(t_room **tab, char **file);
char		*get_name2(char *line);
t_room		**change_add(t_room **tab, char *file);
t_room		*get_address(t_room **tab, char *name);

	/* moov.c */
void		push_name(t_room *room, t_room *save);
void		push_ant_until(t_room *room, int name);
int		clean_the_way(t_room *way);

	/* moov_sec.c */
void		moov_ant_bis(t_room *start, int i, int check, int name);
void		moov_the_last(t_room *start);
void		moov_ant(t_room *start);

	/* my_link.c */
int		my_str_comp(char *s1, char *s2);
t_room		*my_add_link(t_room *mail, t_room *add);
t_room		**modif_tab(t_name name, t_room *a1, t_room *a2, t_room ** tab);

	/* parser.c */
char		is_nbr_ant(char *str);
char		is_room(char *str);
t_room		*get_info(char *str, int ant);
t_room		*creat_maill(char *name, int ant, int type);
t_room		**parser_str(char **file, int size);

	/* print.c */
void		my_putchar(char c);
void		my_putstr(char *str);
void		my_putnbr_base2(int nb, char *base);
void		my_print_char(va_list ap, char format);
void		my_printf(char *format, ...);

	/* tools_2.c */
char		*my_strcat_lem(char *s1, char *s2);
int		my_atoi(char *str);
char		*my_epurstr(char *str);

	/* tools_3.c */
int		my_tablen(t_room **tab);
void		free_room(t_room **tab);
char		is_digit(char c);
char		*get_name(char *str);

	/* tools.c */
int		my_strlen(char *str);
char		*my_strdup(char *src);
char		*my_strstr(char *str, char *to_find);
int		my_strcmp(char *str1, char *str2);
int		my_strncmp(char *str1, char *str2, int n);

	/* water_fill.c */
char		change_all_link_weight(t_room **tab, int p);
char		fill_all_of_the_same_weight(t_room **tab, int p);
t_room		**water_fill(t_room **tab);
void		reset_water(t_room **r);

	/* x_func.c */
int		my_puterror(char *str);
void		xfree(void *ptr);
void		*xmalloc(size_t taille);
void		xclose(int fd);
void		my_free_tab(char **tab);

#endif
