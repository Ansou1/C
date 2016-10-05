##
## Makefile for  in /home/daguen_s/rendu/T2Rush1
##
## Made by daguen_s
## Login   <daguen_s@epitech.net>
##
## Started on  Fri Mar  7 20:44:26 2014 daguen_s
## Last update Sun Mar  9 18:49:07 2014 daguen_s
##

SRC=		main.c\
		get_next_line.c\
		display.c\
		tools_sdl.c\
		xfunction.c\
		check_map.c\
		menu.c\
		sound.c

INCLUDE=	rush.h

CFLAGS=		-Wall -Wextra

LDFLAGS=

OBJ=		$(SRC:.c=.o)

NAME=		epikong

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $@ $^ $(LDFLAGS) -lSDL -lSDL_image -lSDL_mixer

%.o:		%.c $(INCLUDE)
		gcc -c $< $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
