##
## Makefile for libmy in /home/elegbe_m//programmation/fichiers_source_piscine/1ere_iteration/rendu/piscine/Jour_11
## 
## Made by martial elegbede
## Login   <elegbe_m@epitech.net>
## 
## Started on  Mon Oct 22 14:05:54 2012 martial elegbede
## Last update Sat Nov 10 16:31:27 2012 martial elegbede
##

SRC=	chain_from_str.c\
	list_op.c\
	polonianize.c\
	put_in_lists.c\
	delete_lists.c\
	my_nbrdup.c\
	do_inf_add.c\
	do_inf_sub.c\
	do_inf_mult.c\
	do-op.c\
	calc_algo.c\
	my_strdup.c\
	eval_expr.c\
	replace_ops.c\
	get_base.c\
	sub_assignement.c\
	memset.c\
	main.c

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -I./includes

LFLAGS= -Llib -lmy

OBJ=	$(SRC:.c=.o)

NAME=	calc

CC=	gcc

RM=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)

debug:	fclean $(SRC)
	gcc -c $(SRC) $(CFLAGS) -g3
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

.PHONY: debug re fclean clean $(NAME) all