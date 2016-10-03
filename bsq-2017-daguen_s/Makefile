##
## Makefile for makefile fdf in /home/daguen_s//Ighaph/fdf
## 
## Made by simon daguenet
## Login   <daguen_s@epitech.net>
## 
## Started on  Sun Dec  2 21:55:00 2012 simon daguenet
## Last update Sun Dec  9 21:04:16 2012 simon daguenet
##

SRC=	my_bsq.c\
	get_next_line.c\
	my_getnbr.c\
	my_strdup.c


OBJ=	$(SRC:.c=.o)

CC=	cc

NAME=	bsq

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean $(NAME)
