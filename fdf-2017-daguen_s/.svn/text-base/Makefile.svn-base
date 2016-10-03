##
## Makefile for makefile fdf in /home/daguen_s//Ighaph/fdf
## 
## Made by simon daguenet
## Login   <daguen_s@epitech.net>
## 
## Started on  Sun Dec  2 21:55:00 2012 simon daguenet
## Last update Sat Dec  8 16:29:06 2012 simon daguenet
##

SRC=	get_map.c\
	get_next_line.c\
	my_getnbr.c\
	my_str_to_wordtab.c\
	my_strdup.c\
	my_fdf.c\
	draw_line.c\
	gere.c

OBJ=	$(SRC:.c=.o)

CC=	cc

NAME=	fdf

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) -L/usr/lib64 -lmlx_x86_64-linux -L/usr/lib64/X11 -lXext -lX11

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean $(NAME)
