##
## Makefile for minishell1 in /home/corrad_f//projet/minishell1
## 
## Made by florian corradin
## Login   <corrad_f@epitech.net>
## 
## Started on  Tue Dec 11 17:01:03 2012 florian corradin
## Last update Thu May 23 14:42:55 2013 simon daguenet
##

SRC	= main.c\
	  prompt.c\
	  variable.c\
	  str_concat.c\
	  tab_concat.c\
	  fill_env.c\
	  separator.c\
	  clean_pars_line.c\
	  list_double.c\
	  parser_com.c\
	  get_path.c\
	  buitins_env.c\
	  commande.c\
	  x_fct.c\
	  x_fct2.c\
	  pipe.c\
	  type_redir.c\
	  error.c\
	  pipe_redir.c\
	  double_redir.c\
	  get_com_params.c\
	  cd.c\
	  var_env.c\
	  inhibiteur.c\
	  str_tab_inib.c\
	  deshiniber.c\
	  glob.c\
	  back_quote.c\
	  getenv.c\
	  change_directory.c\
	  get_back_quote_file.c\
	  unsetenv.c\
	  exec.c\
	  multipipe.c\
	  dif_parser.c\
	  ascii.c\
	  echo.c\
	  atof.c\
	  type.c\
	  script/is_scripting.c\
	  script/script.c\
	  script/parser_script.c\
	  script/type_script.c\
	  script/script_list.c\
	  script/add_var.c\
	  script/recup_var.c\
	  alias.c\
	  alias_bult.c\
	  buitins.c\
	  script/modif_str.c\
	  script/function.c\
	  script/strtoll.c\
	  script/ex_com.c\
	  script/ex_all.c\
	  script/ex_asign.c\
	  script/set_var.c\
	  script/while.c\
	  script/let.c\
	  script/eval_expr.c\
	  script/str_func.c\
	  script/condition.c\
	  script/if.c\
	  script/ex_function.c\
	  clean_command.c\
	  script/pars_cond_list.c\
	  script/variable_script.c\
	  script/error_script.c\
	  script/case.c\
	  script/read.c\
	  the_time42.c\
	  the_rand.c\
	  script/str_condition.c\
	  script/op.c\
	  script/pars_if.c\
	  script/pars_elem_com.c\
	  script/pars_elem_com2.c\
	  script/prepa_script.c\
	  script/recup_var2.c\
	  init_alias.c\
	  clean_command2.c\
	  option_echo.c\
	  main_separator.c\
	  prompt_effect.c\
	  script/for.c\
	  script/trap.c\
	  script/until.c\
	  script/exec_for.c\
	  check_opt_hist.c\
	  ex_history.c\
	  history.c\
	  new_hist.c\
	  remplace_for_hist.c

CC	= gcc $(LFLAG)

LFLAG	= -O -Wall\
	  -pedantic -ansi

OBJS	= $(SRC:.c=.o)

NAME	= infectsh

LIB	= library/libmy.a

all: $(NAME)

$(LIB):
	(cd ./library && $(MAKE))

$(NAME): $(LIB) $(OBJS)
	$(CC) $^ -o $@  -L./library -lmy

gdb:
	cc $(SRC) -L./library -lmy -g3

clean:
	rm -f a.out
	rm -f $(OBJS)
	(cd ./library && $(MAKE) clean)

fclean: clean
	rm -f $(NAME)
	(cd ./library && $(MAKE) fclean)

re: fclean $(NAME)

.PHONY: all clean fclean re