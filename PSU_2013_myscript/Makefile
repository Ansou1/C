##
## Makefile for  in /home/daguen_s/Projets/my_script
##
## Made by daguen_s
## Login   <daguen_s@epitech.net>
##
## Started on  Fri Feb 14 17:06:23 2014 daguen_s
## Last update Fri Feb 28 17:29:42 2014 daguen_s
##

SRC=			my_script.c\
			parser.c\
			term_and_win.c\
			tty_function.c\
			writting.c\
			xfunction.c

INCLUDE=		my_script.h

CFLAGS=			-Wall -Wextra -pedantic

OBJ=			$(SRC:.c=.o)

NAME=			my_script

all:			$(NAME)

%.i:			%.c $(INCLUDE)
			gcc -E $(@:.i=.c) > $@

$(NAME):		$(OBJ)
			gcc -o $@ $^

%.o:			%.c $(INCLUDE)
			gcc -c $< $(CFLAGS)

clean:
			rm -f $(OBJ)
			@rm -f $(addsuffix .gch, $(INCLUDE))

fclean:			clean
			rm -f $(NAME)

re:			fclean all

.PHONY:			clean fclean re
