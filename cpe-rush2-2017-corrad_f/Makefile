##
## Makefile for sudoku_bi in /home/daguen_s//rush
##
## Made by simon daguenet
## Login   <daguen_s@epitech.net>
##
## Started on  Fri Apr 19 20:42:54 2013 simon daguenet
## Last update Sun Apr 21 22:07:15 2013 simon daguenet
##

CC=		cc -ansi -pedantic -Wextra -Wall -O2

NAME1=		./etape1/sudoki-bi

SRC1=		./etape1/check.c\
		./etape1/get_map.c\
		./etape1/get_next_line.c\
		./etape1/print.c\
		./etape1/resolve.c\
		./etape1/resolve_fou.c\
		./etape1/resolve_sec.c\
		./etape1/resolve_thr.c\
		./etape1/x_function.c

OBJ1=		$(SRC1:.c=.o)

NAME2=		./etape2/sudoki-bis

SRC2=		./etape2/check.c\
		./etape2/get_map.c\
		./etape2/get_next_line.c\
		./etape2/print.c\
		./etape2/resolve.c\
		./etape2/resolve_fou.c\
		./etape2/resolve_sec.c\
		./etape2/resolve_thr.c\
		./etape2/x_function.c

OBJ2=		$(SRC2:.c=.o)

NAME3=		./graph/sudoki-bi-graph

SRC3=		./graph/graphique.c\
		./graph/check.c\
		./graph/get_map.c\
		./graph/get_next_line.c\
		./graph/print.c\
		./graph/resolve.c\
		./graph/resolve_fou.c\
		./graph/resolve_sec.c\
		./graph/resolve_thr.c\
		./graph/x_function.c\
		./graph/draw_all.c

OBJ3=		$(SRC3:.c=.o)

RM=		rm -f

all:		$(NAME1) $(NAME2) $(NAME3)

$(NAME1):	$(OBJ1)
		$(CC) -o $(NAME1) $(OBJ1) -lm

$(NAME2):	$(OBJ2)
		$(CC) -o $(NAME2) $(OBJ2) -lm

$(NAME3):	$(OBJ3)
		cc -o $(NAME3) $(OBJ3) -L/usr/lib64 -lmlx_x86_64-linux -L/usr/lib64/X11 -lXext -lX11 -lm

clean:
		$(RM) $(OBJ1) $(OBJ2) $(OBJ3)

fclean:		clean
		$(RM) $(NAME1) $(NAME2) $(NAME3)

re:		fclean all