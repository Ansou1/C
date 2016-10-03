##
## Makefile for my_select in /home/antoni_s//myselect-2017-antoni_s/lib
##
## Made by sebastien antonico
## Login   <antoni_s@epitech.net>
##
## Started on  Sun Jan 20 00:54:57 2013 sebastien antonico
## Last update Sun Mar 31 18:57:59 2013 sebastien antonico
##

NAME	= libmy.a

SRC	= my_strlen.c \
	  my_puterr.c \
	  my_strcpy.c \
	  my_putchar.c \
	  my_putnbrXX.c \
	  my_getnbr.c \
	  my_strncmp.c \
	  my_memset.c \
	  my_find.c \
	  my_nblen.c \
	  my_printf.c \
	  my_putnbr_base.c \
	  my_putnbr.c \
	  my_putnbr_us.c \
	  my_putptr.c \
	  my_putstr.c \
	  my_putstr_spec.c \
	  my_putthing.c \
	  parsing.c

OBJ	= $(SRC:.c=.o)

CFLAGS	+= -Wall

all:	$(NAME)

$(NAME):	$(OBJ)
	cc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all