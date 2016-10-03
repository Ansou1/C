/*
** mysh.h for mysh2 in /home/daguen_s//secminishell
** 
** Made by simon daguenet
** Login   <daguen_s@epitech.net>
** 
** Started on  Mon Mar  4 13:19:55 2013 simon daguenet
** Last update Sun Mar 10 20:33:41 2013 simon daguenet
*/

#ifndef MYSH_H_
# define MYSH_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <unistd.h>
#include <dirent.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>

# define BUFF	(100)
# define SUP_I	"setenv: Too many arguments.\n"
# define MIN_I	"setenv: Too few arguments.\n"

typedef struct	s_element
{
  char			*data;
  struct s_element	*next;
}			t_list;

void	my_putchar(char c);
void	my_putstr(char *str);
int	my_strlen(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strcat(char *dest, char *src);
char	*my_strdup(char *src);
void	my_putnbr_base2(int nb, char *base);
void	my_print_char(va_list ap, char format);
void	my_printf(char *format, ...);
void	my_put_error(char *str);
void	error_with_function(int i);
void	xfree(void *ptr);
void	*xmalloc(size_t taille);
void	my_dup(int old, int new);
char	*my_epurstr(char *str);
int	good_cmd(char *cmd);
void	init_var(int *var);
int	count_w(char *str);
int	count_char(char *str);
char	**wordtab_dbp(char *str);
int	my_strlen_dbl(char **tab);
void	free_tab(char **tab);
char	*get_path(char **env);
void	put_my_oldpwd(char **my_env, char **env_for_cd);
int	is_sep(char c, char *sep);
int	my_count_word(char *str, char *sep);
char	**str_to_wordtab(char *str, char *sep);
int	get_redirection(char *str);
char	**init_redi(char **redi);
char	**clean_tab(char **tab);
void	redi_out(char **env, char **tab_redi, int v_redi);
void	aff_list(t_list **list);
int	my_rev_list(t_list **begin);
void	free_list(t_list *list);
t_list	*my_put_in_list(t_list **list, char *data);
t_list	*dbl_redi_left(char **tab_redi);
void	redi_in(char **env, char **tab_redi, int v_redi);
void	gestion_redirection(char **env, char *cmd, int v_redi);
char	*my_strdup_oldpwd(char *src);
char	*my_strdup_user(char *src);
char	*get_pwd_for_oldpwd(char **my_env, char *command);
char	*get_value_user(char **my_env, char *command);
char	*my_strdup_old(char *src);
char	*get_value_oldpwd(char **my_env, char *command);
int	existing_directory(char *path);
void	my_builtin_env(char **my_env);
void	my_builtin_setenv(char **my_env, char **tab_co);
void	put_my_oldpwd(char **my_env, char **env_for_cd);
int	my_builtin_unsetenv(char **my_env, char **tab_co);
void	my_builtin_cd(char **my_env, char **tab_co);
void	processus_son(char **my_env, char **tab_co);
void	processus_father(pid_t pid);
void	guid_other_command(char **my_env, char **tab_co);
void	guid_command(char **my_env, char **tab_co);
void	gestion_cmd_other(char **env, char *cmd);
void	exec_pipe(char **my_env, char *tab_co);
int	xfork();
void	xpipe(int pipefd[2]);
void	xclose(int fd);
void	inf_pipe(char **env, char **pipe_cmd, int nbr_pipe);
void	gestion_cmd_pipe(char **env, char **pipe_cmd, int taille);
void	guid_command_all(char **env, char *cmd);
void	my_prompt(char **env);
#endif
