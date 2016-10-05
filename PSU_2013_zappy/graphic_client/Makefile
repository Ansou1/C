SRC=		main.c\
		connection.c\
		sdl.c\
		set_background.c\
		xfunction.c\
		image.c

INCLUDE=	graphique.h

CFLAGS=		-Wall -Wextra

LDFLAGS=	-lSDL -lSDL_image

OBJ=		$(SRC:.c=.o)

NAME=		client_graphique

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $@ $^ $(LDFLAGS)

%.o:		%.c $(INCLUDE)
		gcc -c $< $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		clean fclean help re
