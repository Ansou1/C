##
## Makefile for mysh in /home/daguen_s//secminishell
## 
## Made by simon daguenet
## Login   <daguen_s@epitech.net>
## 
## Started on  Sat Mar  9 12:39:49 2013 simon daguenet
## Last update Sat Mar  9 12:44:25 2013 simon daguenet
##

SRC=	all_strdup.c\
	builtins.c\
	cl_fr.c\
	comp_func.c\
	count.c\
	get_path.c\
	get_value.c\
	list.c\
	mysh.c\
	pipe.c\
	print.c\
	print_error.c\
	redirection.c\
	simple_cmd.c\
	str_to_wordtab.c\
	xfunction.c

OBJ=	$(SRC:.c=.o)

CC=	cc

NAME=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean $(NAME)
