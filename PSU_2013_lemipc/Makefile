##
## Makefile for  in /home/daguen_s/rendu/PSU_2013_lemipc
##
## Made by daguen_s
## Login   <daguen_s@epitech.net>
##
## Started on  Sun Mar 23 15:56:55 2014 daguen_s
## Last update Sat Mar 29 20:46:32 2014 daguen_s
##

SRC=		main.c\
		t.c\
		team.c\
		info_map.c\
		party.c\
		sdl.c\
		get.c

INCLUDE=	lemipc.h

CFLAGS=		-Wall -Wextra

LDFLAGS=	-lSDL -lm

OBJ=		$(SRC:.c=.o)

NAME=		lemipc

all:		$(NAME)

#linking project
$(NAME):	$(OBJ)
		gcc -o $@ $^ $(LDFLAGS)

#object Generation
%.o:		%.c $(INCLUDE)
		gcc -c $< $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		clean fclean help re
