##
## Makefile for makefile printf in /home/daguen_s//myownprintf
## 
## Made by simon daguenet
## Login   <daguen_s@epitech.net>
## 
## Started on  Sun Nov 18 16:18:35 2012 simon daguenet
## Last update Fri Nov 30 21:30:33 2012 simon daguenet
##

SRC=	get_option.c\
	list.c\
	ls_printf.c\
	my_ls.c\
	my_putchar.c\
	my_putnbr_base2.c\
	my_putstr.c\
	my_putstr_temps.c\
	my_strcat.c\
	my_strcmp.c\
	my_strdup.c\
	my_strlen.c\
	my_strstr.c\
	pick-stg.c

OBJ=	$(SRC:.c=.o)

CC=	cc

NAME=	my_ls

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean $(NAME)