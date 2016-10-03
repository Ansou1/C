/*
** sript.h for scripting in /home/corrad_f//projet/infect
** 
** Made by florian corradin
** Login   <corrad_f@epitech.net>
** 
** Started on  Wed Apr  3 11:01:49 2013 florian corradin
** Last update Fri May 24 15:37:24 2013 simon daguenet
*/

#ifndef SCRIPT_H
# define SCRIPT_H

# define WHILE		(1)
# define FOR		(2)
# define UNTIL		(3)
# define IF		(4)
# define ELSE_IF	(5)
# define ELSE		(6)
# define EXEC		(7)
# define DONE		(8)
# define FI		(9)
# define FUNCTION	(10)
# define OTHER		(11)
# define VAR		(12)
# define LET		(13)
# define COM		(14)
# define CALL_FCT	(15)
# define LOCAL		(16)
# define READ		(17)
# define CASE		(18)
# define ESAC		(19)
# define ASIGN		(20)
# define END_FUNC	(21)
# define DO		(22)
# define THEN		(23)
# define TRAP		(24)
# define V_INT		(1)
# define V_DOUBLE	(2)
# define V_STR		(3)
# define V_TAB		(4)

int		g_add;

typedef struct	s_script
{
  char		type;
  int		att;
  int		add;
  char		*name;
  char		*inst;
  char		**tab;
}		t_script;

typedef struct	s_var
{
  char		*name;
  char		**tab;
  char		*val;
  char		type;
  struct s_var	*next;
}		t_var;

/* 1 chaine 2 et 3 ou */
typedef struct	s_cond
{
  int		type;
  char		*data;
  struct s_cond	*next;
}		t_cond;

typedef struct	s_trap
{
  t_script	**s;
  t_var		**v;
  int		i;
  char		active;
}		t_trap;

t_trap		g_trap;

char		g_stop_script;

struct s_op
{
  char		c;
  int		p;
  int		(*f)();
};

typedef struct s_op	t_op;

/* add_var.c */
char		*get_str_sep(char *str, char sep);

/* ex_all.c */
int		ex_type(t_script **s, t_var **v, int *i);
int		ex_all(t_script **s, t_var **v);

/* ex_asign.c */
t_var		*get_tab_var_mail(t_script *s);
t_var		*get_var_mail(t_script *s, t_var *v);
void		ex_asign(t_script *s, t_var **v);

/* ex_com.c */
void		ex_com(t_script **p, t_var **list, int i);
char		**get_for_trap_com(char *com);

/* function.c */
int		is_function(char *line);
t_script	*get_function(char *file, int pos);
t_script	*get_end_function(char *file);
t_script	**pars_function(char **file, int *i, t_script **pars);
t_script	*get_end_function(char *file);

/* is_scripting.c */
char		is_scripting(char *com);
int		free_and_ret(char *s, int ret);
char		is_scripting2(int fd1, char *buf);

/* let.c */
int		unaire(char *inst, int name);
t_script	*exec_let(t_script *s, t_var **list, int pos);
t_script	*pars_let(char *file, int pos);
char		*get_let_name(char *file, int pos);

/* modif_str.c */
char		*replace_by_in_str(char *str, char rep, char by);
char		*get_next_word(char *str);

/* parser_script.c */
int		go_to_in_str(char *str, int i, char c);
t_script	*get_key_done(t_script **pars, int pos);
t_script	*get_other(char *file, int type);
void		check_name(char *str);
int		get_var_type(char *str);
t_script	*get_tab_var(char *name, char *file);
t_script	*get_var(char *file);
t_script	*get_let(char *file, int pos);
t_script	*get_com(char *file);
t_script	*get_inst(char **file, t_script **pars, int pos);
void		put_scri(t_script **scr);
t_script	**get_pars(char **file);
t_script	*get_key_done_error(int ctr_loop, int pos, t_script *ret);
t_script	*get_inst2(char **file, t_script **pars, int pos);

/* recup_var.c */
char		*get_name_var_script(char *name, t_var *list);
char		*recup_var_script_tab(char *name, t_var *list);
char		*get_del_var_script2(char *str, char *ret, int i);
char		*recup_var_script(char *name, t_var *list);
char		*get_del_var_script(char *str, int op);
char		*check_var_script(char *com, int pos, t_var *list);
char		*check_var_script_op(char *com, int pos, t_var *list);

/* script.c */
int		script_exit(t_script **p, t_var *list);
int		strlen_c(char *str, char c);
char		**my_word_tab(char *str, char c);
int		my_exec_script(char *file);
void		my_free_scr(t_script **s);
char		**get_comment(char **file);
t_var		*get_arg_var(char **com, t_var *list);
int		my_script(char **com);
int		my_script2(char **t_file, t_var *list);

/* script_list.c */
t_var		*add_in_list(t_var *list, t_var *add);
void		my_put_list(t_var *list);
void		my_free_list_script(t_var *list);

/* set_var.c */
int		is_in_list(char *name, t_var **list);
void		set_var(char *name, char *value, t_var **list);

/* type_script.c */
char		is_var_script(char *line);
char		is_commande(char *line);
char		is_keyword(char *line);
char		*get_control_instruction_cond(char *file, int i);

/* eval_expr.c */
int		op_plus(int a, int b);
int		op_moins(int a, int b);
int		op_div(int a, int b);
int		op_mul(int a, int b);
int		op_mod(int a, int b);
int		eval_expr(char *str);
int		eval_expr_sub(char *str, int p);
int		is_nb(char *str);

/* str_func */
char		*get_word(char *str);

/* while.c */
char		*get_control_instruction_cond(char *file, int i);
int		exec_while(t_script **s, t_var *v, int *i);
t_script	*get_key_while(char *file, int pos);
int		exec_done(t_script *s, t_var *v, int *i);

/* condition.c */
int		check_nbr_cond(char *s1, char *s2, char *s3);
int		instruction(char *inst, t_var *v);
int		check_str_cond(char *s1, char *s2, char *s3);
int		check_exist_cond(char *s1, char *s2, char *s3);
int		all_exist_cond(char *s1, struct stat sb);
int		one_instruction(char *inst, t_var *v);

/* if.c */
void		free_list_cond(t_cond *list);
t_script	*get_fi(char *file);
t_script	*get_key_if(char *file, int pos);
int		exec_if(t_script **s, t_var **v, int *i);
t_script	*get_then(char *file);
t_script	*get_else(char *file);
t_script	*get_else_if(char *file, int pos);

/* ex_function.c */
t_var		*get_tmp_fct_var(t_script *s);
int		is_call_fct(t_script **s, int i);
int		exec_function(t_script **s, t_var **v, int i);

/* pars_cond_list.c */
void		my_put_list_cond(t_cond **list, char *data, int type);
int		get_size(char *str);
t_cond		*get_cond_list(char *s);

/* variable_script.c */
t_var		*get_spe_var(char **com, t_var *list, char *name);
t_var		*get_var_all_arg(char **com, t_var *list);
t_var		*get_var_len_tab(t_var *list, t_script **p);

/* error_script.c */
void		my_put_error_script(char *str, int line);

/* case.c */
t_script	**get_case(char **file, t_script **p, int *pos);
t_script	*get_case_end(char *file, int line);
t_script	*get_one_case(char *file, int line);
t_script	*get_case_header(char *file, int line);
int		ex_case(t_script **s, t_var **v, int *i);
t_script	*get_read(char *file, int pos);
int		ex_read(t_script *s, t_var **v);

/* for.c */
void		check_error_for(t_script *ret, int line);
t_script	*get_for(char *file, int pos);
char		**get_for_cond(char *inst, t_var *list);
void		init_for_var(char *name, t_var **v);
int		exec_for(t_script **s, t_var **v, int *i);
int		exec_instruc_for(t_script **s, t_var **v, int *i);

/* trap.c */
t_script	*get_trap(char *file, int pos);
void		get_call_trap(t_script **s, char *name);
int		get_trap_glob(t_script **s, t_var **v);

/* until.c */
t_script	*get_until(char *file, int pos);
int		exec_until(t_script **s, t_var **v, int *i);

#endif
