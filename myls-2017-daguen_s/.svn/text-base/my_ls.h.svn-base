/*
** my_ls.h for ml_ls in /home/daguen_s//ls/my_ls
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Tue Nov 27 10:15:48 2012 simon daguenet
** Last update Sun Dec  2 21:47:44 2012 simon daguenet
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdarg.h>

#ifndef MY_LS_H_
# define MY_LS_H_

char	*del_x_options(char *options);
char	*get_options(int ac, char **av);
char	**get_args(int ac, char **av);
void	get_options_and_args(int ac, char **av, char **option, char ***args);
char	*my_strcat(char *dest, char *src);
int	my_strlen(char *str);
char	*my_strdup(char *src);
void	my_putchar(char c);
void	my_putstr(char *str);
void	display_list(char *options, char **args);
char	*my_strstr(char *s1, char *s2);
void	display_without_options(char **tab);
void	display_with_option_d(char *path, char *options);
void	display_data(struct stat sb);
void	display_rights(struct stat sb);
void	display_with_option(char *path, char *options);
int	count_nbr_name(char *path);
void	sort_in_tab(char **tab, int taille);
char	**pick_up_name(char *path, char **tab);
void	sort_in_tab_reverse(char **tab, int taille);
int	check_options(char *options, int nbr, char **tab);
void	display_opt(char **tab, int nbr);
char	*my_putstr_temps(char *str, struct stat sb);
int	my_strcmp(char *s1, char *s2);
void	freetab(char **tab, int line);
void	my_print_char(va_list ap, char format);
int	my_printf(char *format, ...);
long	my_putnbr_base2(long nb, char *base);
void	del_red(char *options, int *j, char *str);
void	init_var(char *var);

#endif
