##
## Makefile for libmy in /home/daguen_s//test
## 
## Made by simon daguenet
## Login   <daguen_s@epitech.net>
## 
## Started on  Mon Oct 22 11:23:02 2012 simon daguenet
## Last update Sun Oct 28 01:41:59 2012 simon daguenet
##

SRC=    my_putchar.c \
        my_isneg.c \
        my_put_nbr.c \
        my_swap.c \
        my_putstr.c \
        my_strlen.c \
        my_getnbr.c \
        my_sort_int_tab.c \
        my_power_rec.c \
        my_square_root.c \
        my_is_prime.c \
        my_find_prime_sup.c \
        my_strcpy.c \
        my_strncpy.c \
        my_revstr.c \
        my_strstr.c \
        my_strcmp.c \
        my_strncmp.c \
        my_strupcase.c \
        my_strlowcase.c \
        my_strcapitalize.c \
        my_str_isalpha.c \
        my_str_isnum.c \
        my_str_islower.c \
        my_str_isupper.c \
        my_str_isprintable.c \
        my_showstr.c \
        my_showmem.c \
        my_strcat.c \
        my_strncat.c \
        my_strlcat.c

NAME=   libmy.a

CC=     cc

OBJ=    $(SRC:.c=.o)

all:    $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm $(OBJ)

fclean:		clean
	rm $(NAME)

re:	fclean all