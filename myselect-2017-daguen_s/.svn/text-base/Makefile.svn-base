##
## Makefile for my_select in /home/daguen_s//charlotte
## 
## Made by simon daguenet
## Login   <daguen_s@epitech.net>
## 
## Started on  Mon Jan 14 14:09:27 2013 simon daguenet
## Last update Sat Jan 19 23:38:51 2013 simon daguenet
##

CC=	cc

NAME=	my_select

SRC=	action.c\
	delete.c\
	fonction_print.c\
	list_chainee.c\
	my_select.c\
	other.c\
	print_action.c\
	print_error.c\
	to_env.c

OBJ=	$(SRC:.c=.o)

LDFLAGS=	-ltermcap -pedantic -ansi -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all