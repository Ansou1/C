/*
** mysh.h for header in /home/daguen_s//my_minishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Wed Dec 19 17:29:48 2012 simon daguenet
** Last update Sun Dec 23 12:57:10 2012 simon daguenet
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <unistd.h>
#include <dirent.h>
#include <signal.h>

#ifndef MYSH_H_
# define MYSH_H_

#define BUFF 1000

void	my_putchar(char c);
void	my_putstr(char *str);
int	my_strlen(char *str);
char	*my_strstr(char *str, char *to_find);
char	*my_strcat_furui(char *dest, char *src);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strcat(char *dest, char *src);
int	my_strcmp(char *s1, char *s2);
char	*my_strdup(char *src);
char	*my_strdup_oldpwd(char *src);
char	*my_strdup_user(char *src);
char	*my_strdup_old(char *src);
int	my_d_strlen(char **str);
int	count_word(char *str);
int	countchar(char *str);
char	**my_str_to_wordtab(char *str);
void	my_builtin_env(char **my_env);
int	count_w(char *str);
int	count_char(char *str);
void	my_putnbr_base2(int nb, char *base);
void	my_print_char(va_list ap, char format);
void	my_printf(char *format, ...);
void	init_var(int *var);
char	**wordtab_dbp(char *str);
char	*get_path(char **env);
void	processus_son(char **my_env, char **tab_co);
void	get_sigint(int sig);
void	processus_father(pid_t pid);
void	my_builtin_setenv(char **my_env, char **tab_co);
int	my_builtin_unsetenv(char **my_env, char **tab_co);
char	*get_pwd_for_oldpwd(char **my_env, char *command);
void	put_my_oldpwd(char **my_env, char **env_for_cd);
char	*get_value_user(char **my_env, char *command);
char	*get_value_oldpwd(char **my_env, char *command);
int	existing_directory(char *path);
void	my_builtin_cd(char **my_env, char **tab_co);
void	guid_other_command(char **my_env, char **tab_co);
void	guid_command(char **my_env, char *command);
char	*my_epurstr(char *str);
void	my_prompt(char **my_env);

#endif
