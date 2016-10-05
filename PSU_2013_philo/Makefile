##
## Makefile for  in /home/daguen_s/rendu/PSU_2013_philo
##
## Made by daguen_s
## Login   <daguen_s@epitech.net>
##
## Started on  Mon Mar 10 11:52:28 2014 daguen_s
## Last update Wed Mar 19 10:25:34 2014 corrad_f
##

SRC=		main.c

INCLUDE=	philo.h

CFLAGS=		-Wall -Wextra

LDFLAGS=	-lpthread

OBJ=		$(SRC:.c=.o)

NAME=		philo

all:		$(NAME)

#linking project
$(NAME):	$(OBJ)
		gcc -o $@ $^ $(LDFLAGS)

#object Generation
%.o:		%.c $(INCLUDE)
		gcc -c $< $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		clean fclean help re
