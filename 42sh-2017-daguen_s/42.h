/*
** 42.h for 42sh in /home/corrad_f//projet/42sh
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Fri Feb 22 17:40:50 2013 florian corradin
** Last update Fri May 24 15:35:55 2013 simon daguenet
*/

#ifndef SH
# define SH

# define _POSIX_C_SOURCE 1
# define _BSD_SOURCE

#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pwd.h>
#include <glob.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <string.h>
#include <time.h>
#include <errno.h>

# define RIGHT_OPEN	(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
# define PIPE		(1)
# define D_LEFT		(2)
# define D_RIGHT	(3)
# define LEFT		(4)
# define RIGHT		(5)
# define SEPARATOR_OR	(1)
# define SEPARATOR_AND	(2)
# define SEMI_COLUMN	(3)
# define FAIL		(-100)
# define SUCCESS	(0)
# define SPECIAL_CHAR	"$/,;|<>\\*-+.%#\n()"
# define CHAR_INIB34	" \\*\t|<>?[\n()"
# define CHAR_INIB39	" \\*\t$|><?[\n()`"
# define STOP		"\033[0m"
# define RED		"\033[31m"
# define WHITE		"\033[37m"
# define PINK		"\033[35m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define CIAN		"\033[36m"
# define GRAS		"\033[01m"
# define VO		"\033[07m"
# define CLIGNO		"\033[05m"
# define SOU		"\033[04m"

# define STORM_TROOPER		"ascii_art/stormtrooper"
# define DARK_VADOR_PATATE	"ascii_art/dark_vador_patate"
# define VADOR			"ascii_art/dark_vador"
# define SEG			"ascii_art/segfault"
# define PIG			"ascii_art/pig"
# define FLINGUEUR		"ascii_art/flingueur"
# define ZOMBIE			"ascii_art/zombi"
# define DIABLE			"ascii_art/diable"
# define KILL			"ascii_art/kill"
# define DOG			"ascii_art/dog"
# define WOLF			"ascii_art/wolf"
# define OPEN			"ascii_art/open"

# define USAGES	"Try --help for more information or m in commad \
line to print the infect manual\n"

int			g_statu; /* statut actuel du shell */
int			g_ascii; /* option ascii */
int			g_old_com; /* valeur de retour de l'ancienne commande */
unsigned int		g_com_ctr;
char			*g_msg_error;
int			g_wait_com;
char			g_debug; /*pour le debug*/
typedef struct		s_hist
{
  int			hr;
  int			min;
  int			nbr;
  char			*data;
  struct s_hist		*previous;
  struct s_hist		*next;
}			t_hist;

typedef struct		s_alias
{
  char			*alias;
  char			*com;
  struct s_alias	*next;
}			t_alias;

t_alias			*g_alias;

typedef struct		s_info
{
  char			**env;
  char			**path;
  char			*old_pwd;
  char			*home;
  char			*term;
  time_t		time;
  t_hist		*hist;
}			t_info;

t_info			info;

typedef struct		s_com
{
  char			*file;
  char			**commande;
  char			redir;
  struct s_com		*next;
  struct s_com		*previous;
}			t_com;

typedef struct		s_string
{
  char			*exec;
  char			*file;
}			t_string;

int	get_nbr_of_redir(t_com *list);
t_hist	*get_cmd_for_history(t_hist *list, char *cmd);
int	is_number(char *str);
int	nbr_in_list_histo();
char	*remplace_nbr_cmd_neg(int nbr, char *str);
char	*remplace_nbr_cmd_pos(int nbr, char *str);
char	*remplace_chaine_cmd(char *str);
char	*replace_cmd_hist(char *str);
char	*rep_str(char *src, char *del, char *rep, int pos);
char	*get_del(char *command);
char	*get_rep(char *command);
char	*ex_history(char *cmd);
t_hist	*put_cmd_in_history(t_hist *list, char *cmd);
void	free_list_histo(t_hist *list);
void	init_check_base(int *var, char *base);
int	check_base_loop(int *var, char *b, char *opt);
int	check_base(char *opt);
int	get_options(char *str);
void	print_just_histo(t_hist *l, int opt, int nbr);
void	print_just_reverse(t_hist *l, int opt, int nbr);
void	gestion_histo(t_hist *l, int option, int nbr);
void	my_history(char **com, t_hist *list);
char	*get_cmd_all();
void	bultins_history(t_com *list);
int	check_is_good_cmd(const char *cmd);
int	check_valide_command(const char *cmd);

/* varibles.c */
char	*get_other_shell_var(char *str);
char	*get_not_env_var(char *str);

/* main.c */
int	my_shell(char *com);
char	*module_str(char *command_line);
int	exit_shell(char *str);
int	my_prompt();
char	*check_sep_com(char **separator, int i);

/* tab_concat */
int	my_tablen(char	**tabl);
char	**my_tabcat(char **tabl, char *str);

/* env.c */
char	*my_fill_home(char *env);
char	*my_fill_path(void);
char	**is_var_is_not_now_is_in_the_env(char **env);
char	**get_good_env(char **env);
int	is_buitins(char **com);
int	is_cd(char **com);
int	is_env(t_com *list);
int	my_exec_line(t_com *list);
int	my_parser_comm(char *com);

/* str_concat.c */
char	*my_strcat(char *strt, char *end);
char	*my_strcat_free_strt(char *strt, char *end);
char	*my_strcat_free_end(char *strt, char *end);
char	*my_strcat_free_all(char *strt, char *end);

/* separator.c */
int	get_number_of_in_str(char *str);
char	*my_strcopy_to_separator(char *str, int *position);
char	**my_get_separator(char *com, char **sep);

/* clean_pars_line.c */
char	*dell_tab(char *str);
int	is_redir(char *str, int pos);
char	*my_strcopy_redir(char *ret, char *sym, int *ctr, int *i);
char	*get_redir_in_str(char *ret, char *com, int *ctr, int *i);
char	*clear_commande_line(char *com);

/* list_double.c */
void	my_get_list_double(t_com **list);
t_com	*recup_list(int size);
void	my_free_list(t_com *list);

/* parser_com.c */
int	get_list_maill(char *com, int *i, t_com *list);
t_com	*my_put_in_list(char *com, t_com *list);
int	init_shell(int *ctr, int *i, char *com);
t_com	*list_fill_and_inhib(t_com *list, t_string str, char *com, int ind);

/* get_path.c */
char	*my_copy_path(char *ret, char *path);
int	have_nbr_of_path(char *path);
char	*get_good_path(char *path);
char    **my_get_path(char **env);

/* buitins_env.c */
char	**dell_env_line(char **env, char *com);
char	**my_unsetenv(char **env, char **com, int mod);
char	*replace_setenv_line(char *env, char **com);
char	**my_setenv_rep(char **com, char **env);
char	**my_setenv(char **com, char **env);
int	my_env_fct(char **com, int mod);
int	sum_size(char **tabl);

/* x_fct.c */
void	xfree(void *ptr);
void	*xmalloc(size_t taille);
int	xfork(int context);
int	xpipe(int pipefd[2], int context);
int	xclose(int fd, int context);
int	xdup2(int oldfd, int newfd, int context);

/* pipe.c */
void	multipipe(t_com *list);
void	multipipe2(t_com *list);
void	multipipe_right2(t_com *list, int fd);
void	multipipe_right(t_com *list, int cas);
void	redir_left(t_com *list);
void	multi_pipe_left_s(t_com *list);
void	multipipe_left(t_com *list, int cas, char *bif);
void	multi_pipe_left_d(t_com *list, char *bif);

/* pipe_redir.c */
void	multipipe_left_file(t_com *list, int cas);
void	multiredir(t_com *list);
char	*eror_multiredir(t_com *list);

/* get_com_parser.c */
t_string	get_com_params(char *com, t_string str);
char	*get_str_file(char *com);
char	*get_str_com(char *com);
int	get_str_com_cut(char *com, int i);

/* error.c */
void	my_put_error(char *str);
void	my_put_on_error(char *str);

/* commande.c */
void	my_exec_commande(t_com *list);
void	my_wait(void);
void	my_wait2(void);
void	my_exec(char **com);
char	my_test_com(char *path_bin, char **com);

/* double_redir.c */
char	*get_buf_redir_left(char *file);
void	double_left(t_com *list, char *bif);
void	redir_right(t_com *list, int cas);
void	redir_simple(t_com *list, int cas);

/* type_redir.c */
int	is_multipipe(t_com *list);
int	is_multipipe_right(t_com *list);
int	is_multipipe_left(t_com *list);
int	is_multipipe_left_file(t_com *list);
int	is_multi_redir(t_com *list);
int	is_redir_simple(t_com *list);

/* separator.c */
int	get_number_of_in_str(char *str);
int	is_separator(char *str);
char	*my_strcopy_to_separator(char *str, int *position);
char	*get_num_sep(char *com, char *sep, int ctr);
char	**my_get_separator(char *com, char **sep);

/* var_env.c */
char	*get_var_env(char *env);
char	*my_getenv(char *var);
char	*get_value_of_var(char *str);
char	*replace_in_str(char *src, char *del, char *rep, int pos);
int	is_special_char(char c);
char	*get_del_var(char *com);
int	is_var(char *str, int pos);
char	*check_var(char *com, int pos);

/* str_tab_inib.c */
char	**str_to_tab_inib(char *str);
char	*get_word_inib(char *str, int *pos);
int	is_c(char *str, int pos, char c);
char	*get_word_inib_suite(int *pos, int ctr, char *str);

/* inhibiteur.c */
int	is_this_type(char c, char *type);
int	is_inib(char *com, int pos);
int	inib_this_char(char com, int inib);
char	*get_str_inhib(char *com);
void	init_get_str_inib(int *i2, int *inib, int *i);

/* deshiniber.c */
char	**de_inhib_tab(char **tabl);
char	*desinhiber(char *str);
int	check_inhibiteur(char *str);

/* glob.c */
char	*recup_glob(char **glob);
char	*my_glob(char *globin);
char	*get_glob(char *str);
char	*put_globin(char *com);

/* back_quote.c */
char	*get_next_file(int fd);
char	*get_bq_rep(char *com);
char	*get_back_quot();
char	*creat_file_bq(char *com);
char	*replace_bq_str(char *com, int pos);
char	**get_back_quote_tab(char **com);
char	*get_del_bq(char *rep);

/* cd.c */
int	change_directory(char **com, int mod);
int	my_cd(char **com, int mod);
char	*my_get_pwd(void);
int	replace_env(void);
void	replace_old_pwd(char *rep);
int	go_home(int mod);
int	go_back(int mod);

/* ascii.c */
int	put_file(char *file, char *color);
int	aff_help();
void	check_option(int ac, char **av);
int	infectsh(char *str);
int	check_c(int ac, char **av);

/* script.c */
int	strlen_c(char *str, char c);
char	**my_word_tab(char *str, char c);
int	my_exec_script(char *file);
int	my_script(char **com);
char	is_scripting(char *com);

/* atof.c */
int	get_exp(int c, char *s, int e);
double	get_double(int e, double a);
double	my_atof(char *s);

/* alias.c */
void	my_put_alias();
void	init_alias(int ac, char **av);
t_alias	*add_in_alias(char *alias, char *com, t_alias *list);
char	*my_replace_alias(char *str, char *del, char *rep);
char	*get_alias_loop(t_alias *alias, char *com);
int	alias_match(char *com, char *path);
char	*modif_com_line(t_alias *alias, char *com, int *ctr);
void	sig_fpe(int sig);
void	my_put_error2(char *str);

/* aliasbult */
t_alias	*alias_bult(char **com);
void	my_put_alias_var(char *com);
t_alias	*my_set_alias(char *com);
char	is_set_alias(char *str);

/* buitins.c */
int	is_buitins(char **com);
void	my_bultins(char **com);
int	ex_bultins(char **com);

/* edit.c */
int	my_putc(int c);
void	del_line();
int	mode_echo();
int	get_data_base(void);
char	*my_edit(char *com, char *buf);
char	*selection();
int	aff_img(char *name, int nb);
int	effect_prompt(char *str, int ret);

/* prompt.c */
int	put_effect(char *p, int i);
void	put_aff(char *p);
char	put_prompt();
int	effect_prompt(char *str, int ret);
int	put_effect2(char *p, int i);

/* type.c */
char	is_digit(char c);
char	is_alpha(char c);
char	is_operator(char c);
char	is_varchar(char c);

/* echo.c */
char	is_option(char *com);
void	put_opt(char *str);
void	echo_e(char **com, char mod);
char	option(char **com);
void	echo1(char **com, char mod);
void	my_echo(char **com);

/* clean_commande */
int	count_pipe(t_com *list);
int	is_strnum(char *str);
int	check_nbr(char *commande);
void	get_cmd2(int nbr);
void	get_cmd(char *command1);
char	**change_command(char **command);
t_com	*clean_command(t_com *list);

/* thetime. */
time_t	get_time();
int	get_seconds();
void	aff_time();
int	get_rand();

/* lib */
void	check_malloc(void *ptr);
char	*my_strdup(char *str);
char	**my_copy_tab(char **src);
void	my_free_tab(char **tabl);
void	my_put_tab(char **tabl);
char	*my_memset(char *str, char c, int size);
char	*my_strcopy(char *ret, char *copy);
char	*next_line(char *buf, int *pos, char *ret);
char	*get_next_line(const int fd);
char	*my_epurstr(char *str);
char	*my_get_word(char *buf, int *pos);
int	my_count_word(char *buf);
int	my_is_word(char *buf, int i);
char	**my_str_to_wordtab(char *buf);
int	my_str_comp(char *s1, char *s2);
int	my_atoi(char *str);
int	is_s(char *str, int pos);
char	*my_epurstr_inib(char *str);
int	my_putchar(unsigned char c);
void	my_putstr(char *str);
int	my_strncmp(char *str1, char *str2, int n);
int	my_strlen(char *str);
int	my_putvoidc(const void *c);
void	my_putvoid(void *str);
char	*my_epurstr_free(char *str);
char	is_digit(char c);
char	is_alpha(char c);
char	is_operator(char c);
char	**my_tabdup(char **tabl);
void	my_eror(int nb);
void	my_put_nbr(int nb);
int	digit(char *base, char c);
int	my_strtoll(const char *nptr, char *base);

#endif
