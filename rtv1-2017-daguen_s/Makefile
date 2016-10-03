##
## Makefile for wolf in /home/daguen_s//charlotte
## 
## Made by simon daguenet
## Login   <daguen_s@epitech.net>
## 
## Started on  Tue Jan  8 11:02:57 2013 simon daguenet
## Last update Sun Mar 17 16:17:59 2013 simon daguenet
##

CC=	cc

NAME=	rtv1

SRC=	all_for_light.c\
	cone.c\
	cylinder.c\
	gere_pixel.c\
	get_k_min.c\
	initialisation.c\
	rotation.c\
	rtv1.c\
	sphere.c

OBJ=	$(SRC:.c=.o)

LDFLAGS=	-L/usr/lib64 -lmlx_x86_64-linux -L/usr/lib64/X11 -lXext -lX11 -lm

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all