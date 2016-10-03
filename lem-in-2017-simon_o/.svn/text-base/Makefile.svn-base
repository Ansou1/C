##
## Makefile for lemin in /home/daguen_s//my_lemin
## 
## Made by simon daguenet
## Login   <daguen_s@epitech.net>
## 
## Started on  Mon Apr  1 15:59:04 2013 simon daguenet
## Last update Sun Apr 28 13:52:23 2013 simon daguenet
##

SRC=		del_crossing_way.c\
		del_crossing_way_sec.c\
		dell_useless_way.c\
		door.c\
		get_file.c\
		get_next_line.c\
		lemin.c\
		link.c\
		moov.c\
		moov_sec.c\
		my_link.c\
		parser.c\
		print.c\
		tools.c\
		tools_2.c\
		tools_3.c\
		water_fill.c\
		x_func.c

OBJ=		$(SRC:.c=.o)

CC=		cc -ansi -pedantic

NAME=		lem_in

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $^ -o $@

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all