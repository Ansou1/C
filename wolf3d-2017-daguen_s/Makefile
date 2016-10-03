##
## Makefile for wolf in /home/daguen_s//charlotte
## 
## Made by simon daguenet
## Login   <daguen_s@epitech.net>
## 
## Started on  Tue Jan  8 11:02:57 2013 simon daguenet
## Last update Mon Jun 17 11:00:35 2013 simon daguenet
##

CC=	cc

NAME=	wolf3d

SRC=	draw.c\
	k_value.c\
	mvt.c\
	my_wolf.c

OBJ=	$(SRC:.c=.o)

LDFLAGS=	-L/usr/lib64 -lmlx_x86_64-linux -L/usr/lib64/X11 -lXext -lX11 -lm -g

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all