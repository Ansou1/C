##
## Makefile for makefile printf in /home/daguen_s//myownprintf
## 
## Made by simon daguenet
## Login   <daguen_s@epitech.net>
## 
## Started on  Sun Nov 18 16:18:35 2012 simon daguenet
## Last update Sun Nov 18 19:40:54 2012 simon daguenet
##

SRC=	exept.c\
	my_getnbr.c\
	my_getpointeur.c\
	my_printf.c\
	my_putchar.c\
	my_putnbr_base2.c\
	my_putstr.c\
	my_putstr_unprintable.c\
	my_revstr.c\
	my_strlen.c

OBJ=	$(SRC:.c=.o)

NAME=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean $(NAME)