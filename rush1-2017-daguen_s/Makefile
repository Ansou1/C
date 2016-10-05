##
## Makefile for makefile in /home/daguen_s//rush/ex_1
## 
## Made by simon daguenet
## Login   <daguen_s@epitech.net>
## 
## Started on  Sun Dec  2 17:01:39 2012 simon daguenet
## Last update Sun Dec  2 17:20:02 2012 simon daguenet
##

SRC=	etape_1/get_next_line.c\
	etape_1/my_getnbr.c\
	etape_1/my_strcat.c\
	etape_1/my_strdup.c\
	etape_1/print.c\
	etape_1/rush.c

OBJ=	$(SRC:.c=.o)

CC=	cc

NAME=	tko2-1

all:	$(NAME)

$(NAME):        $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
	mv $(NAME) etape_1
clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean $(NAME)
