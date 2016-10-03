##
## Makefile for allum1 in /home/daguen_s//myalum1
## 
## Made by simon daguenet
## Login   <daguen_s@epitech.net>
## 
## Started on  Mon Jan 28 09:36:43 2013 simon daguenet
## Last update Sun Feb 10 20:17:35 2013 simon daguenet
##

CC=	cc -ltermcap -pedantic -ansi -Wall -Wextra

NAME=	allum1

SRC=	allum1.c\
	aff_matches.c\
	aff_num.c\
	all_get.c\
	check_pair.c\
	env.c\
	fonction_print.c\
	gest_ia_one.c\
	gest_ia_second.c\
	gest_ia_third.c\
	get_info.c\
	ia.c\
	list.c\
	other.c\
	player.c\
	player_vs_player.c

OBJ=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC)  $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
