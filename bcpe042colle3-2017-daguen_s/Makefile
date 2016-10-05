##
## Makefile for makefile in /home/daguen_s//colle3/colle
## 
## Made by simon daguenet
## Login   <daguen_s@epitech.net>
## 
## Started on  Sun Oct 28 00:35:57 2012 simon daguenet
## Last update Sun Oct 28 01:35:04 2012 simon daguenet
##

SRC=	colle3.c \
	get_info.c

OBJ=	$(SRC:.c=.o)

NAME=	./colle3

cc=	cc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)  -L ./libmy -lmy

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(OBJ)

re:	fclean all