##
## Makefile for rush in /home/hody_a//alum1
## 
## Made by alexy hody
## Login   <hody_a@epitech.net>
## 
## Started on  Mon Feb  4 14:56:54 2013 alexy hody
## Last update Sun Mar  3 15:42:12 2013 simon daguenet
##

CC	=	cc

NAME	=	grimly

SRC	=	etape_1/grimly.c\
		etape_1/laby.c\
		etape_1/get_next_line.c\
		etape_1/algo_laby.c\
		etape_1/end.c\
		etape_1/algo_number.c\
		etape_1/end_number.c\
		etape_1/get_map.c\
		etape_1/print.c\
		etape_1/x_function.c

OBJ	= $(SRC:.c=.o)

CFLAGS	= -o2 -W -Wall -pedantic -Iinclude

RM	= rm -f

all	: $(NAME)

$(NAME)	: $(OBJ)
	cc -o $(NAME) $(OBJ)
	mv $(NAME) etape_1

clean	:
	$(RM) $(OBJ) *~ \#*

fclean	: clean
	$(RM) $(NAME)

re	: fclean all